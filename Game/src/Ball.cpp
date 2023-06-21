//
// Created by Phoebe Mitchell on 19/06/2023.
//

#include "../headers/Ball.h"
#include "../headers/Constants.h"
#include "../headers/Paddle.h"
#include "../headers/Block.h"
#include <cmath>
#include <iostream>

const float RADIUS = 0.2f;
const sf::Color COLOR = sf::Color::White;
const b2Vec2 INITIAL_VELOCITY = {0.1, -1};
const float SPEED = 3;
const float PI = 3.141592653589793238;

Ball::Ball(b2World *world) : Object(RADIUS, RADIUS, COLOR) {
    AddBody(world, b2_dynamicBody, 1, this);
    world->SetContactListener(this);
    SetPosition({Physics::PixelsToUnits(WINDOW_WIDTH / 2), Physics::PixelsToUnits(WINDOW_HEIGHT / 2) + 2});
    auto velocity = INITIAL_VELOCITY;
    velocity.Normalize();
    GetBody()->SetVelocity({velocity.x * SPEED, velocity.y * SPEED});
}

void Ball::Update(Time *time) {
    Object::Update(time);
}

void Ball::BeginContact(b2Contact *contact) {
    auto userData = contact->GetFixtureB()->GetBody()->GetUserData();
    auto contactListener = reinterpret_cast<b2ContactListener*>(userData.pointer);
    auto paddle = dynamic_cast<Paddle*>(contactListener);
    if (paddle != nullptr) {
        float bounceAngle = paddle->CalculateBounceAngle(GetPosition().x);
        b2Vec2 velocity = {0, -1 * SPEED};
        auto sinValue = sin(bounceAngle * (PI/180));
        auto cosValue = cos(bounceAngle * (PI/180));
        velocity = {cosValue * velocity.x - sinValue * velocity.y, sinValue * velocity.x + cosValue * velocity.y};
        GetBody()->SetVelocity(velocity);
        return;
    }

    auto block = dynamic_cast<Block*>(contactListener);
    if (block != nullptr) {
        auto velocity = GetBody()->GetVelocity();
        GetBody()->SetVelocity({velocity.x, -velocity.y});
        block->Destroy();
        return;
    }
}
