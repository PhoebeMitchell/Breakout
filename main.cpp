#include <iostream>
#include "headers/Game.h"

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
const std::string WINDOW_NAME = "Breakout";

int main() {
    Game game(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);

    Object object(50, 50, sf::Color::White);
    game.AddObject(&object);

    game.Run();
}
