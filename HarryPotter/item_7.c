//item.c
#include "my.h"

int damage;

void item2(void) { //���ѳ��� ������ ���

	damage = 4;
	gotoxy(0, 2);
	printf("Damage : +%d", damage);

}

void item3(char* pname, int hp_u_max) { //��Ȱ�� �� ���
	hp_U += HP_STONE;
	gotoxy(0, HP_LINE7);
	printf("[%s]: [ %3d ] / %3d ", pname, hp_U, hp_u_max);
}