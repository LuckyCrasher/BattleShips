//
// Created by twostone on 19.02.24.
//

#include <csignal>
#include <iostream>
#include "ServerClient.h"

namespace BattleShipsGameServer {

    ServerClient::ServerClient(GameServer &gameServer, sockaddr_in client_address, int client_socket):
            client_address(client_address), client_socket(client_socket), gameServer(gameServer) {
        std::cout << "New client with address " << inet_ntoa(client_address.sin_addr) << " on socket "
                  << client_socket << std::endl;
    }

    int ServerClient::get_client_socket() const {
        return client_socket;
    }

    ClientAction ServerClient::handle_data(fd_set &socket_set) {
        std::cout << "Handling client data" << std::endl;
        if (FD_ISSET(this->client_socket, &socket_set)) {
            char buffer[1024] = {0};
            int valread = read(this->client_socket, buffer, sizeof(buffer));

            if (valread == 0) {
                // Client disconnected
                return ClientAction::DISCONNECT;
            } else {
                // Handle data from client
                std::string message = std::string(buffer);
                std::cout << "Received message from " << inet_ntoa(this->client_address.sin_addr) << std::endl;
                std::cout << "Client sent: " << message << std::endl;
                this->gameServer.handleBattleShipsProtocol(message, *this);
            }
        }
        std::cout << "Finished handling client data" << std::endl;
        return NOOP;

    }

    ServerClient::~ServerClient() {
        ::close(this->client_socket);
        this->client_socket = -1;
    }
} // BattleShipsGameServer