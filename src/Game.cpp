//
// Created by Phoebe Mitchell on 16/06/2023.
//

#include "../headers/Game.h"
#include "../headers/Time.h"

const int GRAVITY = 10;

Game::Game(int windowWidth, int windowHeight, std::string windowName) : _window(windowWidth, windowHeight, windowName), _physics({0, GRAVITY}) {

}

void Game::AddObject(Object *object) {
    _objects.push_back(object);
    object->AddToPhysicsWorld(&_physics);
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
        }
        _window.Display();
    }
}
