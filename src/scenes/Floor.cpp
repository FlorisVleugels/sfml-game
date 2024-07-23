#include "Floor.h"

Floor::Floor() {
    layer0Texture.loadFromFile("../resources/para/Layer_0000_9.png");
    layer0Sprite.setTexture(layer0Texture);
    layer0Sprite.setPosition(0, 0);

    layer1Texture.loadFromFile("../resources/para/Layer_0001_8.png");
    layer1Sprite.setTexture(layer1Texture);
    layer1Sprite.setPosition(0, 0);

    layer2Texture.loadFromFile("../resources/para/Layer_0002_7.png");
    layer2Sprite.setTexture(layer2Texture);
    layer2Sprite.setPosition(0, 0);

    layer3Texture.loadFromFile("../resources/para/Layer_0003_6.png");
    layer3Sprite.setTexture(layer3Texture);
    layer3Sprite.setPosition(0, 0);

    layer4Texture.loadFromFile("../resources/para/Layer_0004_Lights.png");
    layer4Sprite.setTexture(layer4Texture);
    layer4Sprite.setPosition(0, 0);

    layer5Texture.loadFromFile("../resources/para/Layer_0005_5.png");
    layer5Sprite.setTexture(layer5Texture);
    layer5Sprite.setPosition(0, 0);

    layer6Texture.loadFromFile("../resources/para/Layer_0006_4.png");
    layer6Sprite.setTexture(layer6Texture);
    layer6Sprite.setPosition(0, 0);

    layer7Texture.loadFromFile("../resources/para/Layer_0007_Lights.png");
    layer7Sprite.setTexture(layer7Texture);
    layer7Sprite.setPosition(0, 0);

    layer8Texture.loadFromFile("../resources/para/Layer_0008_3.png");
    layer8Sprite.setTexture(layer8Texture);
    layer8Sprite.setPosition(0, 0);

    layer9Texture.loadFromFile("../resources/para/Layer_0009_2.png");
    layer9Sprite.setTexture(layer9Texture);
    layer9Sprite.setPosition(0, 0);

    layer10Texture.loadFromFile("../resources/para/Layer_0010_1.png");
    layer10Sprite.setTexture(layer10Texture);
    layer10Sprite.setPosition(0, 0);

    layer11Texture.loadFromFile("../resources/para/Layer_0011_0.png");
    layer11Sprite.setTexture(layer11Texture);
    layer11Sprite.setPosition(0, 0);

    testrect.setSize(sf::Vector2f(50, 800));
    testrect.setPosition(1000,0);
}

void Floor::draw(sf::RenderWindow& window) {
    window.draw(layer11Sprite);
    window.draw(layer10Sprite);
    window.draw(layer9Sprite);
    window.draw(layer8Sprite);
    window.draw(layer7Sprite);
    window.draw(layer6Sprite);
    window.draw(layer5Sprite);
    window.draw(layer4Sprite);
    window.draw(layer3Sprite);
    window.draw(layer2Sprite);
    window.draw(layer1Sprite);
    window.draw(layer0Sprite);
    //window.draw(testrect);
}

