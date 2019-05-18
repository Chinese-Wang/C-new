#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define True 1
#define False 0

typedef int Status;

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

SElemType GetTop(LStack S){  //ȡջ��Ԫ��
    if (S == NULL)
        return ERROR;
    return S->data;
}
