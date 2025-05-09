#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// コールバック関数のプロトタイプ宣言
void judgeResult(int dice, int (*callback)(int));

// 偶数なら1、奇数なら0を返す関数
int isEven(int num) {
    return num % 2 == 0;
}

// 時間待機関数（約3秒）
void waitSeconds(int seconds) {
    time_t start = time(NULL);
    while (time(NULL) - start < seconds);
}

int main() {
    int userGuess;
    char playAgain;

    srand((unsigned int)time(NULL));

    do {
        int dice = rand() % 6 + 1;

        printf("サイコロの出目は奇数（0）か偶数（1）かを当ててください：");
        scanf_s("%d", &userGuess);

        printf("結果を判定中...\n");
        waitSeconds(3); // 3秒待つ

        judgeResult(dice, isEven);

        int correct = isEven(dice);
        if (userGuess == correct) {
            printf("正解！\n");
        }
        else {
            printf("不正解！\n");
        }

        printf("もう一度プレイしますか？ (y/n)：");
        scanf_s(" %c", &playAgain, 2);// 空白を入れてバッファの改行を読み飛ばす

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("ゲームを終了します。\n");

    return 0;
}

void judgeResult(int dice, int (*callback)(int)) {
    printf("サイコロの出目は: %d\n", dice);
    if (callback(dice)) {
        printf("これは偶数（丁）です。\n");
    }
    else {
        printf("これは奇数（半）です。\n");
    }
}
