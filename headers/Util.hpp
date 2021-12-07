#ifndef UTIL_HPP
#define UTIL_HPP

enum class Direction
{
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3,
    NONE = 4
};

struct Coordinates
{
    int x;
    int y;
};

#endif