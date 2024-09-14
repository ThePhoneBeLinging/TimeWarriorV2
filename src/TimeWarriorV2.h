//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//

#ifndef TIMEWARRIORV2_H
#define TIMEWARRIORV2_H
#include <vector>
#include <memory>

#include "Objects/Player.h"


class TimeWarriorV2
{
public:
    static void update(float deltaTime);
    static void setUp();
    static void reset();

private:
    static void handleMovement();
    static inline std::vector<std::shared_ptr<Player>> players_;
    static inline float entranceX_ = 0;
    static inline float entranceY_ = 0;
    static inline int playerIndex_ = 0;
    static inline bool enterPressed_ = false;
};


#endif //TIMEWARRIORV2_H
