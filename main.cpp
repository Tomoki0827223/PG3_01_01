#include <stdio.h>

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
    printf("働く時間（時間単位）を入力してください: ");
    scanf_s("%d", &hours);

    // 賃金を計算
    double recursiveTotal = recursiveWage(hours);
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
