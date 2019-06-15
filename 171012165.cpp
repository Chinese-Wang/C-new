#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define OK 1
#define ERROR 0

typedef struct BitTree{  //���ڵ�
    char data;
    struct BitTree* left;
    struct BitTree* right;
}BitNode,*BiTree;

typedef struct Queu{ //���нڵ�
    BitNode* data;
    struct Queu* next;
}QNode,*Queue;

typedef struct{
    Queue front;
    Queue rear;
}LinkQueue;

typedef int Status;

Status Init(LinkQueue& Q){ //��ʼ������
    Q.front = (QNode*)malloc(sizeof(QNode));
    if(!Q.front) exit(ERROR);
    Q.front->next = NULL;
    Q.rear = Q.front;
    return OK;
}

Status EnQueue(LinkQueue& Q,BitNode* data){ //����
    QNode* newNode;
    newNode = (QNode*)malloc(sizeof(QNode));
    if(!newNode) exit(ERROR);
    newNode->data = data;
    newNode->next = Q.rear->next;
    Q.rear->next = newNode;
    Q.rear = newNode; 
    return OK;
}

Status DeQueue(LinkQueue &Q,BiTree &data){ //����
    Queue p;
    if(Q.rear == Q.front) return ERROR;
    p = Q.front->next;
    data = p->data;
    Q.front->next = p->next;
    if(Q.rear == p) Q.rear = Q.front;
    free(p);
    return OK;
}

Status DestroyQueue(LinkQueue& Q){
    BiTree data;
    while(Q.front != Q.rear){
        DeQueue(Q, data);
    }
    free(Q.front);
    return OK;  
}

/*Status CreateBiTree(BiTree &T){ //���򴴽�������
    char elem;
    printf("���������ݣ�");
    scanf("%c",&elem);
    if(elem == '#') T = NULL;
    else{
        T = (BitNode*)malloc(sizeof(BitNode));
        T->data = elem;
        CreateBiTree(T->left);
        CreateBiTree(T->right);
    }
    return OK;
}
*/
Status CreateBiTree(BiTree &T){ //���򴴽�������
    LinkQueue Q;
    BitNode* p;
    char elem;
    int i = 0; //�ж��������ӻ����Һ���
    Init(Q);
    printf("���������������Ԫ��(@����ýڵ�Ϊ�գ�#��������):");
    scanf("%c",&elem);
    T = (BitNode*)malloc(sizeof(BitNode));
    T->data = elem;
    EnQueue(Q, T);
    EnQueue(Q, T);
    scanf("%c",&elem);
    while( elem != '#'){
        DeQueue(Q,p);
        if(elem != '@'){
            if(i == 0){
                p->left = (BitNode*)malloc(sizeof(BitNode));
                p = p->left;
            }
            else{
                p->right = (BitNode*)malloc(sizeof(BitNode));
                p = p->right;
            }
            p->data = elem;
            EnQueue(Q, p);
            EnQueue(Q, p);
        }
        else
        {
            if(i == 0) p->left = NULL;
            else p->right = NULL;
        }
        i = (i+1)%2;
        scanf("%c",&elem);
    }
    while (Q.rear != Q.front)
    {
        DeQueue(Q, p);
        if(i == 0) p->left = NULL;
        else p->right = NULL;
        i = (i+1)%2;
    }
    return OK;
}

Status DestroyBiTree(BiTree &T){
    if(T == NULL) return OK;
    DestroyBiTree(T->left);
    DestroyBiTree(T->right);
    free(T);
    T = NULL;
    return OK;
}

void CopyBiTree(BiTree T,BiTree &C){
    if(T == NULL) {
        C = NULL;
        return;
    }
    C = (BitNode*)malloc(sizeof(BitNode));
    C->data = T->data;
    CopyBiTree(T->left,C->left);
    CopyBiTree(T->right,C->right);
}

int Count(BiTree T){
    if(T == NULL) return 0;
    return Count(T->left) + Count(T->right) + 1;
}

int Depth(BiTree &T)
{ //���������
    if (T == NULL)
        return 0;
    else
    {
        int m = Depth(T->left);
        int n = Depth(T->right);
        if (m > n)
            return (m + 1);
        else
            return (n + 1);
    }
}

void Display(BiTree T){  //�������������ӡ������
    int row = Depth(T);
    LinkQueue Q;
    BitNode* p = T;
    Init(Q);
    EnQueue(Q,p);
    printf("�����Ƕ����������������@���Ŵ����λ��Ϊ��:\n");
    for(int i = 0;i<row;i++){
        printf("  ");
        for(int j = 0;j < pow(2,i);j++){
            for(int k = 0;k < pow(2, row - i - 1) ;k++)
                printf(" ");
            DeQueue(Q, p);
            if(p){ 
                printf("%c",p->data);
                if(p->left) EnQueue(Q,p->left);
                else EnQueue(Q,NULL);
                if(p->right) EnQueue(Q, p->right);
                else EnQueue(Q, NULL);
            }
            else{
                printf("@");
                EnQueue(Q,NULL);
                EnQueue(Q, NULL);
            }
            for(int k = 0;k < (pow(2, row - i - 1)-1) ;k++)
                printf(" ");
        }
        printf("\n");
    }
    DestroyQueue(Q);
}

int main()
{
    BiTree T;
    BiTree T1;
    int count;
    CreateBiTree(T);
    Display(T);
    CopyBiTree(T,T1);
    printf("���ƵĶ�����Ϊ:\n");
    Display(T1);
    count = Count(T1);
    printf("�����ڵ���Ϊ��%d\n",count);
    DestroyBiTree(T1);
    DestroyBiTree(T);
    return 0;
}

/*
ʾ�����룺
    ABCD@EF@G@H#
ʾ�������
�����Ƕ����������������@���Ŵ����λ��Ϊ��:
          A
      B       C
    D   @   E   F
   @ G @ @ @ H @ @
���ƵĶ�����Ϊ:
�����Ƕ����������������@���Ŵ����λ��Ϊ��:
          A
      B       C
    D   @   E   F
   @ G @ @ @ H @ @
�����ڵ���Ϊ��8
 */