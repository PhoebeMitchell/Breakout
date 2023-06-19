//
// Created by Phoebe Mitchell on 16/06/2023.
//

#ifndef BREAKOUT_GAME_H
#define BREAKOUT_GAME_H


#include <string>
#include "Window.h"
#include "Physics.h"
#include "Object.h"

class Game {
public:
    Game(int windowWidth, int windowHeight, std::string windowName);
    void Run();
    void AddObject(Object *object);
    Physics *GetPhysics();
private:
    Physics _physics;
    Window _window;
    std::vector<Object*> _objects;
};


#endif //BREAKOUT_GAME_H