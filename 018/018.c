#include <stdio.h>
#include <stdlib.h>
//018 baseball
//2020/04/23 PM. 01:19 IBOTIAndy

char* stringCut(char **s, char cutChar){    //�r����� s=�r�ꪺ����, �n�Τ���Ӥ��Ϊ��r��
    int i=0;
    while(*(*s+i) != '\0'){         //����r�굲��
        if(*(*s+i) == cutChar){     //�p�G����ܪ��r���A�}�l����
            *s = *s + i + 1;        //�N�쥻���r����Ψ���j�r�����U�@�Ӧ�m
            //printf("_%c_\n", **s);
            break;                  //���X�j��
        }
        i = i + 1;
    }
    return *s;  //�^�Ǥ��Ϋe����m
}   //---------------------------------------------------------------------

void inputScore(char score[]){              //��J�ӤH���Z
    int i=0, n=0;
    char *inString, s[12]={' '};
    gets(s);                                //��J�@��r��
    inString = s;                           //�ϥΫ��Ы��V�Ĥ@�Ӧ�m
    n = inString[0] - '0';                  //���X�r�ꤤ�� n (��������)
    inString = stringCut(&inString, ' ');   //�N n �h��
    for(i=0; i < n; i++){                       //���X�������������Z(n��)
        score[i] = inString[0];                 //���o�������Z
        inString = stringCut(&inString, ' ');   //�^�Ǥ��Ϋ᪺�r���m
        score[i+1] = '\0';                      //�[�W�����Ÿ�
    }
}

void input(char player[][6], int *outN, int *m){    //��J�����y�������Z
    int i=0;
    for(i=0; i < 9; i++){       //�@9��y��
        inputScore(player[i]);  //��J�y�����Z
    }
    scanf("%d", outN);  //��J�p���ĴX�� out
    scanf("%d", m);     //��J��ܲĴX��y��
}

void baseball(){
    char player[9][6]={{' '}};      //�y���̪��������Z
    int i=0, outN=0, m=0;
    input(player, &outN, &m);       //��J
//    for(i=0; i<9; i++){
//        printf("%s\n", player[i]);  //��X�ˬd
//    }
}

int main(){
    baseball();
//    printf("Hello world!\n");
    return 0;
}
