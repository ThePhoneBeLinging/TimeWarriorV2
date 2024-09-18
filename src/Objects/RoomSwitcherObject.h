//
// Created by Elias on 17/09/2024.
//

#ifndef TIMEWARRIORV2_ROOMSWITCHEROBJECT_H
#define TIMEWARRIORV2_ROOMSWITCHEROBJECT_H

#include <memory>
#include "EngineBase/DrawAble.h"
#include "EngineBase/Collidable.h"

class RoomSwitcherObject : public DrawAble
{
public:
    RoomSwitcherObject(float x, float y, int width, int height, int targetRoom);
    std::shared_ptr<Collidable> getCollidable();
    [[nodiscard]] int getTargetRoom() const;
private:
    std::shared_ptr<Collidable> collidable_;
    int targetRoom_;
};


#endif //TIMEWARRIORV2_ROOMSWITCHEROBJECT_H
