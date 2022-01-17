#include "my.h"

extern int word_time_limit;

void stage1_inst(char* name, char* prop, char* lv)
{
	int len = 0;
	char ch;
	printf("\nSTAGE 1\n\n");
	printf("\n������ �����簡 �� ����� ����� ����� ������ �����Ʈ�� óġ�ϱ� ���� ������ ������ �Ǵµ�...\n\n");
	printf("����� �̸���?\n\n");
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
		printf("\n����� Ư����? \n");
		printf("1 : HP [%d] / ATK [%d]\n", HP1, ATK1);
		printf("2 : HP [%d] / ATK [%d]\n", HP2, ATK2);
		*prop = _getche();
		printf("\n");
		if (!(*prop == '1' || *prop == '2')) {
			printf("1 �Ǵ� 2�� �Է��� �� �ֽ��ϴ�.\n");
		}
	} while (!(*prop == '1' || *prop == '2'));
	*prop -= 48;
	if (*lv == 0 || *lv == 4) {
		do {
			printf("\n���̵��� �����Ͻʽÿ�\n");
			printf("1 : �ʱ�(level 1)\n");
			printf("2 : �߱�(level 2)\n");
			printf("3 : ���(level 3)\n");
			*lv = _getche();
			printf("\n");
			if (!(*lv == '1' || *lv == '2' || *lv == '3')) {
				printf("1 ~ 3�� �Է��� �� �ֽ��ϴ�.\n");
			}
		} while (!(*lv == '1' || *lv == '2' || *lv == '3'));
		*lv -= 48;
	}
	system("pause");
}

void stage2_inst(char* name, int word_time_limit) {

	system("cls");
	printf("\nSTAGE 2\n\n");
	printf("%s ��/�� �����߿� ����� �濡 �����ϰ� �ȴ�.\n", name);
	printf("�� �ȿ��� Ŀ�ٶ� ��, �ٽǸ���ũ�� ���� �ο�� �Ǵµ�...\n\n");
	printf("*����ȭ��*\n\n");
	printf("1. ȭ�� ��ܿ� ��µǴ� ���ܾ [%d] �� �ȿ� �Է��Ͽ� �ٽǸ���ũ�� ������ �� �ֽ��ϴ�.\n\n", word_time_limit / 2);
	printf("2. [%d] �� �ȿ� �������� ���ϰų�, �߸� �Է��ߴٸ� ���ݿ� �����մϴ�.\n\n", word_time_limit / 2);
	printf("3. �ٽǸ���ũ�� [%d] �� �ȿ� ����ġ�� ���ϸ� ���� �����˴ϴ�.\n\n", STAGE_LIMIT_TIME);
	printf("4. ���ܾ� �Է��� �������� �����ϸ� �޺��� �׿� �� ���� �������� �� �� �ֽ��ϴ�.\n\n");
	printf("5. �������� ���ѽð� [%d] �� �߿� ���� �ð��� ������ �˴ϴ�.\n\n", STAGE_LIMIT_TIME);
	system("pause");

}

void stage3_inst(char* name, int word_time_limit) {

	system("cls");
	printf("\nSTAGE 3\n");
	printf("\n����� �濡�� ���� %s ��/�� ����ī�� ������ �����ϰ� �ȴ�..\n", name);
	printf("�� ������ ����ī���� ����, ����͸� ���� �ο�� �Ǵµ�...\n\n");
	printf("*����ȭ��*\n\n");
	printf("1. ȭ�� ��ܿ� ��µǴ� ���ܾ [%d] �� �ȿ� �Է��Ͽ� ����͸� ������ �� �ֽ��ϴ�.\n\n", word_time_limit / 2); // ���� 
	printf("2. [%d] �� �ȿ� �������� ���ϰų�, �߸� �Է��ߴٸ� ���ݿ� �����մϴ�.\n\n", word_time_limit / 2);
	printf("3. ����͸� [%d] �� �ȿ� ����ġ�� ���ϸ� ���� �����˴ϴ�.\n\n", STAGE_LIMIT_TIME);
	printf("4. ���ܾ� �Է��� �������� �����ϸ� �޺��� �׿� �� ���� �������� �� �� �ֽ��ϴ�.\n\n");
	printf("5. �������� ���ѽð� [%d] �� �߿� ���� �ð��� ������ �˴ϴ�.\n\n", STAGE_LIMIT_TIME);

	system("pause");
}

void stage4_inst(char* name, int word_time_limit) {

	system("cls");
	printf("\nSTAGE 4\n");
	printf("\n����͸� ����ģ %s ��/�� ���� �������� ���� �б��� ����, ������� ������.\n", name);
	printf("������� ����Ͽ� �׿��� ���� ���並 ����. \n\n");
	printf("*����ȭ��*\n\n");
	printf("1. ȭ�� ��ܿ� ��µǴ� ���ܾ [%d] �� �ȿ� �Է��Ͽ� ����� ������ �� �ֽ��ϴ�.\n\n", word_time_limit / 2);
	printf("2. [%d] �� �ȿ� �������� ���ϰų�, �߸� �Է��ߴٸ� ���ݿ� �����մϴ�.\n\n", word_time_limit / 2);
	printf("3. ��������� ����� [%d] �� �ȿ� �¸��Ͽ� ���� ���並 ���� �� �ֽ��ϴ�.\n\n", STAGE_LIMIT_TIME);
	printf("4. ���ܾ� �Է��� �������� �����ϸ� �޺��� �׿� �� ���� �������� �� �� �ֽ��ϴ�.\n\n");
	printf("5. �������� ���ѽð� [%d] �� �߿� ���� �ð��� ������ �˴ϴ�.\n\n", STAGE_LIMIT_TIME);
	system("pause");
}

void stage5_inst(char* name, int word_time_limit, int cleared) {
	char* clear[] = { "�й���","�¸���" };
	system("cls");
	printf("\nSTAGE 5\n");
	printf("\n��������� ��ÿ��� %s %s ��/�� ���� ���, �ø��콺�� ������..\n", clear[cleared], name);
	printf("�ø��콺�� ����Ͽ� �׿��� ���ѳ��� �����̸� ����. \n\n");
	printf("*����ȭ��*\n\n");
	printf("1. ȭ�� ��ܿ� ��µǴ� ���ܾ [%d] �� �ȿ� �Է��Ͽ� �ø��콺�� ������ �� �ֽ��ϴ�.\n\n", word_time_limit / 2);
	printf("2. [%d] �� �ȿ� �������� ���ϰų�, �߸� �Է��ߴٸ� ���ݿ� �����մϴ�.\n\n", word_time_limit / 2);
	printf("3. �ø��콺���� ����� [%d] �� �ȿ� �¸��Ͽ� ���ѳ��� �����̸� ���� �� �ֽ��ϴ�.\n\n", STAGE_LIMIT_TIME);
	printf("4. ���ܾ� �Է��� �������� �����ϸ� �޺��� �׿� �� ���� �������� �� �� �ֽ��ϴ�.\n\n");
	printf("5. �������� ���ѽð� [%d] �� �߿� ���� �ð��� ������ �˴ϴ�.\n\n", STAGE_LIMIT_TIME);
	system("pause");
}

void stage6_inst(char* name, int word_time_limit, int cleared) {
	char* clear[] = { "�й���","�¸���" };
	system("cls");
	printf("\nSTAGE 6\n");
	printf("\n �ø��콺���� ��ÿ��� %s %s ��/�� ���߽����� ����,���������� ������. \n", clear[cleared], name);
	printf("���������� ����Ͽ� �׿��� ��Ȱ�� ���� ����. \n\n");
	printf("*����ȭ��*\n\n");
	printf("1. ȭ�� ��ܿ� ��µǴ� ���ܾ [%d] �� �ȿ� �Է��Ͽ� ���������� ������ �� �ֽ��ϴ�.\n\n", word_time_limit / 2);
	printf("2. [%d] �� �ȿ� �������� ���ϰų�, �߸� �Է��ߴٸ� ���ݿ� �����մϴ�.\n\n", word_time_limit / 2);
	printf("3. ������������ ����� [%d] �� �ȿ� �¸��Ͽ� ��Ȱ�� ���� ���� �� �ֽ��ϴ�.\n\n", STAGE_LIMIT_TIME);
	printf("4. ���ܾ� �Է��� �������� �����ϸ� �޺��� �׿� �� ���� �������� �� �� �ֽ��ϴ�.\n\n");
	printf("5. �������� ���ѽð� [%d] �� �߿� ���� �ð��� ������ �˴ϴ�.\n\n", STAGE_LIMIT_TIME);
	system("pause");

}

void stage7_inst(char* name, int word_time_limit, int cleared)
{
	char* clear[] = { "�й���","�¸���" };
	system("cls");
	printf("\nSTAGE 7\n");
	printf("\n������������ ��ÿ��� %s %s ��/�� �ᱹ ����� ������, �����Ʈ�� ������.\n\n", clear[cleared], name);
	printf("���� %s ��/�� �����Ʈ�� ����ġ�� ���� ���踦 ���� �� ���� ���ΰ�? \n\n", name);
	printf("1. ȭ�� ��ܿ� ��µǴ� ���ܾ [%d] �� �ȿ� �Է��Ͽ� �����Ʈ�� ������ �� �ֽ��ϴ�.\n\n", word_time_limit / 2);
	printf("2. [%.1f] �� �ȿ� �������� ���ϰų�, �߸� �Է��ߴٸ� ���ݿ� �����ϰ�, hp�� �����մϴ�.\n\n", TIME_V_LIMIT / 2.0);
	printf("3. ���ܾ� �Է��� �������� �����ϸ� �޺��� �׿� �� ���� �������� �� �� �ֽ��ϴ�.\n\n");
	printf("4. ���ݱ����� ������ ����� HP�� ȯ��˴ϴ�.\n\n");
	printf("5. ȭ�� ����� ���ܾ�� ������ �����Ʈ�� ���� ���ܾ ��µǸ�, �̸� [%d] �� �ȿ� �Է��Ͽ�\n", word_time_limit / 2);
	printf("���� ������ ����� �� �ֽ��ϴ�.\n\n");
	printf("6. ���ݱ��� ���� �������� (1/2/3)�� �Է��Ͽ� ����� �� �ֽ��ϴ�.\n\n");
	printf("7. �����Ʈ�� ����ġ�� ���� ����� HP, ���̵��� ���� ���� ������ �����˴ϴ�.\n\n");
	printf("8. �������� ���� �ʰ� �����Ʈ�� ����ġ�� ���� ���� ������ �� ���ʽ� ������ �־����ϴ�.\n\n");
	system("pause");
}