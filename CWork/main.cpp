#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>

struct student
{
    char first_name[20];//姓
    char last_name[20];//姓名
    double number;//学号
    int C_grade;//C语言成绩
    int re_grade;       //重修信息
    char GPA[2];        //GPA等级
    int rank;     //班级排名
};
//定义一个学生结构体数组，用于存储学生信息
struct student student_list[100];
//已经存储的学生数量
int student_num = 0;

void Sort_by_score();//按成绩排序
//输入score计算GPA等级为A+, A, B+, B, C+, C, D, F,F为60分以下的成绩

//Adds(n, name[], id[], score[]): 批量新增n个学⽣的信息；
void Adds(int n, char name[][20], double id[], int score[])
{
    int i;
    for(i=0;i<n;i++)
    {
        strcpy(student_list[student_num].first_name, name[i]);
        strcpy(student_list[student_num].last_name, name[i]);
        student_list[student_num].number = id[i];
        //如果12位学号前4位为2021、2020、2019，则为重修学生，否则为正常学生
        if(id[i]/100000000==2020||id[i]/100000000==2019)
            student_list[student_num].re_grade = 1;
        else
            student_list[student_num].re_grade = 0;
        //GPA等级为A+, A, B+, B, C+, C, D, F,F为60分以下的成绩
        if(score[i]>=60)
            strcpy(student_list[student_num].GPA, "A+");
        else if(score[i]>=55&&score[i]<60)
            strcpy(student_list[student_num].GPA, "A");
        else if(score[i]>=50&&score[i]<55)
            strcpy(student_list[student_num].GPA, "B+");
        else if(score[i]>=45&&score[i]<50)
            strcpy(student_list[student_num].GPA, "B");
        else if(score[i]>=40&&score[i]<45)
            strcpy(student_list[student_num].GPA, "C+");
        else if(score[i]>=35&&score[i]<40)
            strcpy(student_list[student_num].GPA, "C");
        else if(score[i]>=30&&score[i]<35)
            strcpy(student_list[student_num].GPA, "D");
        else
            strcpy(student_list[student_num].GPA, "F");
        student_list[student_num].rank = i+1;
        student_num++;
    }
}
// Add(name, id, score): 新增⼀个学⽣的信息；
void Add(char name1[],char name2[], double id, int score)
{
    strcpy(student_list[student_num].first_name, name1);
    strcpy(student_list[student_num].last_name, name2);
    student_list[student_num].number = id;
    student_list[student_num].C_grade = score;
    //如果12位学号前4位为2021、2020、2019，则为重修学生，否则为正常学生
    int b=id/100000000;
    if(b==2020||b==2019)
        student_list[student_num].re_grade = 1;
    else
        student_list[student_num].re_grade = 0;
    //GPA等级为A+, A, B+, B, C+, C, D, F,F为60分以下的成绩
    if(score>=93)
        strcpy(student_list[student_num].GPA, "A+");
    else if(score>=90)
        strcpy(student_list[student_num].GPA, "A");
    else if(score>=87)
        strcpy(student_list[student_num].GPA, "B+");
    else if(score>=83)
        strcpy(student_list[student_num].GPA, "B");
    else if(score>=80)
        strcpy(student_list[student_num].GPA, "C+");
    else if(score>=77)
        strcpy(student_list[student_num].GPA, "C");
    else if(score>=73)
        strcpy(student_list[student_num].GPA, "D");
    else
        strcpy(student_list[student_num].GPA, "F");
    //计算这个成绩的班级排名
    student_list[student_num].rank = student_num+1;
    student_num++;
    //排序score值最大的学生排在最前面
    Sort_by_score();
    
    //最大的score的rank为1，其他的rank依次加1，如果score相同，则rank相同
    student_list[0].rank = 1;

    for(int i=1;i<student_num;i++){
        if(student_list[i].C_grade==student_list[i-1].C_grade)student_list[i].rank=student_list[i-1].rank;
        else student_list[i].rank=student_list[i-1].rank+1;
    }
    
    
}
//Delete(id): 根据学号删除某个学⽣的信息；
void Delete(double id)
{
    int i;
    for(i=0;i<student_num;i++)
    {
        if(student_list[i].number==id)
        {
            student_list[i].number = student_list[student_num-1].number;
            strcpy(student_list[i].first_name, student_list[student_num-1].first_name);
            strcpy(student_list[i].last_name, student_list[student_num-1].last_name);
            student_list[i].C_grade = student_list[student_num-1].C_grade;
            student_list[i].re_grade = student_list[student_num-1].re_grade;
            strcpy(student_list[i].GPA, student_list[student_num-1].GPA);
            student_list[i].rank = student_list[student_num-1].rank;
            student_num--;
            break;
        }
    }
}
//Search(id) ：根据学号查找某个学⽣的信息。
void Search(double id)
{
    int i;
    for(i=0;i<student_num;i++)
    {
        if(student_list[i].number==id)
        {
            printf("|%10s|%9s|", student_list[i].first_name, student_list[i].last_name);
            printf("%12.0f|", student_list[i].number);
            printf("%7d|", student_list[i].C_grade);
            if(student_list[i].re_grade==1)
                printf("%9s|", "重修");
            else
                printf("%9s|", "正常");
            printf("%3s|", student_list[i].GPA);
            printf("%4d|\n", student_list[i].rank);
            break;
        }
    }
}

//⽣成根据学号顺序排列学⽣信息的表格
void Sort_by_id(){
    int i,j;
    struct student temp;
    for(i=0;i<student_num;i++)
    {
        for(j=i+1;j<student_num;j++)
        {
            if(student_list[i].number>student_list[j].number)
            {
                temp = student_list[i];
                student_list[i] = student_list[j];
                student_list[j] = temp;
            }
        }
    }
}
//⽣成根据分数由⾼到低顺序排列学⽣信息的表格
void Sort_by_score(){
    int i,j;
    struct student temp;
    for(i=0;i<student_num;i++)
    {
        for(j=i+1;j<student_num;j++)
        {
            if(student_list[i].C_grade<student_list[j].C_grade)
            {
                temp = student_list[i];
                student_list[i] = student_list[j];
                student_list[j] = temp;
            }
        }
    }
}
//返回最⾼分学⽣信息
void Max(){
    int i;
    int max = student_list[0].C_grade;
    for(i=0;i<student_num;i++)
    {
        if(student_list[i].C_grade>max)
        {
            max = student_list[i].C_grade;
        }
    }
    printf("Max is %d\n", max);
}
//返回最低分学⽣信息
void Min(){
    int i;
    int min = student_list[0].C_grade;
    for(i=0;i<student_num;i++)
    {
        if(student_list[i].C_grade<min)
        {
            min = student_list[i].C_grade;
        }
    }
    printf("Min is %d\n", min);
}
//返回所有学⽣c语言期末成绩平均分
void Ave(){
    int i;
    double sum = 0;
    for(i=0;i<student_num;i++)
    {
        sum += student_list[i].C_grade;
    }
    printf("Average is  %f\n", (double)sum/student_num);
}
//返回某个学⽣的成绩是否为素数
void prime(double id){
    //通过id找到该学生成绩
    int i;
    for(i=0;i<student_num;i++)
    {
        if(student_list[i].number==id)
        {
            int j;
            int flag = 1;
            for(j=2;j<=student_list[i].C_grade/2;j++)
            {
                if(student_list[i].C_grade%j==0)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag==1)
                printf("yes\n");//是素数
            else
                printf("no\n");//不是素数
            break;
        }
    }
}
//返回某两个学⽣的成绩是否互质/互素
void coprime(double id1, double id2){
    int i;
    int flag = 0;
    //通过id1，id2找到该学生成绩并判断他们是否互质
    for(i=0;i<student_num;i++)
    {
        if(student_list[i].number==id1)
        {
            int j;
            for(j=2;j<=student_list[i].C_grade/2;j++)
            {
                if(student_list[i].C_grade%j==0 && student_list[i].C_grade/j==id2)
                {
                    flag = 1;//互质
                    break;
                }
            }
            break;
        }
    }
    if(flag==1)
        printf("yes\n");//互质 
    else
        printf("no\n");//不是互质

    


    
}

//以表格形式输出所有学生id
void Print_id(){
    int i;
    printf("All student id:\n");
    for(i=0;i<student_num;i++)
    {
        printf("%12.0f\n", student_list[i].number);
    }
}
//以表格形式输出所有学生信息
void Print_all(){
    int i;
    //固定输出20个字符的-
    printf("|%-6s|%-6s|%-12s|%-3s|%-3s|%-3s|%-3s|\n", "First Name", "Last Name", "Number", "C Grade", "Re Grade", "GPA", "Rank");
    printf("|——————————|—————————|————————————|———————|————————|———|————|\n");
    for(i=0;i<student_num;i++)
    {
        printf("|%10s|%9s|", student_list[i].first_name, student_list[i].last_name);
        printf("%12.0f|", student_list[i].number);
        printf("%7d|", student_list[i].C_grade);
        if(student_list[i].re_grade==1)
            printf("%10s|", "重修");
        else
            printf("%10s|", "正常");
        printf("%3s|", student_list[i].GPA);
        printf("%4d|\n", student_list[i].rank);
    }
    printf("|——————————|—————————|————————————|———————|————————|———|————|\n");
}

//界面菜单
void info(int N){
    system("cls");
    if(N==0){
    printf("Hello, pls input a series of student information!\n");
    printf("Okay, data upload finished. What do you what to do next? You can enter a number to tell me.\n"); 
    printf("1 add\n");
    printf("2 adds\n");
    printf("3 delete\n");
    printf("4 search\n");
    printf("5 sort by id\n");
    printf("6 sort by score\n");
    printf("7 best score\n");
    printf("8 worst score\n");
    printf("9 prime judge\n");
    printf("10 coprime judge\n");
    printf("0 exit\n");
    }
    if(N!=0){
        printf("Do you still need my service? You can enter a number to tell me.\n");
        printf("1 add\n");
        printf("2 adds\n");
        printf("3 delete\n");
        printf("4 search\n");
        printf("5 sort by id\n");
        printf("6 sort by score\n");
        printf("7 best score\n");
        printf("8 worst score\n");
        printf("9 prime judge\n");
        printf("10 coprime judge\n");
        printf("0 exit\n");
    }
}

//执行菜单选项函数switch语句
void menu(int n){
    char first_name[20];
    char  last_name[20];  
    double id;
    int score;
    double id1, id2;
    int N;
    switch(n){
        case 1:
            printf("\nPlease input the first name of the student:");
            scanf("%s", &first_name);
            printf("\nPlease input the last name of the student:");
            scanf("%s", &last_name);
            printf("\nPlease input the id of the student:");
            scanf("%lf", &id);
            printf("\nPlease input the C grade of the student:\n");
            scanf("%d", &score);
            //输入学生信息first_name,last_name id, score
            //scanf("%s %s %lf %d", first_name, last_name, &id, &score);
            Add(first_name,last_name, id, score);
            Print_all();
            break;
        case 2:
            //输入多个学生信息
            printf("\nPlease input the number of students:");
            scanf("%d",&N);
            while( N--){
                printf("\nPlease input the first name of the student:");
                scanf("%s", &first_name);
                printf("\nPlease input the last name of the student:");
                scanf("%s", &last_name);
                printf("\nPlease input the id of the student:");
                scanf("%lf", &id);
                printf("\nPlease input the C grade of the student:\n");
                scanf("%d", &score);
                Add(first_name,last_name, id, score);
            }
            Print_all();
            break;
        case 3:
            //删除学生信息
            Print_id();
            printf("\nPlease input the id of the student:");
            scanf("%lf", &id);
            Delete(id);
            Print_all();
            break;
        case 4:
            //查找学生信息
            Print_id();
            printf("\nPlease input the id of the student:");
            scanf("%lf", &id);
            Search(id);
            break;
        case 5:
            //按id排序
            Sort_by_id();
            Print_all();
            break;
        case 6:
            Sort_by_score();
            Print_all();
            break;
        case 7:
            Max();
            break;
        case 8:
            Min();
            break;
        case 9:
            Print_id();
            printf("\nPlease input the id of the student:");
            scanf("%lf", &id);
            prime(id);
            break;
        case 10:
            Print_id();
            printf("\nPlease input the id of the student:");
            scanf("%lf %lf", &id1, &id2);
            coprime(id1, id2);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Please enter a number between 1 and 10.\n");
            break;
    }
    system("pause");

}

int main(){
    int n;
    info(0);
    printf("Please enter a number between 1 and 10.:");
    Add("Ming", "Xiao", 202100123445, 99);
    Add("Hong", "Xiao", 201900101002, 99);
    Add("Huang", "Xiao", 202001000111, 98);
    Add("Zhang", "Xiao", 202102010111, 97);
    Add("Hua", "Li", 202001101111, 100);
    //不断读入并判断输出info界面菜单
    while(scanf("%d",&n),n){

        //执行菜单选项函数
        menu(n);
        info(1);
        printf("Please enter a number between 1 and 10.:");

    }
}