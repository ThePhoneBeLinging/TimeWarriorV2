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
    SlidingDoor(float x, float y, float targetX, float targetY, float activationXSpeed, float activationYSpeed, float nonActivationXSpeed, float nonActivationYSpeed);
    ~SlidingDoor() override;
    std::shared_ptr<SpeedAble> speed_;
    void activate() override;
    void deactivate() override;
private:
    std::shared_ptr<Collidable> collidable_;
    float originalX_;
    float originalY_;
    float targetX_;
    float targetY_;
    float activationXSpeed_;
    float activationYSpeed_;
    float nonActivationXSpeed_;
    float nonActivationYSpeed_;
};



#endif //SLIDINGDOOR_H
