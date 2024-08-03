#ifndef BOSS_H
#define BOSS_H

#include <SFML/Graphics.hpp>
#include "../animations/Animation.h"
#include <memory>

class Boss {
public:
    Boss();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape body;
    sf::Texture idleTexture;
    std::unique_ptr<Animation> idleAnimation;
};

#endif 
