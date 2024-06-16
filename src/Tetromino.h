//TETROMINO.H
#ifndef TETROMINO_H
#define TETROMINO_H

#include <vector>
#include <SFML/System/Vector2.hpp>

class Tetromino {
public: //ustawienie jako publiczne elementy klasy kształty Tetrisa wraz z funkcją obracania
    std::vector<sf::Vector2i> blocks;

    Tetromino(std::vector<sf::Vector2i> b) : blocks(std::move(b)) {}

    static Tetromino getRandomTetromino();
    std::vector<sf::Vector2i> getRotatedBlocks() const;

private:
//Ustawienie jako prywatnego elementu funkcji układanie kwadratów w konkretne kształty

    static const std::vector<std::vector<sf::Vector2i>> tetrominoShapes;
};

#endif