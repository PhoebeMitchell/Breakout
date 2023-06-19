//
// Created by Phoebe Mitchell on 19/06/2023.
//

#include "../headers/Body.h"
#include <iostream>

Body::Body(b2World *world, float width, float height, b2BodyType bodyType, float mass) {
    _bodyDef.type = bodyType;
    _body = world->CreateBody(&_bodyDef);
    _shape.SetAsBox(width / 2, height / 2);
    b2FixtureDef fixtureDef;
    fixtureDef.density = mass / (width * height);
    fixtureDef.friction = 0;
    fixtureDef.shape = &_shape;
    _body->CreateFixture(&fixtureDef);
}

void Body::SetPosition(b2Vec2 vec2) {
    _body->SetTransform(vec2, _body->GetAngle());
}

b2Vec2 Body::GetPosition() {
    return _body->GetPosition();
}

b2Vec2 Body::GetVelocity() {
    return _body->GetLinearVelocity();
}

void Body::SetVelocity(b2Vec2 velocity) {
    _body->SetLinearVelocity(velocity);
}
