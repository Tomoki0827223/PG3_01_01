#pragma once
#include <iostream>

class Enemy {
public:
    Enemy();

    void Update();

private:


    void Getcloser();
    void separation();


    static void (Enemy::* functionTable[])();

    uint32_t Phase = 0;
};