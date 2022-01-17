//main.c
#include "my.h"

int hp_V;
int hp_U;
//hp_U와 user이름 부분은 나중에 변경할 것

int main_7(char* pname, char pitem[], int hp_u_max, char** words, int atk, char level)
{
    hp_V = HP_V_MAX;
    do {
        hp_U = hp_u_max;
    } while (hp_U > hp_u_max); // 1회만 실행하기 위한 코드


    system("cls"); // 수정 아이템 메뉴가 cls 위에 있었어서 아이템 안보였음 

    //기본 배경화면
    //아이템 메뉴 출력 (0,20)
    gotoxy(0, ITEM_LINE - 2);
    printf("*아이템*\n\n");
    printf("1 : 투명망토 - 볼드모트의 공격을 일정시간 무시합니다.\n");
    printf("2 : 딱총나무 지팡이 - 사용 시 당신의 공격력이 증가합니다.\n");
    printf("3 : 부활의 돌 - 사용 시 당신의 HP를 %d만큼 회복합니다.", HP_STONE);


    //빌런 프로필 출력 (40,15)
    gotoxy(40, HP_LINE7);
    printf("[Voldemort]: [ %3d ] / % 3d", hp_V, HP_V_MAX);
    //+attack함수 실행하면 볼드모트가 공격을 준비합니다! 출력

    //유저 프로필 출력 (0,15)
    gotoxy(0, HP_LINE7);
    printf("[%s]: [ %3d ] /% 3d", pname, hp_U, hp_u_max);


    while (1)
    {
        word(pname, pitem, hp_u_max, words, atk); //단어 출력 (0,0), 단어 네모네모 출력 (0,5)
         //공격단어 출력 (40,0), 공격단어 네모네모 출력 (40,5)   



        if (hp_U <= 0)
        {
            system("cls");
            return 0;
        }
        if (hp_V <= 0)
        {
            system("cls"); // 아이템 사용시 추가 보너스 
            score = 0;
            if (pitem[0] == 1)
                score += 30;
            if (pitem[1] == 1)
                score += ITEM_BONUS;
            if (pitem[2] == 1)
                score += ITEM_BONUS;
            score += hp_U;
            score *= (level * 2 + 4);
            return 1;
        }
    }
}

