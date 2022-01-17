//hp.c
#include "my.h"

void hp_Vf(int* pcombo, int atk) { // 볼트모트 hp 감소하는 기능
    hp_V = hp_V - ((*pcombo) + (damage)) - atk;
    gotoxy(40, HP_LINE7);
    if (hp_V > 0)
        printf("[Voldemort]: [ %3d ] / % 3d", hp_V, HP_V_MAX);
    else if (hp_V <= 0)
        printf("[Voldemort]: [ %3d ] / % 3d", 0, HP_V_MAX);
}

void hp_Uf1(char* pname, int hp_u_max) { // user hp 감소하는 기능 
    hp_U -= 5;
    gotoxy(0, HP_LINE7);
    if (hp_U > 0)
        printf("[%s]: [ %3d ] / %3d", pname, hp_U, hp_u_max);
    else if (hp_U <= 0)
        printf("[%s]: [ %3d ] / %3d", pname, 0, hp_u_max);
}

void hp_Uf2(char* pname, int hp_u_max) { // user hp 감소하는 기능 
    hp_U -= VOLDEMORT_DAMAGE;
    gotoxy(0, HP_LINE7);
    if (hp_U > 0)
        printf("[%s]: [ %3d ] / %3d", pname, hp_U, hp_u_max);
    else if (hp_U <= 0)
        printf("[%s]: [ %3d ] / %3d", pname, 0, hp_u_max);
}