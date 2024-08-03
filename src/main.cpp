#include <SFML/Graphics.hpp>
#include "scenes/Floor.h"
#include "npc/Boss.h"
#include "player/Player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    window.setFramerateLimit(60);

    sf::Clock clock;
    sf::Event event;

    float deltaTime = 0.0f;

    Floor floor;
    Player player;
    Boss boss;

    while (window.isOpen()) {

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        deltaTime = clock.restart().asSeconds();
        
        player.update(deltaTime);
        boss.update(deltaTime);

        window.clear();
        floor.draw(window);
        boss.draw(window);
        player.draw(window);
        window.display();
    }

    return 0;
}
