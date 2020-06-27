#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//035 polynomial
//2020/06/28 AM.00:47 ~ AM.01:11 IBOTIAndy

typedef struct number_s{
    int n;
    int pol;
    struct number_s *next;
}number_t;

typedef number_t* numberp_t;

numberp_t createNewNumber(int n, int pol){
    numberp_t newNumber=(numberp_t)malloc(sizeof(number_t));
    newNumber->n = n;
    newNumber->pol = pol;
    newNumber->next = NULL;
    return newNumber;
}

numberp_t input(){
    numberp_t headp, np;
    char s[100]={' '};
    char *p;
    gets(s);
    p = strtok(s, " ");
    np = createNewNumber(atoi(p), 0);
    headp = np;
    p = strtok(NULL, " ");
    while(p != NULL){
        np->next = createNewNumber(atoi(p), 0);
        np = np->next;
        p = strtok(NULL, " ");
    }
    return headp;
}

void testOutput(numberp_t n){
    while(n != NULL){
        printf("%dx^%d ", n->n, n->pol);
        n = n->next;
    }
    printf("\n");
}

void output(numberp_t n){
    while(n != NULL){
        printf("%d ", n->n);
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

void adder(numberp_t n1, numberp_t n2){
    numberp_t ans=NULL, temp=NULL;
    if(n1->pol != n2->pol){
        if(n1->pol > n2->pol){
            ans = createNewNumber(n1->n, n1->pol);
            n1 = n1->next;
        }
        else{
            ans = createNewNumber(n2->n, n2->pol);
            n2 = n2->next;
        }
    }
    temp = ans;
    while(n1 != NULL && n2 != NULL){
        if(n1->pol == n2->pol){
            temp->next = createNewNumber(n1->n + n2->n, n1->pol);
            temp = temp->next;
            n1 = n1->next;
            n2 = n2->next;
        }
        else if(n1->pol > n2->pol){
            temp->next = createNewNumber(n1->n, n1->pol);
            temp = temp->next;
            n1 = n1->next;
        }
        else{
            temp->next = createNewNumber(n2->n, n2->pol);
            temp = temp->next;
            n2 = n2->next;
        }
    }
    output(ans);
}

void suber(numberp_t n1, numberp_t n2){
    numberp_t ans=NULL, temp=NULL;
    if(n1->pol != n2->pol){
        if(n1->pol > n2->pol){
            ans = createNewNumber(n1->n, n1->pol);
            n1 = n1->next;
        }
        else{
            ans = createNewNumber(0 - n2->n, n2->pol);
            n2 = n2->next;
        }
    }
    temp = ans;
    while(n1 != NULL && n2 != NULL){
        if(n1->pol == n2->pol){
            temp->next = createNewNumber(n1->n - n2->n, n1->pol);
            temp = temp->next;
            n1 = n1->next;
            n2 = n2->next;
        }
        else if(n1->pol > n2->pol){
            temp->next = createNewNumber(n1->n, n1->pol);
            temp = temp->next;
            n1 = n1->next;
        }
        else{
            temp->next = createNewNumber(0 - n2->n, n2->pol);
            temp = temp->next;
            n2 = n2->next;
        }
    }
    output(ans);
}

void math(numberp_t n1, numberp_t n2){
    adder(n1, n2);
    suber(n1, n2);
}

void f1(){
    numberp_t n1, n2;
    n1 = input();
    n2 = input();
    setPol(n1);
    setPol(n2);
//    testOutput(n1);
//    testOutput(n2);
    math(n1, n2);
}

int main(){
     f1();
//    printf("Hello world!\n");
    return 0;
}
