//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//

#include "Player.h"

#include "CollisionController.h"
#include "TimeWarriorZValues.h"
#include "TimeWarriorTexture.h"

Player::Player(float x, float y) : DrawAble(x,y,(int)TimeWarriorZValues::PLAYER,32,32,(int)TimeWarriorTexture::PlayerRight), speed_(SpeedAble(this)),collidable_(Collidable(this)), index_(0), timePassed_(0)
{
    ghost_ = false;
    textureIndexDelta_ = 0;
}

void Player::x(float x)
{
    float oldX = x_;
    DrawAble::x(x);
    if (CollisionController::isCollidingWithSolid(&collidable_))
    {
        x_ = oldX;
    }
}

void Player::y(float y)
{
    float oldY = y_;
    DrawAble::y(y);
    if (CollisionController::isCollidingWithSolid(&collidable_))
    {
        y_ = oldY;
    }
}

void Player::update(float deltaTime)
{
    timePassed_ += deltaTime;
    if (!ghost_)
    {
        // Save the position of the player
        positions_.emplace_back(std::make_shared<SavedPosition>(x_, y_, timePassed_));
    }
    else
    {
        // Load the position of the player
        float oldX = x_;
        float oldY = y_;
        while (positions_.size() > index_ && positions_[index_]->timePassedAtPoint_ < timePassed_)
        {
            x(positions_[index_]->x_);
            y(positions_[index_]->y_);
            if (x_ == oldX && y_ == oldY && (x_ != positions_[index_]->x_ || y_ != positions_[index_]->y_))
            {
                timePassed_ -= deltaTime;
                break;
            }
            textureIndex(textureIndex_ - textureIndexDelta_);

            if (x_ < oldX) {
                textureIndexDelta_ = 2;
            } else if (x_ > oldX) {
                textureIndexDelta_ = 3;
            } else if (y_ < oldY) {
                textureIndexDelta_ = 1;
            } else if (y_ > oldY) {
                textureIndexDelta_ = 0;
            }
            textureIndex(textureIndex_ + textureIndexDelta_);

            index_++;
        }
    }
}

void Player::resetPos(float x, float y)
{
    this->x(x);
    this->y(y);
    index_ = 0;
    textureIndex(textureIndex_ + 4);
    ghost_ = true;
    timePassed_ = 0;
    speed_.xSpeed(0);
    speed_.ySpeed(0);
}

void Player::kill()
{

}
