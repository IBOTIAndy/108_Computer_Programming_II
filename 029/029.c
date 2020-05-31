#include <stdio.h>
#include <stdlib.h>
//029 use structure to math long number
//2020/05/31 pm. 03:36 IBOTIAndy
typedef struct number_s{
    int number;
    struct number_s *nextR;
    struct number_s *beforeL;
}number_t;

typedef struct pNumber_s{
    int integerN;   //整數數量
    int decimalN;   //小數數量
    number_t *top;      //最高位數
    number_t *digits;   //個位數
    number_t *dotStart; //小數
    number_t *low;      //最低位數
}pNumber_t;

int charChangeToInt(char c){
    int ans=0;
    //字元轉數字
    return ans;
}

void change(pNumber_t *a, char *string){
    //新增空間
    //
}

void input(pNumber_t *a, pNumber_t *b, int *N){
    char inString[122]={' '};   //整數60 + 小數點(1) + 小數60 + 結束符號(1) = 122
    gets(inString);
    ////轉換
    gets(inString);
    ////轉換
    scanf("%d", N); //輸入要輸出到小數點後第幾位
}

void output(pNumber_t ans, int N){
    //輸出
}

void add(pNumber_t *a, pNumber_t *b, pNumber_t ans, int N){
    //加法
    output(ans, N);
}

int isBig(pNumber_t *a, pNumber_t *b){
    return 0;
}

void sub(pNumber_t *a, pNumber_t *b, pNumber_t ans, int N){
    //減法
    if(isBig(a, b)){
        add(a, b, ans, N);
    }
    else{
        add(b, a, ans, N);
    }
}

void mul(pNumber_t *a, pNumber_t *b, pNumber_t ans, int N){
    //乘法
    output(ans, N);
}

void f1(){
    int N;
    pNumber_t a = {0, 0, NULL, NULL, NULL, NULL};
    pNumber_t b = {0, 0, NULL, NULL, NULL, NULL};
    pNumber_t ans = {0, 0, NULL, NULL, NULL, NULL};
    input(&a, &b, &N);
    add(&a, &b, ans, N);
    sub(&a, &b, ans, N);
    mul(&a, &b, ans, N);
}

int main(){
    f1();
//    printf("Hello world!\n");
    return 0;
}
