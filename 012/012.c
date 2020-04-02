#include <stdio.h>
#include <stdlib.h>
#include <math.h>   //使用 pow();
//Gray code
//2020/03/31 PM.00:43 IBOTIAndy

/*題目
葛雷碼 (Gray code)
反射二進位編碼-葛雷碼 (Gray code)，是編碼成兩個連續的不同位元
其編碼規則如下
G_1 = {0, 1}
G_1_r = {1, 0}
G_n = {0G_(n-1), 1G_(n-1)_r }
[G_n_r 是 G_n 的逆向順序]
例 :
G_2 = {0G_1, 1G_1_r} = {00, 01, 11, 10}
G_2_r = {10, 11, 01, 00}

-------------
輸入說明 :
第一行是一個測試案例資料，整數 n k
n代表Gray code的位元數
k代表G_n中的第幾個元素
接著是一行 0 分隔測試資料
第三行是第二個測試案例資料
....
最後 -1 結束

-------------
輸出說明 :
二進位 Gray code
每一行是一個測試案例資料的結果
*/

void input(int *n, int *k){ //輸入
    scanf("%d %d", n, k);
}

void grayCode(int n, int k){            // n = 二進位的總位數
    if(n == 1){
        printf("%d", k);
    }
    else if(k < pow(2, n-1)){           // 0 + grayCode(n-1, k)
        printf("0");
        grayCode(n-1, k);
    }
    else{   // if(k >= pow(2, n-1)){    // 1 + grayCode(n-1, (2^(n) - 1-k) );
        printf("1");
        grayCode(n-1, pow(2, n)-1-k);
    }
}

void loopGrayCode(){        //
    int n=0, k=0, select=0;
    do{ //do while(select == 0)  先做一次 如果輸入 0 繼續輸入測資
        input(&n, &k);          //輸入 n & k
        grayCode(n, k); //格雷碼的遞迴
        printf("\n");   //分隔每個測資
        scanf("%d", &select);   //輸入下次的選擇
    } while(select == 0);
}

int main(){
    loopGrayCode();     //格雷碼的迴圈
//    printf("Hello world!\n");
    return 0;
}
