#include<stdio.h>
//108_2020/03/04 HW2 跑壘問題
//PM.01:02 IBOTIAndy
char inputChar(){   //輸入字元
    char c=' ', e=' ';
    scanf("%c%c", &c, &e);
    return c;
}

int charChangeInt(char c){  //字元轉整數
//    printf("%d", c - 48);
    return c - 48;          //字元 '0' 為整數的 48  (編碼)
}

int printBase(int base){    //輸出目前壘上狀態
    int i=0, ans=0;
    for(i=0; i < 3; i++){   //共三壘要輸出
        ans = base % 2;     //依序取出各壘狀態
        base = base / 2;    //(轉為二進位表示)
        printf("%d\n", ans);
    }
    return 0;
}

int baseballGame(){         //棒球
    char ball=' ';
    int i=0, baseman=0, base=0, out=0;
    for(i=0; i < 5; i++){       //打擊手總共5人
        ball = inputChar();     //輸入字元來表示打者的打擊
        if(ball == 'O'){        //如果出局
            out = out + 1;      //出局數 +1
        }
        else if(ball == 'H'){   //H 全壘打
            base = 0;           //向左位移4次
        }
        else{                                                   //安打
            baseman = charChangeInt(ball);                      //將字元改成數字
            base = (base << baseman) | (1 << (baseman - 1));    //改變壘包狀態
            base = base & 7;                                    //清除超出壘包的人
        }
        if(out >= 3){   //如果出局人數超過 3, 清空壘包 並重新開始
            base = 0;   //壘包清空
            out = 0;    //出局數清空
            i = -1;     //將 i 歸0  (因為結束迴圈會+1 所以改成 -1 才會從 0 開始)
        }
    }
    printBase(base);            //輸出各壘狀態
    return 0;
}

int main(){
    baseballGame();
    return 0;
}
