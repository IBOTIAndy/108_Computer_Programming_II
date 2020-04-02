#include <stdio.h>
#include <stdlib.h>
//013 數位電路模擬
//2020/03/31 PM.02:13 IBOTIAndy

/*題目
數位電路模擬I
模擬一個數位IC，內有回饋電路與紀錄器電路
輸入m 是二進位 8 位元，輸出是二進位 4 位元
輸入範圍從 00000000 到 11111111 (十進位 0~255)
回饋方式為 :
C(m) = m if m = 0 or m = 1 (十進位)
C(m) = C(m/2) if m 偶數(十進位)
C(m) = C((m+1)/2) if m 奇數(十進位)
例 :
m=00001010(十進位 10)，則電路回饋依序為十進位 5, 3, 2, 1
C(10)= C(5)=C(3)=C(2)=C(1)=1，共回饋 4 次
紀錄器會記錄回饋電路的回饋次數
R(m) = [C(m) 的回饋次數]，例如 R(10) = 4
若數位IC的輸入為m=00001010(十進位 10) ，因回饋電路的回饋次數為4，則此數位IC輸出為 0100 (十進位 4)

-------------
輸入說明 :
二進位 8 bit 位元
第一行是第一個測試案例資料
接著是一行 0 分隔測試資料
第三行是第二個測試案例資料
....
最後 -1 結束

-------------
輸出說明 :
二進位 4 bit 位元
每一行是一個測試案例資料的結果
*/

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

int toN(int x, int b){  //10進制 轉 N進制
    int i=0, ans=0;
    for(i=0; x; i++){                               //直到 x = 0 (i 用來計算次方)
        ans = ans + (int)(x % b) * power(10, i);    //每次除以 b(進制)取餘數 再 * 10^i
        x = x / b;                                  //去除已經取出的位數
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

void printBinary(int x, int n){     //輸出 n 位數的二進位(Binary)  如 (101, 5) 會少前面兩個 0 (00101)
    int i=0;
    for(i=n-1; i > 0; i--){     //先將高位數補 0
        if(x / power(10, i) == 1){  //如果找到 1
            break;                  //跳出
        }
        printf("0");
    }
    printf("%d\n", x);              //將 1 與其後方數輸出
}

void digitalCircuit(){      //數位電路
    int m=0, n=0, select=0;
    do{ //while(select == 0)    //至少執行一次
        scanf("%d", &m);            //輸入二進位數
        m = to10(m, 2);             //將二進位轉為十進位 (來自010 進制轉換)
//        printf("m = %d\n", m);      //檢查十進位轉換
        n = circuit(m);             //執行電路回饋模擬
//        printf("n = %d\n", n);      //檢查回饋數
        n = toN(n, 2);              //將回饋數轉回二進位 (來自010 進制轉換)
        printBinary(n, 4);          //輸出二進位 4位數 pirntBinary(二進位數, n位數)
        scanf("%d", &select);       //輸入選擇
    } while(select == 0);
}

int main(){
    digitalCircuit();   //數位電路
//    printf("Hello world!\n");
    return 0;
}
