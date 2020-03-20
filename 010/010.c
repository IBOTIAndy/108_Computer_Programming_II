#include <stdio.h>
#include <stdlib.h>
//010 �i���ഫ
//2020/03/21 AM.01:59 IBOTIAndy

void input(int *type, int *b1, int *b2, int *x){    //��J:��ܪ��Ҧ�, �n�Q�ഫ���i��, �n�୼���i��, ���
    scanf("%d", type);  //��J
    if(*type == 3){         //�p�G���A�� 3 (���O 10 -> 2 �� 2 -> 10
        scanf("%d", b1);    //��J�ഫ�e���i��
        scanf("%d", b2);    //��J�ഫ�᪺�i��
    }
    scanf("%d", x);     //��J�ഫ�e���ƭ�
}

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

void selectType(int type, int b1, int b2, int x){   //��ܤ覡
    int ans=0;
    if(type == 1){          //10 �� 2
        ans = toN(x, 2);
    }
    else if(type == 2){     //2 �� 10
        ans = to10(x, 2);
    }
    else if(type == 3){     //b1 �� b2
        ans = to10(x, b1);  //���ର 10 �i��
        ans = toN(ans, b2); //�A�ର b2 �i��
    }
    printf("%d\n", ans);    //��X
}

int main(){
    int type=0, b1=0, b2=0, x=0;
    input(&type, &b1, &b2, &x);     //��J
    selectType(type, b1, b2, x);    //����ഫ�覡�ÿ�X
//    printf("Hello world!\n");
    return 0;
}
