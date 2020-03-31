#include <stdio.h>
#include <stdlib.h>
//014 �^�X�q������ II
//2020/03/31 PM.08:16 IBOTIAndy

/////////////
//�q 010 ���L�ӥ� (�i���ഫ)
int power(int x, int p){    //�]�� math.h �� pow() �|�����D �ҥH�ۤv�g�@��
    int i=0, ans=0;
    ans = 1;    //�]�� 0 ���謰 1 �ҥH���]�w 1
    for(i=0; i < p; i++){   //���W p �� x
        ans = ans * x;      //
    }
    return ans; //�^��
}

int to10(int x, int b){ //N�i�� �� 10�i��
    int i=0, ans=0;
    for(i=0; x; i++){                       //���� x = 0 (i �Ψӭp�⦸��)
        ans = ans + (x % 10) * power(b, i); //�C�����@��� * b^i
        x = x / 10;                         //�h���w�g���X�����
    }
    return ans;
}
///////////////////

int circuit(int m){     //�Ʀ�q������
    if(m == 0 || m == 1){
        return 0;
    }
    if(m % 2 == 0){
        return circuit(m / 2) + 1;
    }
    else{   //if(m % 2 == 1){
        return circuit((m+1) / 2) + 1;
    }
}

void toN(int x, int b, int ans[]){  //10�i�� �� N�i��
    int i=0;
    for(i=0; x; i++){       //���� x = 0 (i �Ψӭp�⦸��)
        ans[i] = x % b;     //�C�����H b(�i��)���l��
        x = x / b;          //�h���w�g���X�����
    }
}
void printBinary(int *x, int n){    //��X n ��ƪ��G�i��(Binary)
    int i=0;
    for(i=n-1; i >= 0; i--){
        printf("%d", x[i]);
        x[i] = 0;
    }
    printf("\n");
}

int recorder(int m){    //�p�ƾ�
    int i=0, ans=0;
    for(i=0; i <= m; i++){      //�q 0 ~ m
        ans = ans + circuit(i); //�N�C�����^�X���Ƭۥ[
    }
    return ans;
}

void digitalCircuitII(){      //�Ʀ�q��II
    int select=0;
    int m=0, n=0, ans[11]={0};
    do{ //while(select == 0)    //�ܤְ���@��
        scanf("%d", &m);            //��J�G�i���
        m = to10(m, 2);             //�N�G�i���ର�Q�i�� (�Ӧ�010 �i���ഫ)
//        printf("m = %d\n", m);      //�ˬd�Q�i���ഫ
        n = recorder(m);            //����q���^�X����
//        printf("n = %d\n", n);      //�ˬd�^�X��
        toN(n, 2, ans);             //�]�� 11 ��� int �ˤ��U  �ҥH�ϥ� array �Ӹ�
        printBinary(ans, 11);        //��X�G�i�� 11��� pirntBinary(�G�i���, n���)
        scanf("%d", &select);       //��J���
    } while(select == 0);
}

int main(){
    digitalCircuitII();   //�Ʀ�q��II
//    printf("Hello world!\n");
    return 0;
}
