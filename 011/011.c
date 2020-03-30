#include <stdio.h>
#include <stdlib.h>
//011 ���J�P2.0
//2020/03/28 AM.00:58 IBOTIAndy

/*�D��
�q���P���a�U�H���o���J�P�A�[�`�I�Ʊ��� 10.5 �hĹ�C
�W�L 10.5 �z�����Ƭ� 0 �B�Ӥ褣�o�~��n�P�C
���@�^�X�å��n�P���@��A���h�n�P�v�Q�C
�{���G
�q���o�@�i���J�P�����a�A���a�i��ܭn�P�Τ��n�P�C
�q���o�@�i���J�P���q���A�q���P�_�O�_���o�P�C
�H�U���p�q���~�|�n�P�G1. �`�I�Ƥ񪱮a�p �� 2. �`�I��8�I�H�U(�t8�I)
��X�q���P���a���I�ơA�H�ιq��Ĺ�Ϊ��aĹ�Υ���C(�����X�GIt's a tie)

��J�d�ҵ��ѡG
A ���o�@�i�������a(���a��oA)
J �A�o�@�i���q��(�q����oJ)
Y ���a��ܭn�P
9 �o�@�i�����a(���a��o9)
8 �q���P��0.5�I�A���W�L8�I�A�A�o�@�i���q��(�q����o8)
N ���a��ܤ��n�P
5 �q���P��8.5�A�C�󪱮a��10�A�]���A��(��o5)

��X�d�ҵ��ѡG
10.0 vs. 0.0
player wins
*/

double draw(int n){
    char s[4]={' '};
    int i=0;
    double point=0.0;
    while(i < n){
        scanf("%s", s);
        if(s[0] == 'A'){
            point = point + 1.0;
        }
        else if(s[0] >= '2' && s[0] <= '9'){
            point = point + (double)(s[0] - '0');
        }
        else if(s[0] == '1' && s[1] == '0'){
            point = point + 10.0;
        }
        else if(s[0] == 'J' || s[0] == 'Q' || s[0] == 'K'){
            point = point + 0.5;
        }
        i = i + 1;
    }
    return point;
}

double checkBlow(double point){
    if(point > 10.5){
        return 0.0;
    }
    else{
        return point;
    }
}

void printWiner(double pointPlayer, double pointComputer){
    printf("%.1f vs. %.1f\n", pointPlayer, pointComputer);
    if(pointPlayer > pointComputer){
        printf("player wins");
    }
    else if(pointPlayer < pointComputer){
        printf("computer wins");
    }
    else{
        printf("It's a tie");
    }
}

//void poker105(){
//    double pointA=0, pointB=0;
//
//    pointA = checkBlow(draw(3));
//    pointB = checkBlow(draw(3));
//    while(1){
//        pointA = pointA + checkBlow(draw(3));
//    }
//    printWiner(pointA, pointB);
//}

int pokerGame(){
    int playerNeed=1, computerNeed=1;
    double pointPlayer=0, pointComputer=0;
    char playerSelect[2]={' '};
    pointPlayer = checkBlow(draw(1));
    pointComputer = checkBlow(draw(1));
    while(1){
        if(playerNeed){
            scanf("%s", playerSelect);
        }
        if(playerSelect[0] == 'Y'){
            pointPlayer = checkBlow(pointPlayer + draw(1));
        }
        else if(playerNeed && playerSelect[0] == 'N'){
            playerNeed = 0;
        }
        if(computerNeed && (pointComputer < pointPlayer || pointComputer <= 8)){
            pointComputer = checkBlow(pointComputer + draw(1));
        }
        else{
            computerNeed = 0;
        }
        if(pointPlayer == 0 || pointComputer == 0){
            break;
        }
        if(playerNeed == 0 && computerNeed == 0){
            break;
        }
    }
    printWiner(pointPlayer, pointComputer);
    return 0;
}

int main(){
    pokerGame();
//    printf("Hello world!\n");
    return 0;
}
