#include <stdio.h>
#include <stdlib.h>
//023 �@��N��
//2020/05/19 PM. 02:57 IBOTIAndy

void input(int *n, int cityToCity[][10]){
    int i=0, j=0;
    printf("�п�J���X�y����(1~20)�G");
    scanf("%d", n);
    printf("�п�J�Ҧ������������Z���G\n");
    for(i=0; i < *n; i++){
        for(j=0; j < *n; j++){
            scanf("%d", &(cityToCity[i][j]));
        }
    }
}

int allArrival(int isArrival[], int n){ //�ˬd�O���O�������������L
    int i=0;
    for(i=0; i < n; i++){
        if(isArrival[i] == 0){  //�p�G�����󪺫����٨S���L
            return 0;           //�^�� false
        }
    }           //���������L�F
    return 1;   //�^�� ture
}

int oneDayNTower(int start, int n, int cityToCity[][10], int isArrival[]){
    int i=0, temp=0, startTemp=0;
    temp = 9999;
    isArrival[start - 1] = 1;   //�N�Ӯy�����������w�g���L
    if(allArrival(isArrival, n)){   //�p�G���������������L�F
        return 0;   //�����A�íp��e�����L����
    }
    else{
        for(i=0; i < n; i++){   //�j�M�Ӯy�����P���y�������Z���̪�
            if(i+1 != start){   //�p�G��諸���O�Ҧb����
                if(!isArrival[i]){  //�åB���O�w�g���L������
                    if(temp > cityToCity[start-1][i]){  //�p�G����񪺫���
                        temp = cityToCity[start-1][i];  //�O�������Z��
                        startTemp = i + 1;              //�O�������s��
                    }
                }
            }
        }   //�~�򩹤U�@�y�����e�i�A�ðO�����e���L���Z��
        return oneDayNTower(startTemp, n, cityToCity, isArrival) + temp;
    }
}

void output(int distance){
    printf("�g�L�Ҧ��������̵u�Z�����G");
    printf("%d\n", distance);
}

void f1(){
    int cityToCity[10][10]={{0}};
    int n=0, isArrival[10]={0};
    int distance=0;
    input(&n, cityToCity);
    distance = oneDayNTower(1, n, cityToCity, isArrival);
    output(distance);
}

int main(){
    f1();
//    printf("Hello world!\n");
    return 0;
}
