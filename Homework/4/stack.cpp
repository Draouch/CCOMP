#include "stack.h"

template<typename K>
void Stack_<K>::if_empty(){

    if(Pila.empty() == true)

        cout << "La pila esta vacia" << endl;

    else
        cout << "La pila esta llena" << endl;;

}

template<typename K>
K Stack_<K>::top(){

    return Pila.back();

}

template<typename K>
void Stack_<K>::push(K x){

    Pila.push_back(x);

}

template<typename K>
void Stack_<K>::pop(){

    Pila.pop_back();

}

template<typename K>
void Stack_<K>::print(){

    for(unsigned int i=0; i < Pila.size(); i++)
        cout << Pila[i] << " ";
    cout << endl;

}

/*template<typename K>
Stack_<K>::Stack_<K> operator+ (Stack_<K> &k1, Stack_<K> &k2){

    Stack_<K> result = k1;

    for(int i= 0; i<k1.Pila.size(); i++){

        result.Pila.push_back(k2.Pila[i]);

    }

    return result;

}
*/
