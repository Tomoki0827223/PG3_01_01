#include "Enemy.h"
#include <cstdio>

void (Enemy::* Enemy::functionTable[])() = {

    &Enemy::Getcloser,
    &Enemy::separation

};

Enemy::Enemy() : Phase(0) {}

void Enemy::Update() {

    // 現在のフェーズの関数を実行
    (this->*functionTable[Phase])();

    // 行列の更新 (例: デバッグ表示)
    printf("Updating matrices...\n");

    // デバッグ用の表示
    printf("Current phase: %d\n", Phase);

    // フェーズ遷移 (次のフェーズに進む)
    Phase = (Phase + 1) % 2;

}

void Enemy::Getcloser() {

    printf("Enemy is approaching.\n");

}

void Enemy::separation() {

    printf("Enemy is retreating.\n");

}
