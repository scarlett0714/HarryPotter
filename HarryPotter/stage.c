#include "my.h"

//0=다시하기 1=스테이지클리어 7=게임클리어
char stageEnd(char stage, char cleared, long time, char* item) {
    char retry_input = 0;
    if (cleared) {
        printf("\n %ld 초 만에 ", STAGE_LIMIT_TIME - time);
        switch (stage) {
        case 2:
            printf("바실리스크와의 대결에서 승리하였습니다!\n");
            break;
        case 3:
            printf("디멘터와의 대결에서 승리하였습니다!\n");
            break;
        case 4:
            printf("덤블도어와의 대결에서 승리하였습니다!\n");
            printf("덤블도어에게 투명 망토를 받았습니다\n");
            item[0] = 1;
            break;
        case 5:
            printf("시리우스와의 대결에서 승리하였습니다!\n");
            printf("시리우스에게 딱총나무 지팡이를 받았습니다\n");
            item[1] = 1;
            break;
        case 6:
            printf("스네이프와의 대결에서 승리하였습니다!\n");
            printf("스네이프에게 부활의 돌을 받았습니다\n");
            item[2] = 1;
            break;
        case 7:
            return 7;
        }
        printf("이번 스테이지에서 얻은 점수 : %ld\n", time);
        score += time;
        printf("누적된 점수 : %ld\n", score);
        return 1;
    }
    else {
        switch (stage) {
        case 2:
            printf("바실리스크와의 대결에서 패배하였습니다\n");
            break;
        case 3:
            printf("디멘터와의 대결에서 패배하였습니다\n");
            break;
        case 4:
            printf("덤블도어와의 대결에서 패배하였습니다\n");
            printf("투명 망토를 얻지 못하였습니다\n");
            item[0] = 0;
            break;
        case 5:
            printf("시리우스와의 대결에서 패배하였습니다\n");
            printf("딱총나무 지팡이를 얻지 못하였습니다\n");
            item[1] = 0;
            break;
        case 6:
            printf("스네이프와의 대결에서 패배하였습니다\n");
            printf("부활의 돌을 얻지 못하였습니다\n");
            item[2] = 0;
            break;
        }
        if (stage < 4 || stage == 7) {
            do {
                printf("다시 하시겠습니까? (y/n) ");
                retry_input = _getche();//메뉴입력
                if (retry_input != 0 && retry_input != 'y' && retry_input != 'n') {
                    printf("\ny 또는 n만 입력하실 수 있습니다.\n");
                }
            } while (retry_input != 0 && retry_input != 'y' && retry_input != 'n');
            for (int i = 0; i < 3; i++)
                item[i] = (item[i] == 2 || item[i] == 1) ? 1 : 0; //추가
            if (retry_input == 'n')
                exit(0);
            else if (retry_input == 'y')
                return 0;
        }
        else {
            printf("이번 스테이지에서 얻은 점수 : 0\n\n");
            printf("누적된 점수 : %ld\n", score);
        }
    }
}