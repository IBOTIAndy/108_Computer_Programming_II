#include <stdio.h>
#include <stdlib.h>
//031 ProjectTime
//2020/06/31 PM.02:32~PM.04:35 IBOTIAndy

typedef struct node_s{
    int needDay;            //需求天數
    int completed;          //完成了ㄇ
    int branchN;            //有幾個分支
    int branch[10];         //後續編號
//    node_s *order[10];      //下一個節點
//    node_s *needOrder[10];  //需要先完成哪些
}node_t;

typedef struct project_s{
    node_t nodes[100];  //節點們
    int nodeN;          //節點數量
}project_t;

//-----input-----
void inputNode(node_t *node){           //輸入節點
    int i=0;
    scanf("%d", &(node->needDay));      //輸入需求天數
    scanf("%d", &(node->branchN));      //輸入節點數量
    node->completed = 0;                //設定為未完成
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

void input(project_t project[], int projectN){  //輸入
    int i=0;
    scanf("%d", &projectN);             //輸入專案數量
    for(i=0; i < projectN; i++){        //輸入專案
        inputProject(&(project[i]));
    }
}
//----/input-----

void f1(){
    int projectN=0;
    project_t project[10];
    input(project, projectN);   //輸入
//    for(i=0; i < projectN; i++){
//
//    }
}

int main(){
    f1();
//    printf("Hello world!\n");
    return 0;
}
