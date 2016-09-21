#include<stdio.h>

void _strncpy(char *s, char *t, int i) {
	
	while(i--)
		  
		  *t++ = *s++;
	
	*t = '\0';
	
}

int main(){
	
	char s[] = "Hola";
	char t[100];
	
	_strncpy(s, t, 2);
	
	printf(t);
	
	return 0;
	
}
