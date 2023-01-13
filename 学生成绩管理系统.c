#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void makemenu();//菜单
void inputstudent();//录入学生信息
void printstudent();//打印学生信息
int countstudent();//统计学生人数
void findstudent();//查找学生信息
void modifystudent();//修改学生信息
void deletestudent();//删除学生信息
void savestudent();//保存学生信息
void readstudent();//读取学生信息
void sortstudent();//排序学生信息
typedef struct Student//学生结构体
{
    char name[20];
    int age;
    int num;
    int chinese;
    int maths;
    int english;
    int sum;
}student;
typedef struct Node//链表
{
    student stu;
    struct Node* next;
}Node;

Node* head=NULL;

void makemenu()
{
    printf("\t\t\t\t*****************************************\n");
    printf("\t\t\t\t*\t欢迎使用学生管理系统v1.0\t*\n");
    printf("\t\t\t\t*****************************************\n");
    printf("\t\t\t\t*\t      请选择功能\t\t*\n");
    printf("\t\t\t\t*****************************************\n");
    printf("\t\t\t\t*\t    1. 录入学生信息\t\t*\n");
    printf("\t\t\t\t*\t    2. 打印学生信息\t\t*\n");
    printf("\t\t\t\t*\t    3. 统计学生人数\t\t*\n");
    printf("\t\t\t\t*\t    4. 查找学生信息\t\t*\n");
    printf("\t\t\t\t*\t    5. 修改学生信息\t\t*\n");
    printf("\t\t\t\t*\t    6. 删除学生信息\t\t*\n");
    printf("\t\t\t\t*\t    7. 保存学生信息\t\t*\n");
    printf("\t\t\t\t*\t    8. 读取学生信息\t\t*\n");
    printf("\t\t\t\t*\t    9. 排序学生信息\t\t*\n");
    printf("\t\t\t\t*\t    0. 退出系统    \t\t*\n");
    printf("\t\t\t\t*****************************************\n");
    printf("\t\t\t\t*       如果系统内已有数据请先读取      *\n");
    printf("\t\t\t\t*****************************************\n");
    printf("请输入你的选择：\n");
}
void inputstudent()
{
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->next=NULL;
    if(head==NULL)//头插法
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;

    }
    printf("请输入学生的姓名:\n");
    scanf("%s",newnode->stu.name);
    printf("\n");
    printf("请输入学生的年龄:\n");
    scanf("%d",&newnode->stu.age);
    printf("\n");
    printf("请输入学生的学号:\n");
    scanf("%d",&newnode->stu.num);
    printf("\n");
    printf("请输入学生的语文成绩:\n");
    scanf("%d",&newnode->stu.chinese);
    printf("\n");
    printf("请输入学生的数学成绩:\n");
    scanf("%d",&newnode->stu.maths);
    printf("\n");
    printf("请输入学生的英语成绩:\n");
    scanf("%d",&newnode->stu.english);
    newnode->stu.sum=newnode->stu.chinese+newnode->stu.maths+newnode->stu.english;
    printf("\n");
    printf("录入成功\n");
    system("pause");
    system("cls");
}
void printstudent()
{
    Node* p=head;
   if(p==NULL)
   {
    printf("没有学生信息，请录入学生信息\n");
   }
   else
   {
        printf("姓名\t年龄\t学号\t语文\t数学\t英语\t总分\t\n");
        while(p!=NULL)
        {
            printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t\n",p->stu.name,p->stu.age,p->stu.num,
            p->stu.chinese,p->stu.maths,p->stu.english,p->stu.sum);
            p=p->next;
        }
   }
    printf("\n");
    system("pause");
    system("cls");
}
int countstudent()
{
    int count=0;
    Node* q=head;
    while(q!=NULL)
    {
        count++;
        q=q->next;
    }
    return count;
}
void findstudent()
{
    char name[20];
    printf("请输入要查找学生的姓名:\n");
    scanf("%s",name);
    Node* p=head;
    while(p!=NULL)
    {
        if(strcmp(name,p->stu.name)==0)
        {
            printf("找到了，该学生的信息为:\n");
            printf("\n");
            printf("姓名\t年龄\t学号\t语文\t数学\t英语\t总分\t\n");
            printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t\n",p->stu.name,p->stu.age,p->stu.num,
            p->stu.chinese,p->stu.maths,p->stu.english,p->stu.sum);
            return;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        printf("没有该学生信息\n");
    }
}
void modifystudent()
{
    char name[20];
    Node* p=head;
    printf("请输入需要修改的学生姓名:\n");
    scanf("%s",name);
    while(p!=NULL)
    {
        if(strcmp(name,p->stu.name)==0)
        {
            printf("请输入修改后的学生姓名、年龄、学号、语文成绩、数学成绩、英语成绩:\n");
            printf("\n");
            printf("请输入学生的姓名:\n");
            scanf("%s",p->stu.name);
            printf("\n");
            printf("请输入学生的年龄:\n");
            scanf("%d",&p->stu.age);
            printf("\n");
            printf("请输入学生的学号:\n");
            scanf("%d",&p->stu.num);
            printf("\n");
            printf("请输入学生的语文成绩:\n");
            scanf("%d",&p->stu.chinese);
            printf("\n");
            printf("请输入学生的数学成绩:\n");
            scanf("%d",&p->stu.maths);
            printf("\n");
            printf("请输入学生的英语成绩:\n");
            scanf("%d",&p->stu.english);
            p->stu.sum=p->stu.chinese+p->stu.maths+p->stu.english;
            break;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        printf("没有该学生信息!\n");
    }
    system("pause");
    system("cls");
}
void deletestudent()
{
    char name[20];
    Node* p1,*p2;
    Node* p=head;
    p2=head;
    printf("请输入要删除的学生姓名:\n");
    scanf("%s",name);
    if(strcmp(head->stu.name,name)==0)
    {
        p1=head;
        head=head->next;
        free(p1);
        printf("删除成功!\n");
        return;
    }
    else
    {
        while(p->next!=NULL)
        {
            if(strcmp(p->next->stu.name,name)==0)
            {
                p2=p->next;
                p->next=p->next->next;
                free(p2);
                printf("删除成功!\n");
                return;
            }
            else
            {
                printf("该学生不存在!\n");
            }
            p=p->next;
            if(p->next==NULL)
            {
                break;
            }
        }
    }
}
void savestudent()
{
    FILE* fp=fopen("D:\\vscode dai ma\\c\\student.txt","w");
    if(fp==NULL)
    {
        printf("打开文件失败!\n");
        return;
    }
    Node *p=head;
    while(p!=NULL)
    {
        fwrite(&p->stu,1,sizeof(student),fp);
        p=p->next;
    }
    fclose(fp);
    printf("数据保存成功!\n");
}
void readstudent()
{
    FILE * fp=fopen("D:\\vscode dai ma\\c\\student.txt","r");
    if(fp==NULL)
    {
        printf("打开失败!\n");
        return;
    }
    student stu;
    while(fread(&stu,1,sizeof(student),fp))
    {
        Node* newnode=(Node*)malloc(sizeof(Node));
        newnode->next=NULL;
        memcpy(newnode,&stu,sizeof(student));
        if(head==NULL)//头插法
        {
            head=newnode;
        }
        else
        {
            newnode->next=head;
            head=newnode;
        }
    }
    fclose(fp);
    printf("加载数据成功!\n");
}
void sortstudent()
{
    Node*p=(Node*)malloc(sizeof(Node));
    Node*q=(Node*)malloc(sizeof(Node));
    if(head==NULL)
    {
        printf("当前无数据!\n");
        return;
    }
    printf("\t\t\t\t*****************************************\n");
    printf("\t\t\t\t*\t      请选择排序方式\t\t*\n");
    printf("\t\t\t\t*****************************************\n");
    printf("\t\t\t\t*\t    1. 语文成绩排序\t\t*\n");
    printf("\t\t\t\t*\t    2. 数学成绩排序\t\t*\n");
    printf("\t\t\t\t*\t    3. 英语成绩排序\t\t*\n");
    printf("\t\t\t\t*\t    4. 学号排序    \t\t*\n");
    printf("\t\t\t\t*\t    5. 总分排序    \t\t*\n");
    printf("\t\t\t\t*****************************************\n");
    int choice=0;
    printf("请输入你的选择:\n");
    scanf("%d",&choice);
    for(p=head;p!=NULL;p=p->next)
    {
        for(q=p->next;q!=NULL;q=q->next)
        {
            switch (choice)
            {
                case 1://语文成绩排序
                if(p->stu.chinese<q->stu.chinese)
                {
                    Node*x=(Node*)malloc(sizeof(Node));
                    x->stu=p->stu;
                    p->stu=q->stu;
                    q->stu=x->stu;
                    free(x);
                }
                break;

                case 2://数学成绩排序
                if(p->stu.maths<q->stu.maths)
                {
                    Node*x=(Node*)malloc(sizeof(Node));
                    x->stu=p->stu;
                    p->stu=q->stu;
                    q->stu=x->stu;
                    free(x);
                }
                break;

                case 3://英语成绩排序
                if(p->stu.english<q->stu.english)
                {
                    Node*x=(Node*)malloc(sizeof(Node));
                    x->stu=p->stu;
                    p->stu=q->stu;
                    q->stu=x->stu;
                    free(x);
                }
                break;

                case 4://学号排序
                if(p->stu.num>q->stu.num)
                {
                    Node*x=(Node*)malloc(sizeof(Node));
                    x->stu=p->stu;
                    p->stu=q->stu;
                    q->stu=x->stu;
                    free(x);
                }
                break;

                case 5://总分排序
                if(p->stu.sum<q->stu.sum)
                {
                    Node*x=(Node*)malloc(sizeof(Node));
                    x->stu=p->stu;
                    p->stu=q->stu;
                    q->stu=x->stu;
                    free(x);
                }
                break;
            
                default:
                printf("输入错误，请重新输入:");
                break;
            }
        }
    }
    printf("排序完成!\n");
}
int main()
{
    while(1)
    {
        makemenu();
        int choice=0;
        scanf("%d",&choice);
        printf("\n");
        switch(choice)
        {
            case 1://录入学生信息
            inputstudent();
            break;

            case 2://打印学生信息
            printstudent();
            break;

            case 3://统计学生人数
            printf("学生总人数为:%d\n",countstudent());
            system("pause");
            system("cls");
            break;

            case 4://查找学生信息
            findstudent();
            system("pause");
            system("cls");
            break;

            case 5://修改学生信息    
            modifystudent();                                                                                                                                                                                                                 
            break;

            case 6://删除学生信息
            deletestudent();
            system("pause");
            system("cls");
            break;

            case 7://保存学生信息
            savestudent();
            system("pause");
            system("cls");
            break;

            case 8://读取学生信息
            readstudent();
            system("pause");
            system("cls");
            break;

            case 9://排序学生信息
            sortstudent();
            system("pause");
            system("cls");
            break;

            case 0://退出系统
            printf("谢谢使用\n");
            return 0;
            break;

            default:
            printf("输入错误，请重新输入:\n");
            system("pause");
            system("cls");
            break;
        }
        getchar();
    }
    
    return 0;
}