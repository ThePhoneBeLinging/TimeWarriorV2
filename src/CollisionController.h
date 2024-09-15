//
// Created by Elias Aggergaard Larsen on 15/09/2024.
//

#ifndef COLLISIONCONTROLLER_H
#define COLLISIONCONTROLLER_H

#include <vector>
#include <memory>
#include "EngineBase/Collidable.h"


class CollisionController
{
public:
    static void addSolidCollidable(const std::shared_ptr<Collidable>& collidable);
    static void removeSolidCollidable(const std::shared_ptr<Collidable>& collidable);
    static bool isCollidingWithSolid(Collidable* collidable);
private:
    static inline std::vector<std::shared_ptr<Collidable>> solidCollidables_;
};



#endif //COLLISIONCONTROLLER_H
