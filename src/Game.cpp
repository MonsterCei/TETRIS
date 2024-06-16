//GAME.CPP
#include "Game.h"
#include <SFML/System/Clock.hpp>

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game() : window(sf::VideoMode(450, 600), "Tetris"), board() {}
//Czas "Świata gry"
void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (window.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update();
        }
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        board.handleInput(event);
    }
}
//Wyświetlanie i aktualizowanie planszy
void Game::update() {
    board.update();
}

void Game::render() {
    window.clear();
    board.draw(window);
    window.display();
}