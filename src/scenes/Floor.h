#ifndef FLOOR_H
#define FLOOR_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>

class Floor {
public:
    Floor();
    void draw(sf::RenderWindow& window);

private:
    std::vector<sf::Texture> textures;
    std::vector<sf::Sprite> sprites;
    const float textureWidth = 928.0f; //float textureWidth = layer0Texture.getSize().x;

    sf::RectangleShape testrect;
};

#endif 

