#include <stdio.h>
#include <stdlib.h>
//023 一日N塔
//2020/05/19 PM. 02:23 IBOTIAndy

void input(int *n, int cityToCity[][20]){
    int i=0, j=0;
    printf("請輸入有幾座城市(1~20)：");
    scanf("%d", n);
    printf("請輸入所有城市之間的距離：\n");
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
