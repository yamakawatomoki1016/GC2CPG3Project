#include <iostream>
#include <list>
#include <cstring>

using namespace std;

void PrintStations(const list<const char*>& stations, const char* year) {
    cout << year << "年の駅一覧:" << endl;
    for (const char* name : stations) {
        cout << "- " << name << endl;
    }
    cout << endl;
}

int main() {
    // 駅名リスト（1970年）
    list<const char*> stations1970 = {
        "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno",
        "Uguisudani", /* Nishinippori(1971~) */ "Nippori", "Nishi-Nippori",
        "Tabata", "Komagome", "Sugamo", "Otsuka", "Ikebukuro",
        "Mejiro", "Takadanobaba", "Shin-Okubo", "Shinjuku", "Yoyogi",
        "Harajuku", "Shibuya", "Ebisu", "Meguro", "Gotanda",
        "Osaki", "Shinagawa", "Tamachi", "Hamamatsucho", "Shimbashi", "Yurakucho"
    };

    // 1970年 → Nishinippori（1971年）を除く
    list<const char*> stations1970Actual = stations1970;
    stations1970Actual.remove("Nishi-Nippori");

    // 2019年：全駅（Nishi-Nippori含む）が揃った
    list<const char*> stations2019 = stations1970;

    // 2022年：2019年に Takanawa Gateway を追加
    list<const char*> stations2022 = stations2019;
    for (auto it = stations2022.begin(); it != stations2022.end(); ++it) {
        if (strcmp(*it, "Shinagawa") == 0) {
            stations2022.insert(next(it), "Takanawa Gateway");
            break;
        }
    }

    // 表示
    PrintStations(stations1970Actual, "1970");
    PrintStations(stations2019, "2019");
    PrintStations(stations2022, "2022");

    return 0;
}
