//
// Created by twostone on 19.02.24.
//

#include "ProtocolMessage.h"

#include <utility>
#include <sstream>
#include <iostream>

namespace BattleShipsGameServer {
    void ProtocolMessage::parseParameters() {
        // Takes only space separated C++ strings.
        if (std::shared_ptr<std::string> locked = this->message.lock()) {
            std::stringstream ss(*locked);
            std::string word;
            while (ss >> word) { // Extract word from the stream.
                this->parameters.push_back(word);
                std::cout << word << std::endl;
            }
        }
    }

    ProtocolMessage::ProtocolMessage(std::string &message) {
        this->message = message;
        parseParameters();
        this->command = std::make_unique<std::string>(parameters[0]);
    }
} // BattleShipsGameServer