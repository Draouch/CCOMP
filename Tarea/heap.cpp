#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector

int main () {
	int myints[] = {1,3,2,4,5,6};
	std::vector<int> v(myints,myints + sizeof(myints)/ sizeof(int));
	
	for (unsigned int i=0; i<v.size(); i++)
		std::cout << ' ' << v[i];
	std::cout << '\n';
	
 	std::make_heap (v.begin(),v.end()); //Mayor adelante
	
	for (unsigned int i=0; i<v.size(); i++)
		std::cout << ' ' << v[i];
	std::cout << '\n';
	
	std::cout << "initial max heap: " << v.front() << '\n';

	std::pop_heap (v.begin(),v.end()); //Mayor al fondo, segundo mayor al frente
	
	for (unsigned int i=0; i<v.size(); i++)
		std::cout << ' ' << v[i];
	std::cout << '\n';
	
	std::cout << "initial max heap: " << v.front() << '\n';
	
	v.pop_back(); //Elimina el ultimo
	
	for (unsigned int i=0; i<v.size(); i++)
		std::cout << ' ' << v[i];
	std::cout << '\n';
	
	std::cout << "max heap after pop : " << v.front() << '\n';
	
	v.push_back(99);
	
	for (unsigned int i=0; i<v.size(); i++)
		std::cout << ' ' << v[i];
	std::cout << '\n';
	
	std::push_heap (v.begin(),v.end());
	
	for (unsigned int i=0; i<v.size(); i++)
		std::cout << ' ' << v[i];
	std::cout << '\n';
	
	std::cout << "max heap after push: " << v.front() << '\n';
	
	std::sort_heap (v.begin(),v.end());
	
	for (int i=0; i<v.size(); i++)
		std::cout << ' ' << v[i];
	std::cout << '\n';
	
	return 0;
}
