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



#include <string.h>

struct Customer {
    char  name[50];
    float amount;
    int   priority;
};

/* 
   Ordena los clientes por nombre (A-Z)
   Si los nombres son iguales, desempata por prioridad (1-3)
*/
void sort_customers_by_name(struct Customer *customer_list, int total_customers)
{
    struct Customer temp_customer;  // variable temporal para intercambiar registros

    for (int current_index = 0; current_index < total_customers - 1; current_index++)
    {
        for (int next_index = current_index + 1; next_index < total_customers; next_index++)
        {
            int name_comparison = strcmp(customer_list[current_index].name,
                                         customer_list[next_index].name);

            // Si el nombre actual va después alfabéticamente, o es igual pero prioridad mayor, intercambiamos
            if (name_comparison > 0 ||
               (name_comparison == 0 && customer_list[current_index].priority > customer_list[next_index].priority))
            {
                temp_customer = customer_list[current_index];
                customer_list[current_index] = customer_list[next_index];
                customer_list[next_index] = temp_customer;
            }
        }
    }
}
