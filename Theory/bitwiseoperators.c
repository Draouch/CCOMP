#include <stdio.h>

int main(){
	
	int a = 12, b = 14, c = -7;
	
	/*AND*/
	
	printf("AND = %d\n", a&b);
	
	/*OR*/
	
	printf("OR = %d\n", a|b);
	
	/*XOR*/
	
	printf("XOR = %d\n", a^b);
	
	/*Complement*/
	
	printf("Complement = %d\n",~a);
	printf("Complement = %d\n",~c);
	
	/*Left Shift*/
	
	printf("Left Shift = %d\n", a<<1);
	
	/*Right Shift*/
	
	printf("Right Shift = %d\n", a>>1);
	
	return 0;
	
}
