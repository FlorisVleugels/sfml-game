#include <SFML/Graphics.hpp>
#include "scenes/Floor.h"
#include "npc/Boss.h"
#include "player/Player.h"
#include "scenes/MainMenu.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Nameless Game");
    window.setFramerateLimit(60);

    MainMenu mainMenu(window.getSize().x, window.getSize().y);
    
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
    
        player.update(deltaTime, floor.bounds);
        boss.update(deltaTime);
        // mainMenu.update();

        window.clear();
        mainMenu.draw(window);
        // floor.draw(window);
        // boss.draw(window);
        // player.draw(window);
        window.display();
    }

    return 0;
}
