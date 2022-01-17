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

	printf("�����Ʈ���� ��ῡ�� �¸��Ͽ����ϴ�...\n");
	printf("���� ����� ��ȭ�ο������ϴ�...\n");
	printf("\n����� ���� : [%d]\n", score);
	if (rnk) {
		printf("RANK : #%d\n", rnk);
	}
	else {
		printf("RANK : %d�� �ȿ� ���� ���߽��ϴ�\n", RANK_SIZE);
	}
	printf("\n��ü ������ ���÷���----- o\n");
	printf("������ �ٽ� �����Ϸ���--- r\n");
	printf("�����Ϸ���--------------- q\n");
	printf("�� �Է��ϼ��� : ");
	do {
		ch = _getch();
		if (ch != 'q' && ch != 'o' && ch != 'r') {
			printf("r, o, q �� �ϳ����� �Է��Ͻ� �� �ֽ��ϴ�.\n");
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
			printf("#%2d %s : %d��\n", i + 1, ranks[i].name, ranks[i].score);
		else
			printf("#%2d No record\n", i + 1);
	}
	system("pause");
}