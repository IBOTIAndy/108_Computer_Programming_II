#include <stdio.h>
#include <stdlib.h>
//019 陣列翻轉
//2020/05/09 PM. 01:20 IBOTIAndy

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

int turnR(int array[][50], int n){  //右轉, 順時鐘
    int i=0, j=0, temp=0;
//    int tArray[50][50]={{0}};
//    for(i=0; i < n; i++){
//        for(j=0; j < n; j++){
//            tArray[i][j] = array[i][j]; //備份
//        }
//    }
    for(i=0; i < n/2; i++){
        for(j=i; j < n-1-i; j++){
            temp = array[i][j];
            array[i][j] = array[n-1-j][i];          //左下給左上
            array[n-1-j][i] = array[n-1-i][n-1-j];  //右下給左下
            array[n-1-i][n-1-j] = array[j][n-1-i];  //右上給右下
            array[j][n-1-i] = temp;                 //左上給右上
//            array[i][j] = tArray[n-1-j][i];         //左下給左上
//            array[n-1-j][i] = tArray[n-1-i][n-1-j]; //右下給左下
//            array[n-1-i][n-1-j] = tArray[j][n-1-i]; //右上給右下
//            array[j][n-1-i] = tArray[i][j];         //左上給右上
        }
    }
    return 0;
}

int turnL(int array[][50], int n){  //左轉, 逆時鐘
    int i=0, j=0, temp=0;
    for(i=0; i < n/2; i++){         //從最外圈開始，逐漸往內縮
        for(j=i; j < n-1-i; j++){   //每次處理一排
            temp = array[i][j];
            array[i][j] = array[j][n-1-i];          //左上 = 右上
            array[j][n-1-i] = array[n-1-i][n-1-j];  //右上 = 右下
            array[n-1-i][n-1-j] = array[n-1-j][i];  //右下 = 左下
            array[n-1-j][i] = temp;                 //左下 = 左上
        }
    }
    return 0;
}

int flipVertically(int array[][50], int n){
    int i=0, j=0, temp=0;
    for(i=0; i < n/2; i++){
        for(j=0; j < n; j++){
            temp = array[i][j];
            array[i][j] = array[n-1-i][j];
            array[n-1-i][j] = temp;
        }
    }
    return 0;
}

int f1(){
    int n=0, select=0;
    int array[50][50]={{0}};
    scanf("%d", &n);        //輸入array的長跟寬
    scanf("%d", &select);   //選擇要怎麼翻轉 (1.不翻轉, 2.順時鐘, 3.逆時鐘, 4上下翻轉)
    array2setNumber(array, 1, 1, n, n); //設定array內部的數字
    switch(select){
    case 1: //不更改
        break;
    case 2: //順時鐘翻轉
        turnR(array, n);
        break;
    case 3: //逆時鐘翻轉
        turnL(array, n);
        break;
    case 4: //上下翻轉
        flipVertically(array, n);
        break;
    default:
        printf("select input ERROR\n");
    }
    printArray2(array, n, n);           //輸出array
    return 0;
}

int main(){
    f1();
//    printf("Hello world!\n");
    return 0;
}
