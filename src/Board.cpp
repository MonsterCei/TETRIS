//BOARD.CPP
#include "Board.h"
#include <algorithm>

Board::Board() : grid(BoardHeight, std::vector<int>(BoardWidth, 0)), currentPiece(), score(0) {
    block.setSize(sf::Vector2f(BlockSize - 1, BlockSize - 1));

    // Ładowanie czcionki

    if (!font.loadFromFile("C:/Users/Samue/CLionProjects/TetrisV2/src/ds_digital/DS-DIGI.TTF")) {
        // Obsługa błędu ładowania czcionki
    }
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Green);
    scoreText.setPosition(BoardWidth * BlockSize + 20, 20);
    updateScoreText();
}

void Board::handleInput(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::A) {
            currentPiece.moveLeft(grid);
        } else if (event.key.code == sf::Keyboard::D) {
            currentPiece.moveRight(grid);
        } else if (event.key.code == sf::Keyboard::S) {
            currentPiece.moveDown(grid);
        } else if (event.key.code == sf::Keyboard::W) {
            currentPiece.rotate(grid);
        }
    }
}

void Board::update() {
    currentPiece.update(grid);
    checkLines();
}

void Board::draw(sf::RenderWindow &window) {
    for (int y = 0; y < BoardHeight; ++y) {
        for (int x = 0; x < BoardWidth; ++x) {
            if (grid[y][x] != 0) {
                block.setPosition(x * BlockSize, y * BlockSize);
                block.setFillColor(sf::Color::Green);
                window.draw(block);
            }
        }
    }

    currentPiece.draw(window, BlockSize);

    // Rysowanie wyniku
    window.draw(scoreText);
}

void Board::checkLines() {
    int linesCleared = 0;
    for (int y = BoardHeight - 1; y >= 0; --y) {
        bool lineFull = true;
        for (int x = 0; x < BoardWidth; ++x) {
            if (grid[y][x] == 0) {
                lineFull = false;
                break;
            }
        }
        if (lineFull) {
            // Usuń pełny rząd i przesuń wszystkie powyżej go w dół
            for (int yy = y; yy > 0; --yy) {
                for (int x = 0; x < BoardWidth; ++x) {
                    grid[yy][x] = grid[yy - 1][x];
                }
            }
            // Wyczyść górny rząd
            for (int x = 0; x < BoardWidth; ++x) {
                grid[0][x] = 0;
            }
            ++linesCleared;
        }
    }
    if (linesCleared > 0) {
        increaseScore(linesCleared);
    }
}

void Board::increaseScore(int linesCleared) {
    score += linesCleared * 20;
    updateScoreText();
}

void Board::updateScoreText() {
    scoreText.setString("Score: " + std::to_string(score));
}


