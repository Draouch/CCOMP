#include<stdio.h>

int strindex(char *s,char *t);

int main(){
	
	char s[] = "anan";
	char t[] = "n";
	
	printf("%d", strindex(s, t));
	
	return 0;
	
}

int strindex(char *s, char *t){
	
	char *a = s;
	char *p, *q;
	
	for(; *s!='\0'; s++){
		
		for(p=s, q=t; *q!='\0' && *p==*q; p++, q++)
			;
		
		if(q>t && *q == '\0')
		   return s-a;
		
	}
	
	return -1;
	
}
