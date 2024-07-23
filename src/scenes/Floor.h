#ifndef FLOOR_H
#define FLOOR_H

#include <SFML/Graphics.hpp>

class Floor {
public:
    Floor();
    void draw(sf::RenderWindow& window);

private:
    sf::Sprite floorSprite;
    sf::Texture floorTexture;
};

#endif

