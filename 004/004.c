#include <stdio.h>

void input(int *inside, int *outside, int *local, int *inMessage, int *outMessage){
    scanf("%d", inside);
    scanf("%d", outside);
    scanf("%d", local);
    scanf("%d", inMessage);
    scanf("%d", outMessage);
}

double mathCost(double monthCost, double inCost, double outCost, double localCost, double inMesCost, double outMesCost, int inside, int outside, int local, int inMessage, int outMessage){
    double totalCost=0.0;
    totalCost = totalCost + (inCost * inside) + (outCost * outside) + (localCost * local);
    totalCost = totalCost + (inMesCost * inMessage) + (outMesCost * outMessage);
    if(monthCost > totalCost){
        return monthCost;
    }
    else{
        return totalCost;
    }
}

void printBest(double cost183, double cost383, double cost983){
    if(cost183 < cost383){
        if(cost183 < cost983){
            printf("183\n");
        }
        else{
            printf("983\n");
        }
    }
    else if(cost383 < cost983){
        printf("383\n");
    }
    else{
        printf("983\n");
    }
}

void math(int inside, int outside, int local, int inMessage, int outMessage){
    double cost183=0.0, cost383=0.0, cost983=0.0;
    cost183 = mathCost(183.0, 0.08, 0.1393, 0.1349, 1.1287, 1.4803, inside, outside, local, inMessage, outMessage);
    cost383 = mathCost(383.0, 0.07, 0.1304, 0.1217, 1.1127, 1.2458, inside, outside, local, inMessage, outMessage);
    cost983 = mathCost(983.0, 0.06, 0.1087, 0.1018, 0.9572, 1.1243, inside, outside, local, inMessage, outMessage);
    printBest(cost183, cost383, cost983);
}

void findBestCost(){
    int inside=0, outside=0, local=0, inMessage=0, outMessage=0;
    input(&inside, &outside, &local, &inMessage, &outMessage);
    math(inside, outside, local, inMessage, outMessage);
}

void test(){
    math(500, 120, 13, 2, 5);
    math(200, 200, 200, 200, 200);
}

int main(){
    findBestCost();
//    test();
    return 0;
}

//´ú¸ê
//183 24
//383 25
//183 26
//983 27
//183 28
//183 29
//383 30
