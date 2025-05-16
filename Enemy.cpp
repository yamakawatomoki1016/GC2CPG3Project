#include "Enemy.h"

Enemy::Enemy() {
    currentState = &Enemy::Approach;
}

void Enemy::Update() {
    (this->*currentState)();
}

void Enemy::Approach() {
    std::cout << "敵が接近してきた！" << std::endl;
    currentState = &Enemy::Shoot;
}

void Enemy::Shoot() {
    std::cout << "敵が射撃を開始した！" << std::endl;
    currentState = &Enemy::Retreat;
}

void Enemy::Retreat() {
    std::cout << "敵が離脱した！" << std::endl;
    currentState = &Enemy::Approach;
}
