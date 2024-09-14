//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//

#include "Player.h"

Player::Player(float x, float y) : DrawAble(x,y,0,0,0,0), speed_(SpeedAble(this)), index_(0), timePassed_(0)
{
    this->height(50);
    this->width(50);
    ghost_ = false;
}

void Player::update(float deltaTime)
{
    timePassed_ += deltaTime;
    if (!ghost_)
    {
        // Save the position of the player
        positions_.emplace_back(std::make_shared<SavedPosition>(x(), y(), timePassed_));
    }
    else
    {
        // Load the position of the player
        while (positions_.size() > index_ && positions_[index_]->timePassedAtPoint_ < timePassed_)
        {
            x(positions_[index_]->x_);
            y(positions_[index_]->y_);
            index_++;
        }
    }
}

void Player::resetPos(float x, float y)
{
    this->x(x);
    this->y(y);
    index_ = 0;
    ghost_ = true;
    timePassed_ = 0;
    speed_.xSpeed(0);
    speed_.ySpeed(0);
}
