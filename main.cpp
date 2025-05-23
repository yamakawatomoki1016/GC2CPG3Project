#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "customers.txt"

typedef struct {
    char name[50];
    char phone[20];
    char email[100];
} Customer;

// 改行削除
void trim_newline(char* str) {
    str[strcspn(str, "\n")] = '\0';
}

void add_customer() {
    Customer c;

    printf("名前を入力してください: ");
    fgets(c.name, sizeof(c.name), stdin);
    trim_newline(c.name);

    printf("電話番号を入力してください: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    trim_newline(c.phone);

    printf("メールアドレスを入力してください: ");
    fgets(c.email, sizeof(c.email), stdin);
    trim_newline(c.email);

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

void search_customer() {
    char keyword[50];
    printf("検索する名前の一部を入力してください: ");
    fgets(keyword, sizeof(keyword), stdin);
    trim_newline(keyword);

    FILE* file;
    errno_t err = fopen_s(&file, FILENAME, "r");
    if (err != 0 || file == NULL) {
        printf("ファイルを開けませんでした。\n");
        return;
    }

    char line[256];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        char line_copy[256];
        strcpy_s(line_copy, sizeof(line_copy), line); // 安全なコピー

        char* context = NULL;
        char* name = strtok_s(line_copy, ",", &context); // 安全なトークナイズ

        if (name && strstr(name, keyword)) {
            printf("見つかりました: %s", line);
            found = 1;
        }
    }

    if (!found) {
        printf("一致する顧客が見つかりませんでした。\n");
    }
    printf("\n");

    fclose(file);
}

void delete_customer() {
    char target[50];
    printf("削除する顧客の名前を入力してください（完全一致）: ");
    fgets(target, sizeof(target), stdin);
    trim_newline(target);

    FILE* file, * temp;
    errno_t err1 = fopen_s(&file, FILENAME, "r");
    errno_t err2 = fopen_s(&temp, "temp.txt", "w");

    if (err1 != 0 || file == NULL || err2 != 0 || temp == NULL) {
        printf("ファイルを開けませんでした。\n");
        return;
    }

    char line[256];
    int deleted = 0;

    while (fgets(line, sizeof(line), file)) {
        char line_copy[256];
        strcpy_s(line_copy, sizeof(line_copy), line);

        char* context = NULL;
        char* name = strtok_s(line_copy, ",", &context);

        if (name && strcmp(name, target) == 0) {
            deleted = 1; // 削除対象
            continue;
        }

        fputs(line, temp);
    }

    fclose(file);
    fclose(temp);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (deleted) {
        printf("顧客「%s」の情報を削除しました。\n\n", target);
    }
    else {
        printf("顧客「%s」は見つかりませんでした。\n\n", target);
    }
}

int main() {
    int choice;

    while (1) {
        printf("1: 顧客を追加\n");
        printf("2: 顧客情報を表示\n");
        printf("3: 顧客を検索\n");
        printf("4: 顧客を削除\n");
        printf("5: 終了\n");
        printf("選択してください: ");
        if (scanf_s("%d", &choice) != 1) {
            printf("入力が無効です。\n");
            while (getchar() != '\n');
            continue;
        }
        getchar(); // 改行除去

        switch (choice) {
        case 1:
            add_customer();
            break;
        case 2:
            view_customers();
            break;
        case 3:
            search_customer();
            break;
        case 4:
            delete_customer();
            break;
        case 5:
            printf("プログラムを終了します。\n");
            return 0;
        default:
            printf("無効な選択です。\n\n");
        }
    }
}
