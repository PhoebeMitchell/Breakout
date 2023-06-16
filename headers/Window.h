//
// Created by Phoebe Mitchell on 16/06/2023.
//

#ifndef BREAKOUT_WINDOW_H
#define BREAKOUT_WINDOW_H

#include "SFML/Graphics.hpp"

class Window {
public:
    Window(int width, int height, std::string name);

    void Clear();
    void PollEvents();
    void Draw(sf::Drawable *drawable);
    void Display();
    bool IsOpen();
private:
    sf::RenderWindow _renderWindow;
};


#endif //BREAKOUT_WINDOW_H