#include"my.h"

void combo(char* s1, char* s2, int* hp, int* cmb, int hp_minus)
{
    int result;
    if (strcmp(s1, s2) == 0)
    {
        result = 1;
        printf("���� ����");
    }
    else
    {
        result = 0;
        printf("���� ����");
    }

    if (result == 1)
    {
        *cmb += 1;
        *hp -= (hp_minus + *cmb);
    }
    else if (result == 0)
    {
        *cmb = 0;
    }
}
