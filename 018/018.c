#include <stdio.h>
#include <stdlib.h>
//018 baseball
//2020/04/24 PM. 01:19 IBOTIAndy

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

int mathScore(int base){    //�p��o�X��
    int ans=0;
    while(base != 0){       //0110          //0100
        if(base & 1 == 1){  //1100 != 0100  //1000 != 0000
            ans=ans+1;      //0+1           //1+1
        }
        base = base >> 1;   //0100          //0000
    }
    return ans;
}

int runBase(int *base, int baseman){    //�]�S
    int score=0;
    *base = (*base << baseman) | (1 << (baseman - 1));  //�����S�]���A
    if(*base > 7){                                      //�p�G���H�^�S
        score = mathScore((*base >> 3));                //�p�����(�p��h�֤H�^���S)
        *base = *base & 7;                              //�M���h�X���H
    }
    return score;   //�^�Ǳo��
}

int math(char player[][6], int playerN, int roundN, int n, int m){
    int i=0, j=0, ans=0, out=0, outN=0, base=0, baseman=0;
    int minWhere=0, mFlag=0, mHit=0, mBack=0, f=1;
    for(i=0; i < roundN; i++){          //���� (1~5)
        for(j=0; j < playerN; j++){     //�y�� (1~9)
            switch(player[j][i]){           //
                case '\0':                  //�p�G�S�F�A���X
                    break;
                case 'O':                   //�X��
                    out = out + 1;          //�X����+1 (�� 3 ���m�S�]
                    outN = outN + 1;        //(outN == b) ���� (b=n)
                    break;
                case 'H':                   //���S��
                    baseman = 4;            //�]�S�אּ 4
                    ans = ans + runBase(&base, baseman);    //�]��runBase�u��p��̦h����3
                    break;                                  //�ҥH�n�h+1�~��p�� +4
                default:                                    //�w��
                    baseman = player[j][i] - '0';           //�w���� = '�r��' - '0';
                    ans = ans + runBase(&base, baseman);    //�]�S
            }
            if(outN == n && f){                 //�p�G out = b
                f = 0;                          //���L���|�A����X (flag)
                printf("%d\n", ans);            //��X���G
                printf("%d,%d\n", mHit, mBack); //
            }
            if(j + 1 == m && baseman){          //�p�G�O�� m ��y�������A�åB�����X�w��
                mFlag = 1;                      // m �}�l�]�S
                mHit = mHit + 1;                // m ��������+1
                minWhere = 1 << (baseman - 1);  // m ����m����
                if(baseman == 4){               // �p�G�O���S��
                    mHit = mHit - 1;            // ���p�⬰�w��
                }
            }
            if(mFlag){                          //�p�G m �}�l�]�S
                minWhere = minWhere << baseman; // m ����
                if(minWhere > 7){               // �p�G m �w�g��F���S
                    mBack = mBack + 1;          // m �^�S��+1
                    minWhere = 0;               // m �q�S�]�W����
                    mFlag = 0;                  // m �����]�S
                }
            }
            if(out == 3){       //�p�G�T��
                minWhere = 0;   // m �q�S�]�W����
                mFlag = 0;      // m �����]�S
                base = 0;       // �����S�]�W���H
                out = 0;        // �X���ƭ��m
            }
            baseman = 0;    //�C���j�鵲���ɡA���m�w��
        }
    }
    return ans;
}

void baseball(){
    char player[9][6]={{' '}};      //�y���̪��������Z
    int outN=0, m=0;
//    int i=0;
    //int ansOut=0, ansM=0;
    input(player, &outN, &m);       //��Jto 33
//    for(i=0; i<9; i++){
//        printf("%s\n", player[i]);  //��X�ˬd
//    }
    math(player, 9, 5, outN, m);    //to 64
}

int main(){
    baseball(); //to 117
//    printf("Hello world!\n");
    return 0;
}
