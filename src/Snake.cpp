#include "Snake.hpp"
#include <iostream>
namespace snake
{
    Coordinates OrientedCell::projection(const Coordinates &coordinates, const Direction &direction)
    {
        return Coordinates();
    }

    void Snake::move(const Direction &direction)
    {        
        switch (direction)
        {
        case Direction::RIGHT:
            for (OrientedCell &cell : _snakeCells)
            {                
                cell._coordinates._x += (cell._shape.getRadius() + 2);
                cell._shape.setPosition(cell._coordinates._x, cell._coordinates._y);
            }
            break;
        case Direction::DOWN:
            for (OrientedCell &cell : _snakeCells)
            {
                cell._coordinates._y += (cell._shape.getRadius() + 2);
                cell._shape.setPosition(cell._coordinates._x, cell._coordinates._y);
            }
            break;
        case Direction::LEFT:
            for (OrientedCell &cell : _snakeCells)
            {
                cell._coordinates._x -= (cell._shape.getRadius() + 2);
                cell._shape.setPosition(cell._coordinates._x, cell._coordinates._y);
            }
            break;
        case Direction::UP:
            for (OrientedCell &cell : _snakeCells)
            {
                cell._coordinates._y -= (cell._shape.getRadius() + 2);
                cell._shape.setPosition(cell._coordinates._x, cell._coordinates._y);
            }
            break;
        default:
            break;
        }        
    }

    void Snake::init()
    {
        _snakeCells.push_back(OrientedCell());
        for(OrientedCell &cell : _snakeCells)
        {
            cell._shape.setFillColor(sf::Color::Green);
            cell._shape.setPosition(cell._coordinates._x, cell._coordinates._y);
        }
    }
} // namespace snake
