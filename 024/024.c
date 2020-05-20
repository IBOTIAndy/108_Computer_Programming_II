#include <stdio.h>
#include <stdlib.h>
//024 ﹃э
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
    while(string != NULL){ //场ち澄Ч
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

int myStrcmp(char *string1, char *string2){ //﹃ゑ耕
    if(myStrSize(string1) == myStrSize(string2)){   //单
        while(*string1 != '\0'){        //
            if(*string1 != *string2){   //狦ぃ单
                return *string2 - *string1;
            }
            string1++;
            string2++;
        }
        return 0;   //单
    }
    else{
        return myStrSize(string2) - myStrSize(string1);
    }
}

void AreplaceB(char *pString[], char *A, char *B){  //ノAB
    int i=0;
    while(pString[i] != NULL){
        if(!myStrcmp(pString[i], B)){   //狦籔B单
            printf("%s ", A);   //ノA
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
