//
// Created by twostone on 19.02.24.
//

#ifndef BATTLESHIPS_PROTOCOLMESSAGE_H
#define BATTLESHIPS_PROTOCOLMESSAGE_H

#include "BattleShipGameServer.h"
#include <memory>
#include <vector>
#include "string"

namespace BattleShipsGameServer {

    class ProtocolMessage {
    private:
        std::string message;
        std::string command;
        std::vector<std::string> parameters;
        void parseParameters();
    public:
        explicit ProtocolMessage(std::string &message);
    };

} // BattleShipsGameServer

#endif //BATTLESHIPS_PROTOCOLMESSAGE_H
