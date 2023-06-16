//
// Created by Phoebe Mitchell on 16/06/2023.
//

#include "../headers/Time.h"

void Time::Tick() {
    previousTime = currentTime;
    currentTime = _clock.getElapsedTime().asSeconds();
}

float Time::GetCurrentTime() {
    return currentTime;
}

float Time::GetTimeDelta() {
    return currentTime - previousTime;
}
