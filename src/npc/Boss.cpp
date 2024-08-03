#include "Boss.h"

Boss::Boss() {
    idleTexture.loadFromFile("../resources/boss/Idle.png");

    idleAnimation = std::make_unique<Animation>(&idleTexture, sf::Vector2u(6, 1), 0.1f);

    body.setSize(sf::Vector2f(280.0f, 162.0f));
    body.setPosition(1000.f, 450.f);
    body.setScale(3.0f, 3.0f);

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
