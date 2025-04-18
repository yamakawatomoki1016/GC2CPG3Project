#include <stdio.h>

// n時間目の時給を再帰的に計算する関数
double recursive_wage(int hour) {
    if (hour == 1) {
        return 100.0;
    }
    return recursive_wage(hour - 1) * 2 - 50;
}

// n時間までの合計賃金を再帰的に計算する関数
double total_recursive_wage(int hour) {
    if (hour == 1) {
        return 100.0;
    }
    return total_recursive_wage(hour - 1) + recursive_wage(hour);
}

int main() {
    int hours;
    double wage_normal = 1072.0;
    int choice;

    while (1) {
        printf("\n========== 賃金比較メニュー ==========\n");
        printf("1. 賃金を比較する\n");
        printf("0. 終了する\n");
        printf("選択してください: ");
        scanf_s("%d", &choice);

        if (choice == 0) {
            printf("終了します。\n");
            break;
        }
        else if (choice == 1) {
            printf("働く時間数を入力してください（単位：時間）: ");
            scanf_s("%d", &hours);

            double total_normal = wage_normal * hours;
            double total_recursive = total_recursive_wage(hours);

            printf("\n【結果比較】\n");
            printf("一般的な賃金体系の合計：%.2f円\n", total_normal);
            printf("再帰的な賃金体系の合計：%.2f円\n", total_recursive);

            if (total_recursive > total_normal) {
                printf("→ 再帰的な賃金の方が得です！\n");
            }
            else {
                printf("→ 一般的な賃金の方が得です！\n");
            }
        }
        else {
            printf("無効な選択です。もう一度お試しください。\n");
        }
    }

    return 0;
}
