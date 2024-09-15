//
// Created by Elias Aggergaard Larsen on 14/09/2024.
//

#include "SlidingDoor.h"

#include <memory>

#include "../../CollisionController.h"
#include "../../TimeWarriorTexture.h"
#include "../../Util.h"

SlidingDoor::SlidingDoor(float x, float y) : DrawAble(x,y,0,50,50,Util::getTextureIndex(TimeWarriorTexture::SlidingDoor))
            ,IActivateAble(),speed_((SpeedAble(this))),collidable_(std::make_shared<Collidable>(this))
{
    CollisionController::addSolidCollidable(collidable_);
}

SlidingDoor::~SlidingDoor()
{
    CollisionController::removeSolidCollidable(collidable_);
}

void SlidingDoor::activate()
{
    if (y_ > 300)
    {
        speed_.ySpeed(0);
        y_ = 300;
    }
    else
    {
        speed_.ySpeed(50);
    }
}

void SlidingDoor::deactivate()
{
    if (y_ < 250)
    {
        speed_.ySpeed(0);
        y_ = 250;
    }
    else
    {
        speed_.ySpeed(-50);
    }
}
