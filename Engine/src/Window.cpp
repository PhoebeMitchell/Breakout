//
// Created by Phoebe Mitchell on 16/06/2023.
//

#include "../headers/Window.h"

Window::Window(int width, int height, std::string name) : _renderWindow(sf::VideoMode(width, height), name){

}

void Window::Clear() {
    _renderWindow.clear();
}

void Window::PollEvents() {
    sf::Event event;
    while (_renderWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                _renderWindow.close();
                break;
        }
    }
}

bool Window::IsOpen() {
    return _renderWindow.isOpen();
}

void Window::Draw(sf::Drawable *drawable) {
    _renderWindow.draw(*drawable);
}

void Window::Display() {
    _renderWindow.display();
}
