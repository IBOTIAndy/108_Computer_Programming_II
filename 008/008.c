#include <stdio.h>
#include <stdlib.h>
//008 ��X���w�ϧ�
//2020/03/20 PM. 05:12 IBOTIAndy

/*�D��
�NCode�g�� �G��function�A�C�@��function�ϥΤ@�h�j��
��J�Ϯ׽s���P�h�ơA��X�U�عϧ�

��J�G��ܱ���X�ϧμҦ��ΰѼ�
��X�G��X�w�����ϧ�
*/

//------------input------------
void inputTypeAndN(int *type, int *n){  //��J�ϧμҦ��ΰѼ�
    scanf("%d", type);  //�ϧμҦ�
    scanf("%d", n);     //�Ѽ�
}
//-----------/input------------

//------------prints------------
void printItoN(int i, int n){   //�q i ��X�� n
    for(; i <= n; i++){         //���j
        printf("%d", i);
    }
}

void printNtoI(int i, int n){   //�q n ��X�� i
    for(; n > i; n--){          //���p
        printf("%d", n);
    }
}

void printNn(int n){        //��X n �� n
    int i=0;
    for(i=0; i < n; i++){   //
        printf("%d", n);
    }
}

void printItoNtoI(int i, int n){    //�q i �� n �A�� i
    printItoN(i, n);        //i  , i+1, ..., n  (�e�b���B�]�t����
    printNtoI(i-1, n-1);    //n-1, n-2, ..., i  (��b���B���]�t����
}

void printNtoItoN(int i, int n){    //�q n �� i �A�� n
    printNtoI(i, n);    //n, n-1, ..., i-1  (�e�b���B���]�t����
    printItoN(i, n);    //i, i+1, ..., n    (�e�b���B�]�t����
}

void printNChar(int n, char c){ //��X n �� char c
    int i=0;
    for(i=0; i < n; i++){
        printf("%c", c);
    }
}
//------------printMod1------------
void printMod1(int n){      //�Ҧ� 1
    int i=0;
    for(i=1; i <= n; i++){  //1
        printItoN(1, i);    //1 2
        printf("\n");       //1 2 3
    }
    for(i=n; i > 0; i--){   //n  , n-1, n-2 3 2 1
        printNtoI(0, i);    //n-1, n-2      2 1
        printf("\n");       //n-2           1
    }
    for(i=1; i <= n; i++){  //1
        printNn(i);         //2 2
        printf("\n");       //3 3 3
    }
}
//-----------/printMod1------------

//------------printMod2------------
void printMod2(int n){              //�Ҧ�2
    int i=0;
    for(i=1; i <= n; i++){          //1
        printItoNtoI(1, i);         //1 2 1
        printf("\n");               //1 2 3 2 1
    }
    for(i=1; i < n; i++){           //____1____
        printNChar(n - i - 1, '_'); //___212___
        printNtoItoN(1, i);         //__32123__
        printNChar(n - i - 1, '_'); //_4321234_
        printf("\n");               //543212345
    }
    for(i=n-1; i >= 1; i--){        //543212345
        printNChar(n - i - 1, '_'); //_4321234_
        printNtoItoN(1, i);         //__32123__
        printNChar(n - i - 1, '_'); //___212___
        printf("\n");               //____1____
    }
}
//-----------/printMod2------------

void selectType(int type, int n){   //��ܼҦ�
    if(type == 1){
        printMod1(n);
    }
    else if(type == 2){
        printMod2(n);
    }
}

void test(){            //����
//    printItoN(2, 5);
    printMod1(5);       //��X�Ҧ�1, 5
    printf("\n");
    printMod2(5);       //��X�Ҧ�2, 5
}

int main(){
    int type=0, n=0;
    inputTypeAndN(&type, &n);   //��J
    selectType(type, n);        //��ܼҦ�
//    test();                     //����
//    printf("Hello world!\n");
    return 0;
}

//test
//50 mod 1
//51 mod 2
//52 mod 1
//53 mod 2
//54 mod 2
