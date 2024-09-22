//
// Created by Elias Aggergaard Larsen on 14/09/2024.
//

#include "SlidingDoor.h"

#include <memory>
#include <vector>

#include "CollisionController.h"
#include "TimeWarriorTexture.h"
#include "TimeWarriorZValues.h"
#include "EngineBase/EngineBase.h"

SlidingDoor::SlidingDoor(float x, float y, float targetX, float targetY, float activationXSpeed, float activationYSpeed,
                         float nonActivationXSpeed, float nonActivationYSpeed) : DrawAble(x, y, (int)TimeWarriorZValues::SLIDINGDOOR, 50, 50,
                                                                                          (int)TimeWarriorTexture::SlidingDoor), speed_(std::make_shared<SpeedAble>(this)),
                                                                                 collidable_(std::make_shared<Collidable>(this)), originalX_(x), originalY_(y),
                                                                                 targetX_(targetX), targetY_(targetY), activationXSpeed_(activationXSpeed), activationYSpeed_(activationYSpeed), nonActivationXSpeed_(nonActivationXSpeed),
                                                                                 nonActivationYSpeed_(nonActivationYSpeed)
{
    CollisionController::addSolidCollidable(collidable_);
    EngineBase::addSpeedAble(std::weak_ptr(speed_));
}

SlidingDoor::~SlidingDoor()
{
    CollisionController::removeSolidCollidable(collidable_);
}

void SlidingDoor::activate()
{
    speed_->xSpeed(activationXSpeed_);
    speed_->ySpeed(activationYSpeed_);
    speed_->x_target(targetX_);
    speed_->y_target(targetY_);
}

void SlidingDoor::deactivate()
{
    speed_->xSpeed(nonActivationXSpeed_);
    speed_->ySpeed(nonActivationYSpeed_);
    speed_->x_target(originalX_);
    speed_->y_target(originalY_);
}
