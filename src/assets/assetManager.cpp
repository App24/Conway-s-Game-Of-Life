#include "assetManager.h"

std::map<std::string, sf::Font> AssetManager::m_fonts;

void AssetManager::loadFont(std::string name, std::string path) {
    sf::Font font;

    if (font.loadFromFile(path))
        m_fonts[name] = font;
}

sf::Font &AssetManager::getFont(std::string name) { return m_fonts.at(name); }