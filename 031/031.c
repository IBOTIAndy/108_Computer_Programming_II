#include <stdio.h>
#include <stdlib.h>
//031 ProjectTime
//2020/06/31 PM.10:50~PM.12:15 IBOTIAndy

typedef struct node_s{
    int needDay;                    //需求天數
    int completed;                  //完成了ㄇ
    int branchN;                    //有幾個分支
    int needBranchN;                //需要幾個分支
    int branch[10];                 //後續編號
    struct node_s *order[10];       //下一個節點
    struct node_s *needOrder[10];   //需要先完成哪些
}node_t;

typedef struct project_s{
    node_t nodes[100];  //節點們
    int nodeN;          //節點數量
}project_t;

//-----input-----
void inputNode(node_t *node){           //輸入節點
    int i=0;
    scanf("%d", &(node->needDay));      //輸入需求天數
    node->completed = 0;                //設定為未完成
    scanf("%d", &(node->branchN));      //輸入節點數量
    node->needBranchN = 0;              //需要的節點數初始化
    for(i=0; i < node->branchN; i++){   //輸入會走到哪些節點
        scanf("%d", &(node->branch[i]));
    }
}

void inputProject(project_t *project){  //輸入專案內容
    int i=0;
    scanf("%d", &(project->nodeN));     //輸入節點數量
    for(i=0; i < project->nodeN; i++){  //輸入節點
        inputNode(&(project->nodes[i]));
    }
}

void input(project_t project[], int *projectN){ //輸入
    int i=0;
    scanf("%d", projectN);              //輸入專案數量
    for(i=0; i < *projectN; i++){       //輸入專案
        inputProject(&(project[i]));
    }
}
//----/input-----


//-----findBranch-----
void findOrder(node_t *node, node_t nodes[], int n){    //找節點的下一個位置
    int i=0;
    for(i=0; i < node->branchN; i++){
        node->order[i] = &(nodes[node->branch[i]-1]);
    } //將要走的節點記錄起來
}

void setNeedOrder(node_t *node, node_t *needNode){  //設定需求節點
    int i=0, branchMax=10;
    for(i=0; i < branchMax; i++){
        if(node->needOrder[i] == NULL){     //找到空位
            node->needBranchN += 1;         //需求數量+1
            node->needOrder[i] = needNode;  //紀錄位置
            break;  //跳出
        }
    }
}

void findNeedOrder(node_t *node){   //使用前一個節點幫助下一個節點找到需求節點
    int i=0;
    for(i=0; i < node->branchN; i++){
        setNeedOrder(node->order[i], node); //將目前的位置給予下一個位置
    }
}

void findBranch(project_t *project){    //連結全部的節點
    int i=0;
    for(i=0; i < project->nodeN; i++){
        findOrder(&(project->nodes[i]), project->nodes, project->nodeN);    //找到節點的下個位置
        findNeedOrder(&(project->nodes[i]));                                //找到節點的上個位置
    }
}
//----/findBranch-----

//-----mathNeedDay-----
int allCompleted(project_t *project){   //全部都完成了嗎
    int i=0;
    for(i=0; i < project->nodeN; i++){  //搜尋全部的節點
        if(project->nodes[i].completed == 0){   //如果有一個節點沒完成
            return 0;   //回傳 false
        }
    }   //都完成
    return 1;   //回傳 true
}

int needAllCompleted(node_t *node){ //檢查前置節點都完成了嗎
    int i=0;
    for(i=0; i < node->needBranchN; i++){   //搜尋全部的前置節點
        if(node->needOrder[i]->completed == 0){ //如果有一個沒完成
            return 0;   //回傳 false
        }
    }   //都完成
    return 1;   //回傳 true
}

//void walkNode(node_t *node, int *needDay){
//    if(needAllCompleted(node)){     //如果全部的前置節點都完成
//        if(*needDay - node->needDay >= 0){
//            node->completed = 1;
//        }
//        if(node->completed){
//            *needDay = *needDay - node->needDay;
//        }
//    }
//}

void walkNode(node_t *node, int needDay, int *allCompleted){   //瀏覽node
    int i=0;
//    if(needAllCompleted(node)){     //如果全部的前置節點都完成
        if(needDay - node->needDay >= 0){   //如果扣除後，還有剩
            node->completed = 1;    //這個路線完成
        }
        else{   //沒有剩
            node->completed = 0;    //這個路線還沒完成
            *allCompleted = 0;  //還沒有全部都完成
        }
        if(node->completed){    //如果路線完成，可以繼續望後走
            for(i=0; i < node->branchN; i++){  //走全部的位置
                walkNode(node->order[i], needDay - node->needDay, allCompleted);    //往後走
            }
        }
//    }
}

void mathNeedDay(project_t *project){
    int needDay=0, allCompleted=0;
//    while(!allCompleted(project) || flag){  //如果還沒全部完成
    while(!allCompleted){   //如果還沒全部完成
        needDay++;          //每次加一天
        allCompleted = 1;   //
        walkNode(&(project->nodes[0]), needDay, &allCompleted); //從第一個位置開始走
    }
    printf("%d\n", needDay);    //全部走完 輸出需要天數
}
//----/mathNeedDay-----

void f1(){
    int projectN=0, i=0;
    project_t project[10];
    input(project, &projectN);  //輸入
    for(i=0; i < projectN; i++){
        findBranch(&(project[i]));  //連接每個節點位置
        mathNeedDay(&(project[i])); //找到需要天數
    }
}

int main(){
    f1();
//    printf("Hello world!\n");
    return 0;
}
