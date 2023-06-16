//
// Created by Phoebe Mitchell on 16/06/2023.
//

#ifndef BREAKOUT_OBJECT_H
#define BREAKOUT_OBJECT_H

#include <SFML/Graphics.hpp>
#include "box2d-lite/Body.h"
#include "Physics.h"
#include "Window.h"

class Object {
public:
    Object(float width, float height, sf::Color color);

    void DrawToWindow(Window *window);
    virtual void Update(Time *time) = 0;
    void AddToPhysicsWorld(Physics *physics);
    void SetOrigin(Vec2 origin);
    void SetPosition(Vec2 position);
    Vec2 GetPosition();
protected:
    Body *GetBody();
private:
    Body _body;
    Vec2 _origin;
    sf::RectangleShape _rectangleShape;
};


#endif //BREAKOUT_OBJECT_H