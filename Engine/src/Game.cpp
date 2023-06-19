//
// Created by Phoebe Mitchell on 16/06/2023.
//

#include "../headers/Game.h"

const int GRAVITY = 0;

Game::Game(int windowWidth, int windowHeight, std::string windowName) : _window(windowWidth, windowHeight, windowName), _physics({0, GRAVITY}) {

}

Physics *Game::GetPhysics() {
    return &_physics;
}

void Game::AddObject(Object *object) {
    _objects.push_back(object);
}

void Game::Run() {
    Time time;
    while (_window.IsOpen()) {
        time.Tick();
        _window.Clear();
        _window.PollEvents();
        _physics.Step(&time);
        for (auto object : _objects) {
            object->DrawToWindow(&_window);
            object->Update(&time);
        }
        _window.Display();
    }
}
