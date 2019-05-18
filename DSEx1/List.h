#ifndef LIST_H
#define LIST_H

#include <algorithm>
using namespace std;

template <typename Object>  //ObjectΪ�ڵ�������Ļ�����������
class List  //��������ģ�� 
{
  private:    
    // The basic doubly linked list node.
    // Nested inside of List, can be public
    // because the Node is itself private
    struct Node
    {
        Object  data; //������ 
        Node   *prev;  //ָ��ǰһ���ڵ� 
        Node   *next;  //ָ���һ���ڵ� 

        //Ĭ�Ϲ��캯�����ṹ�幹�캯����
        Node( const Object & d = Object{ }, Node * p = nullptr, Node * n = nullptr ) 
          : data{ d }, prev{ p }, next{ n } { }  //��ʼ���ṹ��
        
        Node( Object && d, Node * p = nullptr, Node * n = nullptr )  //Object && d ��ֵ���ã����ܸı�d��ֵ����ͨ����������
          : data{ std::move( d ) }, prev{ p }, next{ n } { }  //std::move() ������ת��Ϊ��ֵ���ã���d�е�ֵת�Ƹ�data��d�б�Ϊ��ֵ
    }; 

  public:
    class const_iterator
    {
      public:
  
        // Public constructor for const_iterator.
        const_iterator( ) : current{ nullptr } //���캯������ʼ���б�
          { }

        // Return the object stored at the current position.
        // For const_iterator, this is an accessor with a
        // const reference return type.

        //��������� 
        const Object & operator* ( ) const  //*��������أ�ȡ��ǰ�ڵ������Ԫ��
          { return retrieve( ); } 
        
        const_iterator & operator++ ( ) //����++
        {
            current = current->next; //��currentָ����һ���ڵ�
            return *this;
        }

        const_iterator operator++ ( int ) //ǰ��++
        {
            const_iterator old = *this; 
            ++( *this );
            return old;
        }

        const_iterator & operator-- ( ) //����--
        {
            current = current->prev;
            return *this;
        }

        const_iterator operator-- ( int ) //ǰ��--
        {
            const_iterator old = *this;
            --( *this );
            return old;
        }
            
        bool operator== ( const const_iterator & rhs ) const //== ���������
          { return current == rhs.current; }

        bool operator!= ( const const_iterator & rhs ) const  // ��= ���������
          { return !( *this == rhs ); }

      protected:
        Node *current; //�������еĽڵ�

        // Protected helper in const_iterator that returns the object
        // stored at the current position. Can be called by all
        // three versions of operator* without any type conversions.
        Object & retrieve( ) const //��ȡ��ǰֵ����������Ϊ����
          { return current->data; }

        // Protected constructor for const_iterator.
        // Expects a pointer that represents the current position.
        const_iterator( Node *p ) :  current{ p } //�趨current��ֵ
          { }
        
        friend class List<Object>;  //������Ԫ��
    };

    class iterator : public const_iterator  //iterator���м̳�const_iterator
    {
      public:

        // Public constructor for iterator.
        // Calls the base-class constructor.
        // Must be provided because the private constructor
        // is written; otherwise zero-parameter constructor
        // would be disabled.
        iterator( ) //��ĳ�ʼ��
          { }

        Object & operator* ( )  //*��������� ��ȡֵ
          { return const_iterator::retrieve( ); }

        // Return the object stored at the current position.
        // For iterator, there is an accessor with a
        // const reference return type and a mutator with
        // a reference return type. The accessor is shown first.
        const Object & operator* ( ) const  //����� * ���أ�ȡֵ����
          { return const_iterator::operator*( ); }
        
        //���������
        iterator & operator++ ( ) //����++
        {
            this->current = this->current->next;  //��thisָ������ֵ
            return *this;
        }

        iterator operator++ ( int ) //ǰ��++
        {
            iterator old = *this;
            ++( *this );
            return old;
        }

        iterator & operator-- ( ) //����--
        {
            this->current = this->current->prev;
            return *this;
        }

        iterator operator-- ( int ) //ǰ��--
        {
            iterator old = *this;
            --( *this );
            return old;
        }

      protected:
        // Protected constructor for iterator.
        // Expects the current position.
        iterator( Node *p ) : const_iterator{ p }  //�вι��캯��
          { }

        friend class List<Object>; //������Ԫ��
    };

  public:
    List( ) //��ĳ�ʼ��
      { init( ); }

    ~List( ) //������
    {
        clear( ); //����clear��������
        //�ͷ��ڴ�
        delete head; 
        delete tail;
    }

    List( const List & rhs ) //�������캯��
    {
        init( );
        //ѭ����rhs��ȡֵ����x
        for( auto & x : rhs ) //auto���Զ������Ƶ������ڴӳ�ʼ�����ʽ���ƶϳ���������������
            push_back( x );  //��x��ֵ���뵽������
    }

    List & operator= ( const List & rhs ) // = ���������
    {
        List copy = rhs; //��rhs�е�ֵ������copy��
        std::swap( *this, copy );  //��copy��thisָ��ı��е�Ԫ�ؽ���
        return *this;
    }

    
    List( List && rhs )  //�������캯������ʼ���б�
      : theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail }
    {
        rhs.theSize = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }
   
    List & operator= ( List && rhs ) // = ���������
    {    
        //������˳����е�ֵ�໥����
        std::swap( theSize, rhs.theSize ); 
        std::swap( head, rhs.head );
        std::swap( tail, rhs.tail );
        
        return *this;
    }
    
    // Return iterator representing beginning of list.
    // Mutator version is first, then accessor version.
    iterator begin( )  //ȡ������Ԫ�ڵ�ĵ�ַ
      { return iterator( head->next ); }

    const_iterator begin( ) const  //�������أ�ȡ������Ԫ�ڵ�
      { return const_iterator( head->next ); }

    // Return iterator representing endmarker of list.
    // Mutator version is first, then accessor version.
    iterator end( ) //ȡ�����βԪ��
      { return iterator( tail ); }

    const_iterator end( ) const  ////�������أ�ȡ�����β�ڵ�
      { return const_iterator( tail ); }

    // Return number of elements currently in the list.
    int size( ) const //��������ĳ���
      { return theSize; }

    // Return true if the list is empty, false otherwise.
    bool empty( ) const  //�ж������Ƿ�Ϊ�գ�Ϊ�շ���true�����շ���false
      { return size( ) == 0; }

    void clear( )  //�������Ԫ��
    //������Ϊ��ʱ��ȡ��Ԫ�ڵ�
    {
        while( !empty( ) ) //����Ϊ��ʱ
            pop_front( ); //ɾ����Ԫ�ڵ�
    }
 
    // front, back, push_front, push_back, pop_front, and pop_back
    // are the basic double-ended queue operations.
    Object & front( ) //ȡ������Ԫ�ڵ㣬��������ֵΪ����
      { return *begin( ); }

    const Object & front( ) const  //�������أ�����ͬ��
      { return *begin( ); }

    Object & back( ) //ȡ��βԪ�أ���������ֵ����Ϊ����
      { return *--end( ); }

    const Object & back( ) const //�������أ�����ͬ��
      { return *--end( ); }

    void push_front( const Object & x ) //����ͷ�巨��Ԫ��x��������
      { insert( begin( ), x ); }

    void push_back( const Object & x ) //β�巨����Ԫ��
      { insert( end( ), x ); }

    void push_front( Object && x )  //ͷ�巨����Ԫ��x
      { insert( begin( ), std::move( x ) ); }

    void push_back( Object && x ) //β�巨��������Ԫ��
      { insert( end( ), std::move( x ) ); }

    void pop_front( )  //ɾ����Ԫ�ڵ�
      { erase( begin( ) ); }

    void pop_back( ) //ɾ����β�ڵ�
      { erase( --end( ) ); }

    // Insert x before itr.
    iterator insert( iterator itr, const Object & x ) //��������Ԫ��
    {
        Node *p = itr.current;  //��������  
        ++theSize;  //���ȼ�һ
        return iterator( p->prev = p->prev->next = new Node{ x, p->prev, p } );
    }

    // Insert x before itr.
    iterator insert( iterator itr, Object && x ) //�������أ�����ͬ��
    {
        Node *p = itr.current;
        ++theSize;
        return iterator( p->prev = p->prev->next = new Node{ std::move( x ), p->prev, p } );
    }
    
    // Erase item at itr.
    iterator erase( iterator itr ) //ɾ�����нڵ�Ϊitr��Ԫ��
    {
        Node *p = itr.current; //��������
        iterator retVal( p->next ); 
        p->prev->next = p->next; //��p��ǰһ���ڵ��next��ָ��p����һ���ڵ�
        p->next->prev = p->prev; //��p����һ���ڵ��prev��ָ��p��ǰһ���ڵ�
        delete p;  //�ͷ�p��ָ��Ŀռ�
        --theSize; //����һ

        return retVal; //����ɾ���Ľڵ����һ���ڵ�
    }

    iterator erase( iterator from, iterator to ) //ɾ�����д�from��to��ȫ���ڵ�
    {
        for( iterator itr = from; itr != to; )
            itr = erase( itr );

        return to;
    }

  private:
    int   theSize;  //������
    Node *head;  //ͷָ��
    Node *tail; //βָ��

    void init( )  //��ʼ������Ԫ�غ���
    {
        theSize = 0;
        head = new Node;  //����ռ�
        tail = new Node;  //����ռ�
        head->next = tail;
        tail->prev = head;
    }
};

//��������
#endif
