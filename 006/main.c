#include <stdio.h>
#include <stdlib.h>

void input(int *course, int *hour, int classTime[]){
    int i=0;
    scanf("%d", course);
    scanf("%d", hour);
    for(i=0; i < *hour; i++){
        scanf("%d", &classTime[i]);
    }
}

void printConflict(int course1, int course2, int classTime){
    printf("%d and %d conflict on %d\n", course1, course2, classTime);
}

void findConflict(int course1, int hour1, int classTime1[], int course2, int hour2, int classTime2[]){
    int i=0, j=0;
    for(i=0; i < hour1; i++){
        for(j=0; j < hour2; j++){
            if(classTime1[i] == classTime2[j]){
                printConflict(course1, course2, classTime1[i]);
            }
        }
    }
}

void f1(){
    int course1=0, course2=0, course3=0;                                    //課程編號
    int hour1=0, hour2=0, hour3=0;                                          //課堂小時數
    int classTime1[4]={0}, classTime2[4]={0}, classTime3[4]={0};            //課堂時間
    input(&course1, &hour1, classTime1);                                    //輸入
    input(&course2, &hour2, classTime2);                                    //...
    input(&course3, &hour3, classTime3);                                    //...
    findConflict(course1, hour1, classTime1, course2, hour2, classTime2);   //課堂一 與 課堂二 比較衝堂時間
    findConflict(course1, hour1, classTime1, course3, hour3, classTime3);   //課堂一 與 課堂三 比較衝堂時間
    findConflict(course2, hour2, classTime2, course3, hour3, classTime3);   //課堂二 與 課堂三 比較衝堂時間
}

int main(){
    f1();       //
    return 0;
}
