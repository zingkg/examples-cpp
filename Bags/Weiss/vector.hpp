#ifndef _VECTOR_HPP
#define _VECTOR_HPP
#include <cstddef> // for NULL

// This is Weiss Code

class ArrayIndexOutOfBounds { };

template <class Object>
class Vector
{
  public:
    explicit Vector( int theSize = 0 ) : currentSize( theSize )
      { objects = new Object[ currentSize ]; }
    Vector( const Vector & rhs ) : objects( NULL )
      { operator=( rhs ); }
    ~Vector( )
      { delete [ ] objects; }

    int size( ) const
      { return currentSize; }

    Object & operator[]( int index )
    {
    #ifndef NO_CHECK
        if( index < 0 || index >= currentSize )
            throw ArrayIndexOutOfBounds( );
    #endif
        return objects[ index ];
    }

    const Object & operator[]( int index ) const
    {
                                                     #ifndef NO_CHECK
        if( index < 0 || index >= currentSize )
            throw ArrayIndexOutOfBounds( );
                                                     #endif
        return objects[ index ];
    }


    const Vector & operator = ( const Vector & rhs );
    void resize( int newSize );
  private:
    int currentSize;
    Object * objects;
};

#endif


