#include <SFML/Graphics.hpp>
#include "display/display.h"
#include "grid.h"
#include "input/keyboard.h"
#include "assets/assetLoader.h"

int main() {
    Display::initialiseDisplay(600, 600, "Conway's Game Of Life");

    AssetLoader::loadAssets();

    int generationSpeed = 60;

    sf::Clock clock;
    srand((unsigned)time(NULL));

    Grid grid(200, 0.8f);

    sf::Sprite sprite(grid.getTexture());

    sprite.setScale(Display::getWidth() / (float)grid.getImage().getSize().x, Display::getHeight() / (float)grid.getImage().getSize().y);

    sf::Text speedText(std::to_string(generationSpeed), AssetManager::getFont("arial"), 16);

    while (Display::getWindow().isOpen()) {
        Display::pollEvents();

        if (clock.getElapsedTime().asMilliseconds() >= (1000 / (float)generationSpeed)) {
            clock.restart();
            grid.update();
        }

        if (Keyboard::isKeyPressed(sf::Keyboard::R)) {
            grid.reset();
        }

        if (Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            generationSpeed -= 5;
            if (generationSpeed < 10)
                generationSpeed = 10;
            speedText.setString(std::to_string(generationSpeed));
        } else if (Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            generationSpeed += 5;
            speedText.setString(std::to_string(generationSpeed));
        }

        Display::getWindow().clear();

        Display::getWindow().draw(sprite);
        Display::getWindow().draw(speedText);

        Display::getWindow().display();
        Keyboard::resetInputManager();
    }
}