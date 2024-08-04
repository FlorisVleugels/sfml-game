#include "Collision.h"
#include <SFML/Graphics/Rect.hpp>

Collision::Collision(sf::FloatRect sprite1, sf::FloatRect sprite2) {
this -> sprite1 = sprite1;
this -> sprite2 = sprite2;
}

bool Collision::Evaluator() {
    return sprite1.intersects(sprite2);
}
