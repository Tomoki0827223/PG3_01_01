#include "Enemy.h"


void (Enemy::* Enemy::functionTable[])() = {
    &Enemy::Getcloser,
    &Enemy::separation
};

Enemy::Enemy() : Phase(0) {}

void Enemy::Update() {

    // 現在のフェーズの関数を実行
    (this->*functionTable[Phase])();

    // 行列の更新 (例: デバッグ表示)
    std::cout << "Updating matrices..." << std::endl;

    // デバッグ用の表示
    std::cout << "Current phase: " << Phase << std::endl;

    // フェーズ遷移 (次のフェーズに進む)
    Phase = (Phase + 1) % 2;
}

void Enemy::Getcloser() {
    std::cout << "Enemy is approaching." << std::endl;
}

void Enemy::separation() {
    std::cout << "Enemy is retreating." << std::endl;
}
