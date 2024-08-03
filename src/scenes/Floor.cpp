#include "Floor.h"
#include <SFML/System/Vector2.hpp>

Floor::Floor() {

    std::vector<std::string> textureFiles = {
        "../resources/para/Layer_0011_0.png",
        "../resources/para/Layer_0010_1.png",
        "../resources/para/Layer_0009_2.png",
        "../resources/para/Layer_0008_3.png",
        "../resources/para/Layer_0007_Lights.png",
        "../resources/para/Layer_0006_4.png",
        "../resources/para/Layer_0005_5.png",
        "../resources/para/Layer_0004_Lights.png",
        "../resources/para/Layer_0003_6.png",
        "../resources/para/Layer_0002_7.png",
        "../resources/para/Layer_0001_8.png",
        "../resources/para/Layer_0000_9.png",
    };

    textures.resize(textureFiles.size());
    sprites.resize(textureFiles.size());

    for (size_t i = 0; i < textureFiles.size(); ++i) {
        if (!textures[i].loadFromFile(textureFiles[i])) {
            // Handle loading error
        }
        sprites[i].setTexture(textures[i]);
    }
}

void Floor::draw(sf::RenderWindow& window) {

    int numTiles = window.getSize().x / textureWidth + 1;

    for (int i = 0; i < numTiles; ++i) {
        for (auto& sprite : sprites) {
            sprite.setPosition(i * textureWidth, 0);
            window.draw(sprite);
        }
    }

    // Test rect for making collision
    // testrect.setSize(sf::Vector2f(50,1080));
    // testrect.setPosition(1000,0);

    // window.draw(testrect);
}

