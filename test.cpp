#include <SFML/Graphics.hpp>

enum class Direction
{
    UP,
    RIGHT,
    DOWN,
    LEFT
};

sf::CircleShape const exShape()
{
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color(150, 50, 250));

    // définit un contour orange de 10 pixels d'épaisseur
    shape.setOutlineThickness(10.f);
    shape.setOutlineColor(sf::Color(250, 150, 100));

    return shape;
}

struct Snake
{
    int _x;
    int _y;
    Direction _direction;
    sf::CircleShape _shape;
    Snake(int x, int y) : _x(x), _y(y)
    {
        _shape.setRadius(10.f);
        _shape.setFillColor(sf::Color(150, 50, 250));
        _shape.setPosition(sf::Vector2f(_x, _y));
        _direction = Direction::LEFT;
    }
    void move(int x, int y)
    {
        _x = (x < 800) ? x : 0;
        _y = (y < 600) ? y : 0;
    }
    void moveRight()
    {
        move(_x + 1, _y);
        _shape.setPosition(sf::Vector2f(_x, _y));
    }
    void update()
    {
        if (_direction == Direction::RIGHT)
        {
            moveRight();
            _shape.setPosition(sf::Vector2f(_x, _y));
        }
    }
};

int main()
{
    // création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    Snake snake(100, 50);

    // on fait tourner le programme tant que la fenêtre n'a pas été fermée
    while (window.isOpen())
    {
        // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
        sf::Event event;
        while (window.pollEvent(event))
        {
            // fermeture de la fenêtre lorsque l'utilisateur le souhaite
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                snake._direction = Direction::RIGHT;
        }

        snake.update();

        // effacement de la fenêtre en noir
        window.clear(sf::Color::Black);

        // c'est ici qu'on dessine tout
        // window.draw(...);
        window.draw(snake._shape);
        // window.draw(exShape());

        // fin de la frame courante, affichage de tout ce qu'on a dessiné
        window.display();
    }

    return 0;
}
