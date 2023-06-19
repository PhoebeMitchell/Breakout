//
// Created by Phoebe Mitchell on 19/06/2023.
//

#ifndef BREAKOUT_BALL_H
#define BREAKOUT_BALL_H

#include "box2d/box2d.h"
#include "../../Engine/headers/Object.h"

class Ball : public Object {
public:
    Ball(b2World *world);

    void Update(Time *time) override;
private:
};


#endif //BREAKOUT_BALL_H