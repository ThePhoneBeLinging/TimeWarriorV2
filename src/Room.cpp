

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

void Room::offsetRoom(float deltaX, float deltaY)
{
    std::list<std::shared_ptr<SpeedAble>> speedAblesToUpdate;
    for (const auto& longWall : longWalls_)
    {
        for (const auto& wall : longWall->walls_)
        {
            speedAblesToUpdate.push_back(wall->speed_);
        }
    }

    for (const auto& speedAble : speedAblesToUpdate)
    {
        speedAble->x_target(speedAble->drawAble_->x() + deltaX);
        speedAble->y_target(speedAble->drawAble_->y() + deltaY);
        if (deltaX > 0)
        {
            speedAble->xSpeed(250);
        }
        else
        {
            speedAble->xSpeed(-250);
        }
        if (deltaY > 0)
        {
            speedAble->ySpeed(250);
        }
        else
        {
            speedAble->ySpeed(-250);
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
