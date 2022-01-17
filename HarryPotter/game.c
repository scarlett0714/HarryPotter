#include "my.h"

void gotoxy(int, int);

int game(int stage, long* t, int word_time_limit, int atk, char** words) {

    srand(time(NULL));

    char ch, * a; // �Է°�
    int hp, cmb = 0, hp1 = 2; // # ���� hp1 ��ó�� ü�� ȭ�� ������
    int max_hp[] = { 0, 0, 70, 80, 90, 100, 110 }; // stage1~6 ���� �ִ�ü�� �迭

    char* villan_name[] = { "0", "0", "�ٽǸ���ũ", "�����", "������", "�ø��콺", "��������" }; // #���� �߰��Ѱ�
    int len = 0, rnd = rand() % WORD_INDEX;
    char input_string[50] = { 0 };

    hp = max_hp[stage];
    char level;


    system("cls");
    printf("STAGE%d  level %d", stage, level = 7 - (word_time_limit / 2)); // #����:game �Լ����� level �Ű����� �߰� ���ϰ� ���� ǥ��

    clock_t st_start = clock(), current = clock(), wd_start = clock();

    while (1) {

        // �Է��ؾ� �ϴ� �ܾ� ��¶� ��ǥ (0, 2)
        gotoxy(0, 2);
        a = words[rnd];
        printf("%s", a);

        // �ܾ� ���ѽð� ��¶� ��ǥ (0, 4)
        word_time(wd_start, word_time_limit, WORD_LINE);
        if (stage_time(st_start, STAGE_LIMIT, STAGE_LINE) <= 0) {
            break;
        }

        Sleep(10);

        //���� �̸� ��¶� (60,7)  #���� �߰��� �� 
        gotoxy(60, 7);
        printf("%s ü��", villan_name[stage]);
        gotoxy(60, 8);
        if (hp1 == 2) {
            printf("%3d / %3d", max_hp[stage], max_hp[stage]);
            hp1 = hp1 / 2;
        }

        // �Է¶� ��ǥ(0,8) + �Է°��� �����鼭 �ٷ� �޺��Լ� ������ �� �ְ� �߰��� ������� 
        gotoxy(len, INPUT_LINE);
        if (_kbhit()) {
            ch = _getch();
            if (ch == '\r') {
                //�Է��ϱ� ���� ���� ���� null�� �ٲٱ�
                gotoxy(0, INPUT_LINE);
                input_string[len] = 0;
                for (; len > 0; len--) {
                    printf(" ");
                }

                // �ܾ� �Է½� �޺� ���̱� ��ǥ (10,2) 
                gotoxy(COMBO_LINE_X, COMBO_LINE_Y);
                combo(a, input_string, &hp, &cmb, atk);
                printf("  %d �޺�\n", cmb);

                // �ܾ��Է½� hp ���̸鼭 ���ݸ��� ü���� ���� ��ǥ (60, 8) 

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

        current = clock(); // �߰� 
        if ((int)((current - wd_start) * 2 / CLOCKS_PER_SEC) >= word_time_limit) {
            wd_start = clock();
            gotoxy(COMBO_LINE_X, COMBO_LINE_Y);
            cmb = 0;
            printf("���� ���� %d  �޺�\n", cmb);
            rnd = rand() % WORD_INDEX;
        }

        if (hp <= 0) {
            (*t) = stage_time(st_start, STAGE_LIMIT, STAGE_LINE);
            break;
        }
    }

    // ���ӿ���
    system("cls");
    if (hp <= 0) // ���� hp �� ����� �� break �� ���� ���� ���
    {
        return 1;
    }
    else // ���� �ð��� ������ �ݺ��� �������� ��� 
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
    printf("�ܾ��Է� ���ѽð�");
    gotoxy(0, line);
    for (int i = 0; i < limit - (int)((clock() - start) * 2 / CLOCKS_PER_SEC); i++) {
        printf("��");
    }
    for (int i = 0; i < (int)((clock() - start) * 2 / CLOCKS_PER_SEC); i++) {
        printf("��");
    }
    gotoxy(limit * 2, line);
    printf("            ");
}
long stage_time(clock_t start, int limit, char line) {
    gotoxy(0, line - 1);
    printf("�������� ���ѽð�");
    gotoxy(0, line);
    for (int i = 0; i < limit - (int)((clock() - start) / CLOCKS_PER_SEC); i++) {
        printf("��");
    }
    for (int i = 0; i < (int)((clock() - start) / CLOCKS_PER_SEC); i++) {
        printf("��");
    }
    gotoxy(limit * 2, line);
    printf("            ");
    return limit - (clock() - start) / CLOCKS_PER_SEC;
}