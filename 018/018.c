#include <stdio.h>
#include <stdlib.h>
//018 baseball
//2020/04/24 PM. 01:19 IBOTIAndy

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

int mathScore(int base){    //計算得幾分
    int ans=0;
    while(base != 0){       //0110          //0100
        if(base & 1 == 1){  //1100 != 0100  //1000 != 0000
            ans=ans+1;      //0+1           //1+1
        }
        base = base >> 1;   //0100          //0000
    }
    return ans;
}

int runBase(int *base, int baseman){    //跑壘
    int score=0;
    *base = (*base << baseman) | (1 << (baseman - 1));  //改變壘包狀態
    if(*base > 7){                                      //如果有人回壘
        score = mathScore((*base >> 3));                //計算分數(計算多少人回本壘)
        *base = *base & 7;                              //清除多出的人
    }
    return score;   //回傳得分
}

int math(char player[][6], int playerN, int roundN, int n, int m){
    int i=0, j=0, ans=0, out=0, outN=0, base=0, baseman=0;
    int minWhere=0, mFlag=0, mHit=0, mBack=0, f=1;
    for(i=0; i < roundN; i++){          //局數 (1~5)
        for(j=0; j < playerN; j++){     //球員 (1~9)
            switch(player[j][i]){           //
                case '\0':                  //如果沒了，跳出
                    break;
                case 'O':                   //出局
                    out = out + 1;          //出局數+1 (到 3 重置壘包
                    outN = outN + 1;        //(outN == b) 結束 (b=n)
                    break;
                case 'H':                   //全壘打
                    baseman = 4;            //跑壘改為 4
                    ans = ans + runBase(&base, baseman);    //因為runBase只能計算最多移動3
                    break;                                  //所以要多+1才能計算 +4
                default:                                    //安打
                    baseman = player[j][i] - '0';           //安打數 = '字元' - '0';
                    ans = ans + runBase(&base, baseman);    //跑壘
            }
            if(outN == n && f){                 //如果 out = b
                f = 0;                          //讓他不會再次輸出 (flag)
                printf("%d\n", ans);            //輸出結果
                printf("%d,%d\n", mHit, mBack); //
            }
            if(j + 1 == m && baseman){          //如果是第 m 位球員打擊，並且有打出安打
                mFlag = 1;                      // m 開始跑壘
                mHit = mHit + 1;                // m 的打擊數+1
                minWhere = 1 << (baseman - 1);  // m 的位置移動
                if(baseman == 4){               // 如果是全壘打
                    mHit = mHit - 1;            // 不計算為安打
                }
            }
            if(mFlag){                          //如果 m 開始跑壘
                minWhere = minWhere << baseman; // m 移動
                if(minWhere > 7){               // 如果 m 已經到達本壘
                    mBack = mBack + 1;          // m 回壘數+1
                    minWhere = 0;               // m 從壘包上移除
                    mFlag = 0;                  // m 結束跑壘
                }
            }
            if(out == 3){       //如果三振
                minWhere = 0;   // m 從壘包上移除
                mFlag = 0;      // m 結束跑壘
                base = 0;       // 移除壘包上的人
                out = 0;        // 出局數重置
            }
            baseman = 0;    //每次迴圈結束時，重置安打
        }
    }
    return ans;
}

void baseball(){
    char player[9][6]={{' '}};      //球員們的打擊成績
    int outN=0, m=0;
//    int i=0;
    //int ansOut=0, ansM=0;
    input(player, &outN, &m);       //輸入to 33
//    for(i=0; i<9; i++){
//        printf("%s\n", player[i]);  //輸出檢查
//    }
    math(player, 9, 5, outN, m);    //to 64
}

int main(){
    baseball(); //to 117
//    printf("Hello world!\n");
    return 0;
}
