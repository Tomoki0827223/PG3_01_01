#include <stdio.h>
#include <iostream>

using namespace std;

// 再帰的な賃金を計算する再帰関数
double recursiveWage(int hours) {
    if (hours == 1) {
        return 100; // 最初の1時間は100円
    }
    else {
        return (recursiveWage(hours - 1) * 2) - 50; // 前の時給の2倍から50円引く
    }
}

// 再帰的な賃金の合計を計算する再帰関数
double totalRecursiveWage(int hours) {
    if (hours == 1) {
        return 100; // 最初の1時間は100円
    }
    else {
        return recursiveWage(hours) + totalRecursiveWage(hours - 1);
    }
}

// 一般的な賃金を計算する関数
double standardWage(int hours, double hourlyRate = 1072) {
    return hours * hourlyRate;
}

int main() {
    int hours;

    // 入力
    printf("働く時間（時間単位）を入力してください: ");
    cin >> hours;

    // 賃金を計算
    double recursiveTotal = totalRecursiveWage(hours);
    double standardTotal = standardWage(hours);

    // 結果を表示
    printf("再帰的な賃金体系での賃金: %.2f円\n", recursiveTotal);
    printf("一般的な賃金体系での賃金: %.2f円\n", standardTotal);

    // 比較
    if (recursiveTotal > standardTotal) {
        printf("再帰的な賃金体系のほうが有利です。\n");
    }
    else {
        printf("一般的な賃金体系のほうが有利です。\n");
    }

    return 0;
}
