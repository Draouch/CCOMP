#include <stdio.h>

void *_strcat(char *s, char *t){
	
	while(*s)
		++s;

	while(*s++ = *t++)
		;
	
	return 0;
}

int main(){
	
	char s[10] = "Hola ";
	char t[7] = "Mundo";
	
	_strcat(s, t);
	
	printf(s);
	
	return 0;
}
