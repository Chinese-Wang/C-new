#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "dsexceptions.h"


//˳���Ŷģ���ඨ��
template <typename Object>
class Vector
{
  public:
    explicit Vector( int initSize = 0 ) //��ʾ�������캯������ֹ��ֹ�๹�캯������ʽ�Զ�ת��
      : theSize{ initSize }, theCapacity{ initSize + SPARE_CAPACITY }
      { objects = new Object[ theCapacity ]; }  //��ĳ�ʼ��
      
    Vector( const Vector & rhs )  //�������캯��
      : theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ nullptr }
    { 
        objects = new Object[ theCapacity ]; //��������ռ䣬����ΪtheCapacity
        for( int k = 0; k < theSize; ++k ) //����rhs�е�ֵ
            objects[ k ] = rhs.objects[ k ];
    }
    
    Vector & operator= ( const Vector & rhs )  //���������
    {
        Vector copy = rhs;  //���ÿ������캯��
        std::swap( *this, copy );  //��this��ֵ��copy��ֵ����
        return *this; 
    }
    
    ~Vector( )  //����˳���
      { delete [ ] objects; }

    Vector( Vector && rhs )  //���ع��캯�������ú󣬺�һ��˳���Ϊ��
      : theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ rhs.objects }
    {
        rhs.objects = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
    }
   
    Vector & operator= ( Vector && rhs ) //��������� ������ǰ������˳����ֵ
    {    
        std::swap( theSize, rhs.theSize );
        std::swap( theCapacity, rhs.theCapacity );
        std::swap( objects, rhs.objects );
        
        return *this;
    }
    
    bool empty( ) const //�ж�˳����Ƿ�Ϊ�գ�Ϊ�շ���true
      { return size( ) == 0; }
    int size( ) const  //����˳���ĳ���
      { return theSize; }
    int capacity( ) const //����˳������󳤶�
      { return theCapacity; }

    Object & operator[]( int index ) //��������أ�����˳����±�Ϊindex��Ԫ��ֵ
    {
                                                     #ifndef NO_CHECK
        if( index < 0 || index >= size( ) )  //�ж�indexֵ�Ƿ�Խ��
            throw ArrayIndexOutOfBoundsException{ };
                                                     #endif
        return objects[ index ]; 
    }

    const Object & operator[]( int index ) const  //��������أ�����ͬ�ϣ���������Ϊ������
    {
                                                     #ifndef NO_CHECK
        if( index < 0 || index >= size( ) ) //�ж�indexֵ�Ƿ����
            throw ArrayIndexOutOfBoundsException{ };
                                                     #endif
        return objects[ index ];
    }

    void resize( int newSize ) //��˳����������
    {
        if( newSize > theCapacity ) //�ж��µ�˳����С�Ƿ񳬹�ԭ˳������󳤶�
            reserve( newSize * 2 );  //���ú�����˳���������ݣ�����ԭ˳����ֵ������������
        theSize = newSize;
    }

    void reserve( int newCapacity ) //˳��������
    {
        if( newCapacity < theSize ) //�ж��µ�˳������Ƿ񳬹�ԭ˳����С
            return;

        Object *newArray = new Object[ newCapacity ]; //�����µ�����ռ�
        for( int k = 0; k < theSize; ++k ) //��ԭ˳����ֵ�������µ�˳���
            newArray[ k ] = std::move( objects[ k ] );

        theCapacity = newCapacity; //˳������󳤶ȵ����¿��ٿռ�ĳ���
        std::swap( objects, newArray ); //������ָ�뽻��ֵ
        delete [ ] newArray; //�ͷ�ԭ����Ŀռ�
    }

      // Stacky stuff
    void push_back( const Object & x ) //��x���뵽˳�����
    {
        if( theSize == theCapacity ) //�ж�˳����Ƿ���
            reserve( 2 * theCapacity + 1 ); //���˳������������˳����������
        objects[ theSize++ ] = x; //��x���뵽˳����β
    }
      // Stacky stuff
    void push_back( Object && x ) //�������أ�����ͬ��
    {
        if( theSize == theCapacity )
            reserve( 2 * theCapacity + 1 );
        objects[ theSize++ ] = std::move( x );
    }

    void pop_back( ) //ɾ��˳������һ��Ԫ��
    {
        if( empty( ) ) //�ж�˳����Ƿ�Ϊ��
            throw UnderflowException{ }; //�׳��쳣
        --theSize; //˳����±��һ
    }

    const Object & back ( ) const //ȡ˳������һ��Ԫ��ֵ
    {
        if( empty( ) ) //�ж��Ƿ�Ϊ��
            throw UnderflowException{ }; //�׳��쳣
        return objects[ theSize - 1 ]; //����˳������һ��Ԫ��ֵ
    }

      // Iterator stuff: not bounds checked
    typedef Object * iterator;  //ΪObject���������
    typedef const Object * const_iterator; 

    iterator begin( )  //ȡ˳����һ��Ԫ��
      { return &objects[ 0 ]; }
    const_iterator begin( ) const //�������أ�����ͬ�ϣ���������Ϊ����������
      { return &objects[ 0 ]; }
    iterator end( ) //ȡ�������һ��Ԫ��
      { return &objects[ size( ) ]; }
    const_iterator end( ) const //�������أ�����ͬ�ϣ���������Ϊ����������
      { return &objects[ size( ) ]; }

    static const int SPARE_CAPACITY = 2; //��̬����

  private:
    //����Ԫ��
    int theSize;  //˳���ʵ�ʳ���  
    int theCapacity; //˳�����󳤶�
    Object * objects;  //����ָ��
};

#endif
