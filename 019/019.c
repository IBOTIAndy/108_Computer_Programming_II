#include <stdio.h>
#include <stdlib.h>
//019 陣列翻轉
//2020/05/07 AM. 11:46 IBOTIAndy

int array2setNumber(int array[][50], int start, int count, int nC, int nR){ //設定依照順序的數字
    int i=0, j=0;
    for(i=0; i < nC; i++){      //上到下
        for(j=0; j < nR; j++){  //左到右
            array[i][j] = start;    //從起始數字開始
            start = start + count;  //每次加上間隔數
        }
    }
    return 0;
}

int printArray2(int array[][50], int nC, int nR){   //輸出二維陣列
    int i=0, j=0;
    for(i=0; i < nC; i++){      //上到下
        for(j=0; j < nR; j++){  //左到右
            printf("%d ", array[i][j]); //輸出
        }
        printf("\n");                   //換行
    }
    return 0;
}

int f1(){
    int n=0, select=0;
    int array[50][50]={{0}};
    scanf("%d", &n);        //輸入array的長跟寬
    scanf("%d", &select);   //選擇要怎麼翻轉 (1.不翻轉, 2.順時鐘, 3.逆時鐘, 4上下翻轉)
    array2setNumber(array, 1, 1, n, n); //設定array內部的數字
    printArray2(array, n, n);           //輸出array
    return 0;
}

int main(){
    f1();
//    printf("Hello world!\n");
    return 0;
}
