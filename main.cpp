#include <stdio.h>
#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>

// SetTimeout関数
void SetTimeout(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int main() {
    // 乱数のシードを設定
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // ユーザーの入力を受け付けるラムダ式
    auto getUserInput = []() -> bool {
        std::string userInput;
        std::cout << "奇数(半)か偶数(丁)かを予想してください (半=odd, 丁=even): ";
        std::cin >> userInput;

        if (userInput == "半" || userInput == "odd") {
            return true;  // 奇数を選択
        }
        else if (userInput == "丁" || userInput == "even") {
            return false; // 偶数を選択
        }
        else {
            std::cout << "無効な入力です。再試行してください。\n";
            return getUserInput(); // 再帰的に再入力
        }
        };

    // サイコロの出目をランダムに決定
    int diceRoll = std::rand() % 6 + 1; // 1〜6の乱数

    // ユーザー入力のキャプチャ
    bool userGuess = getUserInput();

    // もったいつけるために3秒待機
    std::cout << "結果を待っています...\n";
    SetTimeout(3000);

    // 出目が奇数か偶数かを判定
    bool isOdd = (diceRoll % 2 == 1);

    // 結果の表示
    std::cout << "サイコロの出目は " << diceRoll << " でした。\n";
    if (isOdd == userGuess) {
        std::cout << "おめでとうございます！予想が当たりました。\n";
    }
    else {
        std::cout << "残念！予想が外れました。\n";
    }

    return 0;
}
