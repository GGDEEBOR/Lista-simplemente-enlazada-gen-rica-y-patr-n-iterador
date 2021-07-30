#include <iostream>
#include "PatronIterator.h" 
#include "LinkedList.h"
#include "Node.h"
using namespace std;

int main(){
    LinkedList<int> a;
    a.push_front(45);
    a.push_front(90);
    a.push_back(1223);
    a.push_back(34);
    a.push_front(6);
    a.push_back(43);
    a.push_front(78);
    cout << endl;
    cout << "Lista inicial de 'a' : " << endl;
    cout << a << endl;
    cout << "------------------------------------------" << endl;

    cout << endl; 
    LinkedList<int> b = move(a);
    cout << endl;
    cout << "Lista inicial de 'b': " << endl;
    cout << b << endl; /*78  6  90  45  1223  34  43*/
    cout << "------------------------------------------" << endl;
    cout << endl;
    cout << "Lista de 'a' despues del movimiento: " << endl;
    cout << a << endl;
    cout << "------------------------------------------" << endl;

    cout << endl;

    LinkedList<int> c = b;

    cout << endl;
    cout << "lista de 'c' despues de la copia: " << endl;
    cout << c << endl;
    cout << "------------------------------------------" << endl;
    cout << "lista de 'b' despues de la  copia: " << endl;
    cout << b << endl;
    cout << "------------------------------------------" << endl;


    cout << "Patron Iterador: " << endl;
    cout << endl;
    for (PatronIterator<int>  it = c.begin(); it != c.end(); it++){
        cout << "Iterador: " << *it  << endl;
    }
    cout << endl;

    return 0;
}