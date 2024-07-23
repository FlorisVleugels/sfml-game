#ifndef FLOOR_H
#define FLOOR_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Floor {
public:
    Floor();
    void draw(sf::RenderWindow& window);

private:
    sf::Sprite layer0Sprite;
    sf::Texture layer0Texture;

    sf::Sprite layer1Sprite;
    sf::Texture layer1Texture;

    sf::Sprite layer2Sprite;
    sf::Texture layer2Texture;

    sf::Sprite layer3Sprite;
    sf::Texture layer3Texture;

    sf::Sprite layer4Sprite;
    sf::Texture layer4Texture;

    sf::Sprite layer5Sprite;
    sf::Texture layer5Texture;

    sf::Sprite layer6Sprite;
    sf::Texture layer6Texture;

    sf::Sprite layer7Sprite;
    sf::Texture layer7Texture;

    sf::Sprite layer8Sprite;
    sf::Texture layer8Texture;

    sf::Sprite layer9Sprite;
    sf::Texture layer9Texture;

    sf::Sprite layer10Sprite;
    sf::Texture layer10Texture;

    sf::Sprite layer11Sprite;
    sf::Texture layer11Texture;

    sf::RectangleShape testrect;
};

#endif

