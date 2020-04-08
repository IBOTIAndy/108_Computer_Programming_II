#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//015 ���ƪ��|�h�B��
//2020/04/08 AM.10:35 IBOTIAndy

int stringtoInt(char *string){
    int i=0, ans=0;
    for(i=0; string[i] >= '0' && string[i] <= '9'; i++){
        ans = (ans * pow(10, i)) + (string[i] - '0');
    }
    return ans;
}

char* stringCut(char *s, char endChar){ //�Ŧr��
    int i=0;
    while(s[i] != endChar){     //������ �����r��
        i = i + 1;
    }
    return (s + i + 1);         //�^��'�����r��'�᪺
}

void inputFractions(int *Numer, int *Dnomin){       //��J
    char inputString[5]={' '}, *dnominString;
    gets(inputString);
    //////////////////////////////////////////////����
    if(inputString[0] == '-'){                          //�p�G�O�t�� �]�� - ���F�Ĥ@���m
        *Numer = 0 - stringtoInt(&(inputString[1]));    //�q[1]�}�l�P�_ �å� 0 - '�o�쪺��' �H���o�t��
    }
    else{                                               //�p�G���O�t��
        *Numer = stringtoInt(&(inputString[0]));        //������
    }
    dnominString = stringCut(inputString, '/');  //���Ч�� / �᪺��m
    *Dnomin = stringtoInt(dnominString);         //���o����
}

////

int dnominHaveZero(int dnomin){
    if(dnomin == 0){
        return 1;
    }
    return 0;
}

void add(int *ansNumer, int *ansDnomin, int numer1, int dnomin1, int numer2, int dnomin2){  //�[�k
    if(dnomin1 == dnomin2){             //�p�G�����۵�
        *ansNumer = numer1 + numer2;    //�����ۥ[
        *ansDnomin = dnomin1;           //�����~��
    }
    else{                               //�������۵��A�������אּ�ۦP�A�ҥH�ϥΦP����誺����
        numer1 = numer1 * dnomin2;      //���l1 * ����2
        numer2 = numer2 * dnomin1;      //���l2 * ����1
        *ansDnomin = dnomin1 * dnomin2; //�����ۭ�
        *ansNumer = numer1 + numer2;    //���l�ۥ[
    }
}

void mul(int *ansNumer, int *ansDnomin, int numer1, int dnomin1, int numer2, int dnomin2){  //���k
    *ansNumer = numer1 * numer2;    //���l * ���l
    *ansDnomin = dnomin1 * dnomin2; //���� * ����
}

int commonFactor(int a, int b){ //�D�̤j���]�ơA�B�w�] a b�� >= 2
    int i=0, temp=0;
    if(a == b){     //�p�G�۵�
        return a;   //�^�Ǧۤv
    }
    else if(a < b){ //�p�G b ����j�A�N a �P b �洫�A�� a ���|�O���j����
        temp = a;   //
        a = b;      //
        b = temp;   //
    }
    for(i=b; i > 1; i--){                   //�q�p���}�l
        if((a % i == 0) && (b % i == 0)){   //�u�n�i�H�P�ɾ㰣���
            return i;                       //�N�N���줽�]�� �^��
        }
    }           //for���� �S����줽�]��
    return -1;  //�^�� -1 (�S���)
}

int simplification(int *numer, int *dnomin){    //���Ƥ�²
    int factor=0;
    if(*dnomin == 0){   //�������ର 0
        return -1;
    }
    else if(*numer == 0){   //���l�� 0
        *dnomin = 1;        //�������Φb�N �ҥH�� 1
    }
    else if(*dnomin > 1 && fabs(*numer) > 1.0){ //���� > 1; |���l| > 1
        factor = commonFactor((int)(fabs(*numer)), *dnomin);    //���o���]��(���l�������, ����)
        if(factor != -1){               //�p�G���̤j���]��
            *numer = *numer / factor;   //
            *dnomin = *dnomin / factor; //
        }
    }
    return 1;
}

int outputFractions(int numer, int dnomin){ //�w�w���Ƥw��²�L
    if(dnomin == 0){    //�������ର 0
        return -1;
    }
    else if(dnomin == 1){   //������ 1 ������X
        printf("%d\n", numer);
    }
    else if(numer > dnomin){    //�������ର�a����
        printf("%d(%d/%d)\n", numer / dnomin, (int)(fabs(numer % dnomin)), dnomin);
    }
    else{   //�u���� ������X
        printf("%d/%d\n", numer, dnomin);
    }
    return 1;
}

void mathFractions(){
    int ansNumer=0, ansDnomin=0;    //����
    int numer1=0, dnomin1=0;        //���� 1
    int numer2=0, dnomin2=0;        //���� 2
    char next=' ', useOperator=' ', eatEnter=' ';
    do{                                                 //�@�w�|���@��
        inputFractions(&numer1, &dnomin1);      //��J����1
        inputFractions(&numer2, &dnomin2);      //��J����2
        scanf("%c%c", &useOperator, &eatEnter); //��J�B��Ÿ�
        scanf("%c%c", &next, &eatEnter);        //��J�n���n�~��
        if(dnominHaveZero(dnomin1) || dnominHaveZero(dnomin2)){ //�p�G�䤤�@�Ӥ����� 0
            printf("ERROR\n");
        }
        else if(useOperator == '+'){                                        //�[�k
            add(&ansNumer, &ansDnomin, numer1, dnomin1, numer2, dnomin2);       //
        }
        else if(useOperator == '-'){                                        //��k
            add(&ansNumer, &ansDnomin, numer1, dnomin1, (0 - numer2), dnomin2); //a - b => a + -b => a + (0 - b)
        }
        else if(useOperator == '*'){                                        //���k
            mul(&ansNumer, &ansDnomin, numer1, dnomin1, numer2, dnomin2);       //
        }
        else if(useOperator == '/'){                                        //���k
            mul(&ansNumer, &ansDnomin, numer1, dnomin1, dnomin2, numer2);       //��̤W�U������ۭ�
        }
        simplification(&ansNumer, &ansDnomin);  //��²
        outputFractions(ansNumer, ansDnomin);   //��X
    } while(next == 'y');   //�p�G����~���X�A�^�� do
}

int main(){
    mathFractions();
//    printf("Hello world!\n");
    return 0;
}
