//
// Created by Elias Aggergaard Larsen on 14/09/2024.
//

#include "SlidingDoor.h"

#include <memory>

SlidingDoor::SlidingDoor(float x, float y) : DrawAble(x,y,0,50,50,2),IActivateAble(),speed_((SpeedAble(this)))
{
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
