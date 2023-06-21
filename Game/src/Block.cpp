//
// Created by Phoebe Mitchell on 21/06/2023.
//

#include "../headers/Block.h"

Block::Block(b2World *world, sf::Color color) : Object(WIDTH, HEIGHT, color) {
    AddBody(world, b2_staticBody, 1, this);
    world->SetContactListener(this);
}

void Block::Update(Time *time) {

}
