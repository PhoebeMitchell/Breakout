//
// Created by Phoebe Mitchell on 19/06/2023.
//

#ifndef BREAKOUT_BODY_H
#define BREAKOUT_BODY_H

#include "box2d/box2d.h"

class Body {
public:
    Body(b2World *world, float width, float height, b2BodyType bodyType, float mass, b2ContactListener *contactListener);

    void SetPosition(b2Vec2 vec2);
    b2Vec2 GetPosition();
    b2Vec2 GetVelocity();
    void SetVelocity(b2Vec2 velocity);
    b2Vec2 GetDimensions();
    void Destroy();
private:
    b2World *_world;
    float _width;
    float _height;
    b2BodyDef _bodyDef;
    b2Body *_body;
    b2PolygonShape _shape;
};


#endif //BREAKOUT_BODY_H