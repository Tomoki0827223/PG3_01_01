#include <stdio.h>
#include <iostream>

using namespace std;

// 再帰的な賃金を計算する再帰関数
double recursiveWage(int hours) {
    if (hours == 1) {
        return 100;
    }
    else {
        return (recursiveWage(hours - 1) * 2) - 50;
    }
}

// 再帰的な賃金の合計を計算する再帰関数
double totalRecursiveWage(int hours) {
    if (hours == 1) {
        return 100;
    }
    else {
        return recursiveWage(hours) + totalRecursiveWage(hours - 1);
    }
}


double standardWage(int hours, double hourlyRate = 1072) {
    return hours * hourlyRate;
}

int main() {
    int hours;

    // 入力
    printf("働く時間（時間単位）を入力してください: ");
    cin >> hours;


    double recursiveTotal = totalRecursiveWage(hours);
    double standardTotal = standardWage(hours);

    // 結果を表示
    printf("再帰的な賃金体系での賃金: %.2f円\n", recursiveTotal);
    printf("一般的な賃金体系での賃金: %.2f円\n", standardTotal);

    // 比較
    if (recursiveTotal > standardTotal) {
        printf("再帰的な賃金体系のほうが有利です。\n\n");
    }
    else {
        printf("一般的な賃金体系のほうが有利です。\n\n");
    }

    // プログラムが終了しないように一時停止
    printf("終了するにはEnterキーを押してください");
    cin.ignore();
    cin.get();

    return 0;
}
