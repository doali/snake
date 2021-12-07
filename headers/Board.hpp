#ifndef BOARD_HPP
#define BOARD_HPP

#include "Util.hpp"

class Element
{
public:
    Element(Coordinates const coordinates);
    virtual ~Element(); // = 0

private:
    Coordinates _coordinates;
};

class Board
{
public:
    Board(const unsigned int width = 1000, const unsigned int height = 1000);
    ~Board();

private:
    unsigned int _width;
    unsigned int _height;
};

#endif // BOARD_HPP