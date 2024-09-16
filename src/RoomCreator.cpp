//
// Created by Elias Aggergaard Larsen on 15/09/2024.
//

#include "RoomCreator.h"

#include "TimeWarriorTexture.h"
#include "Util.h"
#include "EngineBase/EngineBase.h"
#include "EngineBase/KeyBoardKeys.h"
#include "Objects/Wall.h"
#include "Objects/ActivateAble/SlidingDoor.h"

void RoomCreator::setUpRoom(int roomNumber)
{
    roomNumber_ = roomNumber;
    pressurePlates_.clear();
    pressurePlates_.emplace_back(std::make_shared<PressurePlate>(100,100));
    pressurePlates_[0]->setActivateAble(std::make_shared<SlidingDoor>(250,250,250,300,0,50,0,-50));
    walls_.emplace_back(std::make_shared<Wall>(0,0,1200,25,Util::getTextureIndex(TimeWarriorTexture::BrickWall)));
    walls_.emplace_back(std::make_shared<Wall>(0,0,25,800,Util::getTextureIndex(TimeWarriorTexture::BrickWall)));
    walls_.emplace_back(std::make_shared<Wall>(1175,0,25,800,Util::getTextureIndex(TimeWarriorTexture::BrickWall)));
    walls_.emplace_back(std::make_shared<Wall>(0,775,1200,25,Util::getTextureIndex(TimeWarriorTexture::BrickWall)));
}

void RoomCreator::update(float deltaTime)
{
    handleMovement();
    handlePressurePlates();
    for (const auto& player : players_)
    {
        if (player != nullptr)
        {
            player->update(deltaTime);
        }
    }
}

void RoomCreator::enterRoom(int roomNumber)
{
    setUpRoom(roomNumber);
    players_.clear();
    players_.resize(5);

    players_[0] = std::make_shared<Player>(entranceX_,entranceY_);
}

void RoomCreator::resetRoom()
{
    setUpRoom(roomNumber_);
    for (auto& player : players_)
    {
        if (player == nullptr) continue;
        player->resetPos(entranceX_,entranceY_);
    }
    if (playerIndex_ == 4)
    {
        playerIndex_ = -1;
    }
    players_[++playerIndex_] = std::make_shared<Player>(entranceX_,entranceY_);
}

void RoomCreator::handleMovement()
{

    // Player movement
    players_[playerIndex_]->speed_.xSpeed(0);
    players_[playerIndex_]->speed_.ySpeed(0);
    if (EngineBase::keyPressed(ENGINEBASE_KEY_W))
    {
        players_[playerIndex_]->speed_.ySpeed(-100);
    }
    if (EngineBase::keyPressed(ENGINEBASE_KEY_S))
    {
        players_[playerIndex_]->speed_.ySpeed(100);
    }
    if (EngineBase::keyPressed(ENGINEBASE_KEY_A))
    {
        players_[playerIndex_]->speed_.xSpeed(-100);
    }
    if (EngineBase::keyPressed(ENGINEBASE_KEY_D))
    {
        players_[playerIndex_]->speed_.xSpeed(100);
    }
}

void RoomCreator::handlePressurePlates()
{
    for (const auto& pressurePlate : pressurePlates_)
    {
        bool activated = false;
        for (const auto& player : players_)
        {
            if (player == nullptr) continue;
            if (player->collidable_.isColliding(&pressurePlate->collidable_))
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
