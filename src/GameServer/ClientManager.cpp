//
// Created by twostone on 19.02.24.
//

#include <iostream>
#include "ClientManager.h"

namespace BattleShipsGameServer {
    /*ClientManager::ClientManager(std::shared_ptr<fd_set> socket_set): socket_set(std::move(socket_set)) {
        this->clients = std::vector<std::unique_ptr<ServerClient>>(0);
    }*/

    ClientManager::ClientManager(GameServer &gameServer): gameServer(gameServer) {
        this->clients = std::vector<std::unique_ptr<ServerClient>>(0);
    }

    void ClientManager::add_new_client(sockaddr_in client_address, int client_socket) {
        std::cout << "New connection, socket fd is " << client_socket << ", IP is : "
                  << inet_ntoa(client_address.sin_addr)
                  << ", port : " << ntohs(client_address.sin_port) << std::endl;

        this->clients.push_back(std::make_unique<ServerClient>(gameServer, client_address, client_socket));
    }

    void ClientManager::handle_client_data(fd_set &socket_set) {
        // Check if any client sent data
        std::vector<int> disconnectedClients = std::vector<int>();
        ClientAction action;
        int clientId = 0;
        for (const auto & client : this->clients) {
            action = client->handle_data(socket_set);
            if (action == ClientAction::DISCONNECT) disconnectedClients.push_back(clientId);
            clientId++;
        }

        // Free from disconnects
        for (int i : disconnectedClients) {
            std::cout << "Client " << i << " marked for disconnect" << std::endl;
            this->clients.erase(this->clients.begin() + i);
        }

    }

    std::vector<std::unique_ptr<ServerClient>>& ClientManager::get_clients() {
        return this->clients;
    }
} // BattleShipsGameServer