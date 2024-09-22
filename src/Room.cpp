

#include "Room.h"

#include "EngineBase/EngineBase.h"
#include "EngineBase/KeyBoardKeys.h"
Room::Room(float entranceX, float entranceY)
{
    entranceX_ = entranceX;
    entranceY_ = entranceY;
}


void Room::handleLocalThings(const std::vector<std::shared_ptr<Player>>& players)
{
    handlePressurePlates(players);
}


void Room::handlePressurePlates(const std::vector<std::shared_ptr<Player>>& players)
{
    for (const auto& pressurePlate : pressurePlates_)
    {
        bool activated = false;
        for (const auto& player : players)
        {
            if (player == nullptr) continue;
            if (player->collidable_->isColliding(&pressurePlate->collidable_))
            {
                pressurePlate->trigger();
                activated = true;
                break;
            }
        }
        if (!activated)
        {
            pressurePlate->notTrigger();
        }
    }
}

int Room::handleRoomSwitchers(const std::vector<std::shared_ptr<Player>>& players)
{
    for (const auto& roomSwitcher : roomSwitchers_)
    {
        for (const auto& player : players)
        {
            if (player == nullptr) continue;
            if (player->collidable_->isColliding(roomSwitcher->getCollidable().get()))
            {
                return roomSwitcher->getTargetRoom();
            }
        }
    }
    return -1;
}

