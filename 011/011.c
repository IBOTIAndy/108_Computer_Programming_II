#include <stdio.h>
#include <stdlib.h>
//011 撲克牌2.0
//2020/03/28 AM.00:58 IBOTIAndy

/*題目
電腦與玩家各隨機發撲克牌，加總點數接近 10.5 則贏。
超過 10.5 爆掉分數為 0 且該方不得繼續要牌。
任一回合並未要牌的一方，失去要牌權利。
程式：
電腦發一張撲克牌給玩家，玩家可選擇要牌或不要牌。
電腦發一張撲克牌給電腦，電腦判斷是否停發牌。
以下情況電腦才會要牌：1. 總點數比玩家小 或 2. 總點數8點以下(含8點)
輸出電腦與玩家的點數，以及電腦贏或玩家贏或平手。(平手輸出：It's a tie)

輸入範例註解：
A 先發一張給給玩家(玩家獲得A)
J 再發一張給電腦(電腦獲得J)
Y 玩家選擇要牌
9 發一張給玩家(玩家獲得9)
8 電腦牌面0.5點，未超過8點，再發一張給電腦(電腦獲得8)
N 玩家選擇不要牌
5 電腦牌面8.5，低於玩家的10，因此再抽(獲得5)

輸出範例註解：
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
