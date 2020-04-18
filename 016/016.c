#include <stdio.h>
#include <stdlib.h>
//016 分散度
//2020/04/19 AM.01:28 IBOTIAndy

void arrayEmpty(int array[], int n){
    int i=0;
    for(i=0; i < n; i++){
        array[i] = 0;
    }
}

void stringToInt(char s[], int number[], int n){    //字元陣列轉為整數陣列
    int i=0;
    while(s[i] != '\0' && i < n){   //直到結束符號或是超出上限
        push(number, i);            //將數字往高位元推，讓個位數會待在陣列的[0]
        number[0] = s[i] - '0';     //個位數放到陣列起始位置，方便後續計算
        i = i + 1;                  //
    }
}

void input(int array[], int *m, int n){
    char inString[20]={' '};
    gets(inString);
    stringToInt(inString, array, n);
    scanf("%d", m);
}

void f1(int array[], int m, int n){
}

int main(){
    int array[20]={0}, m=0;
    arrayEmpty(array, 20);
    input(array, &m, 20);
    f1(array, m, 20);

//    printf("Hello world!\n");
    return 0;
}
