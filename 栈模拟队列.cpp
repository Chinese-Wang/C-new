#include<stdio.h>
typedef int SElemType;
#include"LStack.cpp"
typedef struct Queue{
	LStack In;
	LStack Out;
}Queue;

Status InitQueue(Queue& Q)
{
	Init(Q.In);
	Init(Q.Out);
	return OK;
}

Status DelQueue(Queue& Q)
{
	Del(Q.In);
	Del(Q.Out);
	return OK;
}

Status EnQueue(Queue& Q,SElemType item)
{
	if(Push(Q.In,item))
		return OK;
	return ERROR;
}

Status OutQueue(Queue& Q,SElemType& item)
{
	SElemType e;
	if(Empty(Q.Out))
	{
		while(!Empty(Q.In))
		{
			Pop(Q.In,e);
			Push(Q.Out,e);
		}
	}
	if(Pop(Q.Out,item))
		return OK;
	else
		printf("ջΪ��\n");
	return ERROR;
}

int main()
{
	Queue Q;
	int e;
	int flag=1;
	int ch;
	InitQueue(Q);
	while(flag){
		printf("��ѡ��:\n");
		printf("1.����һ��Ԫ��\n");  //��������Ԫ��
		printf("2.ɾ��һ��Ԫ��\n");  //ɾ������Ԫ��
		printf("3.�˳�\n");
		scanf("%d",&ch);
		switch(ch){
		case 1:
			printf("����Ҫ�����Ԫ��:");
			scanf("%d",&e);
			EnQueue(Q,e);
			printf("����ɹ�\n");
			break;
		case 2:
			OutQueue(Q,e);
			printf("ɾ����Ԫ��:%d\n",e);
			break;
		case 3:
			flag=0;
			break;
		}
	}
	DelQueue(Q);
	system("pause");
	return 0;
}

/*
��ѡ��:
1.����һ��Ԫ��
2.ɾ��һ��Ԫ��
3.�˳�
1
����Ҫ�����Ԫ��:1
����ɹ�
��ѡ��:
1.����һ��Ԫ��
2.ɾ��һ��Ԫ��
3.�˳�
1
����Ҫ�����Ԫ��:2
����ɹ�
��ѡ��:
1.����һ��Ԫ��
2.ɾ��һ��Ԫ��
3.�˳�
1
����Ҫ�����Ԫ��:3
����ɹ�
��ѡ��:
1.����һ��Ԫ��
2.ɾ��һ��Ԫ��
3.�˳�
2
ɾ����Ԫ��:1
��ѡ��:
1.����һ��Ԫ��
2.ɾ��һ��Ԫ��
3.�˳�
2
ɾ����Ԫ��:2
��ѡ��:
1.����һ��Ԫ��
2.ɾ��һ��Ԫ��
3.�˳�
2
ɾ����Ԫ��:3
��ѡ��:
1.����һ��Ԫ��
2.ɾ��һ��Ԫ��
3.�˳�
3
�밴���������. . .*/
