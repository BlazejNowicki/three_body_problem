#include "engine.h"
#include <math.h>
#include <iostream>

Engine::Engine(std::vector <Vector> position,
               std::vector <Vector> velocity,
               std::vector<float> mass,
               float G,
               float delta,
               int steps_per_frame
) : position(position), velocity(velocity), mass(mass) {
    this->G = G;
    this->delta = delta;
    this->steps_per_frame = steps_per_frame;
    std::cout << G << delta << steps_per_frame<< std::endl;
}


Engine::~Engine() {}

Vector Engine::F(int i) {
    Vector result = {0, 0};
    for (int j = (i + 1) % 3; i != j; j = (j + 1) % 3) {
        float common = G * mass[j] /
                       pow(pow(position[i].x - position[j].x, 2) + pow(position[i].y - position[j].y, 2), 3.0 / 2.0);
        result.x += common * (position[j].x - position[i].x);
        result.y += common * (position[j].y - position[i].y);
    }
    return result;
}

void Engine::calculateStep() {
    for (int i = 0; i < 3; i++) {
        position[i].x = position[i].x + velocity[i].x * delta;
        position[i].y = position[i].y + velocity[i].y * delta;
    }

    for (int i = 0; i < 3; i++) {
        Vector a = F(i);
        velocity[i].x = velocity[i].x + a.x * delta;
        velocity[i].y = velocity[i].y + a.y * delta;
    }
}

void Engine::updateCoordinates() {
    for (int i = 0; i < steps_per_frame; i++) {
        calculateStep();
    }

}

Vector Engine::getCoordinates(int id) {
    return position[id];
}