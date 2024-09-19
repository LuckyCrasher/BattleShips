//
// Created by twostone on 19.02.24.
//

#ifndef BATTLESHIPS_CLIENTMANAGER_H
#define BATTLESHIPS_CLIENTMANAGER_H

#include <arpa/inet.h>
#include <unistd.h>

#include "BattleShipGameServer.h"
#include "ServerClient.h"
#include <vector>
#include <memory>
#include "GameServer.h"

//using namespace BattleShipsGameUtilities;

namespace BattleShipsGameServer {

    class ClientManager {
    private:
        GameServer &gameServer;
        std::vector<std::unique_ptr<ServerClient>> clients;
    public:
        explicit ClientManager(GameServer &gameServer);
        void handle_client_data(fd_set &socket_set);
        std::vector<std::unique_ptr<ServerClient>>& get_clients();
        void add_new_client(sockaddr_in client_address, int client_socket);
        //void sendToClient(int id, const std::string& message);
    };

} // BattleShipsGameServer

#endif //BATTLESHIPS_CLIENTMANAGER_H
