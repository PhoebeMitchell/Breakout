//
// Created by Phoebe Mitchell on 16/06/2023.
//

#ifndef BREAKOUT_PADDLE_H
#define BREAKOUT_PADDLE_H


#include "../../Engine/headers/Object.h"

class Paddle : public Object {
public:
    Paddle(b2World *world);

    void Update(Time *time) override;
private:
    const float SPEED = 5;
    static constexpr float WIDTH = 2;
    static constexpr float HEIGHT = 0.4f;
    const b2Vec2 ORIGIN = {0.5, 1};
};


#endif //BREAKOUT_PADDLE_H