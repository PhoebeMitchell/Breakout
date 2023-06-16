//
// Created by Phoebe Mitchell on 16/06/2023.
//

#include "../headers/Physics.h"

const int PHYSICS_ITERATIONS = 60;

Physics::Physics(Vec2 gravity) : _world(gravity, PHYSICS_ITERATIONS) {

}

void Physics::AddBody(Body *body) {
    _world.Add(body);
}

void Physics::Step(Time *time) {
    _world.Step(time->GetTimeDelta());
}

float Physics::PixelsToUnits(float pixels) {
    return pixels / PIXELS_PER_UNIT;
}
