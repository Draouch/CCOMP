#include<stdio.h>

int strindex(char s[],char t[]);

int main(){
	
	char s[] = "anitalavalatina";
	char t[] = "a";
	
	printf("%d", strindex(s, t));
	
}

int strindex(char s[],char t[]){
	
	int i, j, k;
	
	int resul = -1;
	
	for(i=0; s[i]!='\0'; i++){
		
		for(j=0,k=0; t[k]!='\0' && s[j]==t[k]; j++,k++)
			;
		
		if(k>0 && t[k] == '\0')
		   resul = i;
	}
	
	return resul;
}
