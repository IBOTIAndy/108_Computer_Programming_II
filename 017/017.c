#include <stdio.h>
#include <stdlib.h>
//017 長整數運算
//2020/04/18 PM. 04:55 IBOTIAndy

void push(int number[], int n){     //將陣列的資料往後推，n 為目前最高位元
    int i=0;
    for(i=n; i > 0; i--){           //不斷地推，直到將個位數推走
        number[i] = number[i-1];    //高位元取得低位元的數
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

void input(int *mathO, int number1[], int number2[], int n){    //輸入
    char inputString[50]={' '}, eatEnter=' ';
    scanf("%d%c", mathO, &eatEnter);        //輸入要使用的運算
    gets(inputString);                      //輸入長整數1
    stringToInt(inputString, number1, n);   //字元陣列轉為整數陣列
    gets(inputString);                      //輸入長整數2
    stringToInt(inputString, number2, n);   //字元陣列轉為整數陣列
}

int adder(int *carry, int n1, int n2){  //加法器
    int sum=0;
    sum = n1 + n2 + *carry; //和 = 數字1 + 數字2 + 進位
    *carry = sum / 10;      //進位 = (和 / 10) 取商
    return sum % 10;        //和   = (和 / 10) 取餘
}

void adderBigNumber(int number1[], int number2[], int ans[], int n){    //加法
    int i=0, carry=0;
    for(i=0; i < n; i++){
        ans[i] = adder(&carry, number1[i], number2[i]); //回傳和(sum) <= 加法器：(進位, 數字1, 數字2)
    }
}

int suber(int *borrow, int n1, int n2){ //減法器
    int dif=0;
    n2 = n2 + *borrow;  //先將借位還給被減數
    if(n1 < n2){        //如果數字1 較小，須借位
        *borrow = 1;    //借位
        n1 = n1 + 10;   //+10
    }
    else{               //如果剛好或較大，不須借位
        *borrow = 0;    //不借位
    }
    dif = n1 - n2;      //差 = 數字1 - 數字2
    return dif;         //回傳 差

}

int num1Big(int number1[], int number2[], int n){   //比較兩數大小
    int i=0;
    for(i=n-1; i >= 0; i--){                        //先找到最高位數
        if(number1[i] > 0 && number2[i] == 0){      //如果數量 num1 > num2
            return 1;                               //num1 比較大
        }
        else if(number2[i] > 0 && number1[i] == 0){ //如果數量 num1 < num2
            return 0;                               //num2 比較大
        }
        else if(number1[i] != 0 && number2 != 0){   //如果數量一樣多
            break;                                  //跳出迴圈
        }
    }
    for(; i >= 0; i--){                     //比實際大小
        if(number1[i] > number2[i]){        //如果 num1 最高位數較大
            return 1;                       //num1 比較大
        }
        else if(number2[i] > number1[i]){   //如果 num2 最高位數較大
            return 0;                       //num2 比較大
        }
    }                                   //迴圈結束，兩數相等
    return 2;   //兩數相等
}

void suberBigNumber(int number1[], int number2[], int ans[], int n){    //減法
    int i=0, borrow=0;
    for(i=0; i < n; i++){
        ans[i] = suber(&borrow, number1[i], number2[i]);    //回傳差(dif) <= 減法器：(借位, 數字1, 數字2)
    }
}

void negative(int ans[], int n){    //加上負號
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
            if(num1Big(number1, number2, n)){           //判斷誰比較大
                suberBigNumber(number1, number2, ans, n);   //大數減小數
            }
            else{
                suberBigNumber(number2, number1, ans, n);   //大數減小數
                negative(ans, n);                           //減完加負號
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
