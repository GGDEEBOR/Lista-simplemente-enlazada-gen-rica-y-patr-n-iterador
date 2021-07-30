#ifndef __LINKEDLIST__H__
#define __LINKEDLIST__H__
#include "PatronIterator.h"
#include "Node.h"
#include <iostream>

template <typename T>
class LinkedList{
    private:
        int size;
        Node<T>* head;

    public:
        // constructor
        LinkedList(T);

        // constructor por defecto
        LinkedList();
        
        // constructor copia
        LinkedList(LinkedList &);

        // constructor de movimiento
        LinkedList(LinkedList && );

        // sobrecarga del operador de asignacion copia
        LinkedList & operator= ( const LinkedList & p ){
            LinkedList<T> copy = p;
            //Node<T>* copy = p;
            std::swap( *this, copy );
            return *this;
         }

        // sobrecarga del operador de asignacion movimiento
        LinkedList & operator= ( LinkedList && o ){
            std::swap( size, o.size );
            std::swap( head, o.head );
            return *this;
         }
         

        // destructor
        ~LinkedList();


        int getSize()const;
        Node<T>* getHead()const;

        void setSize(int);
        void setHead(Node<T>*);

        void push_front(T);
        void push_back(T);
        void insert_by_position(T, int);

        void pop_front();
        void pop_back();
        void removeByPosition(int);



        PatronIterator<T> begin()const;
        PatronIterator<T> end()const;

        // sobrecarga del operador de salida
        friend std::ostream& operator << (std::ostream& output, const LinkedList<T> &o){
            Node<T>* current = o.head;
            while(current){
                output << current->getElem() <<"  ";
                current = current->getNext();
            }
            return output;
        }
};

template <typename T>
// constructores
LinkedList<T>::LinkedList (){
    this -> size = 0;
    this -> head = nullptr;
}
template <typename T>
//constructor parametrizado
LinkedList<T>::LinkedList (T elem){
    this -> size = 1;
    this -> head = new Node<T>(elem);
}

template <typename T>
//constructor copia
LinkedList<T>::LinkedList ( LinkedList<T> &o){
    this -> size = o.size;
    Node<T>* nuevo = o.head;
    while (nuevo != nullptr){
        push_back (nuevo -> getElem());
        nuevo = nuevo -> getNext();
    }
}


template<typename T>
// constructor de movimiento
LinkedList<T>::LinkedList(LinkedList&& o):size{o.size}, head{o.head}{
    o.size = 0;
    o.head = nullptr;
}

template <typename T>
// destructor
LinkedList<T>::~LinkedList(){
    Node<T> *p = head;
    while (p){
        p = head -> getNext();
        delete head;
        head = p;
    }
}

template <typename T>
// get
int LinkedList<T>::getSize()const{
    return size;
}
template <typename T>
Node<T> *LinkedList<T>::getHead()const{
    return head;
}

template <typename T>
// set
void LinkedList<T>::setSize(int size){
    this -> size = size;
}
template <typename T>
void LinkedList<T>::setHead(Node<T> *head){
    this -> head = head;
}


template <typename T>
// Metodo insert al inicio
void LinkedList<T>::push_front(T elem){
	Node<T>* nuevo = new Node<T> (elem);
    Node<T>* aux = head;
    if (!head) {
        head = nuevo;
    }
    else{
        nuevo -> setNext(this->head);
        this -> head = nuevo;      
        while (aux) {
            aux = aux -> getNext();
        }
    } 
    size++;
}


template <typename T>
// Metodo insert al final
void LinkedList<T>::push_back(T elem){
	Node<T>* nuevo = new Node<T> (elem);
    Node<T>* aux = head;
    if (!head) {
        head = nuevo;
    }
    else{
        while (aux->getNext() != nullptr) {
            aux = aux -> getNext();
        }
        aux -> setNext(nuevo);
    }  
    size++;
}


//eliminar al inicio de la lista
template <typename T>
void LinkedList<T>::pop_front(){
	
    Node<T>* current = this->head ;
    this->head = this->head->getNext();
    current->setNext(nullptr);
    delete current;
    this->size--;
}

//eliminar al final de la lista
template <typename T>
void LinkedList<T>::pop_back(){
    if(this->head){
        Node<T>*current = this->head;   
        Node<T>*prev = nullptr;
        
        while(current->getNext()){
            prev = current;
            current = current->getNext();
        }
        if(current == this->head){
            this->head = this->head->getNext();
            delete current;
            this->size--;
        }else{
            prev->setNext(nullptr);
            delete current;
            this->size--;
        }
    }
}


template <typename T>
// Metodo que elimina por posicion
void LinkedList<T>::removeByPosition (int pos){ 
    if (this -> head != nullptr){ 
        Node<T>* aux = head;
        Node<T>* aux1 = aux -> getNext();
        if (pos < 0 || pos > getSize() ) {
            cout << "Error " << endl;
        } 
        else if (pos == 0) {
            head = head -> getNext();
            delete aux;
        } 
        else{
            for (int i = 1; i <= pos; i++) {
                if (i == pos){
                    Node<T>* eliminar = aux1 ;
                    aux -> setNext(aux1 -> getNext());
                    delete eliminar;
                }
                aux = aux -> getNext();
                aux1 = aux1 -> getNext();
		    }
        }
        size--;
    }
    else{
        std::cout <<"No hay nodos "<< std::endl;;
    }
}



template <typename T>
PatronIterator<T>  LinkedList<T>::begin()const{
    PatronIterator<T> itr{this-> head};
    return itr;
}


template <typename T>
PatronIterator<T> LinkedList<T>::end()const{
    PatronIterator<T> itr{};
    return itr;
}



#endif