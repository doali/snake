#ifndef _SNAKE_HPP
#define _SNAKE_HPP

#include <list>
#include <stdint.h>
#include <SFML/Graphics.hpp>

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
    };

    struct GUICell
    {
        sf::CircleShape _shape{10.f};        
    };

    struct Cell : public GUICell
    {
        Cell() : GUICell() {}
        /**
         * @brief coordoonées de la cellule
         *
         */
        Coordinates _coordinates;
        size_t _size{4};
    };

    struct OrientedCell : public Cell
    {
        /**
         * @brief direction associée
         * pour déterminer les déplacements futurs
         *
         */
        Direction _direction{Direction::RIGHT};

        static Coordinates projection(const Coordinates &, const Direction &);
    };

    struct TraficCell : public OrientedCell
    {
        /**
         * @brief compteur de passage d'éléments
         * sur cette cellule
         *
         */
        uint8_t _cellPrint{0};
    };

    struct Snake
    {
        Snake() = default;
        explicit Snake(size_t const &size) : _size(size){};

        /**
         * @brief ensemble de cellules
         * constituant le snake
         */
        std::list<OrientedCell> _snakeCells;

        /**
         * @brief ensemble de cellules
         * mémorisant les changements de directions
         * du snake
         *
         */
        std::list<TraficCell> _snakeMovements;

        void move(const Direction &);
        size_t _size{4};

        void init();
    };
} // namespace snake

#endif