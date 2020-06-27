#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//035 polynomial
//2020/06/28 AM.00:34 ~ AM.00:47 IBOTIAndy

typedef struct number_s{
    int n;
    int pol;
    struct number_s *next;
}number_t;

typedef number_t* numberp_t;

numberp_t createNewNumber(int n){
    numberp_t newNumber=(numberp_t)malloc(sizeof(number_t));
    newNumber->n = n;
    newNumber->pol = 0;
    newNumber->next = NULL;
    return newNumber;
}

numberp_t input(){
    numberp_t headp, np;
    char s[100]={' '};
    char *p;
    gets(s);
    p = strtok(s, " ");
    np = createNewNumber(atoi(p));
    headp = np;
    p = strtok(NULL, " ");
    while(p != NULL){
        np->next = createNewNumber(atoi(p));
        np = np->next;
        p = strtok(NULL, " ");
    }
    return headp;
}

void output(numberp_t n){
    while(n != NULL){
        printf("%dx^%d ", n->n, n->pol);
        n = n->next;
    }
    printf("\n");
}

int setPol(numberp_t n){
    if(n->next == NULL){
        n->pol = 0;
    }
    else{
        n->pol = setPol(n->next) + 1;
    }
    return n->pol;
}

void math(numberp_t n1, numberp_t n2){

}

void f1(){
    numberp_t n1, n2;
    n1 = input();
    n2 = input();
    setPol(n1);
    setPol(n2);
//    output(n1);
//    output(n2);
    math(n1, n2);
}

int main(){
     f1();
//    printf("Hello world!\n");
    return 0;
}
