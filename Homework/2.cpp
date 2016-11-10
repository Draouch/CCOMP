#include <iostream>
using namespace std;

//2.2
#define min(x, y) (x < y ? x : y)

//2.1
/*template<typename K>
K min(K k1, K k2){
	
	return k1 < k2 ? k1 : k2;
	
}*/

int main(){
	
	cout << min<int>(2, 4);
	
	return 0;
}
