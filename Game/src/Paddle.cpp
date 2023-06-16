//
// Created by Phoebe Mitchell on 16/06/2023.
//

#include "../headers/Paddle.h"
#include "../headers/Constants.h"

const sf::Color COLOR = sf::Color::White;

Paddle::Paddle() : Object(WIDTH, HEIGHT, COLOR) {
    SetPosition({Physics::PixelsToUnits(WINDOW_WIDTH / 2.0f), Physics::PixelsToUnits(WINDOW_HEIGHT)});
    SetOrigin(ORIGIN);
}

void Paddle::Update(Time *time) {
    GetBody()->velocity = {0, 0};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        GetBody()->velocity = {-SPEED, 0};
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        GetBody()->velocity = {SPEED, 0};
    }
}