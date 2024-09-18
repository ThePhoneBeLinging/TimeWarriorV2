//
// Created by Elias on 18/09/2024.
//

#ifndef TIMEWARRIORV2_LONGWALL_H
#define TIMEWARRIORV2_LONGWALL_H


#include <vector>
#include "Wall.h"

class LongWall
{
public:
    LongWall(float x, float y, int width, int height, int textureIndex, int diameterPerWall);
    ~LongWall();
private:
    std::vector<std::shared_ptr<Wall>> walls_;
};


#endif //TIMEWARRIORV2_LONGWALL_H
