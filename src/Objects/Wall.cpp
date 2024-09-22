//
// Created by Elias Aggergaard Larsen on 15/09/2024.
//

#include "Wall.h"

#include "CollisionController.h"
#include "TimeWarriorZValues.h"
#include "EngineBase/EngineBase.h"

Wall::Wall(float x, float y, int width, int height, int textureIndex)
: DrawAble(x,y,(int) TimeWarriorZValues::WALL,width,height,textureIndex), collidable_(std::make_shared<Collidable>(this)), speed_(std::make_shared<SpeedAble>(this))
{
    CollisionController::addSolidCollidable(collidable_);
    EngineBase::addSpeedAble(std::weak_ptr(speed_));
}

Wall::~Wall()
{
    CollisionController::removeSolidCollidable(collidable_);
}
