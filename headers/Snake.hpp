#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Util.hpp"
#include <vector>

class Board;
class SnakeElement
{
public:
    SnakeElement() = default;
    SnakeElement(Coordinates const &coordinates, Direction const &direction) : _coordinates(coordinates), _direction(direction) {}
    SnakeElement(SnakeElement const &snake)
    {
        _coordinates = snake.coordinates();
        _direction = snake.direction();
    }

    ~SnakeElement() = default;

    Coordinates coordinates() const { return _coordinates; }
    void setCoordinates(Coordinates const coordinates) { _coordinates = coordinates; }

    Direction direction() const { return _direction; }
    void setDirection(Direction const direction) { _direction = direction; }

private:
    Coordinates _coordinates;
    Direction _direction;
};

struct SnakeElementMark
{
    struct SnakeElement snakeElement;
    unsigned int counterElement;
};

class Snake
{
public:
    Snake(Board *board = nullptr, unsigned int const &size = 3);
    virtual ~Snake() = default;

    void setBoard(Board *board) { _board = board; };
    void move();

protected:
    std::vector<SnakeElement> _snakeElement;
    std::vector<SnakeElementMark> _snakeElementMark;
    Board *_board;
};

#endif