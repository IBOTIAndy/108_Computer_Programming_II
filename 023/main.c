#include <stdio.h>
#include <stdlib.h>
//023 一日N塔
//2020/05/19 PM. 02:57 IBOTIAndy

void input(int *n, int cityToCity[][10]){
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

int allArrival(int isArrival[], int n){ //檢查是不是全部城市都走過
    int i=0;
    for(i=0; i < n; i++){
        if(isArrival[i] == 0){  //如果有任何的城市還沒走過
            return 0;           //回傳 false
        }
    }           //全部都走過了
    return 1;   //回傳 ture
}

int oneDayNTower(int start, int n, int cityToCity[][10], int isArrival[]){
    int i=0, temp=0, startTemp=0;
    temp = 9999;
    isArrival[start - 1] = 1;   //將該座城市紀錄為已經走過
    if(allArrival(isArrival, n)){   //如果全部的城市都走過了
        return 0;   //結束，並計算前面走過的路
    }
    else{
        for(i=0; i < n; i++){   //搜尋該座城市與哪座城市的距離最近
            if(i+1 != start){   //如果比對的不是所在城市
                if(!isArrival[i]){  //並且不是已經走過的城市
                    if(temp > cityToCity[start-1][i]){  //如果找到更近的城市
                        temp = cityToCity[start-1][i];  //記錄城市距離
                        startTemp = i + 1;              //記錄城市編號
                    }
                }
            }
        }   //繼續往下一座城市前進，並記錄之前走過的距離
        return oneDayNTower(startTemp, n, cityToCity, isArrival) + temp;
    }
}

void output(int distance){
    printf("經過所有城市的最短距離為：");
    printf("%d\n", distance);
}

void f1(){
    int cityToCity[10][10]={{0}};
    int n=0, isArrival[10]={0};
    int distance=0;
    input(&n, cityToCity);
    distance = oneDayNTower(1, n, cityToCity, isArrival);
    output(distance);
}

int main(){
    f1();
//    printf("Hello world!\n");
    return 0;
}
