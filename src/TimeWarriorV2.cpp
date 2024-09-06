//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//

#include "TimeWarriorV2.h"

void TimeWarriorV2::update(float deltaTime)
{
}

void TimeWarriorV2::setUp()
{
    players_.emplace_back();
}

void TimeWarriorV2::reset()
{
    for (auto& player : players_)
    {
        player.reset();
    }
}
