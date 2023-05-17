#include "Snake.hpp"
#include "Timer.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <chrono>

#include <functional>

static sf::CircleShape shape(5.f);

void update_cirle(sf::RenderWindow &window)
{
    static unsigned int val{0U};
    static unsigned int l_val{0U};
    l_val = (val < (2 * M_PI * 1000)) ? ++val : 0U;

    shape.setRadius(10); // cos(l_val / (2 * M_PI)) * 5 + 5);
    shape.setPosition(100 + 50 * cos(l_val / (2 * M_PI)), 100 + 50 * sin(l_val / (2 * M_PI)));
    shape.setFillColor(sf::Color::Magenta);
}

static sf::CircleShape ball(5.f);

void update_ball(sf::RenderWindow &window)
{
    static unsigned int val{0U};
    static unsigned int l_val{0U};
    l_val = (val < (2 * M_PI * 1000)) ? ++val : 0U;

    ball.setRadius(10); // cos(l_val / (2 * M_PI)) * 5 + 5);
    // ball.setPosition(50 + 50 * cos(-l_val / (2 * M_PI)), 50 + 50 * sin(-l_val / (2 * M_PI)));
    ball.setFillColor(sf::Color::Yellow);
}

namespace snake
{
    struct Area
    {
        Area() = default;

        void init()
        {
            float delta_x{GUICell::RADIUS * 2};
            u_int8_t currCell{0};
            for (OrientedCell &cell : _oCells)
            {
                if (currCell < 4)
                    cell._guiCell._shape.setPosition(cell._coordinates._x + (currCell * delta_x), cell._coordinates._y);
                else
                    cell._guiCell._shape.setPosition(cell._coordinates._x + (currCell * delta_x), cell._coordinates._y + delta_x);
                ++currCell;
            }
        }

        std::vector<OrientedCell> _oCells{8};
    };
}

snake::Direction update_direction(snake::Direction &p_direction, sf::Event const &p_event)
{
    if (p_event.type == sf::Event::KeyPressed)
    {
        switch (p_event.key.code)
        {
        case sf::Keyboard::Right:
            p_direction = snake::Direction::RIGHT;
            break;
        case sf::Keyboard::Down:
            p_direction = snake::Direction::DOWN;
            break;
        case sf::Keyboard::Left:
            p_direction = snake::Direction::LEFT;
            break;
        case sf::Keyboard::Up:
            p_direction = snake::Direction::UP;
            break;
        default:
            break;
        }
    }

    return p_direction;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

    snake::Area l_area;
    l_area.init();

    snake::Snake l_snake;
    l_snake.init();

    timer::Timer l_timer{window, 60};
    l_timer.add(update_cirle, window);
    l_timer.start();

    timer::Timer l_timerBall{window, 60};
    l_timerBall.add(update_ball, window);
    l_timerBall.start();

    auto l_start{std::chrono::high_resolution_clock::now()};
    snake::Direction currDirection{snake::Direction::RIGHT};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            currDirection = update_direction(currDirection, event);
        }

        window.clear();

        for (auto &cell : l_area._oCells)
        {
            window.draw(cell._guiCell._shape);
        }

        for (auto &cell : l_snake._snakeCells)
        {
            window.draw(cell._guiCell._shape);
        }

        {
            auto l_now{std::chrono::high_resolution_clock::now()};
            auto elapsed{std::chrono::duration_cast<std::chrono::milliseconds>(l_now - l_start)};

            if (elapsed.count() >= 300)
            {
                l_snake.move(currDirection);
                l_start = l_now;
            }
        }

        l_timer.run();
        l_timerBall.run();
        window.draw(shape);
        window.draw(ball);

        window.display();
    }

    return 0;
}
