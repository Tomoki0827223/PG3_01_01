#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

//コールバック関数
void DispResult(int* diceResult) {
    if (*diceResult % 2 == 0) {
        printf("結果は丁（偶数）でした。\n\n");
    }
    else {
        printf("結果は半（奇数）でした。\n\n");
    }
}

//ランダムな出目を返す
int rollDice() {
    return rand() % 6 + 1;  //ランダム整数
}

//待ってからコールバック関数を実行する
void setTimeout(void (*p)(int*), int second, int* result) {
    Sleep(second * 1000);  //指定された秒数待つ
    p(result);
}

int main() {

    srand((unsigned)time(0));  //乱数の種を初期化
    int userChoice;
    int diceResult = rollDice();

    printf("サイコロの出目が奇数（半）か偶数（丁）かを当ててください。\n");
    printf_s("1: 奇数（半）、2: 偶数（丁）を入力してください。\n");
    cin >> userChoice;

    printf("結果まで3秒お待ちください...\n\n");

    // 関数ポインタとコールバック関数を使用して3秒後に結果を表示
    setTimeout(DispResult, 3, &diceResult);

    // 正解・不正解を判定
    bool isCorrect = false;
    if ((userChoice == 1 && diceResult % 2 != 0) || (userChoice == 2 && diceResult % 2 == 0)) {
        isCorrect = true;
    }

    if (isCorrect) {
        printf("正解です！\n");
    }
    else {
        printf("不正解です。\n");
    }

    // プログラムが終了しないように一時停止
    printf("終了するにはEnterキーを押してください");
    cin.ignore();
    cin.get();

    return 0;
}
