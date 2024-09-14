//
// Created by Elias Aggergaard Larsen on 14/09/2024.
//

#include "PressurePlate.h"

#include <iostream>

PressurePlate::PressurePlate(float x, float y) : DrawAble(x,y,0,0,0,2), collidable_(Collidable(this))
{
    this->height(50);
    this->width(50);
}

void PressurePlate::trigger()
{
    // TODO Implement trigger
    std::cout << "Triggered Pressure Plate" << std::endl;
}
