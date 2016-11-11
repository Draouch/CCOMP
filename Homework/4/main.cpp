#include <vector>
#include <iostream>

using namespace std;

template<typename K>
class Stack_{

private:
	vector<K> Pila;

public:
	void if_empty();
	K top();
	void push(K x);
	void pop();
	void print();
	friend Stack_ operator+<>(const Stack_ &k1, const Stack_ &k2);

};

#include "stack.cpp"

	int main(){

		Stack_<int> kri, al;
		//Stack_<int> cor = kri + al;
		kri.push(2);
		kri.push(3);
		kri.push(4);
		kri.print();
		al.push(5);
		al.push(6);
		al.push(7);
		al.print();
		//cor.print();

	}

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
