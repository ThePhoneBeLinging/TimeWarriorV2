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
}

void TextureLoader::initPlayerRelatedTextures()
{
    std::vector<std::string> prefixes = {"Player", "Ghost1", "Ghost2", "Ghost3", "Ghost4"};
    std::vector<std::string> suffixes = {"Down", "Up", "Left", "Right"};
    for (const auto& prefix : prefixes)
    {
        for (const auto& suffix : suffixes)
        {
            std::string path = "Resources/Images/" + prefix + suffix + ".png";
            EngineBase::loadTexture(path);
        }
    }
}
