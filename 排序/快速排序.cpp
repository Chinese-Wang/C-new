/*
��������(Quick Sort)ʹ�÷��η����ԡ�
���Ļ���˼���ǣ�ѡ��һ����׼����ͨ��һ������Ҫ��������ݷָ�ɶ����������֣�
����һ���ֵ��������ݶ�������һ���ֵ��������ݶ�ҪС��
Ȼ���ٰ��˷����������������ݷֱ���п�����������������̿��Եݹ���У��Դ˴ﵽ�������ݱ���������С�

�����������̣�
(1) ������������һ����׼ֵ��
(2) �����бȻ�׼ֵС�İڷ��ڻ�׼ǰ�棬���бȻ�׼ֵ��İ��ڻ�׼�ĺ���(��ͬ�������Ե���һ��)������������˳�֮�󣬸û�׼�ʹ������е��м�λ�á�
(3) �ݹ�ذ�"��׼ֵǰ���������"��"��׼ֵ�����������"��������
*/

#include <stdio.h>
#include <stdlib.h>

/*int partition(int *num, int left, int right)
{
    int min = num[right];
    int tmp;
    int i = left;
    for (int j = left; j < right; j++)
    {
        if (num[j] < min)
        {
            tmp = min;
            min = num[j];
            num[j] = min;
            i = i + 1;
        }
    }
    tmp = num[i];
    num[i] = num[right];
    num[right] = tmp;
    return i;
}
/*
 *��������
 * 
 * ����˵��:
 *      num---Ҫ���������
 *      left---�������߽�
 *      right---������ұ߽�
 * 
 */
void quick_sort(int *num, int left, int right)
{
    if (left >= right)
        return;

    //int mid = partition(num,left,right);
    int min = num[left];
    int j = left;
    int tmp;
    for (int i = left + 1; i <= right;)
    {
        if (num[i] < min)
        {
            tmp = num[j];
            num[j] = num[i];
            num[i] = tmp;
            j++;
        }
        else i++;
    }
    quick_sort(num, left, j );
    quick_sort(num, j + 1 , right);
}

/*void swap(int a[], int m, int n)
{
	int temp = a[m];
	a[m] = a[n];
	a[n] = temp;
}
 
void sort_one(int a[], int m, int n)
{
	int p=m;
	int t = a[m];
	if (m > n)
		return;
	for (int i = m+1; i <= n; i++)
	{
		if (a[i] < t)
		{
			swap(a, ++p, i);
		}
	}
	swap(a, m, p);
	sort_one(a,m,p-1);
	sort_one(a, p + 1, n);
}*/

int main()
{
    int nums[] = {10, 2, 5, 7, 4, 1, 11, 15, 14, 7, 8};
    int len = sizeof(nums) / sizeof(int);
    quick_sort(nums, 0, 9);
    for (int i = 0; i < len; i++)
        printf("%d  ", nums[i]);
    printf("\n");
    system("pause");
    return 0;
}