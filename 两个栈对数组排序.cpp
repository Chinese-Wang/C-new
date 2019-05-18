#include<stdio.h>
#include<stdlib.h>

typedef int SElemType;
#include"LStack.cpp"

void Stack_Max(int *nums,int len){  //�Ӵ�С����
    LStack S1,S2;
    SElemType item;
    Init(S1);
    Init(S2);
    int i=0;
    for(;i<len;i++){
        if(Empty(S1) || GetTop(S1) >= nums[i]){   //��ջΪ�ջ�ջ��Ԫ�ش��ڵ���nums[i]ʱ����ջ
            Push(S1,nums[i]);
            continue;
        }
        while(!Empty(S1) && GetTop(S1) < nums[i]){ //��ջ��λ����ջ��Ԫ��ֵС��nums[i]
            Pop(S1,item);   //��S1����Ԫ��
            Push(S2,item);  //��S1����Ԫ��ѹ��S2ջ
        }
        Push(S1,nums[i]);   //��nums[i]ѹ��S1ջ
        while(!Empty(S2)){  //��S2��Ϊ��ʱ��S2�е���ѹ��S1ջ
            Pop(S2,item);
            Push(S1,item);
        }
    }
    while (!Empty(S1))
    {
        Pop(S1,item);
        nums[--i] = item;
    }
    Del(S1);
    Del(S2);
}

int main()
{
    int len;
    int i=0;
    printf("����Ҫ����������С:");
    scanf("%d",&len);
    int *num = (int *)malloc(sizeof(int)*len);
    printf("��������Ԫ��ֵ:");
    for(i=0;i<len;i++)
        scanf("%d",&num[i]);
    Stack_Max(num,len);
    for(i=0;i<len;i++)
        printf("%d   ",num[i]);
    printf("\n");
    system("pause");
    return 0;
}

/*
����Ҫ����������С:5
��������Ԫ��ֵ:5 7 9 10 4
10   9   7   5   4
�밴���������. . .
*/