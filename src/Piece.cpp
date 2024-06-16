//PIECE.CPP
#include "Piece.h"

Piece::Piece() : position(4, 0), fallTime(sf::seconds(1.f)), tetromino(Tetromino::getRandomTetromino()) {}
//System obracania elementów
void Piece::moveLeft(const std::vector<std::vector<int>> &grid) {
    sf::Vector2i newPosition = position + sf::Vector2i(-1, 0);
    if (!checkCollision(grid, newPosition, tetromino.blocks)) {
        position = newPosition;
    }
}

void Piece::moveRight(const std::vector<std::vector<int>> &grid) {
    sf::Vector2i newPosition = position + sf::Vector2i(1, 0);
    if (!checkCollision(grid, newPosition, tetromino.blocks)) {
        position = newPosition;
    }
}

void Piece::moveDown(std::vector<std::vector<int>> &grid) {
    sf::Vector2i newPosition = position + sf::Vector2i(0, 1);
    if (checkCollision(grid, newPosition, tetromino.blocks)) {
        placeOnGrid(grid);
        position = sf::Vector2i(4, 0);
        tetromino = Tetromino::getRandomTetromino();
    } else {
        position = newPosition;
    }
}

void Piece::rotate(const std::vector<std::vector<int>> &grid) {
    std::vector<sf::Vector2i> newBlocks = tetromino.getRotatedBlocks();
    if (!checkCollision(grid, position, newBlocks)) {
        tetromino.blocks = newBlocks;
    }
}

void Piece::update(std::vector<std::vector<int>> &grid) {
    if (clock.getElapsedTime() >= fallTime) {
        moveDown(grid);
        clock.restart();
    }
}

void Piece::draw(sf::RenderWindow &window, int blockSize) {
    sf::RectangleShape block(sf::Vector2f(blockSize - 1, blockSize - 1));
    block.setFillColor(sf::Color::White);
    for (const auto &b : tetromino.blocks) {
        block.setPosition((position.x + b.x) * blockSize, (position.y + b.y) * blockSize);
        window.draw(block);
    }
}
//Kolizje pomiędzy blokami oraz granicami mapy
bool Piece::checkCollision(const std::vector<std::vector<int>> &grid, sf::Vector2i newPosition, const std::vector<sf::Vector2i> &newBlocks) const {
    for (const auto &b : newBlocks) {
        int x = newPosition.x + b.x;
        int y = newPosition.y + b.y;
        if (x < 0 || x >= 10 || y < 0 || y >= 20 || grid[y][x] != 0) {
            return true;
        }
    }
    return false;
}

void Piece::placeOnGrid(std::vector<std::vector<int>> &grid) {
    for (const auto &b : tetromino.blocks) {
        grid[position.y + b.y][position.x + b.x] = 1;
    }
}

