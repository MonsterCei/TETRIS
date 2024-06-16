#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tetromino.h"

class Piece {
public:
    Piece();
    void moveLeft(const std::vector<std::vector<int>> &grid);
    void moveRight(const std::vector<std::vector<int>> &grid);
    void moveDown(std::vector<std::vector<int>> &grid);
    void rotate(const std::vector<std::vector<int>> &grid);
    void update(std::vector<std::vector<int>> &grid);
    void draw(sf::RenderWindow &window, int blockSize);

private:
    Tetromino tetromino;
    sf::Vector2i position;
    sf::Clock clock;
    sf::Time fallTime;

    bool checkCollision(const std::vector<std::vector<int>> &grid, sf::Vector2i newPosition, const std::vector<sf::Vector2i> &newBlocks) const;
    void placeOnGrid(std::vector<std::vector<int>> &grid);
};

#endif
