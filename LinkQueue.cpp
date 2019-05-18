//* * * * * * * * * * * * * * * * * * *
// ��  �� : ��3�� ջ�Ͷ���            *
// ������ : ��ʽ����                  *
// ��  �� : ��ʼ��,�����,������      *
//* * * * * * * * * * * * * * * * * * *
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define TRUE       1
#define FALSE      0
#define OK         1
#define ERROR      0
#define INFEASIBLE -1
#define OVERFLOW   -2

//Status �Ǻ���������,��ֵ�Ǻ������״̬����
typedef int Status;
//ElemType ��˳�������Ԫ������,�˳�����Ϊint��
typedef int QElemType;

//-----��������--���е���ʽ�洢�ṹ-----
typedef struct QNode{       //������ṹ
	QElemType     data;     //������
	struct QNode *next;     //ָ����
}QNode,*QueuePtr;
typedef struct linkqueue{  //������нṹ
	QueuePtr front;        //��ͷָ��
	QueuePtr rear;         //��βָ��
}LinkQueue;

Status InitLinkQueue(LinkQueue &);          //��ʼ��һ������
Status DestroyLinkQueue(LinkQueue &);       //����һ������
int LinkQueueLength(LinkQueue &Q);          //���еĳ���
Status EnLinkQueue(LinkQueue &,QElemType);  //��һ��Ԫ�������
Status DeLinkQueue(LinkQueue &,QElemType &);//��һ��Ԫ�س�����
Status DisplayLinkQueue(LinkQueue);         //��ʾ����������Ԫ��

void main(){
	LinkQueue LQ;
	QElemType e;
	int flag=1,ch,len;
	Status temp;
	//---------------------�����˵-----------------------
	printf("������ʵ����ʽ�ṹ���еĲ�����\n");
	printf("���Խ�������С������еȲ�����\n");
	//----------------------------------------------------
	InitLinkQueue(LQ);       //��ʼ������
	while(flag){
		printf("��ѡ��:\n");
		printf("1.��ʾ��������Ԫ��\n");
		printf("2.�����\n");
		printf("3.������\n");
		printf("4.����еĳ���\n");
		printf("5.�˳�����\n");
		scanf("%d",&ch);
		switch(ch){
		case 1:DisplayLinkQueue(LQ);   //��ʾ����������Ԫ��
			break;
		case 2:printf("������Ҫ�˶ӵ�Ԫ��(һ������):");
			scanf("%d",&e);   //����Ҫ����е��ַ�
			EnLinkQueue(LQ,e);//�����
			DisplayLinkQueue(LQ);
			break;
		case 3:temp=DeLinkQueue(LQ,e);  //������
			if(temp==OK){
				printf("����һ��Ԫ��:%d\n",e);
				DisplayLinkQueue(LQ);
			}
			else printf("����Ϊ��!\n");
			break;
		case 4:len=LinkQueueLength(LQ);
			printf("���еĳ���Ϊ:%d\n",len);
			break;
		default:flag=0;
			printf("�������н�������������˳�!\n");
			getch();
		}
	}
}

Status InitLinkQueue(LinkQueue &Q){//���г�ʼ��
	Q.front=Q.rear=(QueuePtr) malloc(sizeof(QNode)); //����һ��ͷ��㣬������βָ��ָ��ͷ���
	Q.front->next=NULL;
	return OK;
}
Status DestroyLinkQueue(LinkQueue &Q){//����һ������
	QueuePtr p;
	QElemType e;
	while(Q.front!=Q.rear)
		DeLinkQueue(Q,e);
	free(Q.front);
	Q.front=Q.rear=NULL;
	return OK;
}

int LinkQueueLength(LinkQueue &Q){//���еĳ���
	int i=0;
	QueuePtr p=Q.front;
	while(p!=Q.rear){
		++i;
		p=p->next;
	}
	return i;
}

Status EnLinkQueue(LinkQueue &Q,QElemType e){//�����
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));//����һ���½��
	p->data=e;                      //��ֵ
	p->next=NULL;
	Q.rear->next=p;                 //����������β
	Q.rear=p;                       //�޸Ķ�βָ��
	return OK;
}

Status DeLinkQueue(LinkQueue &Q,QElemType &e){//������
	QueuePtr p;
	if(Q.front==Q.rear) return ERROR;     //�ж϶����Ƿ��ѿգ��ѿշ���ERROR
	p=Q.front->next;                      //pָ������е�һ��Ԫ��
	e=p->data;                            //ȡ�ø�Ԫ��ֵ
	Q.front->next=p->next;                //�޸Ķ���ָ��
	if(Q.rear==p) Q.rear=Q.front;         //�������ѿգ��Ѷ�βָ��ָ��ͷ���
	free(p);
	return OK;                            //�ɹ������У�����OK
}

Status DisplayLinkQueue(LinkQueue Q){//��ʾ����������Ԫ��
	QueuePtr p;
	int i=0;
	p=Q.front->next;
	if(p==NULL) printf("����Ϊ��!\n");//����Ϊ��
	else{
		while(p){       //������ʾ����������Ԫ��
			printf("[%d:%d]",++i,p->data);
			p=p->next;
		}
		printf("\n");
	}
	return OK;
}
