#include <stdio.h>
#include <stdlib.h>
//016 ������
//2020/04/19 PM.02:00 IBOTIAndy

void arrayEmpty(int array[], int n){
    int i=0;
    for(i=0; i < n; i++){
        array[i] = 0;
    }
}

void stringToInt(char s[], int number[], int *n){   //�r���}�C�ର��ư}�C
    int i=0;
    while(s[i] != '\0'){        //���쵲���Ÿ��άO�W�X�W��
        number[i] = s[i] - '0'; //�Ӧ�Ʃ��}�C�_�l��m�A��K����p��
        i = i + 1;              //
    }
    *n = i;
}

void input(int array[], int *m, int *n){
    char inString[20]={' '};
    gets(inString);
    stringToInt(inString, array, n);
    scanf("%d", m);
}

int isRepeat(int temp[], int x){
    if(temp[x]){
        return 1;
    }
    temp[x] = 1;
    return 0;
}

int f2(int array[], int m){
    int i=0, temp[10]={0};
    arrayEmpty(temp, 10);
    for(i=0; i < m; i++){
        if(isRepeat(temp, array[i])){
            return 0;
        }
    }
    return 1;
}

void f1(int array[], int m, int n){
    int i=0, ans=0;
    for(i=0; i+m <= n; i++){
        ans = ans + f2((array + i), m);
    }
    printf("%d\n", ans);
}

int main(){
    int array[20]={0}, m=0, n=0;
    arrayEmpty(array, 20);
    input(array, &m, &n);
    f1(array, m, n);

//    printf("Hello world!\n");
    return 0;
}
