//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//

#include "TimeWarriorV2.h"

#include "EngineBase/EngineBase.h"

void TimeWarriorV2::update(float deltaTime)
{
    handleMovement();
}

void TimeWarriorV2::setUp()
{
    EngineBase::loadTexture("Resources/Images/WKing.png");
    EngineBase::loadTexture("Resources/Images/WBishop.png");
    players_.emplace_back(std::make_shared<Player>(entranceX,entranceY));
    players_[0]->x(0);
    players_[0]->y(0);
}

void TimeWarriorV2::reset()
{
    for (auto& player : players_)
    {
        player->resetPos(entranceX,entranceY);
    }
}

void TimeWarriorV2::handleMovement()
{
    if (EngineBase::keyPressed(ENGINEBASE_KEY_ENTER))
    {
        reset();
        return;
    }

    // Player movement
    players_[0]->speed_.xSpeed(0);
    players_[0]->speed_.ySpeed(0);
    if (EngineBase::keyPressed(ENGINEBASE_KEY_W))
    {
        players_[0]->speed_.ySpeed(-100);
    }
    if (EngineBase::keyPressed(ENGINEBASE_KEY_S))
    {
        players_[0]->speed_.ySpeed(100);
    }
    if (EngineBase::keyPressed(ENGINEBASE_KEY_A))
    {
        players_[0]->speed_.xSpeed(-100);
    }
    if (EngineBase::keyPressed(ENGINEBASE_KEY_D))
    {
        players_[0]->speed_.xSpeed(100);
    }

}
