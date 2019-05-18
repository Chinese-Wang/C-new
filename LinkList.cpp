//* * * * * * * * * * * * * * * * * * * * *
// ��  �� : ��2�� ���Ա�                  *
// ������ : ������  (���հ�ʽ 2002.9.28)  *
// ��  �� : ����,ɾ��,����,��ʾ           *
//* * * * * * * * * * * * * * * * * * * * *

#include <stdio.h>
#include <stdlib.h>
//#include <dos.h>
#include <conio.h>

#define TRUE       1
#define FALSE      0
#define OK         1
#define ERROR      0
#define INFEASIBLE -1
#define OVERFLOW   -2

//Status �Ǻ���������,��ֵ�Ǻ������״̬����
typedef int Status;
//ElemType �ǵ���������Ԫ������,�˳�����Ϊint��
typedef int ElemType;

//---���Ա�ĵ�����洢�ṹ---
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList; 

void CreateList_L(LinkList &L){
	//��������ͷ���ĵ�����L,����λ�������Ԫ�ص�ֵ
	int i,n;
	LinkList p;
	L=(LinkList) malloc (sizeof (LNode));
	L->next=NULL; //�Ƚ���һ����ͷ���ĵ�����
	
	
	printf("�������ʼʱ������:"); //�������ɵ�����ʱ��Ԫ�ظ���
	scanf("%d",&n);
	printf("������λ���%d��1�ĸ�Ԫ��(����)������:2 4 5 6 7 ...\n",n);
	for (i=n; i>0; --i){
		p=(LinkList) malloc (sizeof (LNode)); //�����½��
		scanf("%d",&p->data);
		p->next=L->next; L->next=p; //���뵽��ͷ
	}
}//CreateList_L 

void FreeList_L(LinkList &L){
	//���ٴ���ͷ���ĵ������Ա�L
	LinkList p;
	while(L->next){
		p=L->next; //pָ���һ�����
		L->next=p->next;//��ͷ����ָ����ָ��ڶ������
		free(p);
	}
	free(L);  //�ͷű�ͷ�����ռ�Ŀռ�
}//FreeList_L

Status ListInsert_L(LinkList &L, int i, ElemType e){
	//�ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
	LinkList p=L , s;
	int j=0;
	while (p && j<i-1) {p=p->next; ++j;} //Ѱ�ҵ�i-1�����
	if (!p || j>i-1) return ERROR; //iС��1���ߴ��ڱ�
	s=(LinkList) malloc (sizeof (LNode)); //�����½��
	s->data=e; s->next=p->next; //����L��
	p->next=s;
	return OK;
}//ListInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e){
	//�ڴ�ͷ���ĵ������Ա�L��,ɾ����i��Ԫ�أ�����e������ֵ
	LinkList p=L , q;
	int j=0;
	while (p->next && j<i-1){ //Ѱ�ҵ�i����㣬����pָ����ǰ��
		p=p->next; ++j;
	}
	if (!(p->next) || j>i-1) return ERROR; //ɾ��λ�ò�����
	q=p->next; p->next=q->next; //ɾ�����ͷŽ��
	e=q->data; free(q);
	return OK;
}//ListDelete_L

void ListDisplay_L(LinkList L){
	//��ʾ��������Ԫ��
	LinkList p=L->next;
	int i=1;
	printf("��������Ԫ��:");
	while(p)
    {printf("[%d:%d]",i,p->data);++i;p=p->next;}
	printf("\n");
}//ListDisplay_L

int ListFind_Keyword_L(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType)){
	//�ڵ������в��ҹؼ���Ϊe��Ԫ�أ��ɹ����ظ�Ԫ�ص�λ��
	//ʧ�ܷ���0
	int i;
	LinkList p;
	p=L->next; i=1;
	while(!(*compare)(p->data,e)&&(p->next!=NULL))
    {p=p->next;  i++;}//pָ��ָ����һ����ֱ���ҵ�������βΪֹ
	if(!(*compare)(p->data,e)) return 0;//��Ԫ���������в�����
	return i;
}//ListFind_Keyword_L

Status ListFind_Order_L(LinkList L,int i,ElemType &e){
	//�ڵ������в��ҵ�i��Ԫ�أ��ɹ�����True������e���ظ�Ԫ��ֵ��
	//ʧ�ܷ���False
	LinkList p;
	int j;
	p=L->next; j=1;
	while(p->next&&j<i)  //�ƶ�ָ�룬ֱ���ҵ���i��Ԫ��
    {p=p->next;++j;}
	if(!p||j>i) return ERROR; //��i��Ԫ�ز�����
	e=p->data;       //���ҳɹ�����eȡ�ø�Ԫ��ֵ
	return OK;
}//ListFind_Order_L

Status equal(ElemType x,ElemType y){
	return x==y;
}//equal

int main(){
	LinkList L;
	Status temp;
	int i,num,ch,e,flag=1;
	//clrscr();
	//---------------------����˵��-----------------------
	printf("������ʵ����ʽ�ṹ�����Ա�Ĳ�����\n");
	printf("���Խ��в��룬ɾ������λ�����ҵȲ�����\n");
	//----------------------------------------------------
	
	CreateList_L(L);//���ɵ�����
	ListDisplay_L(L);
	while(flag){
		printf("��ѡ��:\n");
		printf("1.��ʾ����Ԫ��\n");  //��ʾ����Ԫ��
		printf("2.����һ��Ԫ��\n");  //��������Ԫ��
		printf("3.ɾ��һ��Ԫ��\n");  //ɾ������Ԫ��
		printf("4.���ؼ��ֲ���Ԫ��\n");  //���ؼ��ֲ���
		printf("5.����Ų���Ԫ��\n"); //����Ų���
		printf("6.�˳�����      \n");  //�˳�
		scanf("%d",&ch);
		switch(ch){
		case 1:
			ListDisplay_L(L); //��ʾ����Ԫ��
			break;
		case 2:
			printf("������Ҫ����Ԫ�ص�λ�ú���ֵ:\n");
			printf("��ʽ��λ��,��ֵ������:2,68\n");
			scanf("%d,%d",&i,&e);  //����Ҫ�����Ԫ�غͲ����λ��
			temp=ListInsert_L(L,i,e);     //����
			if(temp==ERROR) printf("����ʧ��!\n");  //����ʧ��
			else {printf("����ɹ�!\n");ListDisplay_L(L);} //����ɹ�
			break;
		case 3:
			printf("������Ҫɾ��Ԫ�ص�λ��:");
			scanf("%d",&i);    //����Ҫɾ����Ԫ�ص�λ��
			temp=ListDelete_L(L,i,e);  //ɾ��
			if(temp==OK) printf("ɾ����һ��Ԫ��:%d\n",e); //ɾ���ɹ�
			else printf("��Ԫ�ز�����!\n");  //ɾ��ʧ��
			ListDisplay_L(L);
			break;
		case 4:
			printf("������Ҫ���ҵ�Ԫ�ص�ֵ:");
			scanf("%d",&e);      //����Ҫ���ҵ�Ԫ��
			i=ListFind_Keyword_L(L,e,equal);      //��λ
			if(i) printf("��Ԫ������λ��:%d\n",i); //��ʾ��Ԫ��λ��
			else printf("%d������!\n",e);//��ǰԪ�ز�����
			break;
		case 5:
			printf("������Ҫ���ҵ�Ԫ�ص�λ��:");
			scanf("%d",&i);      //����Ҫ���ҵ�Ԫ��
			temp=ListFind_Order_L(L,i,e);      //��λ
			if(temp==OK) printf("��%d��Ԫ��:%d\n",i,e); //��ʾ��Ԫ����ֵ
			else printf("��%d��Ԫ�ز�����!\n",i);//��ǰԪ�ز�����
			break;
		case 6:
			flag=0;
			printf("�����������������˳�!\n");
			getch();
			
		}
    }
	FreeList_L(L);//���ٵ�����
	return 0;
}
