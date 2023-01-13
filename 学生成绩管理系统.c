#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void makemenu();//�˵�
void inputstudent();//¼��ѧ����Ϣ
void printstudent();//��ӡѧ����Ϣ
int countstudent();//ͳ��ѧ������
void findstudent();//����ѧ����Ϣ
void modifystudent();//�޸�ѧ����Ϣ
void deletestudent();//ɾ��ѧ����Ϣ
void savestudent();//����ѧ����Ϣ
void readstudent();//��ȡѧ����Ϣ
void sortstudent();//����ѧ����Ϣ
typedef struct Student//ѧ���ṹ��
{
    char name[20];
    int age;
    int num;
    int chinese;
    int maths;
    int english;
    int sum;
}student;
typedef struct Node//����
{
    student stu;
    struct Node* next;
}Node;

Node* head=NULL;

void makemenu()
{
    printf("\t\t\t\t*****************************************\n");
    printf("\t\t\t\t*\t��ӭʹ��ѧ������ϵͳv1.0\t*\n");
    printf("\t\t\t\t*****************************************\n");
    printf("\t\t\t\t*\t      ��ѡ����\t\t*\n");
    printf("\t\t\t\t*****************************************\n");
    printf("\t\t\t\t*\t    1. ¼��ѧ����Ϣ\t\t*\n");
    printf("\t\t\t\t*\t    2. ��ӡѧ����Ϣ\t\t*\n");
    printf("\t\t\t\t*\t    3. ͳ��ѧ������\t\t*\n");
    printf("\t\t\t\t*\t    4. ����ѧ����Ϣ\t\t*\n");
    printf("\t\t\t\t*\t    5. �޸�ѧ����Ϣ\t\t*\n");
    printf("\t\t\t\t*\t    6. ɾ��ѧ����Ϣ\t\t*\n");
    printf("\t\t\t\t*\t    7. ����ѧ����Ϣ\t\t*\n");
    printf("\t\t\t\t*\t    8. ��ȡѧ����Ϣ\t\t*\n");
    printf("\t\t\t\t*\t    9. ����ѧ����Ϣ\t\t*\n");
    printf("\t\t\t\t*\t    0. �˳�ϵͳ    \t\t*\n");
    printf("\t\t\t\t*****************************************\n");
    printf("\t\t\t\t*       ���ϵͳ�������������ȶ�ȡ      *\n");
    printf("\t\t\t\t*****************************************\n");
    printf("���������ѡ��\n");
}
void inputstudent()
{
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->next=NULL;
    if(head==NULL)//ͷ�巨
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;

    }
    printf("������ѧ��������:\n");
    scanf("%s",newnode->stu.name);
    printf("\n");
    printf("������ѧ��������:\n");
    scanf("%d",&newnode->stu.age);
    printf("\n");
    printf("������ѧ����ѧ��:\n");
    scanf("%d",&newnode->stu.num);
    printf("\n");
    printf("������ѧ�������ĳɼ�:\n");
    scanf("%d",&newnode->stu.chinese);
    printf("\n");
    printf("������ѧ������ѧ�ɼ�:\n");
    scanf("%d",&newnode->stu.maths);
    printf("\n");
    printf("������ѧ����Ӣ��ɼ�:\n");
    scanf("%d",&newnode->stu.english);
    newnode->stu.sum=newnode->stu.chinese+newnode->stu.maths+newnode->stu.english;
    printf("\n");
    printf("¼��ɹ�\n");
    system("pause");
    system("cls");
}
void printstudent()
{
    Node* p=head;
   if(p==NULL)
   {
    printf("û��ѧ����Ϣ����¼��ѧ����Ϣ\n");
   }
   else
   {
        printf("����\t����\tѧ��\t����\t��ѧ\tӢ��\t�ܷ�\t\n");
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
    printf("������Ҫ����ѧ��������:\n");
    scanf("%s",name);
    Node* p=head;
    while(p!=NULL)
    {
        if(strcmp(name,p->stu.name)==0)
        {
            printf("�ҵ��ˣ���ѧ������ϢΪ:\n");
            printf("\n");
            printf("����\t����\tѧ��\t����\t��ѧ\tӢ��\t�ܷ�\t\n");
            printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t\n",p->stu.name,p->stu.age,p->stu.num,
            p->stu.chinese,p->stu.maths,p->stu.english,p->stu.sum);
            return;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        printf("û�и�ѧ����Ϣ\n");
    }
}
void modifystudent()
{
    char name[20];
    Node* p=head;
    printf("��������Ҫ�޸ĵ�ѧ������:\n");
    scanf("%s",name);
    while(p!=NULL)
    {
        if(strcmp(name,p->stu.name)==0)
        {
            printf("�������޸ĺ��ѧ�����������䡢ѧ�š����ĳɼ�����ѧ�ɼ���Ӣ��ɼ�:\n");
            printf("\n");
            printf("������ѧ��������:\n");
            scanf("%s",p->stu.name);
            printf("\n");
            printf("������ѧ��������:\n");
            scanf("%d",&p->stu.age);
            printf("\n");
            printf("������ѧ����ѧ��:\n");
            scanf("%d",&p->stu.num);
            printf("\n");
            printf("������ѧ�������ĳɼ�:\n");
            scanf("%d",&p->stu.chinese);
            printf("\n");
            printf("������ѧ������ѧ�ɼ�:\n");
            scanf("%d",&p->stu.maths);
            printf("\n");
            printf("������ѧ����Ӣ��ɼ�:\n");
            scanf("%d",&p->stu.english);
            p->stu.sum=p->stu.chinese+p->stu.maths+p->stu.english;
            break;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        printf("û�и�ѧ����Ϣ!\n");
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
    printf("������Ҫɾ����ѧ������:\n");
    scanf("%s",name);
    if(strcmp(head->stu.name,name)==0)
    {
        p1=head;
        head=head->next;
        free(p1);
        printf("ɾ���ɹ�!\n");
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
                printf("ɾ���ɹ�!\n");
                return;
            }
            else
            {
                printf("��ѧ��������!\n");
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
        printf("���ļ�ʧ��!\n");
        return;
    }
    Node *p=head;
    while(p!=NULL)
    {
        fwrite(&p->stu,1,sizeof(student),fp);
        p=p->next;
    }
    fclose(fp);
    printf("���ݱ���ɹ�!\n");
}
void readstudent()
{
    FILE * fp=fopen("D:\\vscode dai ma\\c\\student.txt","r");
    if(fp==NULL)
    {
        printf("��ʧ��!\n");
        return;
    }
    student stu;
    while(fread(&stu,1,sizeof(student),fp))
    {
        Node* newnode=(Node*)malloc(sizeof(Node));
        newnode->next=NULL;
        memcpy(newnode,&stu,sizeof(student));
        if(head==NULL)//ͷ�巨
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
    printf("�������ݳɹ�!\n");
}
void sortstudent()
{
    Node*p=(Node*)malloc(sizeof(Node));
    Node*q=(Node*)malloc(sizeof(Node));
    if(head==NULL)
    {
        printf("��ǰ������!\n");
        return;
    }
    printf("\t\t\t\t*****************************************\n");
    printf("\t\t\t\t*\t      ��ѡ������ʽ\t\t*\n");
    printf("\t\t\t\t*****************************************\n");
    printf("\t\t\t\t*\t    1. ���ĳɼ�����\t\t*\n");
    printf("\t\t\t\t*\t    2. ��ѧ�ɼ�����\t\t*\n");
    printf("\t\t\t\t*\t    3. Ӣ��ɼ�����\t\t*\n");
    printf("\t\t\t\t*\t    4. ѧ������    \t\t*\n");
    printf("\t\t\t\t*\t    5. �ܷ�����    \t\t*\n");
    printf("\t\t\t\t*****************************************\n");
    int choice=0;
    printf("���������ѡ��:\n");
    scanf("%d",&choice);
    for(p=head;p!=NULL;p=p->next)
    {
        for(q=p->next;q!=NULL;q=q->next)
        {
            switch (choice)
            {
                case 1://���ĳɼ�����
                if(p->stu.chinese<q->stu.chinese)
                {
                    Node*x=(Node*)malloc(sizeof(Node));
                    x->stu=p->stu;
                    p->stu=q->stu;
                    q->stu=x->stu;
                    free(x);
                }
                break;

                case 2://��ѧ�ɼ�����
                if(p->stu.maths<q->stu.maths)
                {
                    Node*x=(Node*)malloc(sizeof(Node));
                    x->stu=p->stu;
                    p->stu=q->stu;
                    q->stu=x->stu;
                    free(x);
                }
                break;

                case 3://Ӣ��ɼ�����
                if(p->stu.english<q->stu.english)
                {
                    Node*x=(Node*)malloc(sizeof(Node));
                    x->stu=p->stu;
                    p->stu=q->stu;
                    q->stu=x->stu;
                    free(x);
                }
                break;

                case 4://ѧ������
                if(p->stu.num>q->stu.num)
                {
                    Node*x=(Node*)malloc(sizeof(Node));
                    x->stu=p->stu;
                    p->stu=q->stu;
                    q->stu=x->stu;
                    free(x);
                }
                break;

                case 5://�ܷ�����
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
                printf("�����������������:");
                break;
            }
        }
    }
    printf("�������!\n");
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
            case 1://¼��ѧ����Ϣ
            inputstudent();
            break;

            case 2://��ӡѧ����Ϣ
            printstudent();
            break;

            case 3://ͳ��ѧ������
            printf("ѧ��������Ϊ:%d\n",countstudent());
            system("pause");
            system("cls");
            break;

            case 4://����ѧ����Ϣ
            findstudent();
            system("pause");
            system("cls");
            break;

            case 5://�޸�ѧ����Ϣ    
            modifystudent();                                                                                                                                                                                                                 
            break;

            case 6://ɾ��ѧ����Ϣ
            deletestudent();
            system("pause");
            system("cls");
            break;

            case 7://����ѧ����Ϣ
            savestudent();
            system("pause");
            system("cls");
            break;

            case 8://��ȡѧ����Ϣ
            readstudent();
            system("pause");
            system("cls");
            break;

            case 9://����ѧ����Ϣ
            sortstudent();
            system("pause");
            system("cls");
            break;

            case 0://�˳�ϵͳ
            printf("ллʹ��\n");
            return 0;
            break;

            default:
            printf("�����������������:\n");
            system("pause");
            system("cls");
            break;
        }
        getchar();
    }
    
    return 0;
}