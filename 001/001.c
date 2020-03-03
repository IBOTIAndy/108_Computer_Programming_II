#include<stdio.h>
#include<math.h>
//108_2020/03/02 HW1 一元二次方程式
//PM.03:00 IBOTIAndy
int inputInt(){
    int x=0;
    scanf("%d", &x);
    return x;
}
//實根求法 -b +- sqrt( b^2 - 4ac)
//    R = ----------------------
//                 2a
float realNumber1(float a, float b, float c){   //第一個實根( (-b) + sqrt... )
    float R=0;
    R = (((-b) + sqrt((b * b) - 4 * a * c)) / (2 * a));
    return R;
}

float realNumber2(float a, float b, float c){   //第二個實根( (-b) - sqrt... )
    float R=0;
    R = (((-b) - sqrt((b * b) - 4 * a * c)) / (2 * a));
    return R;
}

int unaryQuadraticEquation(){
    int a=0, b=0, c=0;      //aX^2 + bX + c = 0
    float R1=0.0, R2=0.0;   //兩個實根
    a = inputInt(); //輸入
    b = inputInt(); //...
    c = inputInt(); //...
    R1 = realNumber1(a, b, c);  //求第一個實根
    R2 = realNumber2(a, b, c);  //求第二個實根
    printf("%.1f\n", R1);
    printf("%.1f\n", R2);
    return 0;
}

int main(){
    unaryQuadraticEquation();   //一元二次方程式
    return 0;
}
