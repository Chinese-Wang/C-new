#include <iostream>
#include <stdlib.h>
using namespace std;

int del(int num[], int n, int item)
{ //aΪ���飬n����Ԫ�ظ�����itemҪɾ����ֵ
    int i = 0, p = 0;
    while (i < n)
    {
        if (num[p] != item)
            p++;
        i++;
        num[p] = num[i];
    }
    return p;
}

/*ɾ�������нڵ�ֵΪ������Ԫ��
void OddDelete(ListNode *L)
{
    ListNode *tmp = L;
    ListNode *p = L->next;
    while (p)
    {
        if (p->data % 0 != 0)
        {
            tmp->next = p->next;
            free(p);
        }
        else
            tmp = tmp->next;

        p = tmp->next;
    }
}*/

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 4, 4, 4, 7};
    int len;
    len = del(a, 10, 4);
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;
    system("pause");
    return 0;
}
