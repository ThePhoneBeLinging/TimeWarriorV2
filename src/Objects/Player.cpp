//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//

#include "Player.h"

Player::Player() : DrawAble(), speed_(SpeedAble(this)), ghost_(false), index(0)
{
    this->height(50);
    this->width(50);
}

void Player::update()
{
    if (!ghost_)
    {
        xMovement_.push_back(speed_.xSpeed());
        yMovement_.push_back(speed_.ySpeed());
    }
    else
    {
        if (index == xMovement_.size())
        {
            return;
        }
        speed_.xSpeed(xMovement_[index]);
        speed_.ySpeed(yMovement_[index]);
        index++;
    }
}

void Player::reset()
{
    ghost_ = true;
}
