#include "grid.h"
#include <iostream>

Grid::Grid(int gridSize, float threashold) {
    m_gridSize = gridSize;
    m_threashold = threashold;
    m_gridArea = m_gridSize * m_gridSize;
    m_grid = new bool[m_gridArea];
    m_gridImage.create(m_gridSize, m_gridSize);
    m_gridTexture.loadFromImage(m_gridImage);
    reset();
}

void Grid::reset() {
    for (int i = 0; i < m_gridArea; i++) {
        m_grid[i] = (rand() % 100 + 1) / 100.f > m_threashold;
    }
}

void Grid::update() {
    bool *tempGrid = new bool[m_gridArea];
    std::copy(m_grid, m_grid + m_gridArea, tempGrid);

    for (int y = 0; y < m_gridSize; y++) {
        for (int x = 0; x < m_gridSize; x++) {
            int res = 0;

            int xx0 = x - 1;
            int yy0 = y - 1;
            int xx1 = x + 1;
            int yy1 = y + 1;

            if (x != 0)
                res += tempGrid[xx0 + m_gridSize * y] ? 1 : 0;

            if (y != 0)
                res += tempGrid[x + m_gridSize * yy0] ? 1 : 0;

            if (x != m_gridSize - 1)
                res += tempGrid[xx1 + m_gridSize * y] ? 1 : 0;

            if (y != m_gridSize - 1)
                res += tempGrid[x + m_gridSize * yy1] ? 1 : 0;

            if (x != 0 && y != 0)
                res += tempGrid[xx0 + m_gridSize * yy0] ? 1 : 0;

            if (x != m_gridSize - 1 && y != 0)
                res += tempGrid[xx1 + m_gridSize * yy0] ? 1 : 0;

            if (x != 0 && y != m_gridSize - 1)
                res += tempGrid[xx0 + m_gridSize * yy1] ? 1 : 0;

            if (x != m_gridSize - 1 && y != m_gridSize - 1)
                res += tempGrid[xx1 + m_gridSize * yy1] ? 1 : 0;

            if (!(tempGrid[x + m_gridSize * y] && (res == 3 || res == 2)))
                m_grid[x + m_gridSize * y] = false;
            if (!tempGrid[x + m_gridSize * y] && res == 3)
                m_grid[x + m_gridSize * y] = true;
        }
    }

    for (unsigned int x = 0; x < m_gridImage.getSize().x; x++) {
        for (unsigned int y = 0; y < m_gridImage.getSize().y; y++) {
            m_gridImage.setPixel(x, y, m_grid[y * m_gridImage.getSize().x + x] ? sf::Color::White : sf::Color::Black);
        }
    }
    m_gridTexture.update(m_gridImage);
}

sf::Texture &Grid::getTexture() { return m_gridTexture; }

sf::Image &Grid::getImage() { return m_gridImage; }