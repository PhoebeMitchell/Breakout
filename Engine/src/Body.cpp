//
// Created by Phoebe Mitchell on 19/06/2023.
//

#include "../headers/Body.h"
#include <iostream>

Body::Body(b2World *world, float width, float height, b2BodyType bodyType, float mass, b2ContactListener *contactListener) {
    _world = world;
    _bodyDef.type = bodyType;
    _bodyDef.bullet = true;
    _bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(contactListener);
    _body = world->CreateBody(&_bodyDef);
    _shape.SetAsBox(width / 2, height / 2);
    b2FixtureDef fixtureDef;
    fixtureDef.density = mass / (width * height);
    fixtureDef.friction = 0;
    fixtureDef.shape = &_shape;
    fixtureDef.restitution = 1;
    _body->CreateFixture(&fixtureDef);
    _width = width;
    _height = height;
}

b2Vec2 Body::GetDimensions() {
    return {_width, _height};
}

void Body::SetPosition(b2Vec2 vec2) {
    _body->SetTransform(vec2 + b2Vec2(_width / 2, _height / 2), _body->GetAngle());
}

b2Vec2 Body::GetPosition() {
    return _body->GetPosition() - b2Vec2(_width / 2, _height / 2);
}

b2Vec2 Body::GetVelocity() {
    return _body->GetLinearVelocity();
}

void Body::SetVelocity(b2Vec2 velocity) {
    _body->SetLinearVelocity(velocity);
}

void Body::Destroy() {
    _world->DestroyBody(_body);
}
