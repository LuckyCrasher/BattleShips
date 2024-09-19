//
// Created by twostone on 19.02.24.
//

#ifndef BATTLESHIPS_PROTOCOL_H
#define BATTLESHIPS_PROTOCOL_H

#include <unordered_map>
#include <string>
#include <memory>
#include "BattleShipGameServer.h"
#include "ProtocolOperation.h"
#include "ProtocolMessage.h"

namespace BattleShipsGameServer {

    class Protocol {
    private:
        std::unordered_map<std::string, std::unique_ptr<ProtocolOperation>> operations;
    public:
        explicit Protocol() = default;
        //handle message / event
        static void handleProtocolMessage(std::string &message);

    };

} // BattleShipsGameServer

#endif //BATTLESHIPS_PROTOCOL_H
