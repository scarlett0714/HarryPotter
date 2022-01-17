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

#define TIME_LINE 6 //단어제한시간 출력되는 좌표
#define TIME_LIMIT 10 //단어제한시간 10초
#define TIME_V_LINE 6 //방어제한시간 출력되는 좌표
#define TIME_V_LIMIT 15 //방어제한시간 15초
#define TIME_ITEM1 10 //아이템1번 지속시간 10초

#define INPUT_LINE 10
#define INPUT_LINE7 9
#define WORD_INDEX 150
#define ATTACK_INDEX 37

#define STAGE_LIMIT 20 // 시간제한 상수값 
// 게임 페이지 요소 좌표값 
#define WORD_LINE 5
#define STAGE_LINE 8
#define COMBO_LINE_X 10
#define COMBO_LINE_Y 2
#define HP_LINE_X 60
#define HP_LINE_Y 8
#define ITEM_LINE 16
#define HP_LINE7 12

#define TIME_STICK 15 //item2 : 딱총나무 지팡이 사용시 활성시간 15
#define HP_STONE 40 //item3 : 부활의 돌 사용시 회복 체력 40

#define HP_V_MAX 200 // 볼드모드 최대 HP 200
#define VOLDEMORT_DAMAGE 20
#define ITEM_BONUS 50 

#define RANK_SIZE 20




struct rank {
	char name[21]; // 수정 
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

// Rank 관련 함수 원형
int result(char[], struct rank[], char*);
char clear(char*, int, struct rank[]);
int rank_insert(char*, struct rank[]);
void rank_print(struct rank[]);
extern int hp_V; // 볼트모트 hp
extern int hp_U; // 유저 hp
extern int damage; // 데미지 
extern int score; // 누적 점수
