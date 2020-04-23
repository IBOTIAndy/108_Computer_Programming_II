#include <stdio.h>
#include <stdlib.h>
//018 baseball
//2020/04/23 PM. 00:50 IBOTIAndy

char* stringCut(char *s, char cutChar){
    int i=0;
    char *t=s;
    while(*(s+i) != '\n'){
        if(*(s+i) == cutChar){
            s = s + i + 1;
            printf("_%c_\n", *s);
            break;
        }
        i = i + 1;
    }
    return t;
}

void inputScore(char score[]){
    int i=0, n=0;
    char *cut, inString[12]={' '};
    gets(inString);
    n = inString[0] - '0';
    stringCut(inString, ' ');
    for(i=0; i < n; i++){
        cut = stringCut(inString, ' ');
        score[i] = *cut;
    }
}

void input(char player[][5], int *outN, int *m){
    int i=0;
    for(i=0; i < 9; i++){
        inputScore(player[i]);
    }
    scanf("%d", outN);
    scanf("%d", m);
}

void baseball(){
    char player[9][5]={{' '}};
    int i=0, outN=0, m=0;
    input(player, &outN, &m);
    for(i=0; i<9; i++){
        printf("%s\n", player[i]);
    }
}

int main(){
    baseball();
//    printf("Hello world!\n");
    return 0;
}
