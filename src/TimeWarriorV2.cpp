//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//

#include "TimeWarriorV2.h"

#include "RoomCreator.h"
#include "EngineBase/EngineBase.h"
#include "Objects/ActivateAble/SlidingDoor.h"
#include "Texture/TextureLoader.h"

void TimeWarriorV2::update(float deltaTime)
{
    RoomCreator::update(deltaTime);
    handleKeyBoard(deltaTime);
}

void TimeWarriorV2::setUp()
{
    TextureLoader::initTimeWarriorTextures();
    RoomCreator::enterRoom(0);
}

void TimeWarriorV2::handleKeyBoard(float deltaTime)
{
    if (EngineBase::keyPressed(ENGINEBASE_KEY_ENTER) && !enterPressed_)
    {
        RoomCreator::resetRoom();
        enterPressed_ = true;
        return;
    }
    if (EngineBase::keyReleased(ENGINEBASE_KEY_ENTER))
    {
        enterPressed_ = false;
    }
}


