#include <stdio.h>

int main(){
    int person[4][3]; // 4개 층별 3개 호실의 점호 인원 수
    int sum[3] = {0}; // 점호 인원 수 합계 (남, 여 전체)
    float ratio[3]; // 점호 인원 수 비율 (남, 여 전체)

    //1. 남자층 입력.
    printf("Check room (Men)\n");
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            printf("Room #%d0%d > ", (i+1), (j+1));
            scanf("%d", &person[i][j]);
            sum[0] = sum[0] + person[i][j];
        }
    }

    //2. 여자층 입력.
    printf("Check room (Women)\n");
    for(int i=2; i<4; i++){
        for(int j=0; j<3; j++){
            printf("Room #%d0%d > ", (i+1), (j+1));
            scanf("%d", &person[i][j]);
            sum[1] = sum[1] + person[i][j];
        }
    }

    //3. 합계와 비율
    sum[2] = sum[1] + sum[0];
    ratio[0] = (float)sum[0] / 24.0 * 100.0;
    ratio[1] = (float)sum[1] / 24.0 * 100.0;
    ratio[2] = (float)sum[2] / 48.0 * 100.0;

    //4. 결과 출력
    printf("Check Result \n");
    printf("Men : %d/24 (%.1f) %%\n", sum[0], ratio[0]);
    printf("Women : %d/24 (%.1f) %%\n", sum[1], ratio[1]);
    printf("Total : %d/24 (%.1f) %%\n", sum[2], ratio[2]);

    return 0; 
}

