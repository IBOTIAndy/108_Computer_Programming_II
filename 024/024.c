#include <stdio.h>
#include <stdlib.h>
//024 �r��ק�
//2020/05/20 PM. 10:03 IBOTIAndy
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

void f1(){
    char string[1000]={' '};
    char wordP[50]={' '};
    char wordQ[50]={' '};
    char *pString[500];
    input(string, wordP, wordQ);
//    printf("%s\n%s\n%s\n", string, wordP, wordQ);
    cutString(string, pString);
    AreplaceB(pString, wordQ, wordP);
}

int main(){
    f1();
//    printf("Hello world!\n");
    return 0;
}
