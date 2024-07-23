#include "Floor.h"

Floor::Floor() {
    floorTexture.loadFromFile("../resources/para/Layer_0001_8.png");
    floorSprite.setTexture(floorTexture);
    floorSprite.setPosition(0, 0);
}

void Floor::draw(sf::RenderWindow& window) {
    window.draw(floorSprite);
}

