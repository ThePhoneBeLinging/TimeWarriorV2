//
// Created by Elias Aggergaard Larsen on 15/09/2024.
//

#ifndef UTIL_H
#define UTIL_H
#include "TimeWarriorTexture.h"


class Util
{
public:
    static int getTextureIndex(TimeWarriorTexture texture)
    {
        return static_cast<int>(texture);
    }
};



#endif //UTIL_H
