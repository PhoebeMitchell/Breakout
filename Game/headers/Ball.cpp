//
// Created by Phoebe Mitchell on 19/06/2023.
//

#include "Ball.h"
#include "Constants.h"

const float RADIUS = 0.2f;
const sf::Color COLOR = sf::Color::White;
const b2Vec2 INITIAL_VELOCITY = {0.25, 1};
const float SPEED = 3;

Ball::Ball(b2World *world) : Object(RADIUS, RADIUS, COLOR) {
    AddBody(world, b2_dynamicBody, 1);
    SetPosition({Physics::PixelsToUnits(WINDOW_WIDTH / 2), Physics::PixelsToUnits(WINDOW_HEIGHT / 2)});
    auto velocity = INITIAL_VELOCITY;
    velocity.Normalize();
    GetBody()->SetVelocity({velocity.x * SPEED, velocity.y * SPEED});
}

void Ball::Update(Time *time) {

}
