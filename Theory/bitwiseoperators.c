#include <stdio.h>

int main(){
	
	int a = 12, b = 14, c = -7;
	/*a = 1100, b = 1110, c = -111*/
	
	----------------------------------------
	
	/*AND*/
	
	printf("AND = %d\n", a&b); /*12*/
	
	/*OR*/
	
	printf("OR = %d\n", a|b); /*14*/
	
	/*XOR*/
	
	printf("XOR = %d\n", a^b); /*2*/
	
	/*Complement*/
	
	printf("Complement = %d\n",~a); /*-13*/
	printf("Complement = %d\n",~c); /*6*/
	
	/*Left Shift*/
	
	printf("Left Shift = %d\n", a<<1); /*24*/
	
	/*Right Shift*/
	
	printf("Right Shift = %d\n", a>>1); /*6*/
	
	return 0;
	
}
