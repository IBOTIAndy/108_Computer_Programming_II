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
    unsigned int isNeg: 1;
    int integerN;   //整數數量
    int decimalN;   //小數數量
    number_t *top;      //最高位數
    number_t *digits;   //個位數
    number_t *dotStart; //小數
    number_t *low;      //最低位數
}pNumber_t;

int charChangeToInt(char c){
    return c - '0';
}

number_t* createNumber(char c){
    number_t *newNumber = (number_t*)malloc(sizeof(number_t));
    newNumber->number = charChangeToInt(c);
    newNumber->nextR = NULL;
    newNumber->beforeL = NULL;
    return newNumber;
}

void change(pNumber_t *p, char *string){
    number_t *now, *before;
    if(*string == '-'){ //如果是負數
        p->isNeg = 1;   //標記為負數
        string++;       //對齊數字
    }

    //整數部分開始
    now = createNumber(*string);    //建立開頭
    p->top = now;                   //將開頭給予最高位數指標
    string++;                       //往下走
    p->integerN++;                  //整數部分數量+1
    while(*string != '.'){  //處理整數部分
        before = now;                   //前一個繼承現在的位置
        now = createNumber(*string);    //建立新的數字
        before->nextR = now;            //連結前後兩個數字
        now->beforeL = before;          //
        string++;                       //往下走
        p->integerN++;                  //整數部分數量+1
    }
    p->digits = now;    //紀錄個位數位置
    //整數部分結束

    string++;   //跳過小數點

    //小數部分開始
    before = now;                   //前一個繼承現在的位置
    now = createNumber(*string);    //建立小數點開始位置
    before->nextR = now;            //連結前後兩個數字
    now->beforeL = before;          //
    p->dotStart = now;              //紀錄小數點起始位置
    string++;                       //往下走
    p->decimalN++;                  //小數部分數量+1
    while(*string != '\0'){ //處理小數部分
        before = now;                   //前一個繼承現在的位置
        now = createNumber(*string);    //建立新的數字
        before->nextR = now;            //連結前後兩個數字
        now->beforeL = before;          //
        string++;                       //往下走
        p->decimalN++;                  //小數部分數量+1
    }
    p->low = now;   //紀錄最低位數
    //小數部分結束

}

void input(pNumber_t *a, pNumber_t *b, int *N){
    char inString[122]={' '};   //整數60 + 小數點(1) + 小數60 + 結束符號(1) = 122
    gets(inString);
    change(a, inString);    //轉換
    gets(inString);
    change(b, inString);    //轉換
    scanf("%d", N); //輸入要輸出到小數點後第幾位
}

void output(pNumber_t ans, int N){
    int i=0;
    number_t *temp;
    if(ans.isNeg){      //如果是負數，輸出負號
        printf("-");
    }

    temp = ans.top; //整數輸出
    for(i=0; i < ans.integerN; i++, temp = temp->nextR){
        printf("%d", temp->number);
    }

    if(ans.decimalN != 0){  //如果有小數
        if(N != 0){         //並且要輸出小數

            //小數輸出
//            temp = ans.dotStart;
            printf(".");
            for(i=0; i < N && i < ans.decimalN; i++, temp = temp->nextR){
                printf("%d", temp->number);
            }
//            for(; i < N; i++){
//                printf("0");
//            }
        }
    }
    printf("\n");
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
    pNumber_t a = {0, 0, 0, NULL, NULL, NULL, NULL};
    pNumber_t b = {0, 0, 0, NULL, NULL, NULL, NULL};
    pNumber_t ans = {0, 0, 0, NULL, NULL, NULL, NULL};
    input(&a, &b, &N);
//    output(a, 60);         //檢查用
//    output(b, 60);         //檢查用
    add(&a, &b, ans, N);
    sub(&a, &b, ans, N);
    mul(&a, &b, ans, N);
}

int main(){
    f1();
//    printf("Hello world!\n");
    return 0;
}
