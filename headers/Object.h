//
// Created by Phoebe Mitchell on 16/06/2023.
//

#ifndef BREAKOUT_OBJECT_H
#define BREAKOUT_OBJECT_H

#include <SFML/Graphics.hpp>
#include "box2d-lite/Body.h"
#include "../headers/Physics.h"
#include "Window.h"

class Object {
public:
    Object(float width, float height, sf::Color color);

    void DrawToWindow(Window *window);
    void AddToPhysicsWorld(Physics *physics);
private:
    Body _body;
    sf::RectangleShape _rectangleShape;
};


#endif //BREAKOUT_OBJECT_H