#include "my.h"

extern int word_time_limit;

void stage1_inst(char* name, char* prop, char* lv)
{
	int len = 0;
	char ch;
	printf("\nSTAGE 1\n\n");
	printf("\n위대한 마법사가 될 운명인 당신은 사악한 마법사 볼드모트를 처치하기 위한 여정을 떠나게 되는데...\n\n");
	printf("당신의 이름은?\n\n");
	for (int i = 0; i < 20; i++) {
		name[i] = 0;
	}
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			if (ch == '\r' && len > 0) {
				for (; len < 20; len++) {
					name[len] = 0;
				}
				break;
			}
			else if (ch == '\b' && len > 0) {
				len--;
				printf("\b \b");
			}
			else if (ch >= 48 && ch <= 122 && len < 20) {
				printf("%c", ch);
				name[len] = ch;
				len++;
			}
		}

	}
	name[21] = 0;

	do {
		printf("\n당신의 특성은? \n");
		printf("1 : HP [%d] / ATK [%d]\n", HP1, ATK1);
		printf("2 : HP [%d] / ATK [%d]\n", HP2, ATK2);
		*prop = _getche();
		printf("\n");
		if (!(*prop == '1' || *prop == '2')) {
			printf("1 또는 2만 입력할 수 있습니다.\n");
		}
	} while (!(*prop == '1' || *prop == '2'));
	*prop -= 48;
	if (*lv == 0 || *lv == 4) {
		do {
			printf("\n난이도를 선택하십시오\n");
			printf("1 : 초급(level 1)\n");
			printf("2 : 중급(level 2)\n");
			printf("3 : 고급(level 3)\n");
			*lv = _getche();
			printf("\n");
			if (!(*lv == '1' || *lv == '2' || *lv == '3')) {
				printf("1 ~ 3만 입력할 수 있습니다.\n");
			}
		} while (!(*lv == '1' || *lv == '2' || *lv == '3'));
		*lv -= 48;
	}
	system("pause");
}

void stage2_inst(char* name, int word_time_limit) {

	system("cls");
	printf("\nSTAGE 2\n\n");
	printf("%s 은/는 여정중에 비밀의 방에 도착하게 된다.\n", name);
	printf("그 안에서 커다란 뱀, 바실리스크를 만나 싸우게 되는데...\n\n");
	printf("*게임화면*\n\n");
	printf("1. 화면 상단에 출력되는 영단어를 [%d] 초 안에 입력하여 바실리스크를 공격할 수 있습니다.\n\n", word_time_limit / 2);
	printf("2. [%d] 초 안에 공격하지 못하거나, 잘못 입력했다면 공격에 실패합니다.\n\n", word_time_limit / 2);
	printf("3. 바실리스크를 [%d] 초 안에 물리치지 못하면 게임 오버됩니다.\n\n", STAGE_LIMIT_TIME);
	printf("4. 영단어 입력을 연속으로 성공하면 콤보가 쌓여 더 많은 데미지를 줄 수 있습니다.\n\n");
	printf("5. 스테이지 제한시간 [%d] 초 중에 남은 시간이 점수가 됩니다.\n\n", STAGE_LIMIT_TIME);
	system("pause");

}

void stage3_inst(char* name, int word_time_limit) {

	system("cls");
	printf("\nSTAGE 3\n");
	printf("\n비밀의 방에서 나온 %s 은/는 아즈카반 감옥에 도착하게 된다..\n", name);
	printf("그 곳에서 아즈카반의 간수, 디멘터를 만나 싸우게 되는데...\n\n");
	printf("*게임화면*\n\n");
	printf("1. 화면 상단에 출력되는 영단어를 [%d] 초 안에 입력하여 디멘터를 공격할 수 있습니다.\n\n", word_time_limit / 2); // 수정 
	printf("2. [%d] 초 안에 공격하지 못하거나, 잘못 입력했다면 공격에 실패합니다.\n\n", word_time_limit / 2);
	printf("3. 디멘터를 [%d] 초 안에 물리치지 못하면 게임 오버됩니다.\n\n", STAGE_LIMIT_TIME);
	printf("4. 영단어 입력을 연속으로 성공하면 콤보가 쌓여 더 많은 데미지를 줄 수 있습니다.\n\n");
	printf("5. 스테이지 제한시간 [%d] 초 중에 남은 시간이 점수가 됩니다.\n\n", STAGE_LIMIT_TIME);

	system("pause");
}

void stage4_inst(char* name, int word_time_limit) {

	system("cls");
	printf("\nSTAGE 4\n");
	printf("\n디멘터를 물리친 %s 은/는 그의 스승이자 마법 학교의 교장, 덤블도어와 만난다.\n", name);
	printf("덤블도어와 대련하여 그에게 투명 망토를 얻자. \n\n");
	printf("*게임화면*\n\n");
	printf("1. 화면 상단에 출력되는 영단어를 [%d] 초 안에 입력하여 덤블도어를 공격할 수 있습니다.\n\n", word_time_limit / 2);
	printf("2. [%d] 초 안에 공격하지 못하거나, 잘못 입력했다면 공격에 실패합니다.\n\n", word_time_limit / 2);
	printf("3. 덤블도어와의 대련을 [%d] 초 안에 승리하여 투명 망토를 얻을 수 있습니다.\n\n", STAGE_LIMIT_TIME);
	printf("4. 영단어 입력을 연속으로 성공하면 콤보가 쌓여 더 많은 데미지를 줄 수 있습니다.\n\n");
	printf("5. 스테이지 제한시간 [%d] 초 중에 남은 시간이 점수가 됩니다.\n\n", STAGE_LIMIT_TIME);
	system("pause");
}

void stage5_inst(char* name, int word_time_limit, int cleared) {
	char* clear[] = { "패배한","승리한" };
	system("cls");
	printf("\nSTAGE 5\n");
	printf("\n덤블도어와의 대련에서 %s %s 은/는 그의 대부, 시리우스와 만난다..\n", clear[cleared], name);
	printf("시리우스와 대련하여 그에게 딱총나무 지팡이를 얻자. \n\n");
	printf("*게임화면*\n\n");
	printf("1. 화면 상단에 출력되는 영단어를 [%d] 초 안에 입력하여 시리우스를 공격할 수 있습니다.\n\n", word_time_limit / 2);
	printf("2. [%d] 초 안에 공격하지 못하거나, 잘못 입력했다면 공격에 실패합니다.\n\n", word_time_limit / 2);
	printf("3. 시리우스와의 대련을 [%d] 초 안에 승리하여 딱총나무 지팡이를 얻을 수 있습니다.\n\n", STAGE_LIMIT_TIME);
	printf("4. 영단어 입력을 연속으로 성공하면 콤보가 쌓여 더 많은 데미지를 줄 수 있습니다.\n\n");
	printf("5. 스테이지 제한시간 [%d] 초 중에 남은 시간이 점수가 됩니다.\n\n", STAGE_LIMIT_TIME);
	system("pause");
}

void stage6_inst(char* name, int word_time_limit, int cleared) {
	char* clear[] = { "패배한","승리한" };
	system("cls");
	printf("\nSTAGE 6\n");
	printf("\n 시리우스와의 대련에서 %s %s 은/는 이중스파이 교수,스네이프와 만난다. \n", clear[cleared], name);
	printf("스네이프와 대련하여 그에게 부활의 돌을 얻자. \n\n");
	printf("*게임화면*\n\n");
	printf("1. 화면 상단에 출력되는 영단어를 [%d] 초 안에 입력하여 스네이프를 공격할 수 있습니다.\n\n", word_time_limit / 2);
	printf("2. [%d] 초 안에 공격하지 못하거나, 잘못 입력했다면 공격에 실패합니다.\n\n", word_time_limit / 2);
	printf("3. 스네이프와의 대련을 [%d] 초 안에 승리하여 부활의 돌를 얻을 수 있습니다.\n\n", STAGE_LIMIT_TIME);
	printf("4. 영단어 입력을 연속으로 성공하면 콤보가 쌓여 더 많은 데미지를 줄 수 있습니다.\n\n");
	printf("5. 스테이지 제한시간 [%d] 초 중에 남은 시간이 점수가 됩니다.\n\n", STAGE_LIMIT_TIME);
	system("pause");

}

void stage7_inst(char* name, int word_time_limit, int cleared)
{
	char* clear[] = { "패배한","승리한" };
	system("cls");
	printf("\nSTAGE 7\n");
	printf("\n스네이프와의 대련에서 %s %s 은/는 결국 사악한 마법사, 볼드모트를 만난다.\n\n", clear[cleared], name);
	printf("과연 %s 은/는 볼드모트를 물리치고 마법 세계를 구할 수 있을 것인가? \n\n", name);
	printf("1. 화면 상단에 출력되는 영단어를 [%d] 초 안에 입력하여 볼드모트를 공격할 수 있습니다.\n\n", word_time_limit / 2);
	printf("2. [%.1f] 초 안에 공격하지 못하거나, 잘못 입력했다면 공격에 실패하고, hp가 감소합니다.\n\n", TIME_V_LIMIT / 2.0);
	printf("3. 영단어 입력을 연속으로 성공하며 콤보가 쌓여 더 많은 데미지를 줄 수 있습니다.\n\n");
	printf("4. 지금까지의 점수가 당신의 HP로 환산됩니다.\n\n");
	printf("5. 화면 상단의 영단어와 별개로 볼드모트의 공격 영단어가 출력되면, 이를 [%d] 초 안에 입력하여\n", word_time_limit / 2);
	printf("그의 공격을 방어할 수 있습니다.\n\n");
	printf("6. 지금까지 얻은 아이템을 (1/2/3)을 입력하여 사용할 수 있습니다.\n\n");
	printf("7. 볼드모트를 물리치고 남은 당신의 HP, 난이도에 따라 최종 점수가 결정됩니다.\n\n");
	printf("8. 아이템을 쓰지 않고 볼드모트를 물리치면 쓰지 않은 아이템 당 보너스 점수가 주어집니다.\n\n");
	system("pause");
}