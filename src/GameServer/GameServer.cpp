//
// Created by twostone on 11.09.24.
//

#include <iostream>
#include "GameServer.h"

namespace BattleShipsGameServer {

    GameServer::GameServer() {
       this->protocolHandler = Protocol();
    }

    void GameServer::handleBattleShipsProtocol(const std::string &message, ServerClient const &sender) {
        std::cout << "Got Protocol message " << message << std::endl;
        this->protocolHandler.handleProtocolMessage(message);
    }
} // BattleShipsGameServer