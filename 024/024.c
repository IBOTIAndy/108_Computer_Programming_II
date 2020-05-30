#include <stdio.h>
#include <stdlib.h>
//024 �r��ק�
//2020/05/20 PM. 10:18 IBOTIAndy
void input(char *string, char *wordP, char *wordQ){
    gets(string);
    gets(wordP);
    gets(wordQ);
}

char* strcut(char *string, char cut){
    while(*string != '\0'){
        if(*string == cut){
            *string = '\0';
            return string+1;
        }
        string++;
    }
    return NULL;
}

void cutString(char *string, char *pString[]){
    int i=0;
    while(string != NULL){ //����������Χ�
        pString[i] = string;
        string = strcut(string, ' ');
        i = i + 1;
    }
    pString[i] = NULL;
}

int myStrSize(char *string){
    int i=0;
    while(*string != '\0'){
        string++;
        i = i + 1;
    }
    return i;
}

int myStrcmp(char *string1, char *string2){ //�r����
    if(myStrSize(string1) == myStrSize(string2)){   //����
        while(*string1 != '\0'){        //
            if(*string1 != *string2){   //�p�G���۵�
                return *string2 - *string1;
            }
            string1++;
            string2++;
        }
        return 0;   //�۵�
    }
    else{
        return myStrSize(string2) - myStrSize(string1);
    }
}

void AreplaceB(char *pString[], char *A, char *B){  //��A���NB
    int i=0;
    while(pString[i] != NULL){
        if(!myStrcmp(pString[i], B)){   //�p�G�PB�۵�
            printf("%s ", A);   //��A���N
        }
        else{
            printf("%s ", pString[i]);
        }
        i = i + 1;
    }
    printf("\n");
}

void insertAbeforeB(char *pString[], char *A, char *B){  //�bB�e�� ���JA
    int i=0;
    while(pString[i] != NULL){
        if(!myStrcmp(pString[i], B)){   //�p�G�PB�۵�
            printf("%s ", A);   //�b�e�贡�JA
        }
        printf("%s ", pString[i]);
        i = i + 1;
    }
    printf("\n");
}

void deleteA(char *pString[], char *A){ //�R��A
    int i=0;
    while(pString[i] != NULL){
        if(!myStrcmp(pString[i], A)){   //�p�G�PA�۵�
            //���L
        }
        else{
            printf("%s ", pString[i]);
        }
        i = i + 1;
    }
    printf("\n");
}

int allSelected(int wordNumber[], int n){
    int i=0;
    for(i=0; i < n; i++){
        if(wordNumber[i] != 0){
            return 0;
        }
    }
    return 1;
}

void calculatedQuantity(char *string[]){
    char *tString[50]={' '};
    int wordNumber[50]={0};
    int i=0, j=0, k=0, n=0, tempN=0;
    while(string[i] == NULL){
        wordNumber[i] = 1;
        for(j=i+1; string[j] == NULL; j++){
            if(!myStrcmp(string[i], string[j])){   //�p�G�۵�
                wordNumber++;
            }
        }
        i = i + 1;
    }
    for(i=0; wordNumber[i]; i++){
        n = i;
    }
    while(!allSelected(wordNumber, n)){ //�������䧹
        for(i=0, j=0; i < n; i++){   //
            if(wordNumber[i] > wordNumber[j]){  //

            }
        }
    }
}

void f1(){
    char string[1000]={' '};
    char wordP[50]={' '};
    char wordQ[50]={' '};
    char *pString[500];
    input(string, wordP, wordQ);
//    printf("%s\n%s\n%s\n", string, wordP, wordQ);
    cutString(string, pString);
    AreplaceB(pString, wordQ, wordP);
    insertAbeforeB(pString, wordQ, wordP);
    deleteA(pString, wordP);
    calculatedQuantity(pString);
}

int main(){
    f1();
//    printf("Hello world!\n");
    return 0;
}
