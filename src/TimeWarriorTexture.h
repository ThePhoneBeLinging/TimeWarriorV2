//
// Created by Elias Aggergaard Larsen on 15/09/2024.
//

#ifndef TIMEWARRIORTEXTURE_CUH
#define TIMEWARRIORTEXTURE_CUH

enum class TimeWarriorTexture
{
   // The 1 is the amount of textures that EngineBase loads as default
   // EngineBase will eventually run on a matrix, and thus we only need to specify what primaryIndex of the
   // texture to load
   PlayerDown = 1,
   PlayerUp,
   PlayerLeft,
   PlayerRight,
   Ghost1Down,
   Ghost1Up,
   Ghost1Left,
   Ghost1Right,
   Ghost2Down,
   Ghost2Up,
   Ghost2Left,
   Ghost2Right,
   Ghost3Down,
   Ghost3Up,
   Ghost3Left,
   Ghost3Right,
   Ghost4Down,
   Ghost4Up,
   Ghost4Left,
   Ghost4Right,
   PressurePlateUp,
   PressurePlateDown,
   SlidingDoor,
   BrickWall,
   Invisible
};

#endif //TIMEWARRIORTEXTURE_CUH
