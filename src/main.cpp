#include <SFML/Graphics.hpp>
#include "scenes/Floor.h"
#include "npc/Boss.h"
#include "player/Player.h"
#include "scenes/MainMenu.h"
#include "scenes/PauseMenu.h"
#include "util/XMLParser.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Nameless Game");
    window.setFramerateLimit(60);

    MainMenu mainMenu(window.getSize().x, window.getSize().y);
    PauseMenu pauseMenu(window.getSize().x, window.getSize().y);
    
    sf::Clock clock;
    sf::Event event;

    float deltaTime = 0.0f;
    bool isPlaying = false;
    bool isPaused = false;

    Floor floor;
    Player player;
    Boss boss;

    XMLParser loader("../resources/levels/map.xml");
    std::vector<std::vector<int>> matrix = loader.loadMatrix();
    loader.printMatrix(matrix);

    while (window.isOpen()) {

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        deltaTime = clock.restart().asSeconds();
        window.clear();

        if (!isPlaying) {
            mainMenu.update(window, &isPlaying);
            mainMenu.draw(window);
        } else {
            if (!isPaused) {
                player.update(deltaTime, floor.bounds, &isPaused);
                boss.update(deltaTime);
                floor.draw(window);
                boss.draw(window);
                player.draw(window);
            } else { 
                floor.draw(window);
                boss.draw(window);
                player.draw(window);
                pauseMenu.update(window, &isPaused);
                pauseMenu.draw(window);
            }
        }

        window.display();
    }

    return 0;
}
