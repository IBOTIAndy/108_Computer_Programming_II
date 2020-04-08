#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//015 分數的四則運算
//2020/04/08 AM.10:35 IBOTIAndy

int stringtoInt(char *string){
    int i=0, ans=0;
    for(i=0; string[i] >= '0' && string[i] <= '9'; i++){
        ans = (ans * pow(10, i)) + (string[i] - '0');
    }
    return ans;
}

char* stringCut(char *s, char endChar){ //剪字串
    int i=0;
    while(s[i] != endChar){     //直到找到 結束字元
        i = i + 1;
    }
    return (s + i + 1);         //回傳'結束字元'後的
}

void inputFractions(int *Numer, int *Dnomin){       //輸入
    char inputString[5]={' '}, *dnominString;
    gets(inputString);
    //////////////////////////////////////////////分割
    if(inputString[0] == '-'){                          //如果是負數 因為 - 佔了第一格位置
        *Numer = 0 - stringtoInt(&(inputString[1]));    //從[1]開始判斷 並用 0 - '得到的數' 以取得負數
    }
    else{                                               //如果不是負數
        *Numer = stringtoInt(&(inputString[0]));        //直接用
    }
    dnominString = stringCut(inputString, '/');  //指標改到 / 後的位置
    *Dnomin = stringtoInt(dnominString);         //取得分母
}

////

int dnominHaveZero(int dnomin){
    if(dnomin == 0){
        return 1;
    }
    return 0;
}

void add(int *ansNumer, int *ansDnomin, int numer1, int dnomin1, int numer2, int dnomin2){  //加法
    if(dnomin1 == dnomin2){             //如果分母相等
        *ansNumer = numer1 + numer2;    //直接相加
        *ansDnomin = dnomin1;           //分母繼承
    }
    else{                               //分母不相等，分母先改為相同，所以使用同乘對方的分母
        numer1 = numer1 * dnomin2;      //分子1 * 分母2
        numer2 = numer2 * dnomin1;      //分子2 * 分母1
        *ansDnomin = dnomin1 * dnomin2; //分母相乘
        *ansNumer = numer1 + numer2;    //分子相加
    }
}

void mul(int *ansNumer, int *ansDnomin, int numer1, int dnomin1, int numer2, int dnomin2){  //乘法
    *ansNumer = numer1 * numer2;    //分子 * 分子
    *ansDnomin = dnomin1 * dnomin2; //分母 * 分母
}

int commonFactor(int a, int b){ //求最大公因數，且預設 a b都 >= 2
    int i=0, temp=0;
    if(a == b){     //如果相等
        return a;   //回傳自己
    }
    else if(a < b){ //如果 b 比較大，將 a 與 b 交換，讓 a 都會是較大的數
        temp = a;   //
        a = b;      //
        b = temp;   //
    }
    for(i=b; i > 1; i--){                   //從小的開始
        if((a % i == 0) && (b % i == 0)){   //只要可以同時整除兩數
            return i;                       //就代表找到公因數 回傳
        }
    }           //for結束 沒有找到公因數
    return -1;  //回傳 -1 (沒找到)
}

int simplification(int *numer, int *dnomin){    //分數化簡
    int factor=0;
    if(*dnomin == 0){   //分母不能為 0
        return -1;
    }
    else if(*numer == 0){   //分子為 0
        *dnomin = 1;        //分母不用在意 所以改 1
    }
    else if(*dnomin > 1 && fabs(*numer) > 1.0){ //分母 > 1; |分子| > 1
        factor = commonFactor((int)(fabs(*numer)), *dnomin);    //取得公因數(分子取絕對值, 分母)
        if(factor != -1){               //如果有最大公因數
            *numer = *numer / factor;   //
            *dnomin = *dnomin / factor; //
        }
    }
    return 1;
}

int outputFractions(int numer, int dnomin){ //預定分數已化簡過
    if(dnomin == 0){    //分母不能為 0
        return -1;
    }
    else if(dnomin == 1){   //分母為 1 直接輸出
        printf("%d\n", numer);
    }
    else if(numer > dnomin){    //假分數轉為帶分數
        printf("%d(%d/%d)\n", numer / dnomin, (int)(fabs(numer % dnomin)), dnomin);
    }
    else{   //真分數 直接輸出
        printf("%d/%d\n", numer, dnomin);
    }
    return 1;
}

void mathFractions(){
    int ansNumer=0, ansDnomin=0;    //答案
    int numer1=0, dnomin1=0;        //分數 1
    int numer2=0, dnomin2=0;        //分數 2
    char next=' ', useOperator=' ', eatEnter=' ';
    do{                                                 //一定會做一次
        inputFractions(&numer1, &dnomin1);      //輸入分數1
        inputFractions(&numer2, &dnomin2);      //輸入分數2
        scanf("%c%c", &useOperator, &eatEnter); //輸入運算符號
        scanf("%c%c", &next, &eatEnter);        //輸入要不要繼續
        if(dnominHaveZero(dnomin1) || dnominHaveZero(dnomin2)){ //如果其中一個分母有 0
            printf("ERROR\n");
        }
        else if(useOperator == '+'){                                        //加法
            add(&ansNumer, &ansDnomin, numer1, dnomin1, numer2, dnomin2);       //
        }
        else if(useOperator == '-'){                                        //減法
            add(&ansNumer, &ansDnomin, numer1, dnomin1, (0 - numer2), dnomin2); //a - b => a + -b => a + (0 - b)
        }
        else if(useOperator == '*'){                                        //乘法
            mul(&ansNumer, &ansDnomin, numer1, dnomin1, numer2, dnomin2);       //
        }
        else if(useOperator == '/'){                                        //除法
            mul(&ansNumer, &ansDnomin, numer1, dnomin1, dnomin2, numer2);       //後者上下互換後相乘
        }
        simplification(&ansNumer, &ansDnomin);  //化簡
        outputFractions(ansNumer, ansDnomin);   //輸出
    } while(next == 'y');   //如果選擇繼續輸出，回到 do
}

int main(){
    mathFractions();
//    printf("Hello world!\n");
    return 0;
}
