//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//

#include "Player.h"

Player::Player(float x, float y) : DrawAble(x,y,0,0,0,0), speed_(SpeedAble(this)), index_(0), timeSinceLastMovement_(0)
{
    this->height(50);
    this->width(50);
    ghost_ = false;
}

void Player::update(float deltaTime)
{
    if (!ghost_)
    {
        xMovement_.push_back(speed_.xSpeed());
        yMovement_.push_back(speed_.ySpeed());
    }

    else
    {
        if (xMovement_.size() > index_)
        {
            speed_.xSpeed(xMovement_[index_]);
            speed_.ySpeed(yMovement_[index_]);
        }
        index_++;
    }
}

void Player::resetPos(float x, float y)
{
    this->x(x);
    this->y(y);
    index_ = 0;
    ghost_ = true;
}
