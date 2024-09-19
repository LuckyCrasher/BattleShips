#include <iostream>
#include "SocketServer.h"

int main() {
    BattleShipsGameServer::GameServer gameServer = BattleShipsGameServer::GameServer();
    BattleShipsGameServer::startServer(gameServer);
    return 0;
}
