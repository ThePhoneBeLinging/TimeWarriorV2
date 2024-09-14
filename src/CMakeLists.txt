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
)

target_link_libraries(TimeWarriorV2 PUBLIC
        Utility
        EngineBase
)