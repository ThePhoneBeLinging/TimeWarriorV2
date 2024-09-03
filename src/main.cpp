//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//


#include <iostream>

#include "TimeWarriorV2.h"
#include "EngineBase/EngineBase.h"
#include "Objects/Player.h"

int main()
{
    std::cout << "hello world" << std::endl;
    auto player = Player();
    EngineBase::startGUI(TimeWarriorV2::update);
    return 0;
}
