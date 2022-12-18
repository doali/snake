#ifndef _SNAKE_HPP
#define _SNAKE_HPP

#include <vector>
#include <stdint.h>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace snake
{
    enum class Direction
    {
        RIGHT,
        DOWN,
        LEFT,
        UP
    };

    struct Coordinates
    {
        Coordinates() = default;
        Coordinates(float const x, float const y) : _x(x), _y(y) {}
        float _x{0};
        float _y{0};

        friend std::ostream & operator<<(std::ostream &p_os, Coordinates const &p_coord);
    };

    struct GUICell
    {
        static constexpr float RADIUS = 10.f;
        sf::CircleShape _shape{RADIUS};
    };

    struct Cell
    {
        Cell() = default;
        void move(const Direction &direction);
        /**
         * @brief coordoonées de la cellule
         *
         */
        GUICell _guiCell;
        Coordinates _coordinates;

        friend std::ostream & operator<<(std::ostream &p_os, Cell const &p_cell);
    };

    struct OrientedCell : public Cell
    {
        /**
         * @brief direction associée
         * pour déterminer les déplacements futurs
         *
         */
        Direction _direction{Direction::RIGHT};
        void move(const Direction &direction);

        friend std::ostream & operator<<(std::ostream &p_os, OrientedCell const &p_oCell);
    };

    struct Snake
    {
        Snake() = default;
        explicit Snake(size_t const &size) : _size(size){};

        size_t _size{4};
        /**
         * @brief ensemble de cellules
         * constituant le snake
         */
        std::vector<OrientedCell> _snakeCells{_size};

        void move(const Direction &);

        void init();

        friend std::ostream &operator<<(std::ostream &p_os, Snake const &p_snake);
    };
} // namespace snake

#endif