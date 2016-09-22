/* La funcion _atof convierte una cadena de caracteres s a un double,
acepta entrada del tipo notacion cientifica.
Cuenta como entero, al final lo divide por un contador para hallar la parte decimal.
*/

#include <stdio.h>
#include <ctype.h>

double _atof(char s[]);

int main(){

	char cadena[] = "123.45e-6";
	
	printf("%g", _atof(cadena));
	
	return 0;
	
}

double _atof(char s[]){
	
	double val, power, power_e;
	int i, sign, sign_e, h, exp_e;
	
	for(i = 0; isspace(s[i]); i++)          /* Verificamos si hay espacios */
		;
	
	sign = (s[i] == '-') ? -1 : 1;			/* Definimos el signo */
	
	if(s[i] == '+' || s[i] == '-')          /* Determinamos si hay o no signo */
		i++;
	
	for(val = 0.0; isdigit(s[i]); i++)      /* Detectamos los digitos de la parte entera */
		val = 10.0 * val + (s[i] - '0');
	
	if(s[i] == '.')
		i++;
	
	for(power = 1.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');    /* Contador que inicia a partir del punto,*/
		power *= 10.0;                      /* Establece cuales son los decimales.*/
	}
	
	if(s[i] == 'e' || s[i] == 'E')
		i++;
	
	sign_e = (s[i] == '-') ? -1 : 1;
	
	if(s[i] == '+' || s[i] == '-')
		i++;
	
	for(exp_e = 0.0; isdigit(s[i]); i++)     /* Almacena el valor del exponente de "e" en exp_e*/
		exp_e = 10.0 * exp_e + (s[i] - '0');
			
	for(h = 0, power_e = 1; h < exp_e; h++)    /* La cantidad por la cual se divide o multiplica el resultado final */
		power_e *= 10;
			
	if(sign_e == 1)
		return sign * val * power_e / power;
	else
		return sign * val / (power * power_e);
		
}
