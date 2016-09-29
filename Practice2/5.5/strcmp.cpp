#include <stdio.h>

int _strcmp(char *s, char *t, int n){
	
	for(; *s == *t; s++, t++){
		
		if(*s == '\0' || --n <=0)
		   
		   return 0;
		
	}
	
	return *s - *t;
	
}

int main(){
	
	char s[] = "Hol";
	char t[] = "Hon";
	
	printf("%d", _strcmp(s, t, 3));
	
	return 0;
}
