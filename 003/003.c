#include<stdio.h>
//108_2020/03/05 HW3 工資計算
//PM.01:00 IBOTIAndy
int inputInt(){
    int x=0;
    scanf("%d", &x);
    return x;
}

double unconditionalRounding(double x){ //用轉型態方式 無條件捨去至小數點第一位
    int y=0;
    y = x * 10;             //先將小數點第一位乘到個位數 再將型態轉為 int 去掉小數部分
    x = (double)y * 0.1;    //再將 int 轉回 double 後除 10 恢復小數點   (要先轉回double再除 不然小數點會被消除)
    return x;
}

int printPays(double realPay, double laborPremium, double taxes){   //輸出
    printf("%.1f\n", realPay);      //實際所得
    printf("%.1f\n", laborPremium); //勞保費
    printf("%.1f\n", taxes);        //稅金
    return 0;
}

int mathIncome(double hours1, double hours2, double pay, double y){   //計算所得
    double taxes=0.0, laborPremium=0.0, realPay=0.0;
    taxes = (hours1 * pay * 0.08) + (hours2 * pay * 0.08);               //稅金
    laborPremium = y * 0.05;                                             //勞保費
    realPay = (hours1 * pay + hours2 * pay) - (taxes + laborPremium);    //實際所得
    taxes = unconditionalRounding(taxes);               //無條件捨去法取小數點第一位
    laborPremium = unconditionalRounding(laborPremium); //...
//    realPay = unconditionalRounding(realPay);           //收入總和不用取小數第一位
    printPays(realPay, laborPremium, taxes);    //輸出
    return 0;
}

int income(){
    int hours1=0, hours2=0, pay=0, y=0;
    hours1 = inputInt();    //輸入
    hours2 = inputInt();    //...
    pay = inputInt();       //...
    y = inputInt();         //...
    mathIncome(hours1, hours2, pay, y); //計算並輸出
    return 0;
}

int test(){
    mathIncome(100, 200, 160, 23000);
    mathIncome(0, 300, 200, 20000);
    mathIncome(111, 203, 205, 18345);
    return 0;
}

int main(){
    income();   //收入計算
//    test();     //測試用
    return 0;
}
