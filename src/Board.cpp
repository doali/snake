#include "../headers/Board.hpp"

Element::Element(Coordinates const coordinates) : _coordinates(coordinates)
{
}

Element::~Element()
{
}

Board::Board(const unsigned int width, const unsigned int height) : _width(width),
                                                                    _height(height)
{
}

Board::~Board()
{
}