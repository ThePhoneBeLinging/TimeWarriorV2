//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//

#include "Player.h"

Player::Player() : DrawAble(0,0,0,0,0,0), speed_(SpeedAble(this)), index(0)
{
    this->height(50);
    this->width(50);
}

void Player::update(float deltaTime)
{

}

void Player::reset(float x, float y)
{
}
