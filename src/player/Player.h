#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "../animations/Animation.h"
#include "../physics/Collision.h"
#include "memory"

class Player {
public:
    Player();
    void update(float deltaTime, sf::FloatRect bounds);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape body;
    sf::Texture runningTexture;
    sf::Texture idleTexture;
    std::unique_ptr<Animation> runningAnimation;
    std::unique_ptr<Animation> idleAnimation;
    float velocity = 6;
    bool moving;
    bool isColliding;
};

#endif
