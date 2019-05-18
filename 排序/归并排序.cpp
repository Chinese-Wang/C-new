#include<stdio.h>
#include<stdlib.h>
/*
 * ��һ�������е�����������������ϲ���һ��
 *
 * ����˵����
 *     a -- ���������������������
 *     start -- ��1�������������ʼ��ַ��
 *     mid   -- ��1����������Ľ�����ַ��Ҳ�ǵ�2�������������ʼ��ַ��
 *     end   -- ��2����������Ľ�����ַ��
 */
void merge(int a[], int start, int mid, int end)
{
    int *tmp = (int *)malloc((end-start+1)*sizeof(int));    // tmp�ǻ���2������������ʱ����
    int i = start;            // ��1��������������
    int j = mid + 1;        // ��2��������������
    int k = 0;                // ��ʱ���������

    while(i <= mid && j <= end)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }

    while(i <= mid)
        tmp[k++] = a[i++];

    while(j <= end)
        tmp[k++] = a[j++];

    // ��������Ԫ�أ�ȫ�������ϵ�����a�С�
    for (i = 0; i < k; i++)
        a[start + i] = tmp[i];

    free(tmp);
}

/*
 * �鲢����(��������)
 *
 * ����˵����
 *     a -- �����������
 *     start -- �������ʼ��ַ
 *     endi -- ����Ľ�����ַ
 */
void merge_sort(int a[], int start, int end)
{
    if(a==NULL || start >= end)
        return ;

    int mid = (end + start)/2;
    merge_sort(a, start, mid); // �ݹ�����a[start...mid]
    merge_sort(a, mid+1, end); // �ݹ�����a[mid+1...end]

    // a[start...mid] �� a[mid...end]����������ռ䣬
    // �����������һ������ռ�a[start...end]
    merge(a, start, mid, end);
}

int main()
{
    int a[10]={3,6,9,10,15,4,6,7,1,12};
    merge_sort(a,0,9);
    for(int i=0;i<10;i++)
        printf("%d  ",a[i]);

    printf("\n");
    system("pause");
    return 0;
}