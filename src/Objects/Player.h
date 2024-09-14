//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <memory>

#include "EngineBase/DrawAble.h"
#include "EngineBase/SpeedAble.h"
#include "SavedPosition.h"


class Player : public DrawAble
{
public:
    Player(float x, float y);
    void update(float deltaTime);
    void resetPos(float x, float y);
    SpeedAble speed_;
private:
    std::vector<std::shared_ptr<SavedPosition>> positions_;
    float timePassed_;
    int index_;
    bool ghost_;
};


#endif //PLAYER_H
