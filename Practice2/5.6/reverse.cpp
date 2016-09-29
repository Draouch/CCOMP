#include<stdio.h>

int len(char s[]){
	
	int n;
	for(n = 0; s[n] != '\0'; n++)
		;
	return n;
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
	
	char a[] = "Maria";
	
	reverse(a);
	
	printf(a);
	
	return 0;
}
