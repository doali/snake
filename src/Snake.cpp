#include "../headers/Snake.hpp"

Snake::Snake(unsigned int size = 3) : _snakeElement(std::vector<SnakeElement>{size})
{
}

Snake::~Snake()
{
}

void Snake::move()
{
    auto keepDirection = [](Coordinates &coord, Direction &direction)
    {
        switch (direction)
        {
        case Direction::UP:
            --coord.y;
            break;
        case Direction::RIGHT:
            ++coord.x;
            break;
        case Direction::DOWN:
            ++coord.y;
            break;
        case Direction::LEFT:
            --coord.x;
            break;
        case Direction::NONE:
            break;
        }
    };

    for (auto &snakeElmnt : _snakeElement)
    {
        keepDirection(snakeElmnt.coordinates, snakeElmnt.direction);
    }
}
