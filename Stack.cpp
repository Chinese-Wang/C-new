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
} Lnode, *Linklist;

typedef struct Stack
{
    Lnode* top;  //ָ��ջ��
    Lnode* base; //ָ��ջ��
}Stack;

Status Init(Stack &S){  //��ʼ��ջ
    S.top = NULL;
    S.top = S.base;
    return OK;
}

Status Del(Stack &S){   //����ջ
    Linklist p;
	while(S.top){
		p=S.top;
		S.top=S.top->next;
		free(p);
	}
	return OK;
}

Status Push(Stack &S, SElemType item){  //��ջ
    Linklist tmp = (Linklist)malloc(sizeof(Lnode));
    if(tmp == NULL) exit(ERROR);
    tmp->data = item;
    tmp->next = S.top;
    S.top = tmp;
    if(S.top == NULL) S.base = S.top;
    return OK;
}

Status Pop(Stack &S){  //��ջ�������ص���ֵ
    if (S.top == NULL)
        return ERROR;
    Linklist tmp = S.top;
    S.top = tmp->next;
    free(tmp);
    return OK;
}

Status Pop(Stack &S,SElemType &item){  //���ص���ֵ
    if (S.top == NULL)
        return ERROR;
    Linklist tmp = S.top;
    item = S.top->data;
    S.top = S.top->next;
    free(tmp);
    return OK;
}

int Empty(Stack S){ //�ǿշ���0���շ���1
    if(S.top == NULL)
        return OK;
    return ERROR;
}

SElemType GetTop(Stack S){  //ȡջ��Ԫ��
    if (S.top == NULL)
        return ERROR;
    return S.top->data;
}

/*int main()
{
    Stack S;
    Init(S);
    for (int i = 0; i < 10; i++)
    {
        Push(S,i);
    }   
    Diaplay(S);
    Del(S);
    cout<<endl;
    system("pause");
    return 0;
}*/
