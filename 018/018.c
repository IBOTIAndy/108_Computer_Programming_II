#include <stdio.h>
#include <stdlib.h>
//018 baseball
//2020/04/23 PM. 01:19 IBOTIAndy

char* stringCut(char **s, char cutChar){    //字串切割 s=字串的指標, 要用什麼來分割的字元
    int i=0;
    while(*(*s+i) != '\0'){         //做到字串結束
        if(*(*s+i) == cutChar){     //如果找到選擇的字元，開始分割
            *s = *s + i + 1;        //將原本的字串切割到分隔字元的下一個位置
            //printf("_%c_\n", **s);
            break;                  //跳出迴圈
        }
        i = i + 1;
    }
    return *s;  //回傳切割前的位置
}   //---------------------------------------------------------------------

void inputScore(char score[]){              //輸入個人成績
    int i=0, n=0;
    char *inString, s[12]={' '};
    gets(s);                                //輸入一行字串
    inString = s;                           //使用指標指向第一個位置
    n = inString[0] - '0';                  //取出字串中的 n (打擊次數)
    inString = stringCut(&inString, ' ');   //將 n 去除
    for(i=0; i < n; i++){                       //取出全部的打擊成績(n次)
        score[i] = inString[0];                 //取得打擊成績
        inString = stringCut(&inString, ' ');   //回傳切割後的字串位置
        score[i+1] = '\0';                      //加上結束符號
    }
}

void input(char player[][6], int *outN, int *m){    //輸入全部球員的成績
    int i=0;
    for(i=0; i < 9; i++){       //共9位球員
        inputScore(player[i]);  //輸入球員成績
    }
    scanf("%d", outN);  //輸入計算到第幾個 out
    scanf("%d", m);     //輸入選擇第幾位球員
}

void baseball(){
    char player[9][6]={{' '}};      //球員們的打擊成績
    int i=0, outN=0, m=0;
    input(player, &outN, &m);       //輸入
//    for(i=0; i<9; i++){
//        printf("%s\n", player[i]);  //輸出檢查
//    }
}

int main(){
    baseball();
//    printf("Hello world!\n");
    return 0;
}
