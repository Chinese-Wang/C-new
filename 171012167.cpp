#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void create_line(int *num,int *HT,int len){ //����̽��ɢ��
	int key;
	int H0;
	int add; //ÿ�����ӵ�ֵ
	for(int i = 0;i< len;i++){
		key = num[i] % 16;
		add = 1;
		H0 = key;
		while(HT[key] != 0 && add < 15){
			key = H0 + add;
			key = key % 18;
			add++;
		}
		HT[key] = num[i];
	}
}

void create_second(int *num,int *HT,int len){ //����̽��ɢ��
	int key;
	int H0;
	int mi; //�ж��±����ƻ�����
	int k = -1; 
	int d; //ÿ�����ӵ�ֵ
	for(int i = 0;i< len;i++){
		d = 1;
		mi = 0;
		key = num[i] % 16;
		H0 = key;
		while(HT[key] != 0 && d <= 9){
			key = H0 + d*d*pow(k,mi); 
			d = d + mi; //��miֵΪ1ʱd��һ
			mi = (mi + 1) % 2; //miֵΪ0��1
			key= key % 18; 
		}
		HT[key] = num[i];
	}
}

/*
int search_line(int *HT,int key)
{
	int local;
	int add = 1;
	local = key % 16;
	while(HT[local] != key && add < 15){
		local++;
		local = local % 18;
		add++;
	}
	if(add == 15) return -1;
	return local;
}

int search_second(int *HT,int key)
{
	int local;
	int H0;
	int mi = 0; //�ж��±����ƻ�����
	int k = -1; 
	int d = 1; //ÿ�����ӵ�ֵ
	local = key % 16;
	H0 = local;
	while(HT[local] != key && d <= 9){
		local = H0 + d*d*pow(k,mi); 
		d = d + mi; //��miֵΪ1ʱd��һ
		mi = (mi + 1) % 2; //miֵΪ0��1
		local= local % 18; 
	}
	return local;
}*/

void displayHT(int *HT,int len)
{
	for(int i=0;i<len;i++){
		if(HT[i]) printf("[%d:%d]\n",i,HT[i]);
		else printf("[%d: ]\n",i);
	}
}

int main()
{
	int len;
    printf("������������鳤��:");
    scanf("%d",&len);
    int *nums = (int*)malloc(sizeof(int)*len);
    printf("������������Ԫ��:");
    for(int i = 0;i < len;i++)
		scanf("%d",&nums[i]);
	int HT_line[18] = {}; //����̽�⹹�ɵ�ɢ��
	int HT_second[18] = {}; //����̽�⹹�ɵ�ɢ��
	create_line(nums,HT_line,11);
	create_second(nums,HT_second,11);
	printf("����̽��ɢ��:\n");
	displayHT(HT_line, 18);
	printf("\n����̽��ɢ��:\n");
	displayHT(HT_second, 18);
	printf("\n");
	return 0;
}

/*
ʾ�����룺
11
10 24 32 17 31 30 46 47 40 63 49
ʾ�������
����̽��ɢ��:
[0:32]
[1:17]
[2:63]
[3:49]
[4: ]
[5: ]
[6: ]
[7: ]
[8:24]
[9:40]
[10:10]
[11: ]
[12: ]
[13: ]
[14:30]
[15:31]
[16:46]
[17:47]

����̽��ɢ��:
[0:32]
[1:17]
[2:49]
[3: ]
[4: ]
[5: ]
[6: ]
[7: ]
[8:24]
[9:40]
[10:10]
[11:63]
[12: ]
[13:46]
[14:30]
[15:31]
[16:47]
[17: ]
 */
