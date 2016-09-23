#include <stdio.h>

int len(char *s){
	
	int i;
	
	for(i = 0; *s != '\0'; i++)
		++s;
	
	return i;
}


int _strend(char *s, char *t){
	
	int lt = len(t);
	
	while(*s!='\0')
		  ++s;
	--s;
	
	while(*t!='\0')
		  ++t;
	--t;
	
	for(; lt > 0 && *t == *s; --lt){
		--t;
		--s;
	}
	
	if(lt == 0)
	   return 1;
	else
		return 0;
	
}

int main(){
	
	char s[10] = "HolaMundo";
	char t[7] = "Mundo";
	
	printf("%d", _strend(s, t));
	
	return 0;
}
