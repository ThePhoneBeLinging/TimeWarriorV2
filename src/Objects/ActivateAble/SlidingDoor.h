//
// Created by Elias Aggergaard Larsen on 14/09/2024.
//

#ifndef SLIDINGDOOR_H
#define SLIDINGDOOR_H
#include "IActivateAble.h"
#include "EngineBase/DrawAble.h"
#include "EngineBase/SpeedAble.h"


class SlidingDoor : public DrawAble, public IActivateAble
{
public:
    SlidingDoor(float x, float y);
    SpeedAble speed_;
    void activate() override;
    void deactivate() override;
private:
};



#endif //SLIDINGDOOR_H
