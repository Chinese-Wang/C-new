#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define OK 1
#define ERROR 0
#define Ture 1
#define False 0

typedef int Status;
typedef int QElemType;

static int MaxQueueSize = 5;
static int Add = 2;

typedef struct DuSeQueue
{ //������нṹ
	QElemType *data;
	//��ʼ�ռ� 5��Ԫ��;
	//ÿ�β�������2��Ԫ��
	int head; //��ͷ
	int tail; //��β
} DuSeQueue;

Status InitDuSeQueue(DuSeQueue &Q)
{ ////��ʼ��һ������
	Q.data = (QElemType *)malloc(sizeof(QElemType) * MaxQueueSize);
	if (Q.data == NULL)
		exit(False);
	Q.head = 0;
	Q.tail = 0;
	return OK;
}

Status DestroyDuSeQueue(DuSeQueue &Q)
{ //����һ������
	if (Q.data)
		free(Q.data);
	Q.data = NULL;
	return OK;
}

int DuSeQueueLength(DuSeQueue &Q)
{ //���еĳ���
	return (Q.tail - Q.head + MaxQueueSize) % MaxQueueSize;
}

Status EnDuSeQueueFront(DuSeQueue &Q, QElemType item)
{ //��һ��Ԫ�ش�ǰ�����
	int len = MaxQueueSize;
	if ((Q.tail + 1) % MaxQueueSize == Q.head)
	{
		int *tmp = (int *)realloc(Q.data, sizeof(QElemType) * (MaxQueueSize + Add));
		Q.data = tmp;
		MaxQueueSize += Add;
		for (int i = 0; i < Q.tail; i++)
		{
			Q.data[(len + i) % MaxQueueSize] = Q.data[i];
		}
		Q.tail = (Q.tail + len) % MaxQueueSize;
	}
	Q.head = (Q.head - 1 + MaxQueueSize) % MaxQueueSize;
	Q.data[Q.head] = item;
	return OK;
}

Status EnDuSeQueueBack(DuSeQueue &Q, QElemType item)
{ //��һ��Ԫ�شӺ������
	int len = MaxQueueSize;
	if ((Q.tail + 1) % MaxQueueSize == Q.head)
	{ //����
		int *tmp = (int *)realloc(Q.data, sizeof(QElemType) * (MaxQueueSize + Add));
		Q.data = tmp;
		MaxQueueSize += Add;
		if ((Q.tail + 3) != MaxQueueSize)
		{ //��β����ָ���������һ��
			for (int i = 0; i < Q.tail; i++)
			{
				Q.data[(len + i) % MaxQueueSize] = Q.data[i];
			}
			Q.tail = (Q.tail + len) % MaxQueueSize;
		}
	}

	Q.data[Q.tail] = item;
	Q.tail = (Q.tail + 1) % MaxQueueSize;
	return OK;
}

Status DeDuSeQueueFront(DuSeQueue &Q, QElemType &item)
{ //��һ��Ԫ�ش�ǰ������
	if (Q.head == Q.tail)
		return ERROR;
	item = Q.data[Q.head];
	Q.head = (Q.head + 1) % MaxQueueSize;
	return OK;
}

Status DeDuSeQueueBack(DuSeQueue &Q, QElemType &item)
{ //��һ��Ԫ�شӺ������
	if (Q.head == Q.tail)
		return ERROR;
	Q.tail = (Q.tail - 1 + MaxQueueSize) % MaxQueueSize;
	item = Q.data[Q.tail];
	return OK;
}

Status DisplayDuSeQueue(DuSeQueue Q)
{ //��ʾ����������Ԫ��
	if (Q.head == Q.tail)
	{
		printf("����Ϊ��\n");
		return ERROR;
	}
	if (Q.tail < Q.head)
	{
		for (int i = 0; i < MaxQueueSize; i++)
		{
			if (i < Q.tail || i >= Q.head)
				printf("[%d:%d]\n", i, Q.data[i]);
		}
	}
	else
	{
		for (int i = Q.head; i < Q.tail; i++)
			printf("[%d:%d]\n", i, Q.data[i]);
	}
	return OK;
}
Status DisplayDuSeQueueInMemory(DuSeQueue Q)
{ //��ʾ����������Ԫ��
	if (Q.head == Q.tail)
	{
		printf("����Ϊ��\n");
		return ERROR;
	}
	if (Q.tail < Q.head)
	{
		for (int i = 0; i < MaxQueueSize; i++)
		{
			if (i >= Q.tail && i < Q.head)
				printf("[%d: ]\n", i);
			else
				printf("[%d:%d]\n", i, Q.data[i]);
		}
	}
	else
	{
		for (int i = 0; i < MaxQueueSize; i++)
		{
			if (i < Q.head || i >= Q.tail)
				printf("[%d: ]\n", i);
			else
				printf("[%d:%d]\n", i, Q.data[i]);
		}
	}
	return OK;
}

int main()
{
	DuSeQueue Q;
	QElemType e;
	int flag = 1, ch, len;
	int n;
	Status temp;
	InitDuSeQueue(Q); //��ʼ������

	while (flag)
	{
		printf("��ѡ��:\n");
		printf("1.��ʾ��������Ԫ��\n");
		printf("2.��ʾ����Ԫ�����ڴ��еĴ洢\n");
		printf("3.��ͷ�����\n");
		printf("4.��β�����\n");
		printf("5.��ͷ������\n");
		printf("6.��β������\n");
		printf("7.����еĳ���\n");
		printf("8.�˳�����\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			DisplayDuSeQueue(Q); //��ʾ����������Ԫ��
			break;
		case 2:
			DisplayDuSeQueueInMemory(Q); //��ʾ������Ԫ�����ڴ��е���ʾ
			break;
		case 3:
			printf("������Ҫ��ӵ�Ԫ��(һ������):");
			scanf("%d", &e);		//����Ҫ����е��ַ�
			EnDuSeQueueFront(Q, e); //�����
			DisplayDuSeQueueInMemory(Q);
			break;
		case 4:
			printf("������Ҫ��ӵ�Ԫ��(һ������):");
			scanf("%d", &e);	   //����Ҫ����е��ַ�
			EnDuSeQueueBack(Q, e); //�����
			DisplayDuSeQueueInMemory(Q);
			break;
		case 5:
			temp = DeDuSeQueueFront(Q, e); //������
			if (temp == OK)
			{
				printf("����һ��Ԫ��:%d\n", e); //�����в��գ���ʾ�����е�Ԫ��
				DisplayDuSeQueue(Q);
			}
			else
				printf("����Ϊ��!\n"); //�������Ϊ��
			break;
		case 6:
			temp = DeDuSeQueueBack(Q, e);
			if (temp == OK)
			{
				printf("����һ��Ԫ��:%d\n", e); //�����в��գ���ʾ�����е�Ԫ��
				DisplayDuSeQueue(Q);
			}
			else
				printf("����Ϊ��!\n"); //�������Ϊ��
			break;
		case 7:
			len = DuSeQueueLength(Q);
			printf("���еĳ���Ϊ:%d\n", len);
			break;
		default:
			flag = 0;
			printf("�������н�������������˳�!\n");
			getch();
		}
		printf("\n");
	}
	DestroyDuSeQueue(Q);
	return 0;
}

/*
��ѡ��:
1.��ʾ��������Ԫ��
2.��ʾ����Ԫ�����ڴ��еĴ洢
3.��ͷ�����
4.��β�����
5.��ͷ������
6.��β������
7.����еĳ���
8.�˳�����
3
������Ҫ��ӵ�Ԫ��(һ������):1
[0:1]
[1: ]
[2: ]
[3: ]
[4: ]

��ѡ��:
1.��ʾ��������Ԫ��
2.��ʾ����Ԫ�����ڴ��еĴ洢
3.��ͷ�����
4.��β�����
5.��ͷ������
6.��β������
7.����еĳ���
8.�˳�����
4
������Ҫ��ӵ�Ԫ��(һ������):2
[0:1]
[1:2]
[2: ]
[3: ]
[4: ]

��ѡ��:
1.��ʾ��������Ԫ��
2.��ʾ����Ԫ�����ڴ��еĴ洢
3.��ͷ�����
4.��β�����
5.��ͷ������
6.��β������
7.����еĳ���
8.�˳�����
3
������Ҫ��ӵ�Ԫ��(һ������):2
[0:1]
[1:2]
[2: ]
[3: ]
[4:2]

��ѡ��:
1.��ʾ��������Ԫ��
2.��ʾ����Ԫ�����ڴ��еĴ洢
3.��ͷ�����
4.��β�����
5.��ͷ������
6.��β������
7.����еĳ���
8.�˳�����
4
������Ҫ��ӵ�Ԫ��(һ������):5
[0:1]
[1:2]
[2:5]
[3: ]
[4:2]

��ѡ��:
1.��ʾ��������Ԫ��
2.��ʾ����Ԫ�����ڴ��еĴ洢
3.��ͷ�����
4.��β�����
5.��ͷ������
6.��β������
7.����еĳ���
8.�˳�����
4
������Ҫ��ӵ�Ԫ��(һ������):6
[0:5]
[1:6]
[2: ]
[3: ]
[4:2]
[5:1]
[6:2]

��ѡ��:
1.��ʾ��������Ԫ��
2.��ʾ����Ԫ�����ڴ��еĴ洢
3.��ͷ�����
4.��β�����
5.��ͷ������
6.��β������
7.����еĳ���
8.�˳�����
1
[4:2]
[5:1]
[6:2]
[0:5]
[1:6]

��ѡ��:
1.��ʾ��������Ԫ��
2.��ʾ����Ԫ�����ڴ��еĴ洢
3.��ͷ�����
4.��β�����
5.��ͷ������
6.��β������
7.����еĳ���
8.�˳�����
2
[0:5]
[1:6]
[2: ]
[3: ]
[4:2]
[5:1]
[6:2]

��ѡ��:
1.��ʾ��������Ԫ��
2.��ʾ����Ԫ�����ڴ��еĴ洢
3.��ͷ�����
4.��β�����
5.��ͷ������
6.��β������
7.����еĳ���
8.�˳�����
4
������Ҫ��ӵ�Ԫ��(һ������):8
[0:5]
[1:6]
[2:8]
[3: ]
[4:2]
[5:1]
[6:2]

��ѡ��:
1.��ʾ��������Ԫ��
2.��ʾ����Ԫ�����ڴ��еĴ洢
3.��ͷ�����
4.��β�����
5.��ͷ������
6.��β������
7.����еĳ���
8.�˳�����
5
����һ��Ԫ��:2
[5:1]
[6:2]
[0:5]
[1:6]
[2:8]

��ѡ��:
1.��ʾ��������Ԫ��
2.��ʾ����Ԫ�����ڴ��еĴ洢
3.��ͷ�����
4.��β�����
5.��ͷ������
6.��β������
7.����еĳ���
8.�˳�����
6
����һ��Ԫ��:8
[5:1]
[6:2]
[0:5]
[1:6]

��ѡ��:
1.��ʾ��������Ԫ��
2.��ʾ����Ԫ�����ڴ��еĴ洢
3.��ͷ�����
4.��β�����
5.��ͷ������
6.��β������
7.����еĳ���
8.�˳�����
2
[0:5]
[1:6]
[2: ]
[3: ]
[4: ]
[5:1]
[6:2]

��ѡ��:
1.��ʾ��������Ԫ��
2.��ʾ����Ԫ�����ڴ��еĴ洢
3.��ͷ�����
4.��β�����
5.��ͷ������
6.��β������
7.����еĳ���
8.�˳�����
7
���еĳ���Ϊ:4

��ѡ��:
1.��ʾ��������Ԫ��
2.��ʾ����Ԫ�����ڴ��еĴ洢
3.��ͷ�����
4.��β�����
5.��ͷ������
6.��β������
7.����еĳ���
8.�˳�����
8

*/