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
    int integerN;   //��������
    int decimalN;   //С������
    number_t *top;      //���λ��
    number_t *digits;   //��λ��
    number_t *dotStart; //С��
    number_t *low;      //���λ��
}pNumber_t;

int charChangeToInt(char c){
    int ans=0;
    //��Ԫ�D����
    return ans;
}

void change(pNumber_t *a, char *string){
    //�������g
    //
}

void input(pNumber_t *a, pNumber_t *b, int *N){
    char inString[122]={' '};   //����60 + С���c(1) + С��60 + �Y����̖(1) = 122
    gets(inString);
    ////�D�Q
    gets(inString);
    ////�D�Q
    scanf("%d", N); //ݔ��Ҫݔ����С���c��ڎ�λ
}

void output(pNumber_t ans, int N){
    //ݔ��
}

void add(pNumber_t *a, pNumber_t *b, pNumber_t ans, int N){
    //�ӷ�
    output(ans, N);
}

int isBig(pNumber_t *a, pNumber_t *b){
    return 0;
}

void sub(pNumber_t *a, pNumber_t *b, pNumber_t ans, int N){
    //�p��
    if(isBig(a, b)){
        add(a, b, ans, N);
    }
    else{
        add(b, a, ans, N);
    }
}

void mul(pNumber_t *a, pNumber_t *b, pNumber_t ans, int N){
    //�˷�
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
