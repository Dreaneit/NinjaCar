#include <sfml/Graphics.hpp>
#include "Car.h"

int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::VideoMode windowSize = sf::VideoMode(2400, 1200);
    sf::VideoMode finalDesktop = windowSize;

    sf::RenderWindow window(finalDesktop, "Car Ninja Game");

    float centerWidthPosition = finalDesktop.width / 2.0f;
    float centerHeightPosition = finalDesktop.height / 2.0f;

    Car car(centerWidthPosition, centerHeightPosition);
    car.setTextureSize(window.getSize());

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