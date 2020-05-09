#include <stdio.h>
#include <stdlib.h>
//022 尋找五子棋的位置
//2020/05/09 PM.05:46 IBOTIAndy

void inputGobang(int array[][10]){  //輸入五子棋棋盤狀況
    int i=0, j=0, n=0;
    n = 10;
    for(i=0; i < n; i++){
        for(j=0; j < n; j++){
            scanf("%d", &(array[i][j]));
        }
    }
}

int rowConnect(int array[][10], int i, int j, int n){   //左右搜尋
    int t=0, count=0;
    for(t=j-1; t >= 0; t--){    //往左偏移，並在到達邊線前
        if(array[i][t]){        //如果有棋子
            count = count + 1;  //計數器+1
        }
        else{                   //只要有一個是空的
            break;              //跳出迴圈
        }
    }
    for(t=j+1; t < n; t++){     //往右偏移，並在到達邊線前
        if(array[i][t]){        //如果有棋子
            count = count + 1;  //計數器+1
        }
        else{                   //只要有一個是空的
            break;              //跳出迴圈
        }
    }
    if(count >= 4){ //如果左右加上自己有達到五顆
        return 1;   //可以連線
    }
    return 0;       //總共沒有五顆 不能連線
}
int colConnect(int array[][10], int i, int j, int n){   //上下搜尋
    int t=0, count=0;
    for(t=i-1; t >= 0; t--){    //往上偏移，並在到達邊線前
        if(array[t][j]){        //如果有棋子
            count = count + 1;  //計數器+1
        }
        else{                   //只要有一個是空的
            break;              //跳出迴圈
        }
    }
    for(t=i+1; t < n; t++){     //往下偏移，並在到達邊線前
        if(array[t][j]){        //如果有棋子
            count = count + 1;  //計數器+1
        }
        else{                   //只要有一個是空的
            break;              //跳出迴圈
        }
    }
    if(count >= 4){ //如果左右加上自己有達到五顆
        return 1;   //可以連線
    }
    return 0;       //總共沒有五顆 不能連線
}
int LURDConnect(int array[][10], int i, int j, int n){
    int ti=0, tj=0, count=0;
    for(ti=i-1, tj=j-1; ti >= 0 && tj >= 0; ti--, tj--){    //往下偏移，並在到達邊線前
        if(array[ti][tj]){                                  //如果有棋子
            count = count + 1;                              //計數器+1
        }
        else{                                               //只要有一個是空的
            break;                                          //跳出迴圈
        }
    }
    for(ti=i+1, tj=j+1; ti < n && tj < n; ti++, tj++){      //往下偏移，並在到達邊線前
        if(array[ti][tj]){                                  //如果有棋子
            count = count + 1;                              //計數器+1
        }
        else{                                               //只要有一個是空的
            break;                                          //跳出迴圈
        }
    }
    if(count >= 4){ //如果左右加上自己有達到五顆
        return 1;   //可以連線
    }
    return 0;       //總共沒有五顆 不能連線
}
int LDRUConnect(int array[][10], int i, int j, int n){
    int ti=0, tj=0, count=0;
    for(ti=i-1, tj=j+1; ti >= 0 && tj < n; ti--, tj++){ //往下偏移，並在到達邊線前
        if(array[ti][tj]){                              //如果有棋子
            count = count + 1;                          //計數器+1
        }
        else{                                           //只要有一個是空的
            break;                                      //跳出迴圈
        }
    }
    for(ti=i+1, tj=j-1; ti < n && tj >= 0; ti++, tj--){ //往下偏移，並在到達邊線前
        if(array[ti][tj]){                              //如果有棋子
            count = count + 1;                          //計數器+1
        }
        else{                                           //只要有一個是空的
            break;                                      //跳出迴圈
        }
    }
    if(count >= 4){ //如果左右加上自己有達到五顆
        return 1;   //可以連線
    }
    return 0;       //總共沒有五顆 不能連線
}

int isConnect(int array[][10], int i, int j, int n){    //找看看有沒有連線
    if(rowConnect(array, i, j, n)){         //左右搜尋
        return 1;
    }
    else if(colConnect(array, i, j, n)){    //上下搜尋
        return 1;
    }
    else if(LURDConnect(array, i, j, n)){   //左上到右下搜尋
        return 1;
    }
    else if(LDRUConnect(array, i, j, n)){   //右上到左下搜尋
        return 1;
    }
    return 0;   //沒有連線
}

void search(int array[][10]){   //搜尋
    int i=0, j=0, n=0, flag=0;
    n = 10;
    flag = 1;
    for(i=0; i < n; i++){
        for(j=0; j < n; j++){
            if(array[i][j] == 0 && isConnect(array, i, j, n)){  //如果該位子還沒下過，並且可以連到五顆
                flag = 0;
                printf("%d %d\n", i, j);    //輸出該位子
            }
        }
    }
    if(flag){   //如果沒有輸出過位置
        printf("impractical attempt!\n");
    }
}

void gobang(){  //五子棋
    int array[10][10]={{0}};
    inputGobang(array);
    search(array);
}

int main(){
    gobang();
//    printf("Hello world!\n");
    return 0;
}
