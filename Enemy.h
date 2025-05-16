#pragma once
#include <iostream>

class Enemy {
public:
    Enemy();
    void Update();

private:
    typedef void (Enemy::* StateFunc)();
    StateFunc currentState;

    void Approach();
    void Shoot();
    void Retreat();
};
