//
// Created by Phoebe Mitchell on 19/06/2023.
//

#include "../headers/Ball.h"
#include "../headers/Constants.h"
#include "../headers/Paddle.h"
#include <iostream>

const float RADIUS = 0.2f;
const sf::Color COLOR = sf::Color::White;
const b2Vec2 INITIAL_VELOCITY = {0.1, 1};
const float SPEED = 3;

Ball::Ball(b2World *world) : Object(RADIUS, RADIUS, COLOR) {
    AddBody(world, b2_dynamicBody, 1, this);
    world->SetContactListener(this);
    SetPosition({Physics::PixelsToUnits(WINDOW_WIDTH / 2), Physics::PixelsToUnits(WINDOW_HEIGHT / 2)});
    auto velocity = INITIAL_VELOCITY;
    velocity.Normalize();
    GetBody()->SetVelocity({velocity.x * SPEED, velocity.y * SPEED});
}

void Ball::Update(Time *time) {

}

void Ball::BeginContact(b2Contact *contact) {
    auto userData = contact->GetFixtureA()->GetBody()->GetUserData();
    auto contactListener = reinterpret_cast<b2ContactListener*>(userData.pointer);
    auto paddle = dynamic_cast<Paddle*>(contactListener);
    std::cout << "b";
    if (paddle != nullptr) {
        auto velocity = GetBody()->GetVelocity();
        GetBody()->SetVelocity({velocity.x, -velocity.y});
        std::cout << "a";
        return;
    }
    auto block = dynamic_cast<Paddle*>(contactListener);
    if (block != nullptr) {
        auto velocity = GetBody()->GetVelocity();
        GetBody()->SetVelocity({velocity.x, -velocity.y});
        return;
    }
}
