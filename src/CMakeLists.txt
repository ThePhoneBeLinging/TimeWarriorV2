cmake_minimum_required(VERSION 3.28)
project(TimeWarriorV2)

add_executable(TimeWarriorV2
        main.cpp
        TimeWarriorV2.cpp
        TimeWarriorV2.h
        Objects/Player.cpp
        Objects/Player.h
        Objects/SavedPosition.cpp
        Objects/SavedPosition.h
        Objects/PressurePlate.cpp
        Objects/PressurePlate.h
        Objects/ActivateAble/IActivateAble.h
        Objects/ActivateAble/SlidingDoor.cpp
        Objects/ActivateAble/SlidingDoor.h
        CollisionController.cpp
        CollisionController.h
        TimeWarriorTexture.h
        Texture/TextureLoader.cpp
        Texture/TextureLoader.h
        RoomCreator.cpp
        RoomCreator.h
        Objects/Wall.cpp
        Objects/Wall.h
        TimeWarriorZValues.h
        Objects/RoomSwitcherObject.cpp
        Objects/RoomSwitcherObject.h
        Objects/LongWall.cpp
        Objects/LongWall.h
)
include_directories(Objects)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(TimeWarriorV2 PUBLIC
        Utility
        EngineBase
)