#include <stdio.h>

template<typename TYPE1, typename TYPE2>
TYPE1 Min(TYPE1 a, TYPE2 b) {
    if (a >= b) {
        printf("%f\n", static_cast<double>(a));
        return a;
    }
    else {
        printf("%f\n", static_cast<double>(b));
        return static_cast<TYPE1>(b);
    }
}

template<>
char Min<char>(char a, char b) {
    printf("数字以外は代入できません\n");
    return 0;
}

int main() {
    Min<int, float>(5, 6.0f);
    Min<char, char>('a', 'b');
    Min<int, double>(5, 6.0);
    Min<double, float>(5.0, 6.0f);
    return 0;
}
