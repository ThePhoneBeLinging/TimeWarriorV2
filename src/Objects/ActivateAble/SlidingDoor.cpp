//
// Created by Elias Aggergaard Larsen on 14/09/2024.
//

#include "SlidingDoor.h"

#include <memory>
#include <vector>

#include "../../CollisionController.h"
#include "../../TimeWarriorTexture.h"
#include "../../Util.h"

SlidingDoor::SlidingDoor(float x, float y, float targetX, float targetY, float activationXSpeed, float activationYSpeed,
    float nonActivationXSpeed, float nonActivationYSpeed) : DrawAble(x, y, 50, 50, 50,
        Util::getTextureIndex(TimeWarriorTexture::SlidingDoor)), speed_(SpeedAble(this)),
    collidable_(std::make_shared<Collidable>(this)), originalX_(x), originalY_(y),
    targetX_(targetX), targetY_(targetY), activationXSpeed_(activationXSpeed), activationYSpeed_(activationYSpeed), nonActivationXSpeed_(nonActivationXSpeed),
    nonActivationYSpeed_(nonActivationYSpeed)
{
    CollisionController::addSolidCollidable(collidable_);
}

SlidingDoor::~SlidingDoor()
{
    CollisionController::removeSolidCollidable(collidable_);
}

void SlidingDoor::activate()
{
    speed_.xSpeed(activationXSpeed_);
    if (activationXSpeed_ > 0)
    {
        if (targetX_ < x_)
        {
            x_ = targetX_;
            speed_.xSpeed(0);
        }
    }
    else if (activationXSpeed_ < 0)
    {
        if (targetX_ > x_)
        {
            x_ = targetX_;
            speed_.xSpeed(0);
        }
    }

    speed_.ySpeed(activationYSpeed_);
    if (activationYSpeed_ > 0)
    {
        if (targetY_ < y_)
        {
            y_ = targetY_;
            speed_.ySpeed(0);
        }
    }
    else if (activationYSpeed_ < 0)
    {
        if (targetY_ > y_)
        {
            y_ = targetY_;
            speed_.ySpeed(0);
        }
    }
}

void SlidingDoor::deactivate()
{
    speed_.xSpeed(nonActivationXSpeed_);
    if (nonActivationXSpeed_ > 0)
    {
        if (originalX_< x_)
        {
            x_ = originalX_;
            speed_.xSpeed(0);
        }
    }
    else if (nonActivationXSpeed_ < 0)
    {
        if (originalX_ > x_)
        {
            x_ = originalX_;
            speed_.xSpeed(0);
        }
    }

    speed_.ySpeed(nonActivationYSpeed_);
    if (nonActivationYSpeed_ > 0)
    {
        if (originalY_ < y_)
        {
            y_ = originalY_;
            speed_.ySpeed(0);
        }
    }
    else if (nonActivationYSpeed_ < 0)
    {
        if (originalY_ > y_)
        {
            y_ = originalY_;
            speed_.ySpeed(0);
        }
    }
}
