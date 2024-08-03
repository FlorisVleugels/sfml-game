#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "../npc/Boss.h"

class Player {
public:
    Player();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape body;
    sf::Texture runningTexture;
    sf::Texture idleTexture;
    std::unique_ptr<Animation> runningAnimation;
    std::unique_ptr<Animation> idleAnimation;
    float velocity = 6;
    bool moving;
};

#endif

