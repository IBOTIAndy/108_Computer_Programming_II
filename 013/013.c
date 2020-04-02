#include <stdio.h>
#include <stdlib.h>
//013 �Ʀ�q������
//2020/03/31 PM.02:13 IBOTIAndy

/*�D��
�Ʀ�q������I
�����@�ӼƦ�IC�A�����^�X�q���P�������q��
��Jm �O�G�i�� 8 �줸�A��X�O�G�i�� 4 �줸
��J�d��q 00000000 �� 11111111 (�Q�i�� 0~255)
�^�X�覡�� :
C(m) = m if m = 0 or m = 1 (�Q�i��)
C(m) = C(m/2) if m ����(�Q�i��)
C(m) = C((m+1)/2) if m �_��(�Q�i��)
�� :
m=00001010(�Q�i�� 10)�A�h�q���^�X�̧Ǭ��Q�i�� 5, 3, 2, 1
C(10)= C(5)=C(3)=C(2)=C(1)=1�A�@�^�X 4 ��
�������|�O���^�X�q�����^�X����
R(m) = [C(m) ���^�X����]�A�Ҧp R(10) = 4
�Y�Ʀ�IC����J��m=00001010(�Q�i�� 10) �A�]�^�X�q�����^�X���Ƭ�4�A�h���Ʀ�IC��X�� 0100 (�Q�i�� 4)

-------------
��J���� :
�G�i�� 8 bit �줸
�Ĥ@��O�Ĥ@�Ӵ��ծרҸ��
���۬O�@�� 0 ���j���ո��
�ĤT��O�ĤG�Ӵ��ծרҸ��
....
�̫� -1 ����

-------------
��X���� :
�G�i�� 4 bit �줸
�C�@��O�@�Ӵ��ծרҸ�ƪ����G
*/

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

int toN(int x, int b){  //10�i�� �� N�i��
    int i=0, ans=0;
    for(i=0; x; i++){                               //���� x = 0 (i �Ψӭp�⦸��)
        ans = ans + (int)(x % b) * power(10, i);    //�C�����H b(�i��)���l�� �A * 10^i
        x = x / b;                                  //�h���w�g���X�����
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

void printBinary(int x, int n){     //��X n ��ƪ��G�i��(Binary)  �p (101, 5) �|�֫e����� 0 (00101)
    int i=0;
    for(i=n-1; i > 0; i--){     //���N����Ƹ� 0
        if(x / power(10, i) == 1){  //�p�G��� 1
            break;                  //���X
        }
        printf("0");
    }
    printf("%d\n", x);              //�N 1 �P����ƿ�X
}

void digitalCircuit(){      //�Ʀ�q��
    int m=0, n=0, select=0;
    do{ //while(select == 0)    //�ܤְ���@��
        scanf("%d", &m);            //��J�G�i���
        m = to10(m, 2);             //�N�G�i���ର�Q�i�� (�Ӧ�010 �i���ഫ)
//        printf("m = %d\n", m);      //�ˬd�Q�i���ഫ
        n = circuit(m);             //����q���^�X����
//        printf("n = %d\n", n);      //�ˬd�^�X��
        n = toN(n, 2);              //�N�^�X����^�G�i�� (�Ӧ�010 �i���ഫ)
        printBinary(n, 4);          //��X�G�i�� 4��� pirntBinary(�G�i���, n���)
        scanf("%d", &select);       //��J���
    } while(select == 0);
}

int main(){
    digitalCircuit();   //�Ʀ�q��
//    printf("Hello world!\n");
    return 0;
}
