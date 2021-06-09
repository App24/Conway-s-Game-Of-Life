#pragma once

#include <SFML/Graphics.hpp>

class Display {
public:
    static void initialiseDisplay(unsigned int width, unsigned int height, std::string title);

    static void close();

    static void pollEvents();

    static sf::RenderWindow &getWindow();

    static unsigned int getWidth();
    static unsigned int getHeight();

private:
    static sf::RenderWindow m_window;
};