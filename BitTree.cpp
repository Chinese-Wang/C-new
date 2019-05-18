#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct BiNode
{
    BElemType data;
    struct BiNode *lchild;
    struct BiNode *rchild;
} BitNode, *BitTree;

typedef BitTree QElemType;
typedef BitTree SElemType;
#include "ListQueue.cpp"
#include "Stack.cpp"

int len = 0;

void Init(BitTree &T)
{ //��ʼ��
    T = new BitNode;
    T->lchild = NULL;
    T->rchild = NULL;
}

void Del(BitTree &T)
{ //ɾ����
    BitNode *tmp = T;
    if (T)
    {
        Del(T->rchild);
        Del(T->lchild);
        delete tmp;
    }
}

void Create(BitTree &T)
{ //������
    BElemType c;
    cin >> c;
    if (c == '#')
        T = NULL;
    else
    {
        T = new BitNode;
        T->data = c;
        Create(T->lchild);
        Create(T->rchild);
    }
}

int Depth(BitTree &T)
{ //���������
    if (T == NULL)
        return 0;
    else
    {
        int m = Depth(T->lchild);
        int n = Depth(T->rchild);
        if (m > n)
            return (m + 1);
        else
            return (n + 1);
    }
}

int End_Point_Count(BitTree &T)
{ //�˵����ͳ��
    if (T == NULL)
        return 0;
    if (T->rchild == NULL && T->lchild == NULL)
        return 1;
    return End_Point_Count(T->lchild) + End_Point_Count(T->rchild);
}

int Node_Count(BitTree &T)
{ //�ڵ����ͳ��
    if (T == NULL)
        return 0;
    else
        return Node_Count(T->lchild) + Node_Count(T->rchild);
}

void Traver(BitTree &T)
{ //������������е�һ�����·�����ȣ��������·���ϵĽڵ�ֵ
    if (T == NULL)
        return;
    if (T)
    {
        len++; //ȫ�ֱ���
        cout << T->data << "  ";
        int m = Depth(T->lchild);
        int n = Depth(T->rchild);
        if (m > n)
            Traver(T->lchild);
        else
            Traver(T->rchild);
    }
}

int Compare(BitTree &T1, BitTree &T2)
{ //�Ƚ����ö������Ƿ���ȣ���ȷ���1�����ȷ���-1
    if (T1 == NULL && T2 == NULL)
        return 1;
    if (!(T1 && T2))
        return 0;
    if (T1->data != T2->data)
        return 0;
    return Compare(T1->lchild, T2->lchild) && Compare(T1->rchild, T2->rchild);
}

void InOrderTraver(BitTree T)
{ //�������������
    if (T)
    {
        InOrderTraver(T->lchild); //�������������
        cout << T->data << "   "; //����������ڵ�
        InOrderTraver(T->rchild); //��������ҽڵ�
    }
}

void PreOrderTraver(BitTree T)
{ //�������������
    if (T)
    {
        cout << T->data << "    "; //����������ڵ�
        PreOrderTraver(T->lchild); //�������������
        PreOrderTraver(T->rchild); //�������������
    }
}

void PostOrderTraver(BitTree T)
{ //�������������
    if (T)
    {
        PostOrderTraver(T->lchild); //�������������
        PostOrderTraver(T->rchild); //�������������
        cout << T->data << "    ";  //����������ڵ�
    }
}

//����������������ú�����Ҫ����ջ��Ӧ��,ջ�е���������Ϊ BitNode* ����
void InorderTraver_Stack(BitTree T)
{
    Stack S;
    Init(S);
    BitNode *p = T;
    BitNode *q = new BitNode;
    while (p || !Empty(S))
    {
        if (p)
        {
            Push(S, p);
            p = p->lchild;
        }
        else
        {
            Pop(S, q);
            cout << q->data << "  ";
            p = q->rchild;
        }
    }
    Del(S);
}

//�����������������Ҫ�õ����У� ������Ԫ������Ϊ BitNode*
void ChengxuTraver(BitTree T)
{
    ListQueue Q;
    Init(Q);
    BitNode *tmp = T;
    EnQueue(Q, tmp);
    while (!Empty(Q))
    {
        DeQueue(Q, tmp);
        if (tmp)
        { //��tmp��Ϊ��ʱ
            EnQueue(Q, tmp->lchild);
            EnQueue(Q, tmp->rchild);
            cout << tmp->data << "  ";
        }
    }
    Del(Q);
}

    