#include <stdio.h>
#include <stdlib.h>
//029 use structure to math long number
//2020/05/31 pm. 03:36 ~ pm.04:44 IBOTIAndy
//1:08 = 1:08 +
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

number_t* createNumber(int number){
    number_t *newNumber = (number_t*)malloc(sizeof(number_t));
    newNumber->number = number;
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
    now = createNumber(charChangeToInt(*string));   //�����_�^
    p->top = now;                                   //���_�^�o�����λ��ָ��
    string++;                                       //������
    p->integerN++;                                  //�������֔���+1
    while(*string != '.'){  //̎����������
        before = now;                                   //ǰһ���^�ЬF�ڵ�λ��
        now = createNumber(charChangeToInt(*string));   //�����µĔ���
        before->nextR = now;                            //�B�Yǰ��ɂ�����
        now->beforeL = before;                          //
        string++;                                       //������
        p->integerN++;                                  //�������֔���+1
    }
    p->digits = now;    //�o䛂�λ��λ��
    //�������ֽY��

    string++;   //���^С���c

    //С�������_ʼ
    before = now;                                   //ǰһ���^�ЬF�ڵ�λ��
    now = createNumber(charChangeToInt(*string));   //����С���c�_ʼλ��
    before->nextR = now;                            //�B�Yǰ��ɂ�����
    now->beforeL = before;                          //
    p->dotStart = now;                              //�o�С���c��ʼλ��
    string++;                                       //������
    p->decimalN++;                                  //С�����֔���+1
    while(*string != '\0'){ //̎��С������
        before = now;                                   //ǰһ���^�ЬF�ڵ�λ��
        now = createNumber(charChangeToInt(*string));   //�����µĔ���
        before->nextR = now;                            //�B�Yǰ��ɂ�����
        now->beforeL = before;                          //
        string++;                                       //������
        p->decimalN++;                                  //С�����֔���+1
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

int isBig(pNumber_t *a, pNumber_t *b){
    number_t *t1=NULL, *t2=NULL;
    if(a->integerN == b->integerN){ //�������
        t1 = a->top;
        t2 = b->top;
        while(t1 == NULL || t2 == NULL){    //ֱ������һ�����ܱ��^
            if(t1->number < t2->number){        //���t2�^��
                return 0;
            }
            else if(t1->number > t2->number){   //���t1�^��
                return 1;
            }
            t1 = t1->nextR;
            t2 = t2->nextR;
        }
        if(t1 == NULL && t2 == NULL){   //һ�Ӵ�
            return 0;
        }
        else if(t1 == NULL){    //t2�^��
            return 0;
        }
        else{   //t2 == NULL (t1�^��)
            return 1;
        }
    }
    else if(a->integerN < b->integerN){ //a < b -> ����� = 0
        return 0;
    }
    else{   //a > b -> ��� = 1
        return 1;
    }
}

int adder(int *carry, int n1, int n2){  //�ӷ���
    int sum=0;
    sum = n1 + n2 + *carry; //�� = ����1 + ����2 + �Mλ
    *carry = sum / 10;      //�Mλ = (�� / 10) ȡ��
    return sum % 10;        //��   = (�� / 10) ȡ�N
}


void add(pNumber_t *a, pNumber_t *b, pNumber_t ans, int N){
    int i=0, carry=0;
    number_t *now, *after;
    number_t *tA, *tB;
    tA = a->low;
    tB = b->low;
    if(a->integerN >= b->integerN){ //ȡ���������cС��
        ans.integerN = a->integerN;
    }
    else{
        ans.integerN = b->integerN;
    }
    if(a->decimalN >= b->decimalN){
        ans.decimalN = a->decimalN;
    }
    else{
        ans.decimalN = b->decimalN;
    }
    if(a->isNeg == b->isNeg){   //�����̖��ͬ
        ans.isNeg = a->isNeg;   //�o䛷�̖
        carry=0;
        i=ans.decimalN;
        if(i > a->decimalN){
             now = createNumber(adder(&carry, 0, ));
        }
        else if(i > b->decimalN){
             now = createNumber(adder(&carry, ));
        }
        else{
             now = createNumber(adder(&carry, ));
        }
        ans.low = now;
        while(i >= 0){  //��С���_ʼ��
            after = now;
            if(i > a->decimalN){
                 now = createNumber(adder(&carry, ));
            }
            else if(i > b->decimalN){
                 now = createNumber(adder(&carry, ));
            }
            else{
                 now = createNumber(adder(&carry, ));
            }
            now->nextR = after;
            after->beforeL = now;
            i--;

        }
    }
    else{

    }
    output(ans, N);
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
