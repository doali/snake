#include "../headers/SnakeGUI.hpp"
#include "../headers/Board.hpp"
#include <SFML/Graphics.hpp>

SnakeGUI::SnakeGUI(Board *board, unsigned int const &width, unsigned int const &height, unsigned int const &size /* = 3 */) : Snake(board, size),
                                                                                                                           _width(width),
                                                                                                                           _height(height)
{
    unsigned int count{0};
    for (auto &snakeElmnt : _snakeElement)
    {
        snakeElmnt.setDirection(Direction::RIGHT);
        snakeElmnt.coordinates().setX(snakeElmnt.coordinates().x() + count * _width);
        snakeElmnt.coordinates().setY(0);
    }
}

void SnakeGUI::draw()
{
    // sf::RectangleShape shape(sf::Vector2i(_width, _width));
    // shape.setFillColor(sf::Color::Magenta);
}