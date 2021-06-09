#include "keyboard.h"

#include <iostream>

bool Keyboard::keysHeld[sf::Keyboard::KeyCount];
bool Keyboard::keysPressed[sf::Keyboard::KeyCount];
bool Keyboard::keysPressedThisFrame[sf::Keyboard::KeyCount];

bool Keyboard::altHeld;
bool Keyboard::ctrlHeld;
bool Keyboard::shiftHeld;

void Keyboard::resetInputManager() {
    for (auto &key : keysPressedThisFrame) {
        key = false;
    }
}

bool Keyboard::isKeyHeld(sf::Keyboard::Key key) { return keysHeld[key]; }

bool Keyboard::isKeyPressed(sf::Keyboard::Key key) {
    if (keysPressedThisFrame[key])
        return true;
    if (keysHeld[key] && !keysPressed[key]) {
        keysPressed[key] = true;
        keysPressedThisFrame[true] = true;
        return true;
    } else if (!keysHeld[key]) {
        keysPressed[key] = false;
    }
    return false;
}

bool Keyboard::isAltHeld() { return altHeld; }

bool Keyboard::isControlHeld() { return ctrlHeld; }

bool Keyboard::isShiftHeld() { return shiftHeld; }

void Keyboard::onKeyPressed(sf::Event::KeyEvent &event) {
    if (event.code < 0 || event.code > sf::Keyboard::KeyCount)
        return;
    keysHeld[event.code] = true;
    altHeld = event.alt;
    ctrlHeld = event.control;
    shiftHeld = event.shift;
}

void Keyboard::onKeyReleased(sf::Event::KeyEvent &event) {
    if (event.code < 0 || event.code > sf::Keyboard::KeyCount)
        return;
    keysHeld[event.code] = false;
    altHeld = event.alt;
    ctrlHeld = event.control;
    shiftHeld = event.shift;
}