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
    int integerN;   //��������
    int decimalN;   //С������
    number_t *top;      //���λ��
    number_t *digits;   //��λ��
    number_t *dotStart; //С��
    number_t *low;      //���λ��
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
    if(*string == '-'){ //�����ؓ��
        p->isNeg = 1;   //��ӛ��ؓ��
        string++;       //���R����
    }

    //���������_ʼ
    now = createNumber(*string);    //�����_�^
    p->top = now;                   //���_�^�o�����λ��ָ��
    string++;                       //������
    p->integerN++;                  //�������֔���+1
    while(*string != '.'){  //̎����������
        before = now;                   //ǰһ���^�ЬF�ڵ�λ��
        now = createNumber(*string);    //�����µĔ���
        before->nextR = now;            //�B�Yǰ��ɂ�����
        now->beforeL = before;          //
        string++;                       //������
        p->integerN++;                  //�������֔���+1
    }
    p->digits = now;    //�o䛂�λ��λ��
    //�������ֽY��

    string++;   //���^С���c

    //С�������_ʼ
    before = now;                   //ǰһ���^�ЬF�ڵ�λ��
    now = createNumber(*string);    //����С���c�_ʼλ��
    before->nextR = now;            //�B�Yǰ��ɂ�����
    now->beforeL = before;          //
    p->dotStart = now;              //�o�С���c��ʼλ��
    string++;                       //������
    p->decimalN++;                  //С�����֔���+1
    while(*string != '\0'){ //̎��С������
        before = now;                   //ǰһ���^�ЬF�ڵ�λ��
        now = createNumber(*string);    //�����µĔ���
        before->nextR = now;            //�B�Yǰ��ɂ�����
        now->beforeL = before;          //
        string++;                       //������
        p->decimalN++;                  //С�����֔���+1
    }
    p->low = now;   //�o����λ��
    //С�����ֽY��

}

void input(pNumber_t *a, pNumber_t *b, int *N){
    char inString[122]={' '};   //����60 + С���c(1) + С��60 + �Y����̖(1) = 122
    gets(inString);
    change(a, inString);    //�D�Q
    gets(inString);
    change(b, inString);    //�D�Q
    scanf("%d", N); //ݔ��Ҫݔ����С���c��ڎ�λ
}

void output(pNumber_t ans, int N){
    int i=0;
    number_t *temp;
    if(ans.isNeg){      //�����ؓ����ݔ��̖ؓ
        printf("-");
    }

    temp = ans.top; //����ݔ��
    for(i=0; i < ans.integerN; i++, temp = temp->nextR){
        printf("%d", temp->number);
    }

    if(ans.decimalN != 0){  //�����С��
        if(N != 0){         //�K��Ҫݔ��С��

            //С��ݔ��
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
    pNumber_t a = {0, 0, 0, NULL, NULL, NULL, NULL};
    pNumber_t b = {0, 0, 0, NULL, NULL, NULL, NULL};
    pNumber_t ans = {0, 0, 0, NULL, NULL, NULL, NULL};
    input(&a, &b, &N);
//    output(a, 60);         //�z����
//    output(b, 60);         //�z����
    add(&a, &b, ans, N);
    sub(&a, &b, ans, N);
    mul(&a, &b, ans, N);
}

int main(){
    f1();
//    printf("Hello world!\n");
    return 0;
}
