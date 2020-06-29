typedef struct member_s{
    int no;         //打擊次數
    int data[5];    //每次的資料
} member_t;

void input(member_t m[9], int *goal) {
    char temp[10];
    for (int i=0; i<9; i++) {
        scanf("%d", &m[i].no);
        for (int j=0; j<m[i].no; j++) {
            scanf("%s", temp);
            if (temp[1]=='O'){
                m[i].data[j]=0;
            }
            else if (temp[0]=='H'){
                m[i].data[j]=4;
            }
            else {
                m[i].data[j]=(temp[0]-'0');
            }
        }
    }
    scanf("%d", goal);
}
