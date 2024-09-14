//
// Created by Elias Aggergaard Larsen on 14/09/2024.
//

#ifndef PRESSUREPLATE_H
#define PRESSUREPLATE_H
#include "EngineBase/Collidable.h"
#include "EngineBase/DrawAble.h"


class PressurePlate : DrawAble
{
public:
    PressurePlate(float x, float y);
    ~PressurePlate() override = default;
    void trigger();
    Collidable collidable_;
private:


};



#endif //PRESSUREPLATE_H
