#include <stdio.h>
#include <ctype.h>

int _atoi(char *s){
	
	int n, sign;
	
	for(;isspace(*s);s++)   
		;
	sign = ( *s =='-')? -1:1;
	
	if(*s=='+' || *s=='-')
	   s++;
	
	for(n=0;isdigit(*s);s++)
		n = 10 *n + *s - '0';
	
	return sign * n;
	
}

int main(){
	
	char s[10] = "-1564";
	printf("%d", _atoi(s));
	
	return 0;
	
}
