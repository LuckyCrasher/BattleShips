//
// Created by twostone on 19.02.24.
//

#ifndef BATTLESHIPS_BATTLESHIPGAMESERVER_H
#define BATTLESHIPS_BATTLESHIPGAMESERVER_H

//#include "../Utilities/Observer.h"

namespace BattleShipsGameServer {

    class GameServer;

    class SocketServer;
    class ClientManager;
    class ServerClient;
    class Protocol;
    class ProtocolMessage;
    class ProtocolOperation;

    void startServer(GameServer &gameServer);

}

#endif //BATTLESHIPS_BATTLESHIPGAMESERVER_H
