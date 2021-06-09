#pragma once
#include <map>
#include <SFML/Graphics.hpp>

class AssetManager {
public:
    static void loadFont(std::string name, std::string path);

    static sf::Font &getFont(std::string name);

private:
    static std::map<std::string, sf::Font> m_fonts;
};