#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>

using namespace std;

// カードのランクとスートを持つ構造体
struct Card {
    string suit;
    int value;
};

// デッキからランダムにカードを引く
Card drawCard() {
    string suits[] = { "ハート", "ダイヤ", "クラブ", "スペード" };
    int value = rand() % 13 + 1;  // 1から13までのカード

    Card card;
    card.suit = suits[rand() % 4];
    card.value = value > 10 ? 10 : value;  // 10以上のカード（J, Q, K）は10として扱う

    return card;
}

// プレイヤーやディーラーの手札の合計を計算
int calculateTotal(const vector<Card>& hand) {
    int total = 0;
    int aces = 0; // A（エース）は1または11として扱える

    for (const auto& card : hand) {
        if (card.value == 1) {  // A（エース）の場合
            aces++;
            total += 11;  // とりあえずAは11としてカウント
        }
        else {
            total += card.value;
        }
    }

    // Aを1として数えた方が良い場合は、調整する
    while (total > 21 && aces > 0) {
        total -= 10;
        aces--;
    }

    return total;
}

// プレイヤーとディーラーの手札を表示する
void showHand(const vector<Card>& hand, const char* name) {
    printf("%sの手札: ", name);
    for (const auto& card : hand) {
        printf("[%s %d] ", card.suit.c_str(), card.value);
    }
    printf("合計: %d\n", calculateTotal(hand));
}

int main() {
    srand(static_cast<unsigned>(time(0)));  // 乱数の初期化

    // プレイヤーとディーラーの手札
    vector<Card> playerHand;
    vector<Card> dealerHand;

    // 最初に2枚ずつカードを引く
    playerHand.push_back(drawCard());
    playerHand.push_back(drawCard());
    dealerHand.push_back(drawCard());
    dealerHand.push_back(drawCard());

    // プレイヤーのターン
    while (true) {
        showHand(playerHand, "プレイヤー");

        if (calculateTotal(playerHand) > 21) {
            printf("バースト！プレイヤーの負けです。\n");
            return 0;
        }

        printf("カードを引きますか？（1: 引く, 0: やめる）: ");
        int choice;
        scanf_s("%d", &choice);

        if (choice == 1) {
            playerHand.push_back(drawCard());
        }
        else {
            break;
        }
    }

    // ディーラーのターン（ディーラーは17以上になるまで引く）
    while (calculateTotal(dealerHand) < 17) {
        dealerHand.push_back(drawCard());
    }

    // 最終的な手札を表示
    showHand(dealerHand, "ディーラー");

    int playerTotal = calculateTotal(playerHand);
    int dealerTotal = calculateTotal(dealerHand);

    // 勝敗の判定
    if (dealerTotal > 21 || playerTotal > dealerTotal) {
        printf("プレイヤーの勝ちです！\n");
    }
    else if (playerTotal < dealerTotal) {
        printf("ディーラーの勝ちです！\n");
    }
    else {
        printf("引き分けです！\n");
    }

    return 0;
}
