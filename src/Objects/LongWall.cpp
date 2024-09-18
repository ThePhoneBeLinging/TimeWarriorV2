//
// Created by Elias on 18/09/2024.
//

#include "LongWall.h"

LongWall::LongWall(float x, float y, int width, int height, int textureIndex, int diameterPerWall)
{
    for (int i = 0; i < width; i += diameterPerWall)
    {
        //walls_.emplace_back(std::make_shared<Wall>(x + i, y, diameterPerWall, diameterPerWall, textureIndex));
        for (int j = 0; j < height; j += diameterPerWall)
        {
            walls_.emplace_back(std::make_shared<Wall>(x + i, y + j, diameterPerWall, diameterPerWall, textureIndex));
        }
    }
}

LongWall::~LongWall()
{
    walls_.clear();
}
