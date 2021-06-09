#include "display.h"
#include "../input/keyboard.h"

sf::RenderWindow Display::m_window;

void Display::initialiseDisplay(unsigned int width, unsigned int height, std::string title) {
    m_window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
}

void Display::close() { m_window.close(); }

void Display::pollEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            close();
            break;

        case sf::Event::KeyPressed:
            Keyboard::onKeyPressed(event.key);
            break;

        case sf::Event::KeyReleased:
            Keyboard::onKeyReleased(event.key);
            break;
        }
    }
}

unsigned int Display::getWidth() { return m_window.getSize().x; }

unsigned int Display::getHeight() { return m_window.getSize().y; }

sf::RenderWindow &Display::getWindow() { return m_window; }