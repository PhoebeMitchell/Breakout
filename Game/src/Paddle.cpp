//
// Created by Phoebe Mitchell on 16/06/2023.
//

#include "../headers/Paddle.h"
#include "../headers/Constants.h"
#include <iostream>

const sf::Color COLOR = sf::Color::White;

Paddle::Paddle(b2World *world) : Object(WIDTH, HEIGHT, COLOR) {
    AddBody(world, b2_kinematicBody, 1, this);
    SetPosition({Physics::PixelsToUnits(WINDOW_WIDTH / 2.0f), Physics::PixelsToUnits(WINDOW_HEIGHT) - 1});
    SetOrigin(ORIGIN);
}

void Paddle::Update(Time *time) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        GetBody()->SetVelocity({-SPEED, 0});
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        GetBody()->SetVelocity({SPEED, 0});
    } else {
        GetBody()->SetVelocity({0, 0});
    }
}
