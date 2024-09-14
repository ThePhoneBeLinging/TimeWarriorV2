//
// Created by Elias on 14/09/2024.
//

#ifndef TIMEWARRIORV2_SAVEDPOSITION_H
#define TIMEWARRIORV2_SAVEDPOSITION_H


class SavedPosition
{
public:
    SavedPosition(float x, float y, float timePassedAtPoint);
    ~SavedPosition() = default;
    float x_;
    float y_;
    float timePassedAtPoint_;
};


#endif //TIMEWARRIORV2_SAVEDPOSITION_H
