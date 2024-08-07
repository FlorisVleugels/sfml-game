#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>

class Animation {
    public:
        Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
        void Update(float deltaTime);

    public:
        sf::IntRect textureRect;

    private:
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;

        float totalTime;
        float switchTime;
};
#endif // !DEBUG
