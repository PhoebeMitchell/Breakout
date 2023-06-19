//
// Created by Phoebe Mitchell on 16/06/2023.
//

#ifndef BREAKOUT_PHYSICS_H
#define BREAKOUT_PHYSICS_H

#include "box2d/box2d.h"
#include "Time.h"

class Physics {
public:
    Physics(b2Vec2 gravity);

    const static int PIXELS_PER_UNIT = 64;

    void Step(Time *time);
    static float PixelsToUnits(float pixels);
    b2World *GetWorld();
private:
    b2World _world;
};


#endif //BREAKOUT_PHYSICS_H
