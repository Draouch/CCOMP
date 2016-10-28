#include <algorithm>
#include <iostream>
#include <list>

int main()
{

	std::list<int> Lista = { 7, 5, 16, 8 };
	
	Lista.push_front(25);
	
	Lista.push_back(13);
	
	if (find(Lista.begin(), Lista.end(), 16) != Lista.end()) {
		Lista.insert(find(Lista.begin(), Lista.end(), 16), 42);
	}
	
	
	for (int n : Lista) {
		std::cout << n << '\n';
	}
}
