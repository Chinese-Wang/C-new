#include<iostream>
#include<stdlib.h> 
using namespace std;

typedef struct node{
	int data;   
	struct node* next; 
}*LinkList,Lnode;

int len=sizeof(Lnode);  //����ĳ��� 
 
void Init(LinkList &L){ //��ʼ������ 
	L=(LinkList)malloc(len); 
	if(L==NULL) exit(0); 
	L->data=0;
	L->next=NULL; 
}

void Insert_f(LinkList &L,int item){  //ͷ�巨 
	Lnode *p=L->next;
	Lnode *tmp=(Lnode*)malloc(len);
	if(tmp==NULL) exit(0);
	tmp->data=item;
	tmp->next=p;
	L->next=tmp;
	L->data++; 
} 
void Insert_l(LinkList &L,int item){ //β�巨 
	Lnode* p=L;
	while(p->next){
		p=p->next; 
	}
	Lnode *q=(LinkList)malloc(len);
	if(q==NULL) exit(0); 
	q->data=item;
	p->next=q;
	q->next=NULL;
	L->data++;  //ͷ����������ʾ������ 
} 

int Insert_p(LinkList &L,int n,int item){  //����λ�ò���,n��ʾ����ĵط���item�����ֵ 
	int i=0;
	if(i<0||(i>L->data+1)){
		cout<<"λ�ô���"<<endl;
		return 0; 
	} 
	Lnode *p=L;
	while(p&&(i<n-1)){
		p=p->next;
		i++;
	}
	if(!p||i>n-1) return 0;
	Lnode *tmp=(LinkList)malloc(len);
	tmp->next=p->next;
	p->next=tmp;
	tmp->data=item;
	L->data++; 
	return 1;
} 

void del(LinkList &L){ //�������� 
	Lnode* p=L->next;
	Lnode *q; 
	while(p){
		q=p->next;
		free(p);
		p=q; 
	}
	free(L);
	L=NULL; 
} 

void display(LinkList &L){ //����������� 
	Lnode* p=L->next;
	while(p){
		cout<<p->data<<endl;
		p=p->next; 
	} 
} 
int main()
{
	LinkList L;
	Init(L);
	int n;
	int i; 
	int num; 
	cout<<" ����˳���Ԫ�ظ���:";
	cin>>n;
	cout<<"��������(�س�ȷ��):"; 
	for(int i=0;i<n;i++){
		cin>>num;
		Insert_f(L,num); 
	}
	display(L);
	cout<<endl<<endl; 	
	cout<<L->data<<endl; 
	cout<<"�������ڲ����λ�úͲ����ֵ:";
	cin>>i>>num; 
	Insert_p(L,i,num);
	display(L);
	cout<<endl;
	cout<<L->data<<endl; 
	del(L); 
	return 0; 
} 
