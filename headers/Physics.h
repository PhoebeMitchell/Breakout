//
// Created by Phoebe Mitchell on 16/06/2023.
//

#ifndef BREAKOUT_PHYSICS_H
#define BREAKOUT_PHYSICS_H

#include "box2d-lite/MathUtils.h"
#include "box2d-lite/World.h"
#include "Time.h"

class Physics {
public:
    Physics(Vec2 gravity);

    const static int PIXELS_PER_UNIT = 64;

    void AddBody(Body *body);
    void Step(Time *time);
private:
    World _world;
};


#endif //BREAKOUT_PHYSICS_H
