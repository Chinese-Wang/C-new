/*���������Ǿ����ѹ���洢��������þ��󣬲���������Ԫ��ֵ*/
#include<stdio.h>
#include<stdlib.h>

int* CreateArray(int &n){ //���ؾ������
    int *nums;
    int size;
    printf("����������:");
    scanf("%d",&n);
    size = n * (n + 1) / 2;
    nums = (int*)malloc(sizeof(int)*size);
    printf("����������Ԫ�ص�ֵ(��������):");
    for(int i = 0;i < size;i++){
    	scanf("%d",&nums[i]);
    }
    return nums;
}

int SearchPos(int row,int col){ //row�У�col��,Ѱ���±�
    if(col < 0 || row < 0)  return -2;
    if(col > row) return -1;
	return row*(row+1)/2+col; 
}

void Search(int *nums){ //Ѱ�Ҹ�ֵ�������е�λ��,�������ֵ
    int row,col;
    int pos;
    printf("����Ҫ����Ԫ�ص��кź��к�:");
    scanf("%d %d",&row,&col);
    pos = SearchPos(row,col);
    if(pos == -2) printf("�кź��к���������\n");
    if(pos == -1) printf("��Ԫ��ֵΪ��0. δ�������д�ţ�\n");
    else printf("�����±�Ϊ:%d,ֵΪ:%d\n",pos,nums[pos]);
}

void DisplayArray(int *nums, int n){
    int pos;
    for(int i = 0;i< n;i++){
        for(int j = 0;j < n;j++){
            pos = SearchPos(i,j);
            if(pos == -1) printf("%3d",0);
            else printf("%3d",nums[pos]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int *nums;
    int row,col,n;
    int pos;
    nums = CreateArray(n);
    printf("\n");
    DisplayArray(nums, n);
    Search(nums);
    free(nums);
    nums = NULL;
     system("pause");
    return 0;
}
