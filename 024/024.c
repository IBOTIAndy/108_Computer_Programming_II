#include <stdio.h>
#include <stdlib.h>
//024 字串修改
//2020/05/20 PM. 09:31 IBOTIAndy
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
    while(string != NULL){ //直到全部切割完
        pString[i] = string;
        string = strcut(string, ' ');
        i = i + 1;
    }
    pString[i] = NULL;
}

void f1(){
    char string[1000]={' '};
    char wordP[50]={' '};
    char wordQ[50]={' '};
    char *pString[500];
    input(string, wordP, wordQ);
//    printf("%s\n%s\n%s\n", string, wordP, wordQ);
    cutString(string, pString);
}

int main(){
    f1();
//    printf("Hello world!\n");
    return 0;
}
