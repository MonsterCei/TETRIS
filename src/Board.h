//BOARD.H
#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "Piece.h"

class Board {
public:
    Board();
    void handleInput(sf::Event event);
    void update();
    void draw(sf::RenderWindow &window);
//Ustawienie jako prywatnego elementu klasy rozmiaru i kształtu planszy
private:
    static const int BoardWidth = 10;
    static const int BoardHeight = 20;
    static const int BlockSize = 30;
    std::vector<std::vector<int>> grid;
    Piece currentPiece;
    sf::RectangleShape block;

    int score;
    sf::Font font;
    sf::Text scoreText;

    void checkLines();
    void increaseScore(int linesCleared);
    void updateScoreText();
};

#endif