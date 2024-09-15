//
// Created by Elias Aggergaard Larsen on 14/09/2024.
//

#ifndef SLIDINGDOOR_H
#define SLIDINGDOOR_H
#include <memory>

#include "IActivateAble.h"
#include "EngineBase/Collidable.h"
#include "EngineBase/DrawAble.h"
#include "EngineBase/SpeedAble.h"


class SlidingDoor : public DrawAble, public IActivateAble
{
public:
    SlidingDoor(float x, float y);
    ~SlidingDoor() override;
    SpeedAble speed_;
    void activate() override;
    void deactivate() override;
private:
    std::shared_ptr<Collidable> collidable_;
};



#endif //SLIDINGDOOR_H
