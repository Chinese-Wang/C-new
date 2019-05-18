#include<iostream>
#include<stdlib.h>
using namespace std;

/*
 *ѡ������
 *
 * ����˵��:
 *      a---Ҫ���������
 *      size---���鳤��
 * 
 */
void select_sort(int *a,int size){
    void swap(int *a,int m,int n);
    int end=0;
    int min,j;
    for(int i=0;i<size;i++){
        min=i;
        for(j=i+1;j<size;j++){
            if(a[min]>a[j]) min=j;
        }
        swap(a,end,min);
        end++;
    }
}

/*
 *��������
 *
 * ����˵��:
 *      a---Ҫ����Ԫ�ص������׵�ַ
 *      m---�����ĵ�һ��λ��
 *      n---�����ĵڶ���λ��
 * 
 */
void swap(int *a,int m,int n){ //����Ԫ�أ���һ������Ϊ���飬����������ΪҪ������λ��
    int tmp=a[m];
    a[m]=a[n];
    a[n]=tmp;
}

int main()
{
    int A[10]={3,6,9,10,15,4,6,7,1,12};
    select_sort(A,10);
    for(int i = 0; i < 10; i++)
    {
        cout<<A[i]<<"  ";
    }
    cout<<endl;
    system("pause");
    return 0;
}
