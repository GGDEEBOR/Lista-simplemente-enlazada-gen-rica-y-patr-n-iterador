#ifndef __NODE__H__
#define __NODE__H__
#include <iostream>
using namespace std;

template <typename T>
class Node{
    private: 
        T elem;
        Node<T>* next;
        
    public:
        Node(T&);
        Node();

        // Get
        T& getElem();
        Node<T>* getNext()const;
  
        // Set
        void setElem(T&);
        void setNext(Node<T>*);

};

template <typename T>
// Constructores
Node<T>::Node(T& elem){
    this -> elem = elem;
    this -> next = nullptr;
}
template <typename T>
Node<T>::Node(){
    this -> elem = elem;
    this -> next = next;
}

template <typename T>
T& Node<T>::getElem(){
    return elem;
}
template <typename T>
Node<T>* Node<T>::getNext()const{
    return next;
}

template <typename T>
void Node<T>::setElem(T& elem){
    this -> elem = elem;
}
template <typename T>
void Node<T>::setNext(Node* next){
    this -> next = next;
}

#endif