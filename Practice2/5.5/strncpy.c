#include<stdio.h>

void _strncpy(char *s, char *t, int n) {
	
	while(n--)
		  
		  *t++ = *s++;
	
	*t = '\0';
	
}

int main(){
	
	char s[] = "Maria";
	char t[100];
	
	_strncpy(s, t, 3);
	
	printf(t);
	
	return 0;
	
}
