#include "Boss.h"

Boss::Boss() {
    idleTexture.loadFromFile("../resources/boss/demon_slime_FREE_v1.0_288x160_spritesheet.png");

    idleAnimation = std::make_unique<Animation>(&idleTexture, sf::Vector2u(6, 1), 0.1f);

    body.setSize(sf::Vector2f(352.0f, 160.0f));
    body.setPosition(1000.f, 540.f);

    sf::FloatRect bounds = body.getLocalBounds();
    body.setOrigin(bounds.width / 2, bounds.height / 2);
}

void Boss::update(float deltaTime) {
    body.setTexture(&idleTexture);
    idleAnimation -> Update(deltaTime);
    body.setTextureRect(idleAnimation -> textureRect);
}

void Boss::draw(sf::RenderWindow& window) {
    window.draw(body);
}
