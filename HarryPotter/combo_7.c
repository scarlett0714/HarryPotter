//combo.c
#include "my.h"

int combo_s(int* pcombo)
{
	(*pcombo)++;
	gotoxy(0, 1);
	printf("Combo: %3d", *pcombo); //����
	return *pcombo;
}

int combo_f(int* pcombo)
{
	*pcombo = 0;
	gotoxy(0, 1);
	printf("Combo: %3d", *pcombo); //����
	return *pcombo;
}