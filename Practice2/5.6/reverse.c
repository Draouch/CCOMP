#include<stdio.h>

int len(char s[]){
	
	int i;
	for(i = 0; s[i] != '\0'; i++)
		;
	return i;
}

void reverse(char *s){
	
	int c;
	char *temp;
	
	for(temp = s+(len(s)-1); s <= temp; s++, temp--){
		
		c = *s;
		*s = *temp;
		*temp = c;
		
	}
}

int main() {
	
	char a[] = "Hola";
	
	reverse(a);
	
	printf(a);
	
	return 0;
}
