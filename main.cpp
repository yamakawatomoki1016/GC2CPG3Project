#include <iostream>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <thread>
#include <chrono>

// 偶数なら true、奇数なら false
bool isEven(int num) {
    return num % 2 == 0;
}

// 3秒待機する関数
void SetTimeout(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

int main() {
    int userGuess;
    char playAgain;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    do {
        int dice = std::rand() % 6 + 1;

        std::cout << "サイコロの出目は奇数（0）か偶数（1）かを当ててください：";
        std::cin >> userGuess;

        std::cout << "結果を判定中...\n";
        SetTimeout(3);

        //userGuess をキャプチャして std::function にラムダを格納
        std::function<void(int)> judge = [=](int result) {
            std::cout << "サイコロの出目は: " << result << "\n";
            if (isEven(result)) {
                std::cout << "これは偶数（丁）です。\n";
            }
            else {
                std::cout << "これは奇数（半）です。\n";
            }

            int correct = isEven(result);
            if (userGuess == correct) {
                std::cout << "正解！\n";
            }
            else {
                std::cout << "不正解！\n";
            }
            };

        // 呼び出し
        judge(dice);

        std::cout << "もう一度プレイしますか？ (y/n)：";
        std::cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "ゲームを終了します。\n";
    return 0;
}
