#include <stdio.h>
#include <stdlib.h>
//031 ProjectTime
//2020/06/31 PM.02:32~PM.04:35 IBOTIAndy

typedef struct node_s{
    int needDay;            //�ݨD�Ѽ�
    int completed;          //�����F�v
    int branchN;            //���X�Ӥ���
    int branch[10];         //����s��
//    node_s *order[10];      //�U�@�Ӹ`�I
//    node_s *needOrder[10];  //�ݭn����������
}node_t;

typedef struct project_s{
    node_t nodes[100];  //�`�I��
    int nodeN;          //�`�I�ƶq
}project_t;

//-----input-----
void inputNode(node_t *node){           //��J�`�I
    int i=0;
    scanf("%d", &(node->needDay));      //��J�ݨD�Ѽ�
    scanf("%d", &(node->branchN));      //��J�`�I�ƶq
    node->completed = 0;                //�]�w��������
    for(i=0; i < node->branchN; i++){   //��J�|������Ǹ`�I
        scanf("%d", &(node->branch[i]));
    }
}

void inputProject(project_t *project){  //��J�M�פ��e
    int i=0;
    scanf("%d", &(project->nodeN));     //��J�`�I�ƶq
    for(i=0; i < project->nodeN; i++){  //��J�`�I
        inputNode(&(project->nodes[i]));
    }
}

void input(project_t project[], int projectN){  //��J
    int i=0;
    scanf("%d", &projectN);             //��J�M�׼ƶq
    for(i=0; i < projectN; i++){        //��J�M��
        inputProject(&(project[i]));
    }
}
//----/input-----

void f1(){
    int projectN=0;
    project_t project[10];
    input(project, projectN);   //��J
//    for(i=0; i < projectN; i++){
//
//    }
}

int main(){
    f1();
//    printf("Hello world!\n");
    return 0;
}
