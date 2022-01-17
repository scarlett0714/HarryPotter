#include "my.h"

void gotoxy(int, int);

int game(int stage, long* t, int word_time_limit, int atk, char** words) {

    srand(time(NULL));

    char ch, * a; // 입력값
    int hp, cmb = 0, hp1 = 2; // # 수정 hp1 맨처음 체력 화면 나오게
    int max_hp[] = { 0, 0, 70, 80, 90, 100, 110 }; // stage1~6 빌런 최대체력 배열

    char* villan_name[] = { "0", "0", "바실리스크", "디멘터", "덤블도어", "시리우스", "스네이프" }; // #수정 추가한것
    int len = 0, rnd = rand() % WORD_INDEX;
    char input_string[50] = { 0 };

    hp = max_hp[stage];
    char level;


    system("cls");
    printf("STAGE%d  level %d", stage, level = 7 - (word_time_limit / 2)); // #수정:game 함수에서 level 매개변수 추가 안하고 레벨 표현

    clock_t st_start = clock(), current = clock(), wd_start = clock();

    while (1) {

        // 입력해야 하는 단어 출력란 좌표 (0, 2)
        gotoxy(0, 2);
        a = words[rnd];
        printf("%s", a);

        // 단어 제한시간 출력란 좌표 (0, 4)
        word_time(wd_start, word_time_limit, WORD_LINE);
        if (stage_time(st_start, STAGE_LIMIT, STAGE_LINE) <= 0) {
            break;
        }

        Sleep(10);

        //빌런 이름 출력란 (60,7)  #수정 추가한 것 
        gotoxy(60, 7);
        printf("%s 체력", villan_name[stage]);
        gotoxy(60, 8);
        if (hp1 == 2) {
            printf("%3d / %3d", max_hp[stage], max_hp[stage]);
            hp1 = hp1 / 2;
        }

        // 입력란 좌표(0,8) + 입력값을 받으면서 바로 콤보함수 실행할 수 있게 중간에 집어넣음 
        gotoxy(len, INPUT_LINE);
        if (_kbhit()) {
            ch = _getch();
            if (ch == '\r') {
                //입력하기 전에 남은 값들 null로 바꾸기
                gotoxy(0, INPUT_LINE);
                input_string[len] = 0;
                for (; len > 0; len--) {
                    printf(" ");
                }

                // 단어 입력시 콤보 보이기 좌표 (10,2) 
                gotoxy(COMBO_LINE_X, COMBO_LINE_Y);
                combo(a, input_string, &hp, &cmb, atk);
                printf("  %d 콤보\n", cmb);

                // 단어입력시 hp 보이면서 공격마다 체력이 감소 좌표 (60, 8) 

                gotoxy(HP_LINE_X, HP_LINE_Y);
                if (hp > 0)
                    printf("%3d / %3d", hp, max_hp[stage]);
                else if (hp <= 0)
                    printf("%3d / %3d", 0, max_hp[stage]);

                wd_start = clock();
                rnd = rand() % WORD_INDEX;
                len = 0;
            }
            else if (ch == '\b' && len > 0) {
                len--;
                printf("\b \b");
            }
            else if (ch >= 'a' && ch <= 'z' && len < 26) {
                printf("%c", ch);
                input_string[len] = ch;
                len++;
            }
        }

        current = clock(); // 추가 
        if ((int)((current - wd_start) * 2 / CLOCKS_PER_SEC) >= word_time_limit) {
            wd_start = clock();
            gotoxy(COMBO_LINE_X, COMBO_LINE_Y);
            cmb = 0;
            printf("공격 실패 %d  콤보\n", cmb);
            rnd = rand() % WORD_INDEX;
        }

        if (hp <= 0) {
            (*t) = stage_time(st_start, STAGE_LIMIT, STAGE_LINE);
            break;
        }
    }

    // 게임오버
    system("cls");
    if (hp <= 0) // 빌런 hp 다 닳았을 때 break 로 빠져 나온 경우
    {
        return 1;
    }
    else // 제한 시간이 지나서 반복문 빠져나온 경우 
    {
        return 0;
    }
}

void gotoxy(int x, int y) {
    COORD Cur = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void word_time(clock_t start, int limit, char line) {
    gotoxy(0, line - 1);
    printf("단어입력 제한시간");
    gotoxy(0, line);
    for (int i = 0; i < limit - (int)((clock() - start) * 2 / CLOCKS_PER_SEC); i++) {
        printf("■");
    }
    for (int i = 0; i < (int)((clock() - start) * 2 / CLOCKS_PER_SEC); i++) {
        printf("□");
    }
    gotoxy(limit * 2, line);
    printf("            ");
}
long stage_time(clock_t start, int limit, char line) {
    gotoxy(0, line - 1);
    printf("스테이지 제한시간");
    gotoxy(0, line);
    for (int i = 0; i < limit - (int)((clock() - start) / CLOCKS_PER_SEC); i++) {
        printf("■");
    }
    for (int i = 0; i < (int)((clock() - start) / CLOCKS_PER_SEC); i++) {
        printf("□");
    }
    gotoxy(limit * 2, line);
    printf("            ");
    return limit - (clock() - start) / CLOCKS_PER_SEC;
}