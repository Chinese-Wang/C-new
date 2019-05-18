#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef char BElemType;

typedef struct Parent{
	BElemType data;
	int parent;
}Parents;  //˫�׽ڵ� 

void Create(Parents *p,int len){
	char ch;
	int i,j;
	char first,after;
	for(i=0;i<len;i++)
		p[i].parent = -1;
	printf("����������ڵ�ֵ:");
	for(i=0;i<len;i++){
		scanf("%c",&p[i].data);
	}
	printf("\n");
	printf("������ÿ���ڵ�ĸ��ӹ�ϵ(����ǰ���ں��ö��Ÿ���):\n");
	printf("���� #,# ��������:\n");
	scanf("%c,%c",&first,&after);
	while((first != '#') && (after != '#')){
		for(i=0;i<len;i++){
			if(p[i].data == first)
				break;  //�ҳ����ڵ��±� 
		}
		for(j=1;j<len;j++){
			if(p[j].data == after)
				break;  //�ҳ��ӽڵ��±� 
		}
		p[j].parent = i;
		scanf("%c,%c ",&first,&after);
	}
}

int main()
{
	Parents* p;
	int len;
	printf("�����빲�ж��ٸ��ڵ�:");
	scanf("%d",&len);
	p = (Parents *)malloc(sizeof(Parents)*len);
	getchar();
	Create(p,len);
	for(int i=0;i<len;i++){
		printf("%d %c  %d\n",i,p[i].data,p[i].parent);
	}
	//free(p);
	p = NULL;
	system("pause");
	return 0;
}






