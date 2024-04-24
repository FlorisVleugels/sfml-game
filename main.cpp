#include <SFML/Graphics.hpp>
#include "Animation.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::Clock clock;
    sf::Event event;
    window.setFramerateLimit(60);
    sf::RectangleShape player(sf::Vector2f(128.0f, 128.0f));
    player.setPosition(200.f, 200.f);

    sf::Texture playerRunning;
    playerRunning.loadFromFile("assets/Fighter/Run.png");
    player.setTexture(&playerRunning);

    float velocity = 10;
    float deltaTime = 0.0f;

    Animation animation(&playerRunning, sf::Vector2u(8,1), 0.3f);

    while (window.isOpen()) {

        deltaTime = clock.restart().asSeconds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player.move(-velocity, 0.f);
        }

       if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player.move(0.f, -velocity);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player.move(0.f, velocity);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player.move(velocity, 0.f);
        }

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        animation.Update(0, deltaTime);
        player.setTextureRect(animation.textureRect);

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}
