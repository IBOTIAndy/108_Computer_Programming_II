#include <stdio.h>
#include <stdlib.h>
//007 輸入整數，並每找到三個質數就輸出(包含自己)  如 23 = 2, 3, '5', 7, 11, '13', 17, 19, '23' -> 輸出 5, 13, 23
//2020/03/20 PM. 03:32 IBOTIAndy

/*題目
求 1~N 之間的質數
質數是除了 1 與本身之外，無法被其他數整除的數。
可利用巢狀迴圈計算 1~100 間任一個數字，是否會被比它小的數字 (從 2 開始) 整除，會整除的就不是質數。找不到可整除的，就是質數。
質數未達三個造成無輸出情況時則輸出字串："含括的質數未達三個"
輸入：100以內任意自然數
輸出：質數每三個輸出一個
*/

void inputNumber(int *x){   //輸入一個數(指標正整數)
    scanf("%d", x);
}

int isPrime(int x){         //檢查是否為質數
    int i=0;
    for(i=2; i < x; i++){   //從 2 開始，且不包含本身(x)
        if((x % i) == 0){   //如果有數可以整除，代表 x 不是質數
            return 0;       //回傳 0 (False)
        }
    }           //如果沒有任何數可以整除
    return 1;   //回傳 1 (Ture)
}

void findPrime(int n){  //找質數
    int i=0, count=0, notOutput=0;
    notOutput = 1;              //設定為還沒有任何的輸出
    for(i=2; i <= n; i++){      //從 2 開始，並包含自己找質數
        if(isPrime(i)){         //如果是質數
            count = count + 1;  //計數器 + 1
        }
        if(count == 3){         //計數器達到 3
            printf("%d\n", i);  //輸出目前的質數
            count = 0;          //計數器歸零
            notOutput = 0;      //設定為已經有輸出
        }
    }
    if(notOutput){                      //如果沒有任何的輸出
        printf("含括的質數未達三個\n"); //
    }
}

int main(){
    int x=0;
    inputNumber(&x);    //輸入一個數(正整數)
    findPrime(x);       //找質數(正整數)
//    printf("Hello world!\n");
    return 0;
}
