#include<stdio.h>

typedef int SElemType;

#include"LStack.cpp"

int size;

void Del_Medium(LStack& S,int n)
{
	SElemType item;
	if(n==(size/2+1))
	{	
		Pop(S,item);
		return;
	}
	Pop(S,item);
	n--;
	Del_Medium(S,n);
	Push(S,item);
}

int main()
{
	LStack S;
	int e;
	Init(S);
	printf("����ջ�Ĵ�С:");
	scanf("%d",&size);
	printf("������ջԪ��:");
	for(int i=0;i<size;i++){
		scanf("%d",&e);
		Push(S,e);
	}
	Del_Medium(S,size);
	for(int i=0;i<size-1;i++)
	{
		Pop(S,e);
		printf("%d   ",e);
	}
	printf("\n");
	Del(S);
	system("pause");
	return 0;
}
/*
����ջ�Ĵ�С:5
������ջԪ��:1 2 3 4 5
5   4   2   1
�밴���������. . .
*/