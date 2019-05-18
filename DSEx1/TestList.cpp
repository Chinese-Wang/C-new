//ͷ�ļ�������
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime>

#include "dsexceptions.h"
#include "List.h"
#include "Vector.h"

using namespace std;

static const int NUMS_PER_LINE = 14;  //����ȫ�ֳ���


//������ʽ��ջ��ģ��
template <typename Object>
class Stack 
{
  public:
    bool isEmpty( ) const //�ж϶�ջ�Ƿ�Ϊ��
      { return theList.empty( ); }
    
    const Object & top( ) const //ȡջ��Ԫ��
      { return theList.front( ); }

    void push( const Object & x ) //��Ԫ��xѹ��ջ��
      { theList.push_front( x ); }

    void pop( Object & x ) //��ջ��Ԫ�س�ջ
      { x = theList.front( ); theList.pop_front( ); }
  private:
    List<Object> theList; //���Ԫ��
};

//������ʽ����ģ��
template <typename Object>
class Queue  
{
  public:
    bool isEmpty( ) const //�ж϶����Ƿ�Ϊ��
      { return theList.empty( ); }
    const Object & getFront( ) const  //ȡ��ͷԪ��
      { return theList.front( ); }
    void enqueue( const Object & x ) //��Ԫ��x���
      { theList.push_back( x ); }
    void dequeue( Object & x ) //����
      { x = theList.front( ); theList.pop_front( ); }
  private:
    List<Object> theList;  //����Ԫ��
};

//�����ӡ�������е�Ԫ�غ���ģ��
template <typename Collection>
void printCollection( const Collection & c )
{
    cout << "Collection contains: " << c.size( ) << " items" << endl;
    int i = 1;

    if( c.empty( ) ) //��cΪ��ʱ�����"Empty container."
        cout << "Empty container." << endl;
    //��c��Ϊ��ʱ
    else
    {
        for( auto x : c  ) //��c�е�Ԫ������ȡ����ֵ��x
        {
            cout << x << " "; //���x��ֵ
            if( i++ % NUMS_PER_LINE == 0 ) //ÿ���14��Ԫ�����һ������
                cout << endl;
        }
        cout << endl;

        if( c.size( ) > NUMS_PER_LINE ) //���c�е�Ԫ�ظ�������NUMS_PER_LINE���˳�����
            return;

        //c�е�Ԫ�ظ���С��NUMS_PER_LINE���������c�е�����
        cout << "In reverse: " << endl;
        for( auto ritr = end( c ); ritr != begin( c ); ) //�������c�е�ֵ
            cout << *--ritr << " ";
        cout << endl << endl;
    }
}


int jos( int people, int passes, List<int> & order ) 
{
    List<int> theList;  //����һ������
    List<int>::iterator p = begin( theList ); //�������ָ������ͷ�ڵ�
    List<int>::iterator tmp;   //��������
    Stack<int> s;  //������ջs
    Queue<int> q;  //��������q

    order = List<int>{ };  //Ϊorder����ֵ

    int i;
    for( i = people; i >= 1; --i )  //��iС��peopleʱ��ѭ��
        p = theList.insert( p, i ); //�����ݲ�����������ͷ�巨

    while( people-- != 1 ) //��people������1ʱ  
    {
        for( i = 0; i < passes; ++i ) 
            if( ++p == end( theList ) ) //��p�����������һ���ڵ�ʱ
                p = begin( theList ); //��p��Ϊ�����Ԫ�ڵ�

        order.push_back( *p ); //��pָ��Ľڵ���뵽��β
        s.push( *p );  //��pָ��Ľڵ�ѹ��ջ��
        q.enqueue( *p );  //��pָ��Ľڵ����
        tmp = p; //��tmpָ��p
        if( ++p == end( theList ) ) //p��һ����pָ���βʱ 
            p = begin( theList); //��p��Ϊ��ͷ
        theList.erase( tmp ); //ɾ�����нڵ�Ϊtmp��ֵ
    }

    if( order.size( ) % 2 == 0 ) //���order�ĳ���Ϊż��
    {
        s.push( 0 );  //��ջԪ��0
        q.enqueue( 0 );  //���Ԫ��0 
    }

    while( !s.isEmpty( ) && !q.isEmpty( ) ) //��ջ�Ͷ��ж���Ϊ��ʱ
    {
        int x, y;
        s.pop( x ); //����ջ��Ԫ��
        q.dequeue( y );   //��βԪ�س���
        if( x == y )  //���x��yֵ���
            cout << "Middle removed is " << x << endl;
    }
    cout << "Only unremoved is ";
    return *begin( theList );  //������Ԫ�ڵ��ֵ
}

    
void nonsense( int people, int passes )
{
    List<int> lastFew; //��������

    cout << jos( people, passes, lastFew ) << endl;
    
    cout << "(Removal order) "; 
    printCollection( lastFew ); //���ú���
}


class CompareList 
{
public:
    bool operator() ( const List<int> & lhs, const List<int> & rhs ) const
    { return lhs.size( ) < rhs.size( ); }  //�Ƚ���������ĳ��ȣ���lhs���ȴ���rhsʱ����false
};

// Call by value, to test copy constructor
void print( const Vector<List<int>> arr )  //��ӡ�����ֵ
{
    int N = arr.size( ); //N����˳���ĳ���
    
    for( int i = 0; i < N; ++i )
    {
        cout << "arr[" << i << "]:";
        
        for( auto x : arr[ i ] )  //ȡarr�е�ֵ�������
            cout << " " << x; 
        
        cout << endl;
    }
}

int main( )
{
    const int N = 20;  //������N
    Vector<List<int>> arr( N ); //����˳������arr
    List<int> lst; //�����������lst
    
    for( int i = N - 1; i > 0; --i ) //��i>0��ʱ��
    {
        lst.push_front( i ); //��i���뵽�����У�ͷ�巨
        arr[ i ] = lst; //��lst���뵽˳�����
    }

    print( arr ); //��ӡ�����е�ֵ
    
    clock_t start = clock( );  //start����Ϊlong����ȡ��ǰʱ��
    std::sort( begin( arr ), end( arr ), CompareList{ } );  //��С��������
    clock_t end = clock( );   //��ȡ��ǰʱ��
    cout << "Sorting time: " << ( end - start ) << endl;  //������г����ö೤ʱ��
    
    print( arr ); //�����ӡ�����е�ֵ
    
    nonsense( 12, 0 );  //���ú���
    nonsense( 12, 1 );
  //  nonsense( 3737, 37 );
    system("pause");
    return 0;
}
