#include <stdio.h>
#include <stdlib.h>
//016 ������
//2020/04/19 AM.01:28 IBOTIAndy

void arrayEmpty(int array[], int n){
    int i=0;
    for(i=0; i < n; i++){
        array[i] = 0;
    }
}

void stringToInt(char s[], int number[], int n){    //�r���}�C�ର��ư}�C
    int i=0;
    while(s[i] != '\0' && i < n){   //���쵲���Ÿ��άO�W�X�W��
        push(number, i);            //�N�Ʀr�����줸���A���Ӧ�Ʒ|�ݦb�}�C��[0]
        number[0] = s[i] - '0';     //�Ӧ�Ʃ��}�C�_�l��m�A��K����p��
        i = i + 1;                  //
    }
}

void input(int array[], int *m, int n){
    char inString[20]={' '};
    gets(inString);
    stringToInt(inString, array, n);
    scanf("%d", m);
}

void f1(int array[], int m, int n){
}

int main(){
    int array[20]={0}, m=0;
    arrayEmpty(array, 20);
    input(array, &m, 20);
    f1(array, m, 20);

//    printf("Hello world!\n");
    return 0;
}
