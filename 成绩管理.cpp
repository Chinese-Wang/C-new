#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define False 0
#define True 1
#define OVERFLOW -1
#define MAXSIZE 100
#define ADD 10

typedef struct
{
    int grade;
    char name[10];
    float credit;
    float score;
    float grade_point;
} ElemType;

typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} Sqlist;

typedef int Status;

void InitList(Sqlist &L) //����˳���
{
    L.elem = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE); //Ϊ˳������ռ�
    if (! L.elem)
        exit(ERROR);
    L.listsize = MAXSIZE;
    L.length=0;
}

void DestoryList(Sqlist &L) //�������Ա�
{
    free(L.elem);
    L.elem = NULL;
}

Status ListInsert(Sqlist &L, int i, ElemType e) //��iλ�ò���Ԫ��
{
    ElemType *newdata;
    if ((i < 1) || i > L.length)
    {
        return ERROR;
    }
    if (L.length >= L.listsize)
    {
        newdata = (ElemType *)realloc(L.elem, (L.listsize + ADD) * sizeof(ElemType));
        if (!newdata)
            exit(OVERFLOW);
        L.elem = newdata;
        L.listsize += ADD;
    }
    for (int j = L.length - 1; j > i - 1; j--)
    {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e;
    ++L.length;
    return OK;
}

Status ListDelete(Sqlist &L, int i, ElemType &e) //ɾ��˳�����λ��Ϊi��Ԫ��
{
    if ((i < 1) || (i > L.length))
    {
        return ERROR;
    }
    e = L.elem[i - 1];
    for (int j = i; j <= L.length - 1; j++)
    {
        L.elem[j - 1] = L.elem[j];
    }
    --L.length;
    return OK;
}

Status ClearList(Sqlist &L) //������Ա�
{
    delete [] L.elem;
    L.elem = (ElemType*)malloc(L.listsize*sizeof(ElemType));
    L.length = 0;
    return OK;
}

Status ListEmpty(Sqlist L) //��ѯ�б��Ƿ�Ϊ��
{
    return L.length;
}

void Initial_entry(Sqlist& L)  //¼���ʼ����
{
    printf("�������ʼ���ݳ��ȣ�");
    scanf("%d", &L.length);
    if (L.length>L.listsize) {
        ElemType* newbase=(ElemType*)realloc(L.elem,sizeof(ElemType)*L.length);
        L.elem=newbase;
    }

    printf("�������ʼ�ɼ�(ʾ����ѧ�� �γ��� ѧ�� �ɼ� ����)��\n");
    for (int i = 0; i < L.length; i++)
    {
        scanf("%d %s %f %f %f", L.elem[i].grade, L.elem[i].name, L.elem[i].credit, L.elem[i].score, L.elem[i].grade_point);
    }
    printf("¼��ɹ�");
}

void read(Sqlist& L)    //��ȡ�ļ�
{
    FILE *fp;
    int i=0;
    if((fp=fopen("myscore.dat","r"))==NULL)
    {
        printf("cannot open file\n");
        exit(ERROR);
    }
    while(!feof(fp)) //feof()�ж��ļ��Ƿ��˽�β���������ط���ֵ������������0
    {
        //fread(L.elem[i],sizeof(ElemType),1,fp);
        L.length++;
        i++;
    }
}

void save(Sqlist L)    //������д���ļ�
{
    FILE *fp;
    int i=0;
    fp=fopen("my_score.dat","wb");
    if (fp==NULL) {
        printf("���ļ�ʧ�ܣ�\n");
        exit(ERROR);
    }
    for( i = 0; i < L.length; i++)
    {
        //fwrite(L.elem[i],sizeof(ElemType),1,fp);
    }
    fclose(fp);
}

void List_Display(Sqlist L) //��ʾ˳���ȫ��Ԫ��
{
    printf("ѧ��       �γ���       ѧ��     �ɼ�      ����");
    for (int i = 0; i < L.length; i++)
    {
        printf("*********************************\n");
        printf("%d    %s      %f       %f      %f\n",L.elem[i].grade,L.elem[i].name,L.elem[i].credit,L.elem[i].score,L.elem[i].grade_point);
    }
    printf("\n");
}

void menu() //�˵�
{
    printf("******************************\n");
    printf("*********���˳ɼ�����**********\n");
    printf("******************************\n");
    printf("*     1����ʾ���˳ɼ�         *\n");
    printf("*     2������ѧ�ڼ���         *\n");
    printf("*     3������ĳ�Ƴɼ�         *\n");
    printf("*     4��ɾ��ĳ�Ƴɼ�         *\n");
    printf("*     5����ճɼ���           *\n");
    printf("*     6���˳�ϵͳ             *\n");
    printf("******************************\n");
}
int main()
{
    char res;
    Sqlist list;
    InitList(list);
    for(int i=0;i<3;i++)
        Initial_entry(list);
    
    List_Display(list);
    DestoryList(list);
    return 0;
}

