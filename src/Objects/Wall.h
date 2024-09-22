//
// Created by Elias Aggergaard Larsen on 15/09/2024.
//

#ifndef WALL_H
#define WALL_H
#include <memory>

#include "EngineBase/Collidable.h"
#include "EngineBase/DrawAble.h"
#include "EngineBase/SpeedAble.h"


class Wall : public DrawAble
{
public:
    Wall(float x, float y, int width, int height, int textureIndex);
    ~Wall() override;
    std::shared_ptr<Collidable> collidable_;
    std::shared_ptr<SpeedAble> speed_;
};



#endif //WALL_H
