#include <stdio.h>
#include <stdlib.h>
//010 進制轉換
//2020/03/21 AM.01:59 IBOTIAndy

void input(int *type, int *b1, int *b2, int *x){    //輸入:選擇的模式, 要被轉換的進制, 要轉乘的進制, 原數
    scanf("%d", type);  //輸入
    if(*type == 3){         //如果型態為 3 (不是 10 -> 2 或 2 -> 10
        scanf("%d", b1);    //輸入轉換前的進制
        scanf("%d", b2);    //輸入轉換後的進制
    }
    scanf("%d", x);     //輸入轉換前的數值
}

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

void selectType(int type, int b1, int b2, int x){   //選擇方式
    int ans=0;
    if(type == 1){          //10 轉 2
        ans = toN(x, 2);
    }
    else if(type == 2){     //2 轉 10
        ans = to10(x, 2);
    }
    else if(type == 3){     //b1 轉 b2
        ans = to10(x, b1);  //先轉為 10 進制
        ans = toN(ans, b2); //再轉為 b2 進制
    }
    printf("%d\n", ans);    //輸出
}

int main(){
    int type=0, b1=0, b2=0, x=0;
    input(&type, &b1, &b2, &x);     //輸入
    selectType(type, b1, b2, x);    //選擇轉換方式並輸出
//    printf("Hello world!\n");
    return 0;
}
