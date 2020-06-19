#include <stdio.h>
#include <stdlib.h>
//
//
typedef enum scoreType{Grade, GPA, Score}scoreType_t;           //���Z���A
typedef enum grade{F, Cd, C, Cp, Bd, B, Bp, Ad, A, Ap}grade_t;  //���Ĥ��� (d = -, p = +)
typedef union score_u{  //���Z�@�ΪŶ��A�@���u�|�ϥΤ@��
    grade_t grade;  //����

    int scores;     //����
}score_t;
typedef struct course_s{    //�ҵ{
    scoreType_t type;   //���Z�ϥΪ����A
}course_t;
typedef struct student_s{   //�ǥ�
    int ID[5];          //�ǥ�ID
    score_t score[20];  //�ǥͦ��Z
}student_t;
typedef struct class_s{     //�Z��
    int studentN;           //�ǥͼƶq
    student_t student[50];  //�ǥ�
    int courseN;            //�ҵ{�ƶq
    course_t course[20];    //�ҵ{
}class_t;

void setCourseType(course_t *course, scoreType_t type){
    course->type = type;
}

void inputCourseData(int courseN, course_t course[]){
    int i=0;
    char inString[4]={' '};
    for(i=0; i < courseN; i++){
        gets(inString);
        if(inString[0] == 'G' && inString[1] == '\0'){
            setCourseType(&(course[i]), Grade);
        }
        else if(inString[0] == 'G' && inString[1] == 'P'){
            setCourseType(&(course[i]), GPA);
        }
        else if(inString[0] == 'S'){
            setCourseType(&(course[i]), Score);
        }
    }
}

void setGrade(score_t *score){
    char inString[3]={' '};
    score_t tScore;
    gets(inString);
    if(inString[0] == 'A' && inString[1] == '+'){
        tScore.grade = Ap;
    }
    else if(inString[0] == 'A' && inString[1] == '\0'){
        tScore.grade = A;
    }
    else if(inString[0] == 'A' && inString[1] == '-'){
        tScore.grade = Ad;
    }
    else if(inString[0] == 'B' && inString[1] == '+'){
        tScore.grade = Bp;
    }
    else if(inString[0] == 'B' && inString[1] == '\0'){
        tScore.grade = B;
    }
    else if(inString[0] == 'B' && inString[1] == '-'){
        tScore.grade = Bd;
    }
    else if(inString[0] == 'C' && inString[1] == '+'){
        tScore.grade = Cp;
    }
    else if(inString[0] == 'C' && inString[1] == '\0'){
        tScore.grade = C;
    }
    else if(inString[0] == 'C' && inString[1] == '-'){
        tScore.grade = Cd;
    }
    else if(inString[0] == 'F' && inString[1] == '\0'){
        tScore.grade = F;
    }
    score->grade = tScore.grade;
}

void setStudent(int courseN, student_t *student, course_t course[]){
    int i=0;
    for(i=0; i < courseN; i++){
        scanf("%d", student->ID);
        switch(course[i].type){
        case Grade:
            setGrade(student->score);
            break;
        case GPA:

            break;
        case Score:
            scanf("%d", student->score.scores);
            break;
        }
    }
}

void inputStudentData(int studentN, int courseN, student_t student[], course_t course[]){
    int i=0;
    for(i=0; i < studentN; i++){
        setStudent(courseN, &(student[i]), course);

    }
}

void input(class_t *A){
    scanf("%d", &(A->courseN));             //��J�ҵ{�ƶq
    inputCourseData(A->courseN, A->course); //��J�ҵ{���
    scanf("%d", &(A->studentN));    //��J�ǥͼƶq
    inputStudentData(A->studentN, A->courseN, &(A->student), &(A->course));
}

int f1(){
    class_t A;
    input(&A);
    return 0;
}

int main(){
    f1();
//    printf("Hello world!\n");
    return 0;
}
