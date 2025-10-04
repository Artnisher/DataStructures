#include <stdio.h>

/* functions*/
void texto2 (char letras []);
void texto();
int suma();
float division (float numero1, float numero2);

/*main program*/
int main()
{
	int   resultadoSuma;
    float resultadoDivision;
		
	texto();
	texto2("Hola Mundo");
	
	resultadoSuma = suma();
	resultadoDivision = division(1.3, 1.5);
	printf("el resultado de la suma es: %d\n", resultadoSuma);
	printf("el resultado de la division es: %.2f\n", resultadoDivision);
	return 0;
}

/*functions call*/
/*textos*/
void texto()
{
	printf("hola mundo\n");
}

void texto2(char letras [])
{
	printf("%s\n", letras);
}
/*suma*/
int suma()
{
	int num1,
	    num2,
		 sum = num1 + num2;
	printf("la suma entre %d y %d es: %d\n", num1, num2, sum);
	return sum;
}
/*division*/
float division(float numero1, float numero2)
{
	float resultado = numero1 / numero2;
	printf("el resultado es: %.2f\n", resultado);
	return resultado;
}

