#include <stdio.h>
#include <stdlib.h>
#include <math.h>   //�ϥ� pow();
//Gray code
//2020/03/31 PM.00:43 IBOTIAndy

/*�D��
���p�X (Gray code)
�Ϯg�G�i��s�X-���p�X (Gray code)�A�O�s�X����ӳs�򪺤��P�줸
��s�X�W�h�p�U
G_1 = {0, 1}
G_1_r = {1, 0}
G_n = {0G_(n-1), 1G_(n-1)_r }
[G_n_r �O G_n ���f�V����]
�� :
G_2 = {0G_1, 1G_1_r} = {00, 01, 11, 10}
G_2_r = {10, 11, 01, 00}

-------------
��J���� :
�Ĥ@��O�@�Ӵ��ծרҸ�ơA��� n k
n�N��Gray code���줸��
k�N��G_n�����ĴX�Ӥ���
���۬O�@�� 0 ���j���ո��
�ĤT��O�ĤG�Ӵ��ծרҸ��
....
�̫� -1 ����

-------------
��X���� :
�G�i�� Gray code
�C�@��O�@�Ӵ��ծרҸ�ƪ����G
*/

void input(int *n, int *k){ //��J
    scanf("%d %d", n, k);
}

void grayCode(int n, int k){            // n = �G�i�쪺�`���
    if(n == 1){
        printf("%d", k);
    }
    else if(k < pow(2, n-1)){           // 0 + grayCode(n-1, k)
        printf("0");
        grayCode(n-1, k);
    }
    else{   // if(k >= pow(2, n-1)){    // 1 + grayCode(n-1, (2^(n) - 1-k) );
        printf("1");
        grayCode(n-1, pow(2, n)-1-k);
    }
}

void loopGrayCode(){        //
    int n=0, k=0, select=0;
    do{ //do while(select == 0)  �����@�� �p�G��J 0 �~���J����
        input(&n, &k);          //��J n & k
        grayCode(n, k); //��p�X�����j
        printf("\n");   //���j�C�Ӵ���
        scanf("%d", &select);   //��J�U�������
    } while(select == 0);
}

int main(){
    loopGrayCode();     //��p�X���j��
//    printf("Hello world!\n");
    return 0;
}
