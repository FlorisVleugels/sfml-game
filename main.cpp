#include <SFML/Graphics.hpp>
#include "Animation.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    window.setFramerateLimit(60);

    sf::Clock clock;
    sf::Event event;

    sf::RectangleShape player(sf::Vector2f(128.0f, 128.0f));
    player.setPosition(0.f, 540.f);

    sf::Texture playerRunning;
    playerRunning.loadFromFile("assets/Fighter/Run.png");
    Animation running(&playerRunning, sf::Vector2u(8,1), 0.1f);

    sf::Texture playerIdle;
    playerIdle.loadFromFile("assets/Fighter/Idle.png");
    Animation idle(&playerIdle, sf::Vector2u(6,1), 0.1f);

    float velocity = 10;
    float deltaTime = 0.0f;

    bool moving;

    while (window.isOpen()) {

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        deltaTime = clock.restart().asSeconds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player.move(-velocity, 0.f);
            moving = true;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player.move(velocity, 0.f);
            moving = true;
        }

        if (moving == true) {
            player.setTexture(&playerRunning);
            running.Update(deltaTime);
            player.setTextureRect(running.textureRect);
        } else {
            player.setTexture(&playerIdle);
            idle.Update(deltaTime);
            player.setTextureRect(idle.textureRect);
        }

        moving = false;

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}
