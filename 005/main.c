#include <stdio.h>
#include <stdlib.h>

double draw(int n){
    char s[4]={' '};
    int i=0;
    double point=0.0;
    while(i < n){
        scanf("%s", s);
        if(s[0] == 'A'){
            point = point + 1.0;
        }
        else if(s[0] >= '2' && s[0] <= '9'){
            point = point + (double)(s[0] - '0');
        }
        else if(s[0] == '1' && s[1] == '0'){
            point = point + 10.0;
        }
        else if(s[0] == 'J' || s[0] == 'Q' || s[0] == 'K'){
            point = point + 0.5;
        }
        i = i + 1;
    }
    return point;
}

double checkBlow(double point){
    if(point > 10.5){
        return 0.0;
    }
    else{
        return point;
    }
}

void printWiner(double pointA, double pointB){
    printf("%.1f\n", pointA);
    printf("%.1f\n", pointB);
    if(pointA > pointB){
        printf("A wins.");
    }
    else if(pointA < pointB){
        printf("B wins.");
    }
    else{
        printf("It's a tie.");
    }
}

void poker105(){
    double pointA=0, pointB=0;
    pointA = checkBlow(draw(3));
    pointB = checkBlow(draw(3));
    printWiner(pointA, pointB);
}

int main(){
    poker105();
    return 0;
}
