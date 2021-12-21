#include "Snake.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

    snake::Snake snake;    
    snake.init();

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
                    snake.move(snake::Direction::RIGHT);
                    break;                
                case sf::Keyboard::Down:
                    snake.move(snake::Direction::DOWN);
                    break;                
                case sf::Keyboard::Left:
                    snake.move(snake::Direction::LEFT);
                    break;                
                case sf::Keyboard::Up:
                    snake.move(snake::Direction::UP);
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
        
        window.display();
    }

    return 0;
}
