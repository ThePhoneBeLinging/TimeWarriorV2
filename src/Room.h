//
// Created by Elias Aggergaard Larsen on 22/09/2024.
//

#ifndef ROOM_H
#define ROOM_H
#include "LongWall.h"
#include "Player.h"
#include "PressurePlate.h"
#include "RoomSwitcherObject.h"
#include "Wall.h"
#include "ActivateAble/SlidingDoor.h"


class Room
{
public:
    Room(float entranceX, float entranceY);
    void handleLocalThings(const std::vector<std::shared_ptr<Player>>& players);
    int handleRoomSwitchers(const std::vector<std::shared_ptr<Player>>& players);
    void handlePressurePlates(const std::vector<std::shared_ptr<Player>>& players);
    void offsetRoom(float deltaX, float deltaY);
    std::vector<std::shared_ptr<PressurePlate>> pressurePlates_;
    std::vector<std::shared_ptr<SlidingDoor>> slidingDoors_;
    std::vector<std::shared_ptr<LongWall>> longWalls_;
    std::vector<std::shared_ptr<RoomSwitcherObject>> roomSwitchers_;
    float entranceX_;;
    float entranceY_;
    int roomNumber_;
    bool switchingRooms_ = false;
};



#endif //ROOM_H
