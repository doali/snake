#include "../headers/Board.hpp"
#include <SFML/Graphics.hpp>

int main()
{
    Board board(Coordinates{100, 100}, 1000, 1000);    

    // sf::RenderWindow window(sf::VideoMode(board.width(), board.height()), "Snake");
    // window.setVerticalSyncEnabled(true);

    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     window.clear();
    //     // window.draw(shape);
    //     window.display();
    // }

    return 0;
}
