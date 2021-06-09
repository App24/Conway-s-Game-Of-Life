#pragma once

#include <SFML/Window.hpp>

class Keyboard {
public:
    static void resetInputManager();

    static bool isKeyHeld(sf::Keyboard::Key key);
    static bool isKeyPressed(sf::Keyboard::Key key);

    static void onKeyPressed(sf::Event::KeyEvent &event);
    static void onKeyReleased(sf::Event::KeyEvent &event);

    static bool isAltHeld();
    static bool isControlHeld();
    static bool isShiftHeld();

private:
    static bool keysHeld[sf::Keyboard::KeyCount];
    static bool keysPressed[sf::Keyboard::KeyCount];
    static bool keysPressedThisFrame[sf::Keyboard::KeyCount];

    static bool altHeld;
    static bool ctrlHeld;
    static bool shiftHeld;
};