/*�����ǵݼ�������������������������*/
#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef struct LinkNode{
	int data;
	struct LinkNode* next;
}LNode,*LinkList;

void Init(LinkList &L){
	L = (LNode*)malloc(sizeof(LNode));
	if(!L) exit(ERROR);
	L->next = NULL;
}

Status Create(LinkList &L){ //�����ǵݼ���������
	int n,num;
	LNode *p;
	LNode *f;
	LNode *newNode;
	printf("�����뵥������:");
	scanf("%d",&n);
	printf("�����뵥�����ֵ:");
	for(int i = 0;i < n;i++){
		scanf("%d",&num);
		f = L;
		p = f->next;
		while(p && p->data < num){
			f = p;
			p = p->next;
		}
		newNode = (LNode*)malloc(sizeof(LNode));
		newNode->data = num;
		newNode->next = p;
		f->next = newNode;
	}
	return OK;
}

Status Destroy(LinkList &L){
	LNode *p = L;
	LNode *q;
	while(p){
		q = p->next;
		free(p);
		p = q;
	}
	return OK;
}

void Display(LinkList L){
	LNode* p = L->next;
	int i = 1;
	printf("����ֵΪ:\n"); 
	while(p){
		printf("[%d:%d]   ",i,p->data);
		i++;
		p = p->next;
	}
}

int Sum(LinkList L){
	int res = 0;
	LNode *p = L->next;
	while(p){
		res += p->data;
		p = p->next;
	}
	return res;
}

int main()
{
	LinkList L;
	int sum;
	Init(L);
	Create(L);
	Display(L);
	printf("\n");
	sum = Sum(L);
	printf("����ĺ�Ϊ��%d\n",sum);
	Display(L);
	printf("\n");
	Destroy(L);
	return 0;
}

/*
ʾ�����룺
	5
	8 9 7 6 4
ʾ�����:
	����ֵΪ:
	[1:4]   [2:6]   [3:7]   [4:8]   [5:9]
	����ĺ�Ϊ��34
	����ֵΪ:
	[1:4]   [2:6]   [3:7]   [4:8]   [5:9]
 */