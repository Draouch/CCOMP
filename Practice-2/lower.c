#include <stdio.h>

int main(){
	
	char a = 'A';
	printf("%c", lower(&a));
	
	return 0;
	
}

int lower(char *c){

	return *c - 'A' + 'a';
	
}
