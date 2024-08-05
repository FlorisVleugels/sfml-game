#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>

#define MAX_ITEMS 3

class MainMenu {

    public:
        MainMenu(float width, float height);
        ~MainMenu();
        void draw(sf::RenderWindow &window);
        void update();

    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text menu[MAX_ITEMS];
        sf::Text title;
        sf::FloatRect bounds[MAX_ITEMS+1];
};

#endif // !MAINMENU_H
