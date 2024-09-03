//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//

#ifndef TIMEWARRIORV2_H
#define TIMEWARRIORV2_H
#include <vector>

#include "Objects/Player.h"


class TimeWarriorV2
{
public:
    static void update(float deltaTime);
    static void setUp();
    static void reset();

private:
    static inline std::vector<Player> players_;
};


#endif //TIMEWARRIORV2_H
