//
// Created by Elias Aggergaard Larsen on 14/09/2024.
//

#ifndef IACTIVATEABLE_H
#define IACTIVATEABLE_H



class IActivateAble
{
public:
    virtual void activate() = 0;
    virtual void deactivate() = 0;
};

#endif //IACTIVATEABLE_H