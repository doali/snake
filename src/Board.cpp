#include "../headers/Board.hpp"

Element::Element(Coordinates const &coordinates) : _coordinates(coordinates)
{
}

Element::~Element()
{
}

Board::Board(Coordinates const &coordinates, unsigned int const &width /* = 1000 */, unsigned int const &height /* = 1000 */) : _coordinates(coordinates),
                                                                                                                             _width(width),
                                                                                                                             _height(height)

{
    _snake.setBoard(this);
}
