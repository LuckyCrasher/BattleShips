//
// Created by twostone on 19.02.24.
//

#ifndef BATTLESHIPS_SERVERCLIENT_H
#define BATTLESHIPS_SERVERCLIENT_H

#include <netinet/in.h>
//#include "BattleShipGameServer.h"
#include "ClientManager.h"
#include "GameServer.h"


namespace BattleShipsGameServer {

    enum ClientAction {
        DISCONNECT,
        NOOP,
    };

    class ServerClient {
    private:
        GameServer &gameServer;
        sockaddr_in client_address;
        int client_socket;
    public:
        ServerClient(GameServer &gameServer, sockaddr_in client_address, int client_socket);
        ~ServerClient();
        int get_client_socket() const;
        BattleShipsGameServer::ClientAction handle_data(fd_set &socket_set);
        //void sendMessage();

    };

} // BattleShipsGameServer

#endif //BATTLESHIPS_SERVERCLIENT_H
