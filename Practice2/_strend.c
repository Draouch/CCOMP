#include <stdio.h>

int len(char *s){
	
	int i;
	
	for(i = 0; *s != '\0'; i++)
		++s;
	
	return i;
}


int _strend(char s[], char t[]){
	
	int ls;
	int lt;
	
	
	for(ls = len(s), lt = len(t); s[ls-1] == t[lt-1]; ls--, lt--)
		;
	
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
