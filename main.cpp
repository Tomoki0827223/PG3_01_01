#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <functional>

// SetTimeout関数
void SetTimeout(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int main() {
    // 乱数のシードを設定
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // ユーザーの入力を受け付けるラムダ式
    std::function<bool()> getUserInput = [&]() {  // [&] でキャプチャ
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
    auto rollDice = []() -> int {
        return std::rand() % 6 + 1; // 1〜6の乱数
        };

    // 出目が奇数か偶数かを判定するラムダ式
    auto isOdd = [](int number) -> bool {
        return number % 2 == 1; // 奇数ならtrue
        };

    // サイコロを振って結果を表示するラムダ式
    auto displayResult = [](int diceRoll, bool userGuess, bool result) {
        std::cout << "サイコロの出目は " << diceRoll << " でした。\n";
        if (result == userGuess) {
            std::cout << "おめでとうございます！予想が当たりました。\n";
        }
        else {
            std::cout << "残念！予想が外れました。\n";
        }
        };

    // ユーザー入力のキャプチャ
    bool userGuess = getUserInput();

    // サイコロの出目を決定
    int diceRoll = rollDice();

    // もったいつけるために3秒待機
    std::cout << "結果を待っています...\n";
    SetTimeout(3000);

    // 出目が奇数か偶数かを判定して結果を表示
    bool result = isOdd(diceRoll);
    displayResult(diceRoll, userGuess, result);

    return 0;
}
