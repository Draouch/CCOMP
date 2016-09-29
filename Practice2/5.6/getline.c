#include <stdio.h>
#define MAXLINE 100

char line[MAXLINE];

int getline(char *arr, int len){
	
	int l = 0;
	
	while((*arr = getchar()) != '\n' && *arr != EOF && l < MAXLINE)
		arr++, l++;
	
	*arr = '\0';
	
	return 1;
	
}

int main(){
	
	int len=0;
	while((len = getline(line, MAXLINE)) != 0){
		
		printf("Line: %s\nLong: %d\n", line, len);
		
	}
	
	return 0;
	
}
