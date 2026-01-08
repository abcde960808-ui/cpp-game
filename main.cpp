#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"

using namespace std;

void showMenu(int choice) {
    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    gotoxy(25, 5);
    cout << "文字介面小遊戲系統";

    string menu[3] = { "開始遊戲", "遊戲說明", "離開程式" };

    for (int i = 0; i < 3; i++) {
        gotoxy(28, 8 + i * 2);
        if (i == choice) {
            rlutil::setColor(rlutil::GREEN);
            cout << "> " << menu[i];
        } else {
            rlutil::setColor(rlutil::WHITE);
            cout << "  " << menu[i];
        }
    }
}

void gameIntro() {
    rlutil::cls();
    rlutil::setColor(rlutil::CYAN);
    cout << "【遊戲說明】\n\n";
    cout << "系統會隨機產生 1~100 的數字\n";
    cout << "請輸入數字來猜答案\n";
    cout << "系統會提示太大或太小\n\n";
    cout << "按任意鍵返回主選單...";
    rlutil::anykey();
}

void guessGame() {
    rlutil::cls();
    srand(time(0));
    int answer = rand() % 100 + 1;
    int guess, count = 0;

    while (true) {
        rlutil::cls();
        rlutil::setColor(rlutil::WHITE);
        cout << "請輸入你的猜測 (1~100)：";
        cin >> guess;
        count++;

        if (guess > answer) {
            rlutil::setColor(rlutil::RED);
            cout << "太大了！\n";
        } else if (guess < answer) {
            rlutil::setColor(rlutil::BLUE);
            cout << "太小了！\n";
        } else {
            rlutil::setColor(rlutil::GREEN);
            cout << "恭喜猜中了！\n";
            cout << "共猜了 " << count << " 次\n";
            break;
        }
        rlutil::anykey();
    }

    cout << "\n按任意鍵返回主選單...";
    rlutil::anykey();
}

int main() {

    system("chcp 65001 > nul && dir");

    int choice = 0;

    while (true) {
        showMenu(choice);
        int key = rlutil::getkey();

        if (key == rlutil::KEY_UP) {
            choice = (choice + 2) % 3;
        } else if (key == rlutil::KEY_DOWN) {
            choice = (choice + 1) % 3;
        } else if (key == rlutil::KEY_ENTER) {
            if (choice == 0) guessGame();
            else if (choice == 1) gameIntro();
            else break;
        }
    }

    rlutil::cls();
    rlutil::setColor(rlutil::WHITE);
    cout << "感謝遊玩！";
    return 0;
}
