#include <sfml/Graphics.hpp>
#include "Car.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Car Ninja Game");

    Car car(400, 300);

    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                car.setPressedKey(event.key.code);
            }
            else if (event.type == sf::Event::KeyReleased)
            {
                car.setPressedKey(event.key.code);
            }
        }

        float deltaTime = clock.restart().asSeconds();
        car.setDeltaTime(deltaTime);

        car.update();
        window.clear();
        car.draw(window);
        window.display();
    }

    return 0;
}