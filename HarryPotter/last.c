#include "my.h"

int result(char name[], struct rank ranks[], char* level) {
	char sel;
	int rnk;
	rnk = rank_insert(name, ranks);
	while (1) {
		system("cls");
		sel = clear(name, rnk, ranks);
		switch (sel) {
		case 'r': break;
		case 'o': rank_print(ranks); break;
		case 'q': exit(0); break;
		}
		if (sel == 'r') {
			(*level)++;
			break;
		}
	}
	system("cls");
	return 0;
}

char clear(char* name, int rnk, struct rank ranks[]) {
	char ch;

	printf("볼드모트와의 대결에서 승리하였습니다...\n");
	printf("마법 세계는 평화로워졌습니다...\n");
	printf("\n당신의 점수 : [%d]\n", score);
	if (rnk) {
		printf("RANK : #%d\n", rnk);
	}
	else {
		printf("RANK : %d위 안에 들지 못했습니다\n", RANK_SIZE);
	}
	printf("\n전체 순위를 보시려면----- o\n");
	printf("게임을 다시 시작하려면--- r\n");
	printf("종료하려면--------------- q\n");
	printf("를 입력하세요 : ");
	do {
		ch = _getch();
		if (ch != 'q' && ch != 'o' && ch != 'r') {
			printf("r, o, q 중 하나만을 입력하실 수 있습니다.\n");
		}
		else {
			return ch;
		}
	} while (ch != 'q' && ch != 'o' && ch != 'r');
}

int rank_insert(char* name, struct rank ranks[]) {
	int i;
	for (i = 0; i < RANK_SIZE; i++) {
		if (score > ranks[i].score) {
			for (int j = RANK_SIZE - 2; j >= i; j--) {
				ranks[j + 1].score = ranks[j].score;
				strcpy(ranks[j + 1].name, ranks[j].name);
			}
			ranks[i].score = score;
			strcpy(ranks[i].name, name);
			return i + 1;
		}
	}
	return 0;
}

void rank_print(struct rank ranks[]) {
	system("cls");
	for (int i = 0; i < RANK_SIZE; i++) {
		if (strcmp(ranks[i].name, "\0"))
			printf("#%2d %s : %d점\n", i + 1, ranks[i].name, ranks[i].score);
		else
			printf("#%2d No record\n", i + 1);
	}
	system("pause");
}