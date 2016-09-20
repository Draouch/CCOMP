#include<stdio.h>

int len(char *s){
	
	int i;
	
	for(i = 0; *s != '\0'; i++)
		++s;
	
	return i;
}

void reverse(char s[], int i){
	
	int temp, j;
	
	j = len(s) - (i + 1);
	
	if( i < j ){
		
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		
		reverse(s, ++i);
		
	}
	
}

int main(){
	
	char s[] = "Hola";
	
	reverse(s, 0);
	
	printf(s);
	
	return 0;
	
}
