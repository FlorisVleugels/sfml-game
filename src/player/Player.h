#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "../animations/Animation.h"

class Player {
public:
    Player();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape body;
    sf::Texture runningTexture;
    sf::Texture idleTexture;
    Animation runningAnimation;
    Animation idleAnimation;
    float velocity;
    bool moving;
};

#endif

