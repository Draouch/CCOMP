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
