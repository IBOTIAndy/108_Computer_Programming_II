#include "binaryConverter.h"

int power(int x, int p){    //因為 math.h 的 pow() 會有問題 所以自己寫一個
    int i=0, ans=0;
    ans = 1;    //因為 0 次方為 1 所以先設定 1
    for(i=0; i < p; i++){   //乘上 p 次 x
        ans = ans * x;      //
    }
    return ans; //回傳
}

int to10(int x, int b){ //N進制 轉 10進制
    int i=0, ans=0;
    for(i=0; x; i++){                       //直到 x = 0 (i 用來計算次方)
        ans = ans + (x % 10) * power(b, i); //每次取一位數 * b^i
        x = x / 10;                         //去除已經取出的位數
    }
    return ans;
}

int toN(int x, int b){  //10進制 轉 N進制
    int i=0, ans=0;
    for(i=0; x; i++){                               //直到 x = 0 (i 用來計算次方)
        ans = ans + (int)(x % b) * power(10, i);    //每次除以 b(進制)取餘數 再 * 10^i
        x = x / b;                                  //去除已經取出的位數
    }
    return ans;
}

