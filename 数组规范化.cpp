/*�������������ƶ�������֮ǰ*/

#include<stdio.h>
#include<stdlib.h>

void Move(int *num,int len){
    int tmp;
    int i=0;
    while(i<len){
        if(num[i]<0)
        {
            tmp = num[len];
            num[len]=num[i];
            num[i]=tmp;
            len--;
        }
        else i++;
    }
}

int main()
{
    int len;
    printf("�������鳤��:");
    scanf("%d",&len);
    int *nums = (int *)malloc(sizeof(int)*len);
    printf("��������ֵ:");
    for (int i = 0; i < len; i++)
        scanf("%d",&nums[i]);    
    Move(nums,len-1);
    for (int i = 0; i < len; i++)
        printf("%d  ",nums[i]);
    printf("\n");
    system("pause");
    return 0;    
}
