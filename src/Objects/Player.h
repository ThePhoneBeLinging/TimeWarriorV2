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
    Player(float x, float y);
    void update(float deltaTime);
    void resetPos(float x, float y);
    SpeedAble speed_;
private:
    std::vector<float> xPositions_;
    std::vector<float> yPositions_;
    std::vector<float> timePassedForPos_;
    float timeSinceLastMovement_;
    int index_;
    bool ghost_;
};


#endif //PLAYER_H
