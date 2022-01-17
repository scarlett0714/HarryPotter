//word.c
#include "my.h"

void word(char* pname, char pitem[], int hp_u_max, char** words, int atk)
{
    srand(time(NULL));

    char ch;
    int len = 0, rnd = rand() % WORD_INDEX, rnd_V = rand() % ATTACK_INDEX;
    char input_string[50] = { 0 };
    char* attack[ATTACK_INDEX] = { "Accendio", "Aquaeructo", "Avada Kedabra", "Bombarda", "Bombarda Maxima", "Confringo", "Confundo", "Crucio", "Duro", "Evanesco", "Expelliarmus", "Expulso", "Flagrate", "Furnunculus", "Homenum Revelio", "Immorbarus", "Impedimenta", "Imperio", "Incarcerous", "Incendio", "Lacanum inflamore", "Langlock", "Levicorpus", "Locomotor Mortis", "Mobilicorpus", "Mosmordre", "Obliviat", "Obscuro", "Petrificus Totalus", "Portus", "Reducto", "Relashio", "Rictusempra", "Sectumsempra", "Serpensortia", "Stupefy", "Wingardium Leviosa" };
    char* a, * b; //a,b는 단어비교변수

    //아이템 획득여부 불러올경우 포인터로 바꾸어주기

    int item1 = 0; //투명망토기능 사용

    int combo = 0;
    int* pcombo = &combo;
    long long item2_time = time(0) - TIME_STICK;

    extern int damage;

    clock_t current = clock(), wd_start = clock(), current_V = clock, wd_V_start = clock();


    while ((hp_U > 0) * (hp_V > 0) == 1)
    {
        //단어출력
        gotoxy(0, 0);
        printf("%s", words[rnd]);
        a = words[rnd];
        //입력단어 제한시간 타이머
        gotoxy(0, TIME_LINE - 1);
        printf("기본입력 제한시간");
        gotoxy(0, TIME_LINE);
        for (int i = 0; i < TIME_LIMIT - (int)((current - wd_start) * 2 / CLOCKS_PER_SEC); i++) {
            printf("■");
            current = clock();
        }
        for (int i = 0; i < (int)((current - wd_start) * 2 / CLOCKS_PER_SEC); i++) {
            printf("□");
            current = clock();
        }
        gotoxy(TIME_LIMIT * 2, TIME_LINE);
        printf("            ");
        Sleep(10);

        //공격단어출력
        gotoxy(40, 0);
        b = attack[rnd_V];
        printf("%s!                           ", b);


        //공격단어 제한시간 타이머 
        gotoxy(40, TIME_V_LINE - 1);
        printf("방어입력 제한시간");
        gotoxy(40, TIME_V_LINE);
        for (int i = 0; i < TIME_V_LIMIT - (int)((current_V - wd_V_start) * 2 / CLOCKS_PER_SEC); i++) {
            printf("■");
            current_V = clock();
        }
        for (int i = 0; i < (int)((current_V - wd_V_start) * 2 / CLOCKS_PER_SEC); i++) {
            printf("□");
            current_V = clock();
        }

        gotoxy(40 + TIME_V_LIMIT * 2, TIME_V_LINE);
        printf("            ");

        Sleep(10);


        if (time(0) >= item2_time + TIME_STICK)
        {
            gotoxy(0, 2);
            printf("                                        ");
            damage = 0;
        }


        // 추가 
        if (pitem[0] == 2)
        {
            gotoxy(0, ITEM_LINE);
            printf("투명망토를 사용하였습니다.                                        ");
        }

        if (pitem[1] == 2)
        {
            gotoxy(0, ITEM_LINE + 1);
            printf("딱총나무 지팡이를 사용하였습니다.                                 ");

        }

        if (pitem[2] == 2)
        {
            gotoxy(0, ITEM_LINE + 2);
            printf("부활의 돌을 사용하였습니다.                                        ");
        }

        if (pitem[0] == 0)
        {
            gotoxy(0, ITEM_LINE);
            printf("                                                                ");
        }

        if (pitem[1] == 0)
        {
            gotoxy(0, ITEM_LINE + 1);
            printf("                                                                ");

        }

        if (pitem[2] == 0)
        {
            gotoxy(0, ITEM_LINE + 2);
            printf("                                                                ");
        }

        //단어입력
        gotoxy(len, INPUT_LINE7);
        if (_kbhit())
        {
            ch = _getch();
            if (ch == '\b' && len > 0)
            {
                len--;
                printf("\b \b");
            }
            else if (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '1' && ch <= '3') || ch == '!' || ch == ' ') && len < 26)
            {
                printf("%c", ch);
                input_string[len] = ch;
                len++;
            }
            else if (ch == '\r')
            {
                gotoxy(0, INPUT_LINE7);
                input_string[len] = 0;
                for (; len > 0; len--) {
                    printf(" ");
                }



                //아이템 사용
                if (input_string[0] == '1')
                {
                    if (pitem[0] == 1)
                    {
                        item1 = 1;
                        pitem[0] = 2;
                    }

                }

                else if (input_string[0] == '2')
                {
                    if (pitem[1] == 1)
                    {
                        item2_time = time(0);
                        item2();
                        pitem[1] = 2;
                    }
                }

                else if (input_string[0] == '3')
                {
                    if (pitem[2] == 1)
                    {
                        item3(pname, hp_u_max);
                        pitem[2] = 2;
                    }


                }

                //공격단어비교
                else if (input_string[strlen(input_string) - 1] == '!')
                {
                    input_string[strlen(input_string) - 1] = '\0';

                    if (!strcmp(input_string, b)) // b = attack[rnd]
                    {
                        wd_V_start = clock();
                        rnd_V = rand() % ATTACK_INDEX;
                        len = 0;
                    }
                    else
                    {
                        hp_Uf2(pname, hp_u_max);
                    }

                }

                //단어비교
                else
                {

                    if (!strcmp(input_string, a)) // a = words[rnd]
                    {
                        hp_Vf(pcombo, atk);
                        combo = combo_s(pcombo);
                        wd_start = clock();
                        rnd = rand() % WORD_INDEX;
                        len = 0;
                    }
                    else
                    {
                        hp_Uf1(pname, hp_u_max);
                        combo = combo_f(pcombo);
                    }

                }

                //단어비교 끝
            }


        }




        if ((int)((current - wd_start) * 2 / CLOCKS_PER_SEC) >= TIME_LIMIT) //입력단어 알고리즘 작동
        {
            hp_Uf1(pname, hp_u_max); // 단어를 시간 내에 입력하지 못했을 경우 유저의 hp감소 구현
            combo = combo_f(pcombo); //단어를 시간 내에 입력하지 못했을 경우 combo=0
            wd_start = clock();
            rnd = rand() % WORD_INDEX;
        }

        if ((int)((current_V - wd_V_start) * 2 / CLOCKS_PER_SEC) >= TIME_V_LIMIT) //공격단어 알고리즘 작동
        {
            if (item1 != 1)
                hp_Uf2(pname, hp_u_max); // 공격단어를 시간 내에 입력하지 못했을 경우 유저의 hp감소 구현
            else
                item1 = 0;
            wd_V_start = clock();
            rnd_V = rand() % ATTACK_INDEX;
        }

    }

}