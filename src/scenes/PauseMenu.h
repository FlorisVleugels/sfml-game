#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <SFML/Graphics.hpp>

#define MAX_ITEMS 3

class PauseMenu {

    public:
        PauseMenu(float width, float height);
        ~PauseMenu();
        void draw(sf::RenderWindow &window);
        void update(sf::RenderWindow &window, bool *isPaused);

    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text menu[MAX_ITEMS];
        sf::FloatRect bounds[MAX_ITEMS+1];
        bool isReleased;
        sf::RectangleShape background;
};

#endif // !PAUSEMENU_H
