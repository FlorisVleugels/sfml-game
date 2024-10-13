#include "PauseMenu.h"
#include <SFML/Graphics/Color.hpp>
#include <iostream>

PauseMenu::PauseMenu(float width, float height) {

    if (!font.loadFromFile("../resources/fonts/OptimusPrincepsSemiBold.ttf")) {
        // Handle loading error
    }

    menu[0].setFont(font);
    menu[0].setString("Continue");
    bounds[0] = menu[0].getLocalBounds();
    menu[0].setOrigin(bounds[0].width / 2, bounds[0].height / 2 );
    menu[0].setPosition(sf::Vector2f(width / 2, height / 20 * 8.5 ));
    menu[0].setFillColor(sf::Color::Red);

    menu[1].setFont(font);
    menu[1].setString("Settings");
    bounds[1] = menu[1].getLocalBounds();
    menu[1].setOrigin(bounds[1].width / 2, bounds[1].height / 2 );
    menu[1].setPosition(sf::Vector2f(width / 2, height / 20 * 10 ));

    menu[2].setFont(font);
    menu[2].setString("Quit");
    bounds[2] = menu[2].getLocalBounds();
    menu[2].setOrigin(bounds[2].width / 2, bounds[2].height / 2 );
    menu[2].setPosition(sf::Vector2f(width / 2, height / 20 * 11.5 ));

    selectedItemIndex = 0;
    isReleased = true;

    background.setSize(sf::Vector2f(width, height));
    background.setFillColor(sf::Color(0, 0, 0, 200));
}

PauseMenu::~PauseMenu() {
}

void PauseMenu::update(sf::RenderWindow &window, bool *isPaused) {

    // TODO: Why MAX_ITEMS -1? Seems somoething wrong
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && selectedItemIndex < MAX_ITEMS - 1 && isReleased) {
        selectedItemIndex++; 
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
        menu[selectedItemIndex - 1].setFillColor(sf::Color::White);
        isReleased = false;
    } 

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && selectedItemIndex > 0 && isReleased) {
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
        menu[selectedItemIndex + 1].setFillColor(sf::Color::White);
        isReleased = false;
    }

    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        isReleased = true;  
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        if (selectedItemIndex == 0) {
            std::cout << "Continue Playing" << "\n";
            *isPaused = false;
        } else if (selectedItemIndex == 1) {
            std::cout << "Opening the options menu" << "\n";
            std::cout << "settings option location" << menu[1].getPosition().x << menu[1].getPosition().y << "\n";
        } else if (selectedItemIndex == 2) {
            window.close();
        }
    }
}

void PauseMenu::draw(sf::RenderWindow &window) {

    window.draw(background);

    for (int i = 0; i < MAX_ITEMS; i++) {
        window.draw(menu[i]);
    }
}

