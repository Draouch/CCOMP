#include <stdio.h>

void _strncat(char *s, char *t, int i){
	
	while(*s)
		  ++s;
	
	while(i--)
		*s++ = *t++;
	
	*t = '\0';
}

int main(){
	
	char s[10] = "Hola ";
	char t[7] = "Mundo";
	
	_strncat(s, t, 1);
	
	printf(s);
	
	return 0;
}
