//
// Created by Phoebe Mitchell on 16/06/2023.
//

#ifndef BREAKOUT_TIME_H
#define BREAKOUT_TIME_H


#include <SFML/System/Clock.hpp>

class Time {
public:
    void Tick();
    float GetCurrentTime();
    float GetTimeDelta();
private:
    float previousTime = 0;
    float currentTime = 0;
    sf::Clock _clock;
};


#endif //BREAKOUT_TIME_H