//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//


#include <iostream>

#include "TimeWarriorV2.h"
#include "EngineBase/EngineBase.h"

int main()
{
    TimeWarriorV2::setUp();
    EngineBase::startGUI(TimeWarriorV2::update);
    return 0;
}
