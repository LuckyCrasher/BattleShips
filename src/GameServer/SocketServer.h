//
// Created by twostone on 16.02.24.
//

#ifndef BATTLESHIPS_SOCKETSERVER_H
#define BATTLESHIPS_SOCKETSERVER_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <memory>

#include "BattleShipGameServer.h"
#include "ClientManager.h"

/*using BattleShipsGameUtilities::Observer;
using BattleShipsGameUtilities::Subject;
using BattleShipsGameUtilities::Message;
*/

namespace BattleShipsGameServer {

    class SocketServer {
    private:
        const static int MAX_CLIENTS = 16;
        const static int PORT = 12345;
        int server_socket;
        fd_set read_fds{};
        sockaddr_in server_address{};
        std::unique_ptr<ClientManager> client_manager;
        GameServer &gameServer;

        void listen() const;
        void acceptPendingConnections();
    public:
        explicit SocketServer(GameServer &gameServer);
        [[noreturn]] void run();
    };

} // SocketServer

#endif //BATTLESHIPS_SOCKETSERVER_H
