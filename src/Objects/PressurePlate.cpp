//
// Created by Elias Aggergaard Larsen on 14/09/2024.
//

#include "PressurePlate.h"

#include "TimeWarriorZValues.h"
#include "TimeWarriorTexture.h"
#include "EngineBase/EngineBase.h"

PressurePlate::PressurePlate(float x, float y) : DrawAble(x,y,(int)TimeWarriorZValues::PRESSUREPLATE,50,50,(int)TimeWarriorTexture::PressurePlateUp), collidable_(Collidable(this)), speed_(std::make_shared<SpeedAble>(this))
{
    EngineBase::addSpeedAble(std::weak_ptr(speed_));
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
