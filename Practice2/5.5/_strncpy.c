#include<stdio.h>

void _strncpy(char *src, char *dest, int i) {
	
	while(i--)
			
		*dest++ = *src++;
	
	*dest = '\0';

}

int main(){
	
	char s[] = "Hola";
	char t[100];
	
	_strncpy(s, t, 1);
	
	printf(t);
	
	return 0;
	
}
