//
// Created by Phoebe Mitchell on 16/06/2023.
//

#include "../headers/Object.h"

Object::Object(float width, float height, sf::Color color) {
    _rectangleShape.setSize(sf::Vector2f(width, height));
    _rectangleShape.setFillColor(color);
    _body.Set({width / Physics::PIXELS_PER_UNIT, height / Physics::PIXELS_PER_UNIT}, 1);
}

void Object::AddToPhysicsWorld(Physics *physics) {
    physics->AddBody(&_body);
}

void Object::DrawToWindow(Window *window) {
    _rectangleShape.setPosition(_body.position.x * Physics::PIXELS_PER_UNIT, _body.position.y * Physics::PIXELS_PER_UNIT);
    window->Draw(&_rectangleShape);
}
