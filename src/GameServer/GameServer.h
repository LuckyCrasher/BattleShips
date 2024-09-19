//
// Created by twostone on 11.09.24.
//

#ifndef BATTLESHIPS_GAMESERVER_H
#define BATTLESHIPS_GAMESERVER_H

#include <string>
#include "BattleShipGameServer.h"
#include "Protocol.h"

namespace BattleShipsGameServer {

    class GameServer {
    private:
        Protocol protocolHandler;
    public:
        GameServer();
        void handleBattleShipsProtocol(const std::string &message, const ServerClient &sender);
    };

} // BattleShipsGameServer

#endif //BATTLESHIPS_GAMESERVER_H
