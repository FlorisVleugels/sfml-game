#include "Player.h"

Player::Player()
    : runningAnimation(&runningTexture, sf::Vector2u(8, 1), 0.1f),
      idleAnimation(&idleTexture, sf::Vector2u(6, 1), 0.1f),
      velocity(10.0f),
      moving(false) {

    body.setSize(sf::Vector2f(128.0f, 128.0f));
    body.setPosition(0.f, 540.f);

    runningTexture.loadFromFile("../resources/Fighter/Run.png");
    idleTexture.loadFromFile("../resources/Fighter/Idle.png");
}

void Player::update(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        moving = false;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        body.move(-velocity, 0.f);
        moving = true;
        body.setScale(-1.0f, 1.0f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        body.move(velocity, 0.f);
        moving = true;
        body.setScale(1.0f, 1.0f);
    } else {
        moving = false;
    }

    if (moving) {
        body.setTexture(&runningTexture);
        runningAnimation.Update(deltaTime);
        body.setTextureRect(runningAnimation.textureRect);
    } else {
        body.setTexture(&idleTexture);
        idleAnimation.Update(deltaTime);
        body.setTextureRect(idleAnimation.textureRect);
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(body);
}

