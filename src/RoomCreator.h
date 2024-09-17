//
// Created by Elias Aggergaard Larsen on 15/09/2024.
//

#ifndef ROOMCREATOR_H
#define ROOMCREATOR_H
#include "Objects/Player.h"
#include "Objects/PressurePlate.h"
#include "Objects/Wall.h"
#include "RoomSwitcherObject.h"


class RoomCreator
{
public:
    static void setUpRoom(int roomNumber);
    static void update(float deltaTime);
    static void enterRoom(int roomNumber);
    static void resetRoom();
private:
    static void handleMovement();
    static void handlePressurePlates();
    static void handleRoomSwitchers();
    static inline std::vector<std::shared_ptr<Player>> players_;
    static inline std::vector<std::shared_ptr<PressurePlate>> pressurePlates_;
    static inline std::vector<std::shared_ptr<Wall>> walls_;
    static inline std::vector<std::shared_ptr<RoomSwitcherObject>> roomSwitchers_;
    static inline float entranceX_ = 50;
    static inline float entranceY_ = 50;
    static inline int playerIndex_ = 0;
    static inline int roomNumber_ = 0;
    static inline bool enterPressed_ = false;
};



#endif //ROOMCREATOR_H
