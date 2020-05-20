#include <stdio.h>
#include <stdlib.h>
//024 ¦r¦ê­×§ï
//2020/05/20 PM. 09:10 IBOTIAndy
void input(char *string, char *wordP, char *wordQ){
    gets(string);
    gets(wordP);
    gets(wordQ);
}

void f1(){
    char string[1000]={' '};
    char wordP[50]={' '};
    char wordQ[50]={' '};
    char *pString[500];
    input(string, wordP, wordQ);
//    printf("%s\n%s\n%s\n", string, wordP, wordQ);

    AreplaceB(string);
}

int main(){
    f1();
//    printf("Hello world!\n");
    return 0;
}
