#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "customers.txt"

typedef struct {
    char name[50];
    char phone[20];
    char email[100];
} Customer;

void add_customer() {
    Customer c;

    printf("名前を入力してください: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = '\0'; // 改行削除

    printf("電話番号を入力してください: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0';

    printf("メールアドレスを入力してください: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = '\0';

    FILE* file;
    errno_t err = fopen_s(&file, FILENAME, "a");
    if (err != 0 || file == NULL) {
        perror("ファイルを開けませんでした");
        return;
    }

    fprintf(file, "%s,%s,%s\n", c.name, c.phone, c.email);
    fclose(file);
    printf("顧客情報を保存しました。\n\n");
}

void view_customers() {
    FILE* file;
    errno_t err = fopen_s(&file, FILENAME, "r");
    if (err != 0 || file == NULL) {
        printf("まだ顧客情報が登録されていません。\n\n");
        return;
    }

    char line[256];
    printf("登録された顧客情報:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    printf("\n");
    fclose(file);
}

int main() {
    int choice;

    while (1) {
        printf("1: 顧客を追加\n");
        printf("2: 顧客情報を表示\n");
        printf("3: 終了\n");
        printf("選択してください: ");
        scanf_s("%d", &choice);
        getchar(); // 改行読み飛ばし

        switch (choice) {
        case 1:
            add_customer();
            break;
        case 2:
            view_customers();
            break;
        case 3:
            printf("プログラムを終了します。\n");
            return 0;
        default:
            printf("無効な選択です。\n\n");
        }
    }
}
