//
// Created by Elias Aggergaard Larsen on 15/09/2024.
//

#include "RoomCreator.h"

#include "TimeWarriorTexture.h"
#include "EngineBase/EngineBase.h"
#include "EngineBase/KeyBoardKeys.h"
#include "Objects/longWall.h"
#include "Objects/ActivateAble/SlidingDoor.h"

void RoomCreator::setUpRooms(int amountOfRooms)
{
    rooms_.resize(amountOfRooms);
    for (int i = 0; i < amountOfRooms; i++)
    {
        rooms_[i] = std::make_shared<Room>(0,0);
        setUpRoom(rooms_[i],i);
    }
}

void RoomCreator::update(float deltaTime)
{
    handleMovement();
    currentRoom_->handleLocalThings(players_);
    int newRoom = currentRoom_->handleRoomSwitchers(players_);
    if (newRoom != -1)
    {
        enterRoom(newRoom);
        return;
    }
    for (const auto& player : players_)
    {
        if (player != nullptr)
        {
            player->update(deltaTime);
        }
    }
}

void RoomCreator::setUpRoom(std::shared_ptr<Room> room ,int roomNumber)
{
    int roomWidth = 1200;
    int roomHeight = 800;
    int wallWidth = 50;

    room->entranceX_ = 150;
    room->entranceY_ = 150;
    room->pressurePlates_.clear();
    room->longWalls_.clear();
    room->roomSwitchers_.clear();
    room->roomNumber_ = roomNumber;
    switch (roomNumber)
    {
        case 0:
        {
            room->pressurePlates_.emplace_back(std::make_shared<PressurePlate>(100,100));
            auto door1 = std::make_shared<SlidingDoor>(250,250,250,300,0,50,0,-50);
            room->pressurePlates_[0]->setActivateAble(door1);
            EngineBase::addDrawAble(std::weak_ptr(door1));

            // longWalls around the room

            room->longWalls_.emplace_back(std::make_shared<LongWall>(0, 0, roomWidth, wallWidth, (int)TimeWarriorTexture::BrickWall, wallWidth));
            room->longWalls_.emplace_back(std::make_shared<LongWall>(0, 0, wallWidth, roomHeight, (int)TimeWarriorTexture::BrickWall, wallWidth));
            room->longWalls_.emplace_back(std::make_shared<LongWall>(roomWidth - wallWidth, 0, wallWidth, roomHeight, (int)TimeWarriorTexture::BrickWall, wallWidth));
            room->longWalls_.emplace_back(std::make_shared<LongWall>(0, roomHeight - wallWidth, roomWidth, wallWidth, (int)TimeWarriorTexture::BrickWall, wallWidth));
            // Top middle
            room->longWalls_.emplace_back(std::make_shared<LongWall>(250, 0, wallWidth, 250, (int)TimeWarriorTexture::BrickWall, wallWidth));
            room->longWalls_.emplace_back(std::make_shared<LongWall>(250, 300, wallWidth, roomHeight - 300, (int)TimeWarriorTexture::BrickWall, wallWidth));

            room->roomSwitchers_.push_back(std::make_shared<RoomSwitcherObject>(500,300,50,50,1));
            break;
        }
        case 1:
        {
            room->longWalls_.emplace_back(std::make_shared<LongWall>(roomWidth + 0, roomHeight - wallWidth, roomWidth, wallWidth, (int)TimeWarriorTexture::BrickWall, wallWidth));
            room->longWalls_.emplace_back(std::make_shared<LongWall>(roomWidth + roomWidth - wallWidth, 0, wallWidth, roomHeight, (int)TimeWarriorTexture::BrickWall, wallWidth));
            room->longWalls_.emplace_back(std::make_shared<LongWall>(roomWidth, 500, roomWidth, wallWidth, (int)TimeWarriorTexture::BrickWall, wallWidth));
            break;
        }

        default:
            throw std::invalid_argument("Room number not found");
    }
    for (const auto& pressurePlate : room->pressurePlates_)
    {
        EngineBase::addDrawAble(std::weak_ptr(pressurePlate));
    }
}


void RoomCreator::enterRoom(int roomNumber)
{
    currentRoom_ = rooms_[roomNumber];

    players_.clear();
    players_.resize(5);
    playerIndex_ = 0;
    players_[playerIndex_] = std::make_shared<Player>(currentRoom_->entranceX_,currentRoom_->entranceY_);
    EngineBase::addDrawAble(std::weak_ptr(players_[playerIndex_]));
}

void RoomCreator::resetRoom()
{
    setUpRoom(currentRoom_,currentRoom_->roomNumber_);
    for (auto& player : players_)
    {
        if (player == nullptr) continue;
        player->resetPos(currentRoom_->entranceX_,currentRoom_->entranceY_);
    }
    if (playerIndex_ == 4)
    {
        playerIndex_ = -1;
    }
    players_[++playerIndex_] = std::make_shared<Player>(currentRoom_->entranceX_,currentRoom_->entranceY_);
    EngineBase::addDrawAble(std::weak_ptr(players_[playerIndex_]));
}

void RoomCreator::handleMovement()
{

    // Player movement
    players_[playerIndex_]->speed_->xSpeed(0);
    players_[playerIndex_]->speed_->ySpeed(0);
    if (EngineBase::keyPressed(ENGINEBASE_KEY_W))
    {
        players_[playerIndex_]->speed_->ySpeed(-100);
    }
    if (EngineBase::keyPressed(ENGINEBASE_KEY_S))
    {
        players_[playerIndex_]->speed_->ySpeed(100);
    }
    if (EngineBase::keyPressed(ENGINEBASE_KEY_A))
    {
        players_[playerIndex_]->speed_->xSpeed(-100);
    }
    if (EngineBase::keyPressed(ENGINEBASE_KEY_D))
    {
        players_[playerIndex_]->speed_->xSpeed(100);
    }
}


