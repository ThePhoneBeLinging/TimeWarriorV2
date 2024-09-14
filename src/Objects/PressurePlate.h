//
// Created by Elias Aggergaard Larsen on 14/09/2024.
//

#ifndef PRESSUREPLATE_H
#define PRESSUREPLATE_H
#include <memory>

#include "ActivateAble/IActivateAble.h"
#include "EngineBase/Collidable.h"
#include "EngineBase/DrawAble.h"


class PressurePlate : DrawAble
{
public:
    PressurePlate(float x, float y);
    ~PressurePlate() override = default;
    void setActivateAble(std::shared_ptr<IActivateAble> activateAble);
    void trigger();
    void notTrigger();
    Collidable collidable_;
private:
    std::shared_ptr<IActivateAble> activateAble_;

};



#endif //PRESSUREPLATE_H
