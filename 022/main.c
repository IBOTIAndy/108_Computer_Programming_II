#include <stdio.h>
#include <stdlib.h>
//022 �M�䤭�l�Ѫ���m
//2020/05/09 PM.05:46 IBOTIAndy

void inputGobang(int array[][10]){  //��J���l�ѴѽL���p
    int i=0, j=0, n=0;
    n = 10;
    for(i=0; i < n; i++){
        for(j=0; j < n; j++){
            scanf("%d", &(array[i][j]));
        }
    }
}

int rowConnect(int array[][10], int i, int j, int n){   //���k�j�M
    int t=0, count=0;
    for(t=j-1; t >= 0; t--){    //���������A�æb��F��u�e
        if(array[i][t]){        //�p�G���Ѥl
            count = count + 1;  //�p�ƾ�+1
        }
        else{                   //�u�n���@�ӬO�Ū�
            break;              //���X�j��
        }
    }
    for(t=j+1; t < n; t++){     //���k�����A�æb��F��u�e
        if(array[i][t]){        //�p�G���Ѥl
            count = count + 1;  //�p�ƾ�+1
        }
        else{                   //�u�n���@�ӬO�Ū�
            break;              //���X�j��
        }
    }
    if(count >= 4){ //�p�G���k�[�W�ۤv���F�줭��
        return 1;   //�i�H�s�u
    }
    return 0;       //�`�@�S������ ����s�u
}
int colConnect(int array[][10], int i, int j, int n){   //�W�U�j�M
    int t=0, count=0;
    for(t=i-1; t >= 0; t--){    //���W�����A�æb��F��u�e
        if(array[t][j]){        //�p�G���Ѥl
            count = count + 1;  //�p�ƾ�+1
        }
        else{                   //�u�n���@�ӬO�Ū�
            break;              //���X�j��
        }
    }
    for(t=i+1; t < n; t++){     //���U�����A�æb��F��u�e
        if(array[t][j]){        //�p�G���Ѥl
            count = count + 1;  //�p�ƾ�+1
        }
        else{                   //�u�n���@�ӬO�Ū�
            break;              //���X�j��
        }
    }
    if(count >= 4){ //�p�G���k�[�W�ۤv���F�줭��
        return 1;   //�i�H�s�u
    }
    return 0;       //�`�@�S������ ����s�u
}
int LURDConnect(int array[][10], int i, int j, int n){
    int ti=0, tj=0, count=0;
    for(ti=i-1, tj=j-1; ti >= 0 && tj >= 0; ti--, tj--){    //���U�����A�æb��F��u�e
        if(array[ti][tj]){                                  //�p�G���Ѥl
            count = count + 1;                              //�p�ƾ�+1
        }
        else{                                               //�u�n���@�ӬO�Ū�
            break;                                          //���X�j��
        }
    }
    for(ti=i+1, tj=j+1; ti < n && tj < n; ti++, tj++){      //���U�����A�æb��F��u�e
        if(array[ti][tj]){                                  //�p�G���Ѥl
            count = count + 1;                              //�p�ƾ�+1
        }
        else{                                               //�u�n���@�ӬO�Ū�
            break;                                          //���X�j��
        }
    }
    if(count >= 4){ //�p�G���k�[�W�ۤv���F�줭��
        return 1;   //�i�H�s�u
    }
    return 0;       //�`�@�S������ ����s�u
}
int LDRUConnect(int array[][10], int i, int j, int n){
    int ti=0, tj=0, count=0;
    for(ti=i-1, tj=j+1; ti >= 0 && tj < n; ti--, tj++){ //���U�����A�æb��F��u�e
        if(array[ti][tj]){                              //�p�G���Ѥl
            count = count + 1;                          //�p�ƾ�+1
        }
        else{                                           //�u�n���@�ӬO�Ū�
            break;                                      //���X�j��
        }
    }
    for(ti=i+1, tj=j-1; ti < n && tj >= 0; ti++, tj--){ //���U�����A�æb��F��u�e
        if(array[ti][tj]){                              //�p�G���Ѥl
            count = count + 1;                          //�p�ƾ�+1
        }
        else{                                           //�u�n���@�ӬO�Ū�
            break;                                      //���X�j��
        }
    }
    if(count >= 4){ //�p�G���k�[�W�ۤv���F�줭��
        return 1;   //�i�H�s�u
    }
    return 0;       //�`�@�S������ ����s�u
}

int isConnect(int array[][10], int i, int j, int n){    //��ݬݦ��S���s�u
    if(rowConnect(array, i, j, n)){         //���k�j�M
        return 1;
    }
    else if(colConnect(array, i, j, n)){    //�W�U�j�M
        return 1;
    }
    else if(LURDConnect(array, i, j, n)){   //���W��k�U�j�M
        return 1;
    }
    else if(LDRUConnect(array, i, j, n)){   //�k�W�쥪�U�j�M
        return 1;
    }
    return 0;   //�S���s�u
}

void search(int array[][10]){   //�j�M
    int i=0, j=0, n=0, flag=0;
    n = 10;
    flag = 1;
    for(i=0; i < n; i++){
        for(j=0; j < n; j++){
            if(array[i][j] == 0 && isConnect(array, i, j, n)){  //�p�G�Ӧ�l�٨S�U�L�A�åB�i�H�s�줭��
                flag = 0;
                printf("%d %d\n", i, j);    //��X�Ӧ�l
            }
        }
    }
    if(flag){   //�p�G�S����X�L��m
        printf("impractical attempt!\n");
    }
}

void gobang(){  //���l��
    int array[10][10]={{0}};
    inputGobang(array);
    search(array);
}

int main(){
    gobang();
//    printf("Hello world!\n");
    return 0;
}
