//
// Created by Elias Aggergaard Larsen on 15/09/2024.
//

#include "TextureLoader.h"
#include <vector>
#include <string>

#include "EngineBase/EngineBase.h"

void TextureLoader::initTimeWarriorTextures()
{
    initPlayerRelatedTextures();
    initPressurePlateTextures();

    // SlidingDoor
    EngineBase::loadTexture("Resources/Images/SlidingDoor.png");

    EngineBase::loadTexture("Resources/Images/Wall.png");
}

void TextureLoader::initPlayerRelatedTextures()
{
    std::vector<std::string> prefixes = {"Player", "Ghost1", "Ghost2", "Ghost3", "Ghost4"};
    std::vector<std::string> suffixes = {"Down", "Up", "Left", "Right"};
    for (const auto& prefix : prefixes)
    {
        for (const auto& suffix : suffixes)
        {
            std::string path = "Resources/Images/Ghosts" + prefix + suffix + ".png";
            EngineBase::loadTexture(path);
        }
    }
}

void TextureLoader::initPressurePlateTextures()
{
    // PressurePlate Up
    EngineBase::loadTexture("Resources/Images/PressurePlateUp.png");
    // PressurePlate Down
    EngineBase::loadTexture("Resources/Images/WKnight.png");
}
