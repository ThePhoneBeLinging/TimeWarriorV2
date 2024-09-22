//
// Created by Elias on 17/09/2024.
//

#include "RoomSwitcherObject.h"
#include "TimeWarriorZValues.h"
#include "TimeWarriorTexture.h"
#include "EngineBase/EngineBase.h"

RoomSwitcherObject::RoomSwitcherObject(float x, float y, int width, int height, int targetRoom)
: DrawAble(x,y,(int) TimeWarriorZValues::HIDDEN,width,height,(int) TimeWarriorTexture::Invisible), collidable_(std::make_shared<Collidable>(this)),speed_(std::make_shared<SpeedAble>(this)), targetRoom_(targetRoom)
{
    EngineBase::addSpeedAble(speed_);
}

std::shared_ptr<Collidable> RoomSwitcherObject::getCollidable()
{
    return collidable_;
}

int RoomSwitcherObject::getTargetRoom() const
{
    return targetRoom_;
}

