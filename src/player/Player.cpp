#include "Player.h"
#include <SFML/Graphics/Rect.hpp>
#include "iostream"

Player::Player() {

    runningTexture.loadFromFile("../resources/Fighter/Run.png");
    idleTexture.loadFromFile("../resources/Fighter/Idle.png");

    runningAnimation = std::make_unique<Animation>(&runningTexture, sf::Vector2u(8, 1), 0.1f),
    idleAnimation = std::make_unique<Animation>(&idleTexture, sf::Vector2u(6, 1), 0.1f),

    body.setSize(sf::Vector2f(128.0f, 128.0f));
    body.setPosition(0.f, 540.f);

    // Set the origin to the center of the sprite
    sf::FloatRect bounds = body.getLocalBounds();
    body.setOrigin(bounds.width / 2, bounds.height / 2);
}

void Player::update(float deltaTime, sf::FloatRect bounds, bool *isPaused) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        std::cout << "Back to main menu" << "\n";
        *isPaused = true;
    }

    Collision Collision(body.getGlobalBounds(), bounds);
    isColliding = Collision.Evaluator();

    if (isColliding) {
        body.move(0.f, velocity);
    }

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
        runningAnimation -> Update(deltaTime);
        body.setTextureRect(runningAnimation -> textureRect);
    } else {
        body.setTexture(&idleTexture);
        idleAnimation -> Update(deltaTime);
        body.setTextureRect(idleAnimation -> textureRect);
    }

}

void Player::draw(sf::RenderWindow& window) {
    window.draw(body);
}

