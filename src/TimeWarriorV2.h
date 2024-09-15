//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//

#ifndef TIMEWARRIORV2_H
#define TIMEWARRIORV2_H
#include <vector>
#include <memory>

#include "Objects/Player.h"
#include "Objects/PressurePlate.h"


class TimeWarriorV2
{
public:
    static void update(float deltaTime);
    static void setUp();
private:
    static void handleKeyBoard(float deltaTime);
    static inline bool enterPressed_ = false;

};


#endif //TIMEWARRIORV2_H
