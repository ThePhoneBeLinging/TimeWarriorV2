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
    int roomWidth = 1200;
    int roomHeight = 800;
    int wallWidth = 50;

    entranceX_ = 150;
    entranceY_ = 150;
    pressurePlates_.clear();
    walls_.clear();
    roomNumber_ = roomNumber;
    switch (roomNumber_)
    {
        case 1:

            pressurePlates_.emplace_back(std::make_shared<PressurePlate>(100,100));
            pressurePlates_[0]->setActivateAble(std::make_shared<SlidingDoor>(250,250,250,300,0,50,0,-50));

            // Walls around the room
            walls_.emplace_back(std::make_shared<Wall>(0,0,roomWidth,wallWidth,Util::getTextureIndex(TimeWarriorTexture::BrickWall)));
            walls_.emplace_back(std::make_shared<Wall>(0,0,wallWidth,roomHeight,Util::getTextureIndex(TimeWarriorTexture::BrickWall)));
            walls_.emplace_back(std::make_shared<Wall>(roomWidth - wallWidth,0,wallWidth,roomHeight,Util::getTextureIndex(TimeWarriorTexture::BrickWall)));
            walls_.emplace_back(std::make_shared<Wall>(0,roomHeight - wallWidth,roomWidth,wallWidth,Util::getTextureIndex(TimeWarriorTexture::BrickWall)));

            // Middle walls
            walls_.emplace_back(std::make_shared<Wall>(250,0,wallWidth,(roomHeight - (roomHeight - 250)),Util::getTextureIndex(TimeWarriorTexture::BrickWall)));
            walls_.emplace_back(std::make_shared<Wall>(250,300,wallWidth,(roomHeight - (roomHeight - 500)),Util::getTextureIndex(TimeWarriorTexture::BrickWall)));
            break;
        default:
            throw std::invalid_argument("Room number not found");
    }

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
