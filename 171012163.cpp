/*�ó�����ջ�Ͷ����жϻ���*/

#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define True 1
#define False 0

typedef char SElemType;
typedef char QElemType;

typedef int Status;

/*
 *���ж���
 */
typedef struct ListNode
{
    QElemType data;
    struct ListNode* next;
}ListNode,*ListLink;

typedef struct ListQueue
{
    ListLink head;  //��ͷ
    ListLink tail;  //��β
    int len;
}ListQueue;

Status Init_Queue(ListQueue& Q){  //��ʼ������
    Q.head=Q.tail=(ListLink)malloc(sizeof(ListNode));
    Q.tail->next=NULL;
    Q.len=0;
    return OK;
}

Status Del_Queue(ListQueue& Q){ //���ٶ���
    ListLink tmp=Q.head;
    while(tmp!=NULL){
        Q.head=tmp->next;
        tmp=Q.head;
    }
    Q.head=Q.tail=NULL;
    return OK;
}

Status EnQueue(ListQueue& Q,QElemType item){ //���
    ListNode* newNode = (ListLink)malloc(sizeof(QElemType));
    newNode->data = item;
    newNode->next = NULL;
    Q.tail->next=newNode;
    Q.tail=newNode;
    Q.len++;
    return OK;
}

Status DeQueue(ListQueue& Q){ //�޷�������ֵ
    ListNode *tmp=Q.head->next;
    Q.head=tmp->next;
    free(tmp);
    Q.len--;
    return OK;
}

Status DeQueue(ListQueue& Q,QElemType& item){ //�з�������ֵ
    if(Q.head == Q.tail) return ERROR;
    ListNode *tmp=Q.head->next;
    item=tmp->data;
    Q.head->next = tmp->next;
    if(Q.tail == tmp) Q.head = Q.tail;
    Q.len--;
    return OK;
}

QElemType GetQueue(ListQueue Q){
    if(Q.head != Q.tail)
        return Q.head->next->data;
    return ERROR;
}

int Empty(ListQueue Q){ //�ж϶����Ƿ�Ϊ�գ�Ϊ�շ���1
    return !Q.len;    
}

/*
 *��ջ����
 */
typedef struct Lnode
{
    SElemType data; //������
    struct Lnode *next; //ָ����һ��Ԫ��
} Lnode, *LStack;

Status Init_Stack(LStack &S){  //��ʼ��ջ
    S = NULL;
    return OK;
}

Status Del_Stack(LStack &S){   //����ջ
    Lnode* p=S;
	while(p){
		S = S->next;
		free(p);
		p = S;
	}
	return OK;
}

Status Push(LStack &S, SElemType e){  //��ջ
    Lnode* tmp = (LStack)malloc(sizeof(Lnode)); //���ٽڵ�
    if(tmp == NULL) exit(ERROR); 
    tmp->data = e;  //�����븳ֵ
    tmp->next = S;
    S = tmp; 
    return OK;
}

Status Pop(LStack &S,SElemType& e){  //���ص���ֵ
    if (S == NULL)
        return ERROR;
    Lnode* tmp;
    tmp = S->next;
    e = S->data;
    free(S);
    S = tmp;
    return OK;
}

int Empty(LStack S){ //�ǿշ���0���շ���1
    if(S == NULL)
        return OK;
    return ERROR;
}

/*
 *�ж��ַ����Ƿ��ǻ���(�ö�ջ�Ͷ���ʵ��)������Ƿ���1�����򷵻�0
 *
 * ����˵��:
 *      c---�ַ������׵�ַ
 *      len---�ַ�������
 * 
 */
int Judge(char *c,int len){
    if(c == NULL || len == 1) return 1;
    LStack S;
    ListQueue Q;
    char cQ,cS;
    int flag=1;
    Init_Stack(S);
    Init_Queue(Q);
    for(int i=0;i<len;i++){
        EnQueue(Q,c[i]);
        Push(S,c[i]);
    }
    while (!Empty(S)&&flag)
    {
        Pop(S,cS);
        DeQueue(Q,cQ);
        if( cS != cQ )
            flag = 0;
    }
    Del_Queue(Q);
    Del_Stack(S);
    return flag;
}

int main()
{
    char c[100];
    char tmp;
    int len = 0;
    printf("����Ҫ�жϵ��ַ���(����'#'ֹͣ���룬�ַ�����󳤶�100):\n");
    scanf("%c",&tmp);
    while(tmp!='#'){
        c[len] = tmp;
        len++;
        scanf("%c",&tmp);
    }
    if(Judge(c,len))
        printf("���ַ����ǻ��ģ�\n");
    else printf("���ַ������ǻ��ģ�\n");
    printf("\n");
    return 0;
}

/*
ʾ�����룺
    abcdefgfedcba#
ʾ�������
    ���ַ����ǻ��ģ�

*/
