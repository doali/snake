#ifndef _SNAKE_HPP
#define _SNAKE_HPP

#include <vector>
#include <stdint.h>

enum class Direction 
{
    RIGHT,
    DOWN,
    LEFT,
    UP
};

struct Coordinates
{
    float _x;
    float _y;
};
struct LivingCell
{
    Coordinates _coordinates;    
    Direction _direction;
    uint8_t _size;
    static Coordinates projection(const Coordinates &, const Direction &);    
};
struct Snake
{        
    Snake(const int &size = 4);
    std::vector<LivingCell> _livingCell;
    void move(const Direction &);
};

#endif