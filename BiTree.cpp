#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <conio.h>

#define TRUE       1
#define FALSE      0
#define OK         1
#define ERROR      0
#define INFEASIBLE -1
#define OVERFLOW   -2

//Status �Ǻ���������,��ֵ�Ǻ������״̬����
typedef int Status;
//TElemType �Ƕ���������Ԫ������,�˳�����Ϊchar��
typedef char TElemType;

//-----�������Ķ�������洢��ʾ-----
typedef struct  BiTNode{      //������������ṹ
  TElemType  data;                //������
  struct BiTNode *lchild,*rchild; //���Һ���ָ����
}BiTNode,*BiTree;

Status CreateBiTree(BiTree &T);//����һ��������(�������ַ�������)
Status CreateBiTreeInPreOrderResult(BiTree &T);//����һ��������(��������������)
Status CreateBiTreeInBracket(BiTree &T);//����һ��������(Ƕ�����ŷ�����)
Status PrintElement(BiTree t);
Status PreOrderTraverse(BiTree T,Status (*Visit)(BiTree t)); //����ݹ����������
Status InOrderTraverse(BiTree T,Status (*Visit)(BiTree t));  //����ݹ����������
Status PostOrderTraverse(BiTree T,Status (*Visit)(BiTree t));//����ݹ����������

char * pstr;

Status CreateBiTree(BiTree &T){//����һ��������(�������ַ�������)
  int i,len,choice=0;
  char str[200];
  printf("��ѡ�����������ķ���:\n");
  printf("1.����������Ľ�����������\n");
  printf("2.��Ƕ�����ű�ʾ�����������\n");
  do{
    gets(str);
    choice = atoi(str);
  }while(choice<1||choice>2);
  if(choice==1){
    printf("��������������������Ľ��,����ݴ˽�����������\n");
    printf("����Ҷ�ӽ���Կո��ʾ��\n");
    printf("����:abc__de_g__f___(�س�)���������¶�������\n");
    printf("           a      \n");
    printf("          /       \n");
    printf("         b        \n");
    printf("        / \\       \n");
    printf("       c   d      \n");
    printf("          / \\     \n");
    printf("         e   f    \n");
    printf("          \\       \n");
    printf("           g      \n");
    pstr=gets(str);
    len=strlen(str);
    for(i=len;i<180;++i)
      str[i]=' ';
    str[i]=0;
    CreateBiTreeInPreOrderResult(T);//��ʼ��������
  }
  else{
    printf("������Ƕ�����ű�ʾ����ʾ�Ķ�����,����ݴ˽�����������\n");
    printf("����:(a(b(c,d(e(,g),f))))(�س�)���������¶�������\n");
    printf("           a      \n");
    printf("          /       \n");
    printf("         b        \n");
    printf("        / \\       \n");  //ǰһ��\Ϊת���ַ�
    printf("       c   d      \n");
    printf("          / \\     \n");
    printf("         e   f    \n");
    printf("          \\       \n");
    printf("           g      \n");
    pstr=gets(str);
    CreateBiTreeInBracket(T);       //��ʼ��������
  }
  return OK;
}

Status CreateBiTreeInPreOrderResult(BiTree &T){
//���ݴ�����ַ���*str�е���������������Ľ��,�������Ӵ洢�Ķ�������
//(��ĳ��������ӻ��Һ���,���Կո��ʾ��"����")��
  if(!(*pstr)||*pstr==' '){  //pstrȫ�ֱ���
    T=NULL;
    pstr++;
  }
  else{
    T=(BiTNode *)malloc(sizeof(BiTNode)); //����һ���½��
    if(!T) exit(OVERFLOW);
    T->data=*(pstr++); //�ȸ�ֵȻ���ټ�
    CreateBiTreeInPreOrderResult(T->lchild);  //����������
    CreateBiTreeInPreOrderResult(T->rchild);  //����������
  }
  return OK;
}

Status CreateBiTreeInBracket(BiTree &T){
//����Ƕ�����ű�ʾ�����ַ���*str�������Ӵ洢�Ķ�����
//����:*pstr="(a(b(c),d(e(,f),g)))"
  BiTree stack[100],p;
  int top=0, k;  //topΪջָ��,kָ���������Һ���;
  T=NULL;
  while(*pstr){
    switch(*pstr){
      case '(':stack[top++]=p;k=1;break;  //����,�丸���Ϊ*p
      case ')':top--;             break;
      case ',':               k=2;break;  //�ҽ��,�丸���Ϊ*p
      case ' ':                   break;
      default :
	      p=(BiTree)malloc(sizeof(BiTNode));
	      p->data=*pstr;
	      p->lchild=p->rchild=NULL;
	      if(!T) T=p;                      //�����
	      else{
	        switch(k){
	          case 1:stack[top-1]->lchild=p;break;
	          case 2:stack[top-1]->rchild=p;break;
	        }
	      }
    }
    pstr++;
  }
  return OK;
}

Status DestroyBiTree(BiTree &T){
  if(T){
    if(T->lchild) DestroyBiTree(T->lchild);   //����������
    if(T->rchild) DestroyBiTree(T->rchild);   //����������
    free(T);   //���ٸ����
    T=NULL;
    return OK;
  }
  else
    return OK;
}

Status PrintElement(BiTree t){
  printf("%c",t->data);  //��ʾ���������
  return OK;
}

Status PreOrderTraverse(BiTree T, Status (*Visit)(BiTree t)){//����
  if(T){
    if((*Visit)(T))     //���ʽ��
	if(PreOrderTraverse(T->lchild,Visit))   //����������
	    if(PreOrderTraverse(T->rchild,Visit))   //����������
		    return OK;
    return ERROR;
  }
  else return OK;
}

Status InOrderTraverse(BiTree T, Status (*Visit)(BiTree t)){//����
  if(T){
    if(InOrderTraverse(T->lchild,Visit))   //����������
	if((*Visit)(T))     //���ʽ��
	    if(InOrderTraverse(T->rchild,Visit))   //����������
		return OK;
    return ERROR;
  }
  else return OK;
}

Status PostOrderTraverse(BiTree T, Status (*Visit)(BiTree e)){//����
  if(T){
    if(PostOrderTraverse(T->lchild,PrintElement))   //����������
	if(PostOrderTraverse(T->rchild,PrintElement))   //����������
	    if((*Visit)(T))     //���ʽ��
		return OK;
    return ERROR;
  }
  else return OK;
}

Status DisplayBiTreeInConcave(BiTree T){//�԰����ʾ�����һ�ö�����
   BiTree stack[100],p;
   int level[100][2],top,n,i,width=4;
   char childtype[3]={'L','R','D'};
   const int MaxWidth = 30;
   if(T){
     top=0;
     stack[top]=T;          //�������ջ
     level[top][0]=width;
     level[top][1]=2;       //2��ʾ�Ǹ�
     while(top>=0){
       p=stack[top];       //��ջ��������ʾ�ý��ֵ
       n=level[top][0];
       for(i=1;i<=n;i++) printf(" ");//����nΪ��ʾ����,�ַ����Ҷ�����ʾ
       printf("%c (%c)",p->data,childtype[level[top][1]]);
       for(i=n+1;i<=MaxWidth;i+=2) printf("��");
       printf("\n");
       top--;
       if(p->rchild){//���������������ջ
	 top++;
	 stack[top]=p->rchild;
	 level[top][0]=n+width; //��ʾ������width
	 level[top][1]=1;       //1��ʾ��������
       }
       if(p->lchild){//���������������ջ
	 top++;
	 stack[top]=p->lchild;
	 level[top][0]=n+width;  //��ʾ������width
	 level[top][1]=0;        //0��ʾ��������
       }
     }
   }
   else
     printf("�ö�������һ�ÿն�����!\n");
   return OK;
}

Status DisplayBiTreeInBracket(BiTree T){
//��Ƕ�����ű�ʾ�����һ�ö�����
   if(T){
     printf("%c",T->data);
     if(T->lchild || T->rchild){
       printf("(");
       if(T->lchild) DisplayBiTreeInBracket(T->lchild);     //�ݹ鴦��������
       if(T->rchild) printf(",");
       if(T->rchild) DisplayBiTreeInBracket(T->rchild);    //�ݹ鴦��������
       printf(")");
     }
   }
   else
     printf("�ö�������һ�ÿն�����!");
   return OK;
}

int main(){
  BiTree T;
  char ch,j;
  char str[200];
  int choice,flag=1,len,i;
  Status temp;
  printf("������ʵ�ֶ������Ĳ���:\n");
  printf("���Խ��н���������, �ݹ��������򡢺�������Ȳ�����\n");

  CreateBiTree(T);

  while(flag){
    printf("��ѡ��: \n");
    printf("1.�ݹ��������\n");
    printf("2.�ݹ��������\n");
    printf("3.�ݹ�������\n");
    printf("4.�����ʾ�����������\n");
    printf("5.Ƕ�����ű�ʾ�����������\n");
    printf("6.���¹���������\n");
    printf("7.�˳�����\n");
    scanf("%d",&choice);
    switch(choice){
      case 1:
	if(T){
	  printf("�������������:");
	  PreOrderTraverse(T,PrintElement); //����ݹ����������
	  printf("\n");
	}
	else
	  printf("������Ϊ��!\n");
	break;
      case 2:
	if(T){
	  printf("�������������:");
	  InOrderTraverse(T,PrintElement);  //����ݹ����������
	  printf("\n");
	}
	else
	  printf("������Ϊ��!\n");
	break;
      case 3:
	if(T){
	  printf("�������������:");
	  PostOrderTraverse(T,PrintElement);//����ݹ����������
	  printf("\n");
	}
	else
	  printf("������Ϊ��!\n");
	break;
      case 4:
	DisplayBiTreeInConcave(T);
	break;
      case 5:
       printf("(");
	DisplayBiTreeInBracket(T);
       printf(")\n");
	break;
      case 6:
	DestroyBiTree(T);
	CreateBiTree(T);
	break;
      default:
	flag=0;
	printf("�������н�������������˳�!\n");
	getch();
    }
  }

  DestroyBiTree(T);
  system("pause");
  return 0;

}
