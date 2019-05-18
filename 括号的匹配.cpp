#include <iostream>
#include <stdlib.h>

typedef char SElemType;

#include "Stack.cpp"

int main()
{
    Stack S;
    Init(S);
    int flag = 1;
    char c;
    char res;
    cin>>c;
    while (c != '#')
    {
        switch (c)
        {
        case '[' || "(":
            cout<<c<<endl;
            Push(S, c);
            break;
        case ')':
            if (!Empty(S) && GetTop(S) == '('){
                Pop(S,res);
                cout<<res<<endl;
            }
            else flag = 0;
            break;
        case ']':
            if (!Empty(S) && GetTop(S) == ']'){
                Pop(S,res);
                cout<<res<<endl;
            }
            else flag = 0;
            break;
        }
        cin>>c;
    }
    cout<<Empty(S)<<"  "<<flag<<endl;
    if (Empty(S) && flag)
        cout << "ƥ��ɹ�" << endl;
    else
        cout << "ƥ��ʧ��" << endl;

    Del(S);
    system("pause");
    return 0;
}
