#include <stdio.h>
#include <stdlib.h>
//008 輸出指定圖形
//2020/03/20 PM. 05:12 IBOTIAndy

/*題目
將Code寫成 二個function，每一個function使用一層迴圈
輸入圖案編號與層數，輸出各種圖形

輸入：選擇欲輸出圖形模式及參數
輸出：輸出預期的圖形
*/

//------------input------------
void inputTypeAndN(int *type, int *n){  //輸入圖形模式及參數
    scanf("%d", type);  //圖形模式
    scanf("%d", n);     //參數
}
//-----------/input------------

//------------prints------------
void printItoN(int i, int n){   //從 i 輸出到 n
    for(; i <= n; i++){         //漸大
        printf("%d", i);
    }
}

void printNtoI(int i, int n){   //從 n 輸出到 i
    for(; n > i; n--){          //漸小
        printf("%d", n);
    }
}

void printNn(int n){        //輸出 n 個 n
    int i=0;
    for(i=0; i < n; i++){   //
        printf("%d", n);
    }
}

void printItoNtoI(int i, int n){    //從 i 到 n 再到 i
    printItoN(i, n);        //i  , i+1, ..., n  (前半部且包含中間
    printNtoI(i-1, n-1);    //n-1, n-2, ..., i  (後半部且不包含中間
}

void printNtoItoN(int i, int n){    //從 n 到 i 再到 n
    printNtoI(i, n);    //n, n-1, ..., i-1  (前半部且不包含中間
    printItoN(i, n);    //i, i+1, ..., n    (前半部且包含中間
}

void printNChar(int n, char c){ //輸出 n 個 char c
    int i=0;
    for(i=0; i < n; i++){
        printf("%c", c);
    }
}
//------------printMod1------------
void printMod1(int n){      //模式 1
    int i=0;
    for(i=1; i <= n; i++){  //1
        printItoN(1, i);    //1 2
        printf("\n");       //1 2 3
    }
    for(i=n; i > 0; i--){   //n  , n-1, n-2 3 2 1
        printNtoI(0, i);    //n-1, n-2      2 1
        printf("\n");       //n-2           1
    }
    for(i=1; i <= n; i++){  //1
        printNn(i);         //2 2
        printf("\n");       //3 3 3
    }
}
//-----------/printMod1------------

//------------printMod2------------
void printMod2(int n){              //模式2
    int i=0;
    for(i=1; i <= n; i++){          //1
        printItoNtoI(1, i);         //1 2 1
        printf("\n");               //1 2 3 2 1
    }
    for(i=1; i < n; i++){           //____1____
        printNChar(n - i - 1, '_'); //___212___
        printNtoItoN(1, i);         //__32123__
        printNChar(n - i - 1, '_'); //_4321234_
        printf("\n");               //543212345
    }
    for(i=n-1; i >= 1; i--){        //543212345
        printNChar(n - i - 1, '_'); //_4321234_
        printNtoItoN(1, i);         //__32123__
        printNChar(n - i - 1, '_'); //___212___
        printf("\n");               //____1____
    }
}
//-----------/printMod2------------

void selectType(int type, int n){   //選擇模式
    if(type == 1){
        printMod1(n);
    }
    else if(type == 2){
        printMod2(n);
    }
}

void test(){            //測試
//    printItoN(2, 5);
    printMod1(5);       //輸出模式1, 5
    printf("\n");
    printMod2(5);       //輸出模式2, 5
}

int main(){
    int type=0, n=0;
    inputTypeAndN(&type, &n);   //輸入
    selectType(type, n);        //選擇模式
//    test();                     //測試
//    printf("Hello world!\n");
    return 0;
}

//test
//50 mod 1
//51 mod 2
//52 mod 1
//53 mod 2
//54 mod 2
