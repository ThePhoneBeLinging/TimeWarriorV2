//
// Created by Elias Aggergaard Larsen on 15/09/2024.
//

#include "CollisionController.h"

void CollisionController::addSolidCollidable(const std::shared_ptr<Collidable>& collidable)
{
    solidCollidables_.push_back(collidable);
}

void CollisionController::removeSolidCollidable(const std::shared_ptr<Collidable>& collidable)
{
    solidCollidables_.erase(std::ranges::remove(solidCollidables_, collidable).begin(), solidCollidables_.end());

}

bool CollisionController::isCollidingWithSolid(Collidable* collidable)
{
    for (const auto& solidCollidable : solidCollidables_)
    {
        if (collidable->isColliding(solidCollidable.get()))
        {
            return true;
        }
    }
    return false;
}
