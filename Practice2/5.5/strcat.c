#include <stdio.h>

void _strcat(char *s, char *t, int n){
	
	while(*s)
		  ++s;
	
	while(n--)
		  *s++ = *t++;

}

int main(){
	
	char s[10] = "Hola ";
	char t[7] = "Maria";
	
	_strcat(s, t, 2);
	
	printf(s);
	
	return 0;
}
