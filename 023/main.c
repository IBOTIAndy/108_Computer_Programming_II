#include <stdio.h>
#include <stdlib.h>
//023 �@��N��
//2020/05/19 PM. 02:23 IBOTIAndy

void input(int *n, int cityToCity[][20]){
    int i=0, j=0;
    printf("�п�J���X�y����(1~20)�G");
    scanf("%d", n);
    printf("�п�J�Ҧ������������Z���G\n");
    for(i=0; i < *n; i++){
        for(j=0; j < *n; j++){
            scanf("%d", &(cityToCity[i][j]));
        }
    }
}

void oneDayNTower(){
    int cityToCity[20][20]={{0}};
    int n=0, isArrival[20]={0};
    input(&n, cityToCity);
}

int main(){
    oneDayNTower();
//    printf("Hello world!\n");
    return 0;
}
