cmake_minimum_required(VERSION 3.27)
project(BattleShips)

set(CMAKE_CXX_STANDARD 17)

add_executable(BattleShips src/main.cpp)

include_directories(src/GameServer)
include_directories(src/Utilities)

add_subdirectory(src/GameServer)
add_subdirectory(src/Utilities)

target_link_libraries(BattleShips BattleShipsGameServer)