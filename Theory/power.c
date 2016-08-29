#include <stdio.h>

int main(){
	
	int a;
	
	scanf("%d", &a);
	
	if( a==0 ){
		
		printf("El numero no es potencia de 2.\n");
	
	}else{
		
		if( (a&(a-1)) == 0){
			
			printf("El numero es potencia de 2.\n");
		
		}else{
		
			printf("El numero no es potencia de 2.\n");
		}
	}
	
	return 0;
	
}
