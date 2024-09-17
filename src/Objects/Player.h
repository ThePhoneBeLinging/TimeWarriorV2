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
#include "EngineBase/Collidable.h"


class Player : public DrawAble
{
public:
    Player(float x, float y);
    ~Player() override = default;
    void x(float x) override;
    void y(float y) override;
    void update(float deltaTime);
    void resetPos(float x, float y);
    void kill();
    SpeedAble speed_;
    Collidable collidable_;
private:
    std::vector<std::shared_ptr<SavedPosition>> positions_;
    float timePassed_;
    int index_;
    bool ghost_;
    int ghostIndex_;
};


#endif //PLAYER_H
