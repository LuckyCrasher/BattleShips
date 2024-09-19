//
// Created by twostone on 19.02.24.
//

#include "Protocol.h"

namespace BattleShipsGameServer {

    void Protocol::handleProtocolMessage(std::string &message) {
        ProtocolMessage protoMessage = ProtocolMessage(message);
    }
} // BattleShipsGameServer