#pragma once

#include <SFML/Graphics.hpp>

class Grid {
public:
    Grid(int gridSize, float threashold);

    void update();

    void reset();

    sf::Texture &getTexture();
    sf::Image &getImage();

private:
    sf::Image m_gridImage;
    sf::Texture m_gridTexture;
    float m_threashold;
    int m_gridSize;
    int m_gridArea;
    bool *m_grid;
};