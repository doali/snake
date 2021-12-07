#include "../headers/Snake.hpp"
#include "../headers/Board.hpp"

Snake::Snake(Board *board, unsigned int const &size) : _board(board),
                                                _snakeElement(std::vector<SnakeElement>{size})
{
}

void Snake::move()
{
    auto keepDirection = [](Coordinates coord, Direction direction)
    {
        switch (direction)
        {
        case Direction::UP:
            coord.setY(coord.y() - 1);
            break;
        case Direction::RIGHT:
            coord.setX(coord.x() + 1);
            break;
        case Direction::DOWN:
            coord.setY(coord.y() + 1);
            break;
        case Direction::LEFT:
            coord.setY(coord.x() - 1);
            break;
        case Direction::NONE:
            break;
        }
    };

    for (auto &snakeElmnt : _snakeElement)
    {
        keepDirection(snakeElmnt.coordinates(), snakeElmnt.direction());
    }
}
