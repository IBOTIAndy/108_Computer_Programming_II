#include <stdio.h>
#include <stdlib.h>
//017 ����ƹB��
//2020/04/18 PM. 04:55 IBOTIAndy

void push(int number[], int n){     //�N�}�C����Ʃ�����An ���ثe�̰��줸
    int i=0;
    for(i=n; i > 0; i--){           //���_�a���A����N�Ӧ�Ʊ���
        number[i] = number[i-1];    //���줸���o�C�줸����
    }
}

void stringToInt(char s[], int number[], int n){    //�r���}�C�ର��ư}�C
    int i=0;
    while(s[i] != '\0' && i < n){   //���쵲���Ÿ��άO�W�X�W��
        push(number, i);            //�N�Ʀr�����줸���A���Ӧ�Ʒ|�ݦb�}�C��[0]
        number[0] = s[i] - '0';     //�Ӧ�Ʃ��}�C�_�l��m�A��K����p��
        i = i + 1;                  //
    }
}

void input(int *mathO, int number1[], int number2[], int n){    //��J
    char inputString[50]={' '}, eatEnter=' ';
    scanf("%d%c", mathO, &eatEnter);        //��J�n�ϥΪ��B��
    gets(inputString);                      //��J�����1
    stringToInt(inputString, number1, n);   //�r���}�C�ର��ư}�C
    gets(inputString);                      //��J�����2
    stringToInt(inputString, number2, n);   //�r���}�C�ର��ư}�C
}

int adder(int *carry, int n1, int n2){  //�[�k��
    int sum=0;
    sum = n1 + n2 + *carry; //�M = �Ʀr1 + �Ʀr2 + �i��
    *carry = sum / 10;      //�i�� = (�M / 10) ����
    return sum % 10;        //�M   = (�M / 10) ���l
}

void adderBigNumber(int number1[], int number2[], int ans[], int n){    //�[�k
    int i=0, carry=0;
    for(i=0; i < n; i++){
        ans[i] = adder(&carry, number1[i], number2[i]); //�^�ǩM(sum) <= �[�k���G(�i��, �Ʀr1, �Ʀr2)
    }
}

int suber(int *borrow, int n1, int n2){ //��k��
    int dif=0;
    n2 = n2 + *borrow;  //���N�ɦ��ٵ��Q���
    if(n1 < n2){        //�p�G�Ʀr1 ���p�A���ɦ�
        *borrow = 1;    //�ɦ�
        n1 = n1 + 10;   //+10
    }
    else{               //�p�G��n�θ��j�A�����ɦ�
        *borrow = 0;    //���ɦ�
    }
    dif = n1 - n2;      //�t = �Ʀr1 - �Ʀr2
    return dif;         //�^�� �t

}

int num1Big(int number1[], int number2[], int n){   //�����Ƥj�p
    int i=0;
    for(i=n-1; i >= 0; i--){                        //�����̰����
        if(number1[i] > 0 && number2[i] == 0){      //�p�G�ƶq num1 > num2
            return 1;                               //num1 ����j
        }
        else if(number2[i] > 0 && number1[i] == 0){ //�p�G�ƶq num1 < num2
            return 0;                               //num2 ����j
        }
        else if(number1[i] != 0 && number2 != 0){   //�p�G�ƶq�@�˦h
            break;                                  //���X�j��
        }
    }
    for(; i >= 0; i--){                     //���ڤj�p
        if(number1[i] > number2[i]){        //�p�G num1 �̰���Ƹ��j
            return 1;                       //num1 ����j
        }
        else if(number2[i] > number1[i]){   //�p�G num2 �̰���Ƹ��j
            return 0;                       //num2 ����j
        }
    }                                   //�j�鵲���A��Ƭ۵�
    return 2;   //��Ƭ۵�
}

void suberBigNumber(int number1[], int number2[], int ans[], int n){    //��k
    int i=0, borrow=0;
    for(i=0; i < n; i++){
        ans[i] = suber(&borrow, number1[i], number2[i]);    //�^�Ǯt(dif) <= ��k���G(�ɦ�, �Ʀr1, �Ʀr2)
    }
}

void negative(int ans[], int n){    //�[�W�t��
    int i=0;
    for(i=n-1; i >= 0; i--){
        if(ans[i] != 0){
            ans[i] = 0 - ans[i];
            break;
        }
    }
}

void bigNumberMath(int mathO, int number1[], int number2[], int ans[], int n){
    switch(mathO){
        case 1:     // +
            adderBigNumber(number1, number2, ans, n);
            break;
        case 2:     // -
            if(num1Big(number1, number2, n)){           //�P�_�֤���j
                suberBigNumber(number1, number2, ans, n);   //�j�ƴ�p��
            }
            else{
                suberBigNumber(number2, number1, ans, n);   //�j�ƴ�p��
                negative(ans, n);                           //��[�t��
            }
            break;
        case 3:     // *
            //multBigNumber(number1, number2, ans, n);
            break;
        default:
            printf("ERROR from \"mathO\"\n");
    }
}

int main(){
    int mathO=0, number1[50]={0}, number2[50]={0}, ans[100]={0};
    input(&mathO, number1, number2, 50);
    bigNumberMath(mathO, number1, number2, ans, 50);
    //output(ans, 100);
//    printf("Hello world!\n");
    return 0;
}
