//
// Created by Elias Aggergaard Larsen on 15/09/2024.
//

#include "Wall.h"

#include "CollisionController.h"
#include "TimeWarriorZValues.h"

Wall::Wall(float x, float y, int width, int height, int textureIndex)
: DrawAble(x,y,(int) TimeWarriorZValues::WALL,width,height,textureIndex), collidable_(std::make_shared<Collidable>(this))
{
    CollisionController::addSolidCollidable(collidable_);
}

Wall::~Wall()
{
    CollisionController::removeSolidCollidable(collidable_);
}
