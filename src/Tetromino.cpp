#include "Tetromino.h"
#include <cstdlib>
#include <ctime>

const std::vector<std::vector<sf::Vector2i>> Tetromino::tetrominoShapes = {
        {{0, 0}, {1, 0}, {0, 1}, {1, 1}},       // O-shape
        {{0, 0}, {1, 0}, {2, 0}, {3, 0}},       // I-shape
        {{0, 0}, {-1, 0}, {0, -1}, {1, -1}},    // S-shape
        {{0, 0}, {-1, 0}, {0, 1}, {1, 1}},      // Z-shape
        {{0, 0}, {-1, 0}, {0, 1}, {0, -1}},     // T-shape
        {{0, 0}, {-1, 0}, {1, 0}, {1, -1}},     // L-shape
        {{0, 0}, {1, 0}, {-1, 0}, {-1, -1}}     // J-shape
};

Tetromino Tetromino::getRandomTetromino() {
    //Losowanie kolejnych bloków z pomocą srnand
    srand(static_cast<unsigned>(time(nullptr)));
    int shapeIndex = rand() % tetrominoShapes.size();
    return Tetromino(tetrominoShapes[shapeIndex]);
}

std::vector<sf::Vector2i> Tetromino::getRotatedBlocks() const {
    std::vector<sf::Vector2i> rotated;
    for (const auto &block : blocks) {
//Obracanie bloków w obie strony z pomocą funkcji for
        rotated.push_back(sf::Vector2i(-block.y, block.x));
    }
    return rotated;
}