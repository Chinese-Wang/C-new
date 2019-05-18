#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define True 1
#define False 0

typedef int Status;

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

Status Display_Queue(ListQueue Q){
    if(Q.len == 0) return ERROR;
    ListLink tmp=Q.head->next;
    int i=0;
    while(tmp!=Q.tail){
        printf("[%d,%d]\n",i++,tmp->data);
        tmp=tmp->next;
    }
    return OK;
}