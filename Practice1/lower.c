#include<stdio.h>

char lower(char s){
	
	char h;
	h = s - 'A' + 'a';
	return h;
	
	
}

int main (){
	
	char a = 'A';
	printf("%c", lower(a));
	
}
