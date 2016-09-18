#include<stdio.h>

int len(char s[]){
	
	int i;
	for(i = 0; s[i] != '\0'; i++)
		;
	return i;
}

void reverse(char s[]){
	
	char temp;
	int i = 0;
	int j = len(s) - 1;
	
	for(i = 0, j = len(s) - 1; i < j; i++, j--){
		
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		
	}
	
}

int main() {
	
	char a[] = "Hola";
	
	reverse(a);
	
	printf(a);
	
	return 0;
}
