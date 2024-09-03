//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <vector>

#include "EngineBase/DrawAble.h"
#include "EngineBase/SpeedAble.h"


class Player : public DrawAble
{
public:
    Player();
    void update();
    void reset();

private:
    bool ghost_;
    std::vector<float> xMovement_;
    std::vector<float> yMovement_;
    int index;
    SpeedAble speed_;
};


#endif //PLAYER_H
