#include <stdio.h>
#include <stdlib.h>
//014 回饋電路模擬 II
//2020/03/31 PM.08:16 IBOTIAndy

/////////////
//從 010 拿過來用 (進制轉換)
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
///////////////////

int circuit(int m){     //數位電路模擬
    if(m == 0 || m == 1){
        return 0;
    }
    if(m % 2 == 0){
        return circuit(m / 2) + 1;
    }
    else{   //if(m % 2 == 1){
        return circuit((m+1) / 2) + 1;
    }
}

void toN(int x, int b, int ans[]){  //10進制 轉 N進制
    int i=0;
    for(i=0; x; i++){       //直到 x = 0 (i 用來計算次方)
        ans[i] = x % b;     //每次除以 b(進制)取餘數
        x = x / b;          //去除已經取出的位數
    }
}
void printBinary(int *x, int n){    //輸出 n 位數的二進位(Binary)
    int i=0;
    for(i=n-1; i >= 0; i--){
        printf("%d", x[i]);
        x[i] = 0;
    }
    printf("\n");
}

int recorder(int m){    //計數器
    int i=0, ans=0;
    for(i=0; i <= m; i++){      //從 0 ~ m
        ans = ans + circuit(i); //將每次的回饋次數相加
    }
    return ans;
}

void digitalCircuitII(){      //數位電路II
    int select=0;
    int m=0, n=0, ans[11]={0};
    do{ //while(select == 0)    //至少執行一次
        scanf("%d", &m);            //輸入二進位數
        m = to10(m, 2);             //將二進位轉為十進位 (來自010 進制轉換)
//        printf("m = %d\n", m);      //檢查十進位轉換
        n = recorder(m);            //執行電路回饋模擬
//        printf("n = %d\n", n);      //檢查回饋數
        toN(n, 2, ans);             //因為 11 位數 int 裝不下  所以使用 array 來裝
        printBinary(ans, 11);        //輸出二進位 11位數 pirntBinary(二進位數, n位數)
        scanf("%d", &select);       //輸入選擇
    } while(select == 0);
}

int main(){
    digitalCircuitII();   //數位電路II
//    printf("Hello world!\n");
    return 0;
}
