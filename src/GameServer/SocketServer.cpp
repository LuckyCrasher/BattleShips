//
// Created by twostone on 16.02.24.
//


#include "SocketServer.h"
//#include "Observer.h"

//using namespace BattleShipsGameUtilities;

namespace BattleShipsGameServer {

    void startServer(GameServer &gameServer) {
        SocketServer server = SocketServer(gameServer);
        server.run();
    }

    SocketServer::SocketServer(GameServer &gameServer): gameServer(gameServer) {
        FD_ZERO(&read_fds);

        // Create a socket
        server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket == 0) {
            perror("Socket creation failed");
            exit(EXIT_FAILURE);
        }

        // Set up the server address structure
        this->server_address = {0};
        this->server_address.sin_family = AF_INET;
        this->server_address.sin_addr.s_addr = INADDR_ANY;
        this->server_address.sin_port = htons(PORT);

        // Bind the socket to the specified port
        if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
            perror("Bind failed");
            exit(EXIT_FAILURE);
        }

        // create the client manager
        this->client_manager = std::make_unique<ClientManager>(gameServer);

        // start listening
        listen();
    }

    void SocketServer::listen() const {
        // Listen for incoming connections
        if (::listen(server_socket, MAX_CLIENTS) < 0) {
            perror("Listen failed");
            exit(EXIT_FAILURE);
        }
        std::cout << "Server listening on port " << PORT << std::endl;
    }

    void SocketServer::acceptPendingConnections() {
        int clientSocket;
        sockaddr_in clientAddress{};
        socklen_t clientAddrLen = sizeof(clientAddress);
        // If a new connection is pending, accept it
        clientSocket = accept(this->server_socket, (struct sockaddr *) &clientAddress,&clientAddrLen);

        if (clientSocket < 0) {
            perror("Accept error");
            exit(EXIT_FAILURE);
        } else {
            this->client_manager->add_new_client(clientAddress, clientSocket);
        }
    }

    [[noreturn]] void SocketServer::run() {
        int max_sd=0, sd=0;
        std::vector<std::unique_ptr<ServerClient>> *clients;

        // run server loop
        while (true) {
            // Clear the socket set
            FD_ZERO(&read_fds);

            // Add server socket to the set
            FD_SET(this->server_socket, &this->read_fds);
            max_sd = this->server_socket;

            // Add child sockets to the set
            clients = &this->client_manager->get_clients();
            for (const auto & client : *clients) {
                sd = client->get_client_socket();
                if (sd > 0) {
                    FD_SET(sd, &this->read_fds);
                }
                if (sd > max_sd) {
                    max_sd = sd;
                }
            }

            // WAIT <- this mf returns when there is activity... for an activity on any of the sockets
            int activity = select(max_sd + 1, &read_fds, nullptr, nullptr, nullptr);

            if ((activity < 0) && (errno != EINTR)) {
                perror("Select error");
            }

            if (FD_ISSET(server_socket, &read_fds)) acceptPendingConnections();
            this->client_manager->handle_client_data(this->read_fds);
        }
    }

} // SocketServer