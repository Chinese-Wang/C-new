#include<iostream>
#include<stdlib.h>
using namespace std;


int main()
{
	float res_1=0,res_2=0;
    float credit;  //ÿ�ſγ̵�ѧ��
    float grade;  //ÿ�ſγ̵ĳɼ� 
    cout<<"����ѧ�ֺͳɼ�:";
	cin>>credit>>grade; 
    while(credit!=0 && grade!=0){
        cin>>credit>>grade;
        res_1 += credit*(grade-50)/10;
        res_2 += credit;
    }
    
    cout<<"����Ϊ:"<<res_1/res_2<<endl;
    system("pause");
    return 0;
}
