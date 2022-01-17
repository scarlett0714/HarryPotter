//my.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define _CRT_SECURE_NO_WARNINGS

#define HP1 130
#define HP2 100 
#define ATK1 7 
#define ATK2 8
#define STAGE_LIMIT_TIME 20
#define DEFEND_LIMIT_TIME 10

#define TIME_LINE 6 //�ܾ����ѽð� ��µǴ� ��ǥ
#define TIME_LIMIT 10 //�ܾ����ѽð� 10��
#define TIME_V_LINE 6 //������ѽð� ��µǴ� ��ǥ
#define TIME_V_LIMIT 15 //������ѽð� 15��
#define TIME_ITEM1 10 //������1�� ���ӽð� 10��

#define INPUT_LINE 10
#define INPUT_LINE7 9
#define WORD_INDEX 150
#define ATTACK_INDEX 37

#define STAGE_LIMIT 20 // �ð����� ����� 
// ���� ������ ��� ��ǥ�� 
#define WORD_LINE 5
#define STAGE_LINE 8
#define COMBO_LINE_X 10
#define COMBO_LINE_Y 2
#define HP_LINE_X 60
#define HP_LINE_Y 8
#define ITEM_LINE 16
#define HP_LINE7 12

#define TIME_STICK 15 //item2 : ���ѳ��� ������ ���� Ȱ���ð� 15
#define HP_STONE 40 //item3 : ��Ȱ�� �� ���� ȸ�� ü�� 40

#define HP_V_MAX 200 // ������ �ִ� HP 200
#define VOLDEMORT_DAMAGE 20
#define ITEM_BONUS 50 

#define RANK_SIZE 20




struct rank {
	char name[21]; // ���� 
	int score;
};

void gotoxy(int x, int y);
int main_7(char*, char[], int, char**, int, char);
void word(char*, char[], int, char**, int);
void hp_Vf(int*, int);
void hp_Uf1(char*, int);
void hp_Uf2(char*, int);

int combo_s(int*);
int combo_f(int*);

void item2(void);
void item3(char*, int);

// stage 1~7
void gotoxy(int, int);
void word_time(clock_t, int, char);
long stage_time(clock_t, int, char);
void combo(char*, char*, int*, int*, int);
int game(int, long*, int, int, char**);
char stageEnd(char, char, long, char*);
void stage1_inst(char*, char*, char*);
void stage2_inst(char*, int);
void stage3_inst(char*, int);
void stage4_inst(char*, int);
void stage5_inst(char*, int, int);
void stage6_inst(char*, int, int);
void stage7_inst(char*, int, int);

// Rank ���� �Լ� ����
int result(char[], struct rank[], char*);
char clear(char*, int, struct rank[]);
int rank_insert(char*, struct rank[]);
void rank_print(struct rank[]);
extern int hp_V; // ��Ʈ��Ʈ hp
extern int hp_U; // ���� hp
extern int damage; // ������ 
extern int score; // ���� ����
