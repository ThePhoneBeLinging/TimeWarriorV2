//
// Created by Elias Aggergaard Larsen on 15/09/2024.
//

#ifndef ROOMCREATOR_H
#define ROOMCREATOR_H
#include "Room.h"
#include "Objects/Player.h"
#include "Objects/PressurePlate.h"
#include "Objects/Wall.h"
#include "Objects/RoomSwitcherObject.h"
#include "Objects/LongWall.h"


class RoomCreator
{
public:
    static void setUpRooms(int amountOfRooms);
    static void update(float deltaTime);
    static void enterRoom(int roomNumber);
    static void resetRoom();
    static bool isSwitchingRooms();
private:
    static void handleMovement();
    static void setUpRoom(const std::shared_ptr<Room>& room ,int roomNumber);
    static inline std::shared_ptr<Room> currentRoom_;
    static inline std::vector<std::shared_ptr<Player>> players_;
    static inline std::vector<std::shared_ptr<Room>> rooms_;
    static inline int playerIndex_ = 0;
    static inline bool roomSwitching_ = false;

};



#endif //ROOMCREATOR_H
