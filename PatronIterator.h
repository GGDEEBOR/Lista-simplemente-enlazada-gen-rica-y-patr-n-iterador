#ifndef __PATRONITERATOR__H__
#define __PATRONITERATOR__H__
#include <iostream>
#include "Node.h"

template<typename T>
class PatronIterator{
    public:
        PatronIterator() : current{ nullptr }{}

        PatronIterator( Node<T> *p ) : current{ p } {}

    
        PatronIterator & operator++ (){
            current = current -> getNext();
            return *this;
        } 

        PatronIterator operator++ (int){
            PatronIterator old = *this;
            ++( *this );
            return old;
        }

        bool operator== ( const PatronIterator & p ) const{ 
            return current == p.current;
        }

        bool operator!= ( const PatronIterator & o ) const{ 
            return !( *this == o ); 
        }

        T operator*() const {
            return current-> getElem() ;
        }
    

    private:
        Node<T> *current;

        
};


#endif