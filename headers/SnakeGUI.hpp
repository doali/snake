#ifndef SNAKEGUI_HPP
#define SNAKEGUI_HPP

#include "Snake.hpp"

class SnakeGUI : public Snake
{
public:
    SnakeGUI(Board *board, unsigned int const &width, unsigned int const &height, unsigned int const &size = 3);
    virtual ~SnakeGUI() final {};

    void draw();

private:
    unsigned int _width;
    unsigned int _height;
};

#endif