#include<stdio.h>

void _strcpy(char *src, char *dest) {
	
	while((*dest++ = *src++))
		;

}

int main(){
	
	char s[] = "Hola";
	char t[100];
	
	_strcpy(s, t);
	
	printf(t);
	
	return 0;
	
}
