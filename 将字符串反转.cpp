#include<stdio.h>
#include<stdlib.h>

int len;
int n;

void Transfer(char *ch){
    char c=ch[n];
    n++;
    if(n==len){
        n=0;
        ch[n]=c;
        return;
    }
    Transfer(ch);
    n++;
    ch[n]=c;
}

int main()
{
    char c[100];
    char tmp;
    printf("����Ҫ��ת���ַ���(����'#'ֹͣ���룬�ַ�����󳤶�100):\n");
    scanf("%c",&tmp);
    while(tmp!='#'){
        c[len] = tmp;
        len++;
        scanf("%c",&tmp);
    }
    Transfer(c);
    for (int i = 0; i < len; i++)
        printf("%c",c[i]);
    printf("\n");
    system("pause");
    return 0;
}