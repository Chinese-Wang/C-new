#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int search(const char *key,char *str) 
{
    typedef struct
    {
        char son[10];
    }Elem; 
    
    int i,j,m,l,k=0;
    int num1=0,num2=0;

    int f=0;  //f=1��ƥ��ɹ��ı�־

    num1=strlen(str);  //num1Ϊstr�ĳ���

    //i�������ַ����ĳ���
    //j���Ƹ�ֵ
    //k�����µ����Խṹb���±�
    //l�����������������ԭ�����е�λ��
    //m���Ƽ���������ֵ��str���±�
    //num2=0;
    for(i=1;i<=num1;i++)
        num2=num2+i;    //num2��ʾkey�ַ����ĳ��ȴ��ڵ���2��ȫ���Ӵ����� 
    
    printf("%d   %d\n",num1,num2);
    Elem *b=(Elem *)malloc(sizeof(Elem)*num2);
    for( i = 1; i <= num1; i++)
    {
        l=0;
        while(1)
        {
            m=l;
            for( j = 0; j < i; j++)
            {
                b[k].son[j]=str[m];
                m++;
            }
            printf("%s\n",b[k].son);
            l++;
            k++;
            if (m==num1)
                break;
        }
    }
    for( i = 0; i < num2; i++)
    { 
        printf("%s\n",b[i].son);
        if (strcmp(key,b[i].son)==0) {
            f=1;
            break;
        }
    }
    free(b);
    b=NULL;
    return f;
}



int main()
{
    char s[]="HUAWEI";
    char k[]="WE";
    int res;
    res=search(k,s);
    if(res==1)
        printf("ƥ��ɹ�\n");
    else
    {
        printf("ƥ��ʧ��");
    }
    system("pause");
    return 0;
}

/*int main()
{
    char s[]="�л���ͳ����";
    char a[]="��ͳ";
    if (strstr(s,a)) {
        printf("ƥ��ɹ���\n");
    }
    else
    {
        printf("ƥ��ʧ�ܣ�\n");
    }
    system("pause");
    return 0;
    
}
*/