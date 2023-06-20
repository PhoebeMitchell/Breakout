//
// Created by Phoebe Mitchell on 16/06/2023.
//

#include "../headers/Physics.h"

Physics::Physics(b2Vec2 gravity) : _world(gravity) {

}

void Physics::Step(Time *time) {
    if (time->GetCurrentTime() >= previousStepTime + TIME_STEP) {
        previousStepTime = time->GetCurrentTime();
        _world.Step(time->GetTimeDelta(), 6, 2);
    }
}

float Physics::PixelsToUnits(float pixels) {
    return pixels / PIXELS_PER_UNIT;
}

b2World *Physics::GetWorld() {
    return &_world;
}
