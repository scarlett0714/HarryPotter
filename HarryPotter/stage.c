#include "my.h"

//0=�ٽ��ϱ� 1=��������Ŭ���� 7=����Ŭ����
char stageEnd(char stage, char cleared, long time, char* item) {
    char retry_input = 0;
    if (cleared) {
        printf("\n %ld �� ���� ", STAGE_LIMIT_TIME - time);
        switch (stage) {
        case 2:
            printf("�ٽǸ���ũ���� ��ῡ�� �¸��Ͽ����ϴ�!\n");
            break;
        case 3:
            printf("����Ϳ��� ��ῡ�� �¸��Ͽ����ϴ�!\n");
            break;
        case 4:
            printf("��������� ��ῡ�� �¸��Ͽ����ϴ�!\n");
            printf("������� ���� ���並 �޾ҽ��ϴ�\n");
            item[0] = 1;
            break;
        case 5:
            printf("�ø��콺���� ��ῡ�� �¸��Ͽ����ϴ�!\n");
            printf("�ø��콺���� ���ѳ��� �����̸� �޾ҽ��ϴ�\n");
            item[1] = 1;
            break;
        case 6:
            printf("������������ ��ῡ�� �¸��Ͽ����ϴ�!\n");
            printf("������������ ��Ȱ�� ���� �޾ҽ��ϴ�\n");
            item[2] = 1;
            break;
        case 7:
            return 7;
        }
        printf("�̹� ������������ ���� ���� : %ld\n", time);
        score += time;
        printf("������ ���� : %ld\n", score);
        return 1;
    }
    else {
        switch (stage) {
        case 2:
            printf("�ٽǸ���ũ���� ��ῡ�� �й��Ͽ����ϴ�\n");
            break;
        case 3:
            printf("����Ϳ��� ��ῡ�� �й��Ͽ����ϴ�\n");
            break;
        case 4:
            printf("��������� ��ῡ�� �й��Ͽ����ϴ�\n");
            printf("���� ���並 ���� ���Ͽ����ϴ�\n");
            item[0] = 0;
            break;
        case 5:
            printf("�ø��콺���� ��ῡ�� �й��Ͽ����ϴ�\n");
            printf("���ѳ��� �����̸� ���� ���Ͽ����ϴ�\n");
            item[1] = 0;
            break;
        case 6:
            printf("������������ ��ῡ�� �й��Ͽ����ϴ�\n");
            printf("��Ȱ�� ���� ���� ���Ͽ����ϴ�\n");
            item[2] = 0;
            break;
        }
        if (stage < 4 || stage == 7) {
            do {
                printf("�ٽ� �Ͻðڽ��ϱ�? (y/n) ");
                retry_input = _getche();//�޴��Է�
                if (retry_input != 0 && retry_input != 'y' && retry_input != 'n') {
                    printf("\ny �Ǵ� n�� �Է��Ͻ� �� �ֽ��ϴ�.\n");
                }
            } while (retry_input != 0 && retry_input != 'y' && retry_input != 'n');
            for (int i = 0; i < 3; i++)
                item[i] = (item[i] == 2 || item[i] == 1) ? 1 : 0; //�߰�
            if (retry_input == 'n')
                exit(0);
            else if (retry_input == 'y')
                return 0;
        }
        else {
            printf("�̹� ������������ ���� ���� : 0\n\n");
            printf("������ ���� : %ld\n", score);
        }
    }
}