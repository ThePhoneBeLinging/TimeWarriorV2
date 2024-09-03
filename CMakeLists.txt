cmake_minimum_required(VERSION 3.28)
project(TimeWarriorV2)

set(CMAKE_CXX_STANDARD 20)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Resources
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(TimeWarriorV2
        src/main.cpp
        src/TimeWarriorV2.cpp
        src/TimeWarriorV2.h
        src/Objects/Player.cpp
        src/Objects/Player.h
)
include_directories(src)

add_subdirectory(dependencies/Utility)
add_subdirectory(dependencies/EngineBase)
target_link_libraries(TimeWarriorV2 PUBLIC
        Utility
        EngineBase
)