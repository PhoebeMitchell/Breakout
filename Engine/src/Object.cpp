//
// Created by Phoebe Mitchell on 16/06/2023.
//

#include <iostream>
#include "../headers/Object.h"

Object::Object(float width, float height, sf::Color color) {
    _rectangleShape.setSize(sf::Vector2f(width * Physics::PIXELS_PER_UNIT, height * Physics::PIXELS_PER_UNIT));
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

Body *Object::GetBody() {
    return &_body;
}

void Object::SetOrigin(Vec2 origin) {
    auto rectangleShapeSize = _rectangleShape.getSize();
    _origin = {origin.x * Physics::PixelsToUnits(rectangleShapeSize.x), origin.y * Physics::PixelsToUnits(rectangleShapeSize.y)};
    _rectangleShape.setOrigin(_origin.x, origin.y);
    SetPosition(_body.position);
}

void Object::SetPosition(Vec2 position) {
    _body.position = position - _origin;
}

Vec2 Object::GetPosition() {
    return _body.position + _origin;
}
