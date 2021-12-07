#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Util.hpp"
#include <vector>

struct SnakeElement
{
    Coordinates coordinates;
    Direction direction;
};

struct SnakeElementMark
{
    struct SnakeElement snakeElement;
    unsigned int counterElement;
};

class Snake
{
public:
    Snake() = default;
    Snake(unsigned int size = 3);
    ~Snake();

    void move();

private:
    std::vector<SnakeElement> _snakeElement;
    std::vector<SnakeElementMark> _snakeElementMark;
};

#endif