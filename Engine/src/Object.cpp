//
// Created by Phoebe Mitchell on 16/06/2023.
//

#include <iostream>
#include "../headers/Object.h"

Object::Object(float width, float height, sf::Color color) {
    _rectangleShape.setSize(sf::Vector2f(width * Physics::PIXELS_PER_UNIT, height * Physics::PIXELS_PER_UNIT));
    _rectangleShape.setFillColor(color);
}

void Object::DrawToWindow(Window *window) {
    _rectangleShape.setPosition(_body->GetPosition().x * Physics::PIXELS_PER_UNIT, _body->GetPosition().y * Physics::PIXELS_PER_UNIT);
    window->Draw(&_rectangleShape);
}

void Object::SetOrigin(b2Vec2 origin) {
    auto rectangleShapeSize = _rectangleShape.getSize();
    _origin = {origin.x * Physics::PixelsToUnits(rectangleShapeSize.x), origin.y * Physics::PixelsToUnits(rectangleShapeSize.y)};
    _rectangleShape.setOrigin(origin.x, origin.y);
    SetPosition(_body->GetPosition());
}

void Object::SetPosition(b2Vec2 position) {
    _body->SetPosition(position - _origin);
}

void Object::AddBody(b2World *world, b2BodyType bodyType, float mass) {
    _body = std::make_unique<Body>(world, _rectangleShape.getSize().x, _rectangleShape.getSize().y, bodyType, mass);
}

b2Vec2 Object::GetPosition() {
    return _body->GetPosition() + _origin;
}

Body *Object::GetBody() {
    return _body.get();
}
