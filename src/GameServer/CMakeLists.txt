file(GLOB BattleShipsGameServer_SOURCES "*.cpp" "*.h")

# Add the sources to the library
add_library(BattleShipsGameServer ${BattleShipsGameServer_SOURCES}
        GameServer.cpp
        GameServer.h
        ProtocolOperation.cpp
        ProtocolOperation.h)