#include <stdio.h>

int main(){
    int size; //별의 갯수 빈칸 의 갯수 빈칸 의 갯수 
    int stars, blank1, blank2; // , 1 , 2 반복문을 위한 변수
    
    printf("크기를 입력하시오.\n");
    scanf("%d", &size);

    blank1 = 0;
    blank2 = size * 2-2;

    //1. 위 쪽 V표시 만들기.

    for(int i=0; i<size; i++){
    for(int b = 0; b < blank1; b++){
        printf(" ");
    }
    
    printf("*");
    
    for(int b = 0; b < blank2; b++){
        printf(" ");
    }

    printf("*\n");

    blank1++;
    blank2 = blank2-2;
    }
     
    //2. 아래쪽 내려가는 V 만들기.
    blank1 = 0; // blank 1 초기화.
    stars = size*2; // 별의 갯수 초기화.

    // size만큼 사각형 만들기
    for(int j=0; j<size; j++){
        for(int i=0; i<size*2; i++){
            printf("*");
        }
        printf("\n");
    }

    // 밑 부분(삼각형) 만들기
    for(int i=0; i<size; i++){
        for(int b=0; b<blank1; b++){
            printf(" ");
        }
        for(int s=0; s<stars; s++){
            printf("*");
        }
        printf("\n");
        blank1++;
        stars = stars - 2;
    }

    //3. 아래 받침대 만들기
    for(int i=0; i<size*2; i++){
        printf("*");
    }

    return 0;
}