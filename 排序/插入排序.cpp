#include<iostream>
using namespace std;

/*
 *��������
 * 
 * ����˵��:
 * 		a---Ҫ���������
 * 		len---����ĳ���
 */
void sort(int a[],int len){
	int value,j;
	for(int i=1;i<len;i++){
		value=a[i];
		for(j=i-1;j>=0;j--){
			if(a[j] > value){
				a[j+1]=a[j]; //��a[j]��ֵ�����ƣ�
			}
			else break;
		}
		a[j+1]=value;
	}
}

int main()
{
	int arr[10]={2,5,6,90,53,56,15,12,45,12};
	sort(arr,10);
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
		cout<<arr[i]<<"   ";
	cout<<endl;	
	system("pause");
	return 0;
} 
