#include <stdio.h>
#include <stdlib.h>

/*
 *ð������(Bubble Sort)���ֱ���Ϊ�����������ĭ����
 *
 *����һ�ֽϼ򵥵������㷨������������ɴ�Ҫ��������У�ÿ�α���ʱ���������ǰ�������εıȽ������������Ĵ�С��
 *���ǰ�߱Ⱥ��ߴ��򽻻����ǵ�λ�á�������һ�α���֮������Ԫ�ؾ������е�ĩβ�� 
 *������ͬ�ķ����ٴα���ʱ���ڶ����Ԫ�ؾͱ����������Ԫ��֮ǰ���ظ��˲�����ֱ���������ж�����Ϊֹ��
 */

/*
 *ð������
 *
 * ����˵��:
 *      num---Ҫ���������
 *      len---����ĳ���
 */
void Bubble_sort_1(int *num, int len)
{

    if (num == NULL || len < 2)
        return;

    int tmp;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (num[j] > num[j+1])
            {
                tmp = num[j+1];
                num[j+1] = num[j];
                num[j] = tmp;
            }
        }
    }
}

void Bubble_sort_2(int *num, int len)
{

    if (num == NULL || len < 2)
        return;

    int tmp;
    int flag;  //���λ�������ѭ���������ӷ������ݽ���
    for (int i = 0; i < len; i++)
    {
        flag =1;  //��ʼ��1����ʾ�����ݽ���
        for (int j = 0; j < len - i - 1; j++)
        {
            if (num[j] > num[j+1])
            {
                tmp = num[j+1];
                num[j+1] = num[j];
                num[j] = tmp;
                flag = 0; //�����ݽ�������0
            }
        }
        if(flag) break;  //���û�����ݽ������˳�
    }
}

int main()
{
    int nums[] = {10, 2, 5, 7, 4, 1, 11, 15, 14, 7, 8};
    int len = sizeof(nums) / sizeof(int);
    Bubble_sort_2(nums, len);
    for (int i = 0; i < len; i++)
        printf("%d  ", nums[i]);
    printf("\n");
    system("pause");
    return 0;
}