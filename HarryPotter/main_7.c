//main.c
#include "my.h"

int hp_V;
int hp_U;
//hp_U�� user�̸� �κ��� ���߿� ������ ��

int main_7(char* pname, char pitem[], int hp_u_max, char** words, int atk, char level)
{
    hp_V = HP_V_MAX;
    do {
        hp_U = hp_u_max;
    } while (hp_U > hp_u_max); // 1ȸ�� �����ϱ� ���� �ڵ�


    system("cls"); // ���� ������ �޴��� cls ���� �־�� ������ �Ⱥ����� 

    //�⺻ ���ȭ��
    //������ �޴� ��� (0,20)
    gotoxy(0, ITEM_LINE - 2);
    printf("*������*\n\n");
    printf("1 : ������� - �����Ʈ�� ������ �����ð� �����մϴ�.\n");
    printf("2 : ���ѳ��� ������ - ��� �� ����� ���ݷ��� �����մϴ�.\n");
    printf("3 : ��Ȱ�� �� - ��� �� ����� HP�� %d��ŭ ȸ���մϴ�.", HP_STONE);


    //���� ������ ��� (40,15)
    gotoxy(40, HP_LINE7);
    printf("[Voldemort]: [ %3d ] / % 3d", hp_V, HP_V_MAX);
    //+attack�Լ� �����ϸ� �����Ʈ�� ������ �غ��մϴ�! ���

    //���� ������ ��� (0,15)
    gotoxy(0, HP_LINE7);
    printf("[%s]: [ %3d ] /% 3d", pname, hp_U, hp_u_max);


    while (1)
    {
        word(pname, pitem, hp_u_max, words, atk); //�ܾ� ��� (0,0), �ܾ� �׸�׸� ��� (0,5)
         //���ݴܾ� ��� (40,0), ���ݴܾ� �׸�׸� ��� (40,5)   



        if (hp_U <= 0)
        {
            system("cls");
            return 0;
        }
        if (hp_V <= 0)
        {
            system("cls"); // ������ ���� �߰� ���ʽ� 
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

