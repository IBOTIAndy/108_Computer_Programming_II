#include <stdio.h>
#include <stdlib.h>
//
//
typedef enum scoreType{Grade, GPA, Score}scoreType_t;           //成績型態
typedef enum grade{F, Cd, C, Cp, Bd, B, Bp, Ad, A, Ap}grade_t;  //等第分級 (d = -, p = +)
typedef union score_u{  //成績共用空間，一次只會使用一種
    grade_t grade;  //等第

    int scores;     //分數
}score_t;
typedef struct course_s{    //課程
    scoreType_t type;   //成績使用的型態
}course_t;
typedef struct student_s{   //學生
    int ID[5];          //學生ID
    score_t score[20];  //學生成績
}student_t;
typedef struct class_s{     //班級
    int studentN;           //學生數量
    student_t student[50];  //學生
    int courseN;            //課程數量
    course_t course[20];    //課程
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
    scanf("%d", &(A->courseN));             //輸入課程數量
    inputCourseData(A->courseN, A->course); //輸入課程資料
    scanf("%d", &(A->studentN));    //輸入學生數量
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
