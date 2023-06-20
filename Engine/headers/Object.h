//
// Created by Phoebe Mitchell on 16/06/2023.
//

#ifndef BREAKOUT_OBJECT_H
#define BREAKOUT_OBJECT_H

#include <SFML/Graphics.hpp>
#include "box2d/box2d.h"
#include "Physics.h"
#include "Window.h"
#include "Body.h"

class Object : public b2ContactListener {
public:
    Object(float width, float height, sf::Color color);

    void DrawToWindow(Window *window);
    virtual void Update(Time *time) = 0;
    void SetOrigin(b2Vec2 origin);
    void SetPosition(b2Vec2 position);
    void AddBody(b2World *world, b2BodyType bodyType, float mass, b2ContactListener *contactListener);
    b2Vec2 GetPosition();
    Body *GetBody();
private:
    b2Vec2 _originOffset = {0, 0};
    std::unique_ptr<Body> _body;
    sf::RectangleShape _rectangleShape;
};


#endif //BREAKOUT_OBJECT_H