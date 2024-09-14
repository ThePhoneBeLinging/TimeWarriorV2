//
// Created by Elias Aggergaard Larsen on 14/09/2024.
//

#include "PressurePlate.h"


PressurePlate::PressurePlate(float x, float y) : DrawAble(x,y,0,0,0,2), collidable_(Collidable(this))
{
    this->height(50);
    this->width(50);
}

void PressurePlate::setActivateAble(std::shared_ptr<IActivateAble> activateAble)
{
    activateAble_ = std::move(activateAble);
}

void PressurePlate::trigger()
{
    // TODO Implement trigger
    activateAble_->activate();
}

void PressurePlate::notTrigger()
{
    activateAble_->deactivate();
}
