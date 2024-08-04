#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

class Collision {
    public:
        Collision(sf::FloatRect sprite1, sf::FloatRect sprite2);
        bool Evaluator();

    private:
        sf::FloatRect sprite1;
        sf::FloatRect sprite2;
};

#endif 
