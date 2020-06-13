#include <stdio.h>
#include <stdlib.h>
//031 ProjectTime
//2020/06/31 PM.08:00~PM.10:43 IBOTIAndy

typedef struct node_s{
    int needDay;                    //�ݨD�Ѽ�
    int completed;                  //�����F�v
    int branchN;                    //���X�Ӥ���
    int needBranchN;                //�ݭn�X�Ӥ���
    int branch[10];                 //����s��
    struct node_s *order[10];       //�U�@�Ӹ`�I
    struct node_s *needOrder[10];   //�ݭn����������
}node_t;

typedef struct project_s{
    node_t nodes[100];  //�`�I��
    int nodeN;          //�`�I�ƶq
}project_t;

//-----input-----
void inputNode(node_t *node){           //��J�`�I
    int i=0;
    scanf("%d", &(node->needDay));      //��J�ݨD�Ѽ�
    node->completed = 0;                //�]�w��������
    scanf("%d", &(node->branchN));      //��J�`�I�ƶq
    node->needBranchN = 0;              //�ݭn���`�I�ƪ�l��
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

void input(project_t project[], int *projectN){ //��J
    int i=0;
    scanf("%d", projectN);              //��J�M�׼ƶq
    for(i=0; i < *projectN; i++){       //��J�M��
        inputProject(&(project[i]));
    }
}
//----/input-----


//-----findBranch-----
void findOrder(node_t *node, node_t nodes[], int n){    //��`�I���U�@�Ӧ�m
    int i=0;
    for(i=0; i < node->branchN; i++){
        node->order[i] = &(nodes[node->branch[i]-1]);
    } //�N�n�����`�I�O���_��
}

void setNeedOrder(node_t *node, node_t *needNode){  //�]�w�ݨD�`�I
    int i=0, branchMax=10;
    for(i=0; i < branchMax; i++){
        if(node->needOrder[i] == NULL){     //���Ŧ�
            node->needBranchN += 1;         //�ݨD�ƶq+1
            node->needOrder[i] = needNode;  //������m
            break;  //���X
        }
    }
}

void findNeedOrder(node_t *node){   //�ϥΫe�@�Ӹ`�I���U�U�@�Ӹ`�I���ݨD�`�I
    int i=0;
    for(i=0; i < node->branchN; i++){
        setNeedOrder(node->order[i], node); //�N�ثe����m�����U�@�Ӧ�m
    }
}

void findBranch(project_t *project){    //�s���������`�I
    int i=0;
    for(i=0; i < project->nodeN; i++){
        findOrder(&(project->nodes[i]), project->nodes, project->nodeN);    //���`�I���U�Ӧ�m
        findNeedOrder(&(project->nodes[i]));                                //���`�I���W�Ӧ�m
    }
}
//----/findBranch-----

void f1(){
    int projectN=0, i=0;
    project_t project[10];
    input(project, &projectN);  //��J
    for(i=0; i < projectN; i++){
        findBranch(&(project[i]));  //�s���C�Ӹ`�I��m
    }
}

int main(){
    f1();
//    printf("Hello world!\n");
    return 0;
}
