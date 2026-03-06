#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu();
int findRoom(int persons[5]);
int addMan(int mc, char mn[10][20], int mr[10], int manRoomCount[5]);
int addWoman(int wc, char wn[10][20], int wr[10], int womanRoomCount[5]);
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc);

int main() {
    char mn[10][20]; // 남학생 이름
    int mr[10];  // 남학생 배정된 호실번호 배열
    int mc = 0; // 등록된 총 남학생 수
    
    char wn[10][20]; // 여학생 이름
    int wr[10];  // 여학생 배정된 호실 번호 배열
    int wc = 0; // 등록된 총 여학생 수
    
    int manRoomCount[5] = {0}; // 각각의 남자 방에 현재 인원 수
    int womanRoomCount[5] = {0}; // 각각의 여자 방에 현재 인원 수

    int menu = 1; // 메뉴값

    printf("==========================================\n");
    printf("생활관 호실 배정 프로그램\n");
    printf("==========================================\n");

    while (menu != 0) {
        printMenu();
        scanf("%d", &menu);

        switch (menu) {
            case 0:
                break; 

            case 1:
                mc = addMan(mc, mn, mr, manRoomCount); 
                break;

            case 2:
                wc = addWoman(wc, wn, wr, womanRoomCount);
                break;

            default:
                printf("잘못된 입력입니다. 다시 선택해주세요.\n");
                break;
        }
    }

    printReport(mn, mr, mc, wn, wr, wc);

    return 0;
}

// 1. 메뉴
void printMenu() {
    printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
}

// 2. 배정할 호실 찾기 함수
int findRoom(int persons[5]) {
    int room = 0;

    while(1) {
        room = rand() % 5;
        if (persons[room] < 2) {
            room++;
            return room; 
        }
    }
}

// 3. 남학생 추가
int addMan(int mc, char mn[10][20], int mr[10], int manRoomCount[5]) {
    int roomNum = 0;
    
    if (mc >= 10) {
        printf("등록인원의 최대는 10명 입니다. \n");
        return mc; 
    }
    
    printf("학생 이름은? > ");
    scanf("%s", mn[mc]);

    roomNum = findRoom(manRoomCount); 
    manRoomCount[roomNum - 1]++;      
    mr[mc] = 100 + roomNum;     

    printf("%s 학생 %d호실 배정되었습니다.\n", mn[mc], mr[mc]);
    mc++;

    return mc;
}

// 4. 여학생 추가
int addWoman(int wc, char wn[10][20], int wr[10], int womanRoomCount[5]) {
    int roomNum = 0;
    
    if (wc >= 10) {
        printf("등록인원의 최대는 10명 입니다. \n");
        return wc; 
    }
    
    printf("학생 이름은? > ");
    scanf("%s", wn[wc]);

    roomNum = findRoom(womanRoomCount); 
    womanRoomCount[roomNum - 1]++;      
    wr[wc] = roomNum + 200 ;     

    printf("%s 학생 %d호실 배정되었습니다.\n", wn[wc], wr[wc]);
    wc++;

    return wc;
}

// 5. 최종 결과 출력
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc) {
    printf("==========================================\n");
    printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
    printf("==========================================\n");
    
    printf("남학생 명단 (%d명)\n", mc);
    for(int i = 0; i < mc; i++) {
        printf("%d. %s [%d호]\n", i + 1, mn[i], mr[i]);
    }
    
    printf("\n여학생 명단 (%d명)\n", wc);
    for(int i = 0; i < wc; i++) {
        printf("%d. %s [%d호]\n", i + 1, wn[i], wr[i]);
    }
    
    printf("\n호실별 배정 명단\n");
    for(int room = 0; room < 5; room++) {
        printf("%d호 : ", (room+101));
        for(int i = 0; i < mc; i++) {
            if (mr[i] == (room+101)) {
                printf("%s ", mn[i]);
            }
        }
        printf("\n");
    }
    for(int room = 0; room < 5; room++) {
        printf("%d호 : ", (room+201));
        for(int i = 0; i < wc; i++) {
            if (wr[i] == (room+201)) {
                printf("%s ", wn[i]);
            }
        }
        printf("\n");
    }
}
