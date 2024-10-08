#include <stdio.h>
#include <iostream>

using namespace std;

// 再帰的な賃金を計算する関数
double recursiveWage(int hours) {
    double wage = 100;  // 最初の1時間の時給
    double total = wage;

    for (int i = 2; i <= hours; ++i) {
        wage = wage * 2 - 50;  // 時給の計算
        total += wage;
    }

    return total;
}

// 一般的な賃金を計算する関数
double standardWage(int hours, double hourlyRate = 1072) {
    return hours * hourlyRate;
}

int main() {
    int hours;

    // 入力
    cout << "働く時間（時間単位）を入力してください: ";
    cin >> hours;

    // 賃金を計算
    double recursiveTotal = recursiveWage(hours);
    double standardTotal = standardWage(hours);

    // 結果を表示
    cout << "再帰的な賃金体系での賃金: " << recursiveTotal << "円" << endl;
    cout << "一般的な賃金体系での賃金: " << standardTotal << "円" << endl;

    // 比較
    if (recursiveTotal > standardTotal) {
        cout << "再帰的な賃金体系のほうが有利です。" << endl;
    }
    else {
        cout << "一般的な賃金体系のほうが有利です。" << endl;
    }

    return 0;
}
