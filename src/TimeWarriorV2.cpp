//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//

#include "TimeWarriorV2.h"

#include "EngineBase/EngineBase.h"
#include "Objects/ActivateAble/SlidingDoor.h"

void TimeWarriorV2::update(float deltaTime)
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

void TimeWarriorV2::setUp()
{
    // Amount of clones + player
    players_.resize(5);
    // Player up
    EngineBase::loadTexture("Resources/Images/Player.png");
    // Player Up
    EngineBase::loadTexture("Resources/Images/WBishop.png");
    // Player Left
    EngineBase::loadTexture("Resources/Images/WQueen.png");
    // Player Right
    EngineBase::loadTexture("Resources/Images/WKing.png");
    // Ghost1 Down
    EngineBase::loadTexture("Resources/Images/Ghost1.png");
    // Ghost1 Up
    EngineBase::loadTexture("Resources/Images/Ghost1Up.png");
    // Ghost1 Left
    EngineBase::loadTexture("Resources/Images/Ghost1Left.png");
    // Ghost1 Right
    EngineBase::loadTexture("Resources/Images/Ghost1Right.png");
    // Ghost2 Down
    EngineBase::loadTexture("Resources/Images/Ghost2.png");
    // Ghost2 Up
    EngineBase::loadTexture("Resources/Images/Ghost2Up.png");
    // Ghost2 Left
    EngineBase::loadTexture("Resources/Images/Ghost2Left.png");
    // Ghost2 Right
    EngineBase::loadTexture("Resources/Images/Ghost2Right.png");
    // Ghost3 Down
    EngineBase::loadTexture("Resources/Images/Ghost3.png");
    // Ghost3 Up
    EngineBase::loadTexture("Resources/Images/Ghost3Up.png");
    // Ghost3 Left
    EngineBase::loadTexture("Resources/Images/Ghost3Left.png");
    // Ghost3 Right
    EngineBase::loadTexture("Resources/Images/Ghost3Right.png");
    // Ghost4 Down
    EngineBase::loadTexture("Resources/Images/Ghost4.png");
    // Ghost4 Up
    EngineBase::loadTexture("Resources/Images/Ghost4Up.png");
    // Ghost4 Left
    EngineBase::loadTexture("Resources/Images/Ghost4Left.png");
    // Ghost4 Right
    EngineBase::loadTexture("Resources/Images/Ghost4Right.png");
    // PressurePlate Up
    EngineBase::loadTexture("Resources/Images/PressurePlateUp.png");
    // PressurePlate Down
    EngineBase::loadTexture("Resources/Images/WKnight.png");
    // SlidingDoor
    EngineBase::loadTexture("Resources/Images/SlidingDoor.png");


    players_[0] = std::make_shared<Player>(entranceX_,entranceY_);
    pressurePlates_.emplace_back(std::make_shared<PressurePlate>(100,100));
    pressurePlates_[0]->setActivateAble(std::make_shared<SlidingDoor>(250,250));
}

void TimeWarriorV2::reset()
{
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

void TimeWarriorV2::handleMovement()
{
    if (EngineBase::keyPressed(ENGINEBASE_KEY_ENTER) && !enterPressed_)
    {
        reset();
        enterPressed_ = true;
        return;
    }
    if (EngineBase::keyReleased(ENGINEBASE_KEY_ENTER))
    {
        enterPressed_ = false;
    }

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

void TimeWarriorV2::handlePressurePlates()
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
