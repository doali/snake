#include "Snake.hpp"
#include <iostream>
#include <array>

namespace snake
{
    std::string DirectionToString(Direction const &direction)
    {
        std::string sDirection{"NONE"};
        switch (direction)
        {
        case Direction::RIGHT:
            sDirection = "RIGHT";
            break;
        case Direction::DOWN:
            sDirection = "DOWN";
            break;
        case Direction::LEFT:
            sDirection = "LEFT";
            break;
        case Direction::UP:
            sDirection = "UP";
            break;
        default:
            break;
        }
        return sDirection;
    }

    void Cell::move(const Direction &direction)
    {
        switch (direction)
        {
        case Direction::RIGHT:
            _coordinates._x += (GUICell::RADIUS * 2);
            _guiCell._shape.setPosition(_coordinates._x, _coordinates._y);
            break;
        case Direction::DOWN:
            _coordinates._y += (GUICell::RADIUS * 2);
            _guiCell._shape.setPosition(_coordinates._x, _coordinates._y);
            break;
        case Direction::LEFT:
            _coordinates._x -= (GUICell::RADIUS * 2);
            _guiCell._shape.setPosition(_coordinates._x, _coordinates._y);
            break;
        case Direction::UP:
            _coordinates._y -= (GUICell::RADIUS * 2);
            _guiCell._shape.setPosition(_coordinates._x, _coordinates._y);
            break;
        default:
            break;
        }
    }

    void OrientedCell::move(const Direction &direction)
    {
        Cell::move(direction);
        _direction = direction;
    }

    void Snake::move(Direction const &direction)
    {
        u_int16_t index {0};
        for (; index < _snakeCells.size() - 1; ++index)
        {
            _snakeCells[index] = _snakeCells[index + 1];
        }
        _snakeCells[index].move(direction);
    }

    void Snake::init()
    {
        float delta_x{GUICell::RADIUS * 2};
        u_int8_t currCell{0};
        for (OrientedCell &cell : _snakeCells)
        {
            cell._guiCell._shape.setPosition(cell._coordinates._x + (currCell * delta_x), cell._coordinates._y);
            ++currCell;            
        }
    }

    std::ostream &operator<<(std::ostream &p_os, Coordinates const &p_coord)
    {
        p_os << "(" << p_coord._x << ", " << p_coord._y << ")";
        return p_os;
    }

    std::ostream &operator<<(std::ostream &p_os, Cell const &p_cell)
    {
        p_os << p_cell._coordinates;
        return p_os;
    }

    std::ostream &operator<<(std::ostream &p_os, OrientedCell const &p_oCell)
    {
        p_os << DirectionToString(p_oCell._direction) << ", " << p_oCell;
        return p_os;
    }

    std::ostream &operator<<(std::ostream &p_os, Snake const &p_snake)
    {
        for (auto const &oCell : p_snake._snakeCells)
        {
            p_os << oCell << std::endl;
        }

        return p_os;
    }
} // namespace snake
