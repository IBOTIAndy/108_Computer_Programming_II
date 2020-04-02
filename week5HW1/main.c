#include <stdio.h> // main.c
#include <math.h>
#include <assert.h>
double computeBMI(int kg, int height) {
    double BMI = 0.0, M = height/100.0;
    if (kg<=0 || height<=0)
        return 0;
    BMI = round(100*kg/(M*M))/100; //四捨五入取兩位小數
    if (BMI <18.5)
        return -1;
    if (BMI >24)
        return -2;
    return BMI;
}

int main() {
    int kg = 52, height = 155;
    double expectedResult = 21.64f;
    double result = computeBMI(kg, height);
    assert(fabs(result-expectedResult) < 0.0001);
    assert(computeBMI(0, height) == 0);
    assert(computeBMI(kg, 0) == 0);
    assert(computeBMI(0, 0) == 0);
    assert(computeBMI(1, height) == -1);
    assert(computeBMI(kg, 100) == -2);
    printf("Hi\n");
    return 0;
}
