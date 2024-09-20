//
// Created by Elias on 18/09/2024.
//

#include "LongWall.h"

#include <list>

#include "EngineBase/EngineBase.h"

LongWall::LongWall(float x, float y, int width, int height, int textureIndex, int diameterPerWall)
{
    std::list<std::weak_ptr<DrawAble>> wallsToAdd;
    for (int i = 0; i < width; i += diameterPerWall)
    {
        //walls_.emplace_back(std::make_shared<Wall>(x + i, y, diameterPerWall, diameterPerWall, textureIndex));
        for (int j = 0; j < height; j += diameterPerWall)
        {
            auto wall = std::make_shared<Wall>(x + i, y + j, diameterPerWall, diameterPerWall, textureIndex);
            walls_.emplace_back(wall);
            wallsToAdd.push_back(std::weak_ptr(wall));
        }
    }
    EngineBase::addDrawAbles(wallsToAdd);
}

LongWall::~LongWall()
{
    walls_.clear();
}
