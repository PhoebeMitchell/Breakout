//
// Created by Phoebe Mitchell on 21/06/2023.
//

#ifndef BREAKOUT_BLOCK_H
#define BREAKOUT_BLOCK_H

#include "box2d/box2d.h"
#include "../../Engine/headers/Object.h"
#include "Constants.h"

class Block : public Object {
public:
    Block(b2World *world, sf::Color color);

    void Update(Time *time) override;
    void Destroy();

    static constexpr float WIDTH = 1;
    static constexpr float HEIGHT = .5f;
private:
};


#endif //BREAKOUT_BLOCK_H