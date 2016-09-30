#include <stdio.h>

int _strend(char *s, char *t){
	
	int cont = 0;
	
	for(; *s; s++)
		;
	
	for(; *t; t++)
		cont++;
	
	while(cont != 0){
	
		if(*s == *t){
			cont--;
			t--;
			s--;
		}
	
		else
			return 0;
	
	}
	
	return 1;
}

int main(){
	
	char s[10] = "HolaMundo";
	char t[7] = "Mundo";
	
	printf("%d", _strend(s, t));
	
	return 0;
}
