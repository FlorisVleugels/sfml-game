#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::Clock clock;
    sf::Event event;
    window.setFramerateLimit(60);
    
    sf::IntRect playerSheet(0, 0, 128, 128);

    sf::Texture textureRunning;
    textureRunning.loadFromFile("assets/Fighter/Run.png");

    sf::Texture textureIdle;
    textureIdle.loadFromFile("assets/Fighter/Idle/Idle.png");
    sf::Sprite player(textureIdle, playerSheet);

    float velocity = 10;
    float acceleration = 0;

    while (window.isOpen()) {
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

        if (acceleration == 1) {
            if (clock.getElapsedTime().asSeconds() > 0.1f) {
                if (playerSheet.left == 1024)
                    playerSheet.left = 0;
                else 
                    playerSheet.left += 128;

                sf::Sprite player(textureRunning, playerSheet);
                player.setTextureRect(playerSheet);
                clock.restart();
            }
        }
        
        if (clock.getElapsedTime().asSeconds() > 0.1f) {
            if (playerSheet.left == 768)
                playerSheet.left = 0;
            else 
                playerSheet.left += 128;

            sf::Sprite player(textureIdle, playerSheet);
            player.setTextureRect(playerSheet);
            clock.restart();
        }

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}
