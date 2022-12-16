#include "Snake.hpp"
#include "Timer.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <chrono>

#include <functional>

static sf::CircleShape shape(10.f);

void update_cirle(sf::RenderWindow &window)
{        
    static unsigned int val{0U};
    static unsigned int l_val{0U};
    l_val = (val < (2 * M_PI * 1000)) ? ++val : 0U;

    shape.setRadius(10);//cos(l_val / (2 * M_PI)) * 5 + 5);
    shape.setPosition(100 + 50 * cos(l_val / (2 * M_PI)), 100 + 50 * sin(l_val / (2 * M_PI)));
    shape.setFillColor(sf::Color::Magenta);    
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

    snake::Snake snake;
    snake.init();

    timer::Timer l_timer{window, 60};    
    l_timer.add(update_cirle, window);
    l_timer.start();

    auto l_start{std::chrono::high_resolution_clock::now()};    
    snake::Direction currDirection{snake::Direction::RIGHT};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Right:
                    // snake.move(snake::Direction::RIGHT);
                    currDirection = snake::Direction::RIGHT;                    
                    break;
                case sf::Keyboard::Down:
                    // snake.move(snake::Direction::DOWN);
                    currDirection = snake::Direction::DOWN;
                    break;
                case sf::Keyboard::Left:
                    // snake.move(snake::Direction::LEFT);
                    currDirection = snake::Direction::LEFT;
                    break;
                case sf::Keyboard::Up:
                    // snake.move(snake::Direction::UP);
                    currDirection = snake::Direction::UP;
                    break;
                default:
                    break;
                }
            }
        }

        window.clear();
        
        for(auto &cell : snake._snakeCells)
        {
            window.draw(cell._shape);
        }

        {
            auto l_now{std::chrono::high_resolution_clock::now()};
            auto elapsed{std::chrono::duration_cast<std::chrono::milliseconds>(l_now - l_start)};

            if (elapsed.count() >= 80)
            {
                snake.move(currDirection);
                l_start = l_now;
            }
        }
            
        l_timer.run();
        window.draw(shape);

        window.display();
    }

    return 0;
}
