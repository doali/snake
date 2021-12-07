#ifndef BOARD_HPP
#define BOARD_HPP

#include "Util.hpp"
#include "Snake.hpp"

class Element
{
public:
    Element(Coordinates const &coordinates);
    virtual ~Element();

private:
    Coordinates _coordinates;
};

class Board
{
public:
    Board(Coordinates const &coordinates, unsigned int const &width = 1000, unsigned int const &height = 1000);
    ~Board() = default;

    inline unsigned int width() const { return _width; }
    inline unsigned int height() const { return _height; }
    inline Coordinates coordinates() const { return _coordinates; }
    inline Snake snake() const { return _snake; }

private:
    unsigned int _width;
    unsigned int _height;
    Coordinates _coordinates;
    Snake _snake;
};

#endif // BOARD_HPP