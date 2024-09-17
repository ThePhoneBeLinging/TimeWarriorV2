//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//

#include "Player.h"

#include "CollisionController.h"
#include "Util.h"
#include "TimeWarriorZValues.h"

Player::Player(float x, float y) : DrawAble(x,y,(int)TimeWarriorZValues::PLAYER,40,40,Util::getTextureIndex(TimeWarriorTexture::PlayerRight)), speed_(SpeedAble(this)),collidable_(Collidable(this)), index_(0), timePassed_(0)
{
    ghost_ = false;
    ghostIndex_ = 0;
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
            index_++;
        }
    }
}

void Player::resetPos(float x, float y)
{
    this->x(x);
    this->y(y);
    index_ = 0;
    ghostIndex_++;

    switch (ghostIndex_)
    {
    case 1:
        textureIndex(Util::getTextureIndex(TimeWarriorTexture::Ghost1Right));
        z_ = (int)TimeWarriorZValues::GHOST1;
        break;
    case 2:
        textureIndex(Util::getTextureIndex(TimeWarriorTexture::Ghost2Right));
            z_ = (int)TimeWarriorZValues::GHOST2;
        break;
    case 3:
        textureIndex(Util::getTextureIndex(TimeWarriorTexture::Ghost3Right));
            z_ = (int)TimeWarriorZValues::GHOST3;
        break;
    case 4:
        textureIndex(Util::getTextureIndex(TimeWarriorTexture::Ghost4Right));
            z_ = (int)TimeWarriorZValues::GHOST4;
        break;
    default:
        break;
    }

    ghost_ = true;
    timePassed_ = 0;
    if (z_ != 14) z(14);
    speed_.xSpeed(0);
    speed_.ySpeed(0);
}

void Player::kill()
{

}
