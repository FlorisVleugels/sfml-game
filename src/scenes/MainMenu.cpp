#include "MainMenu.h"
#include <SFML/Graphics/Rect.hpp>

MainMenu::MainMenu(float width, float height) {

    if (!font.loadFromFile("../resources/fonts/OptimusPrincepsSemiBold.ttf")) {
        // Handle loading error
    }

    menu[0].setFont(font);
    menu[0].setString("Play");
    bounds[0] = menu[0].getLocalBounds();
    menu[0].setOrigin(bounds[0].width / 2, bounds[0].height / 2 );
    menu[0].setPosition(sf::Vector2f(width / 2, height / 20 * 13 ));

    menu[1].setFont(font);
    menu[1].setString("Settings");
    bounds[1] = menu[1].getLocalBounds();
    menu[1].setOrigin(bounds[1].width / 2, bounds[1].height / 2 );
    menu[1].setPosition(sf::Vector2f(width / 2, height / 20 * 14.5 ));

    menu[2].setFont(font);
    menu[2].setString("Quit");
    bounds[2] = menu[2].getLocalBounds();
    menu[2].setOrigin(bounds[2].width / 2, bounds[2].height / 2 );
    menu[2].setPosition(sf::Vector2f(width / 2, height / 20 * 16 ));

    title.setFont(font);
    title.setCharacterSize(126);
    title.setString("Nameless Game");
    bounds[3] = title.getLocalBounds();
    title.setOrigin(bounds[3].width / 2, bounds[3].height / 2 );
    title.setPosition(sf::Vector2f(width / 2, height / 4 ));
}

MainMenu::~MainMenu() {
}

void MainMenu::draw(sf::RenderWindow &window) {

    for (int i = 0; i < MAX_ITEMS; i++) {
        window.draw(menu[i]);
    }
    window.draw(title);
}
