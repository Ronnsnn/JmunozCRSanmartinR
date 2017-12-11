/*
*	MULTIPLICACION CLASICA
*	Metodologia de la investigacion - LCC - DMCC
*	Integrantes:	Joao Munoz C.
*					Ronny San Martin R.
*	Profesor:		Ruben Carvajal S.
*
*	Resumen:
*		Multiplicacion de dos numeros de largo arbitrario con uso de arreglos de
*		variable unsigned int (bloques de 4 digitos).	
*
*	Compilacion:	gcc mui.c -o mui
*	Ejecucion:		./mui A B r
*					(A y B numeros enteros, r es opcional (producto))
*	Salida:			Tiempo de ejecucion en segudos y producto
*					(en caso de ingresar r como tercer argumento).
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


long long techo (double n)
{
	if (n > (long long) n)	return ((long long) n + 1);
	else					return (long long) n;
}

//Convierte un string (numero hexadecimal) en un unsigned int dinamico
void convertir (unsigned int *int_entrada, char *char_entrada, long long largo)
{
	long long i, j, k;
	char aux[5];

	for (i = largo-1, k = 0; i > -1; i -= 4, k++)
	{
		strcpy(aux, "    ");					//aux<--(0000)
		for (j = 0; i - j > -1 && j < 4; j++)	//modificacion de cada digito de aux
			if(isdigit(char_entrada[i-j]))
				aux[3-j] = char_entrada[i-j];
		int_entrada[k] = (unsigned int) atoi (aux);	//int_entrada[k] <-aux
	}
}

//Multiplicacion de dos numeros de largo arbitrario
void multiplicacion (unsigned int *p, unsigned int *a, unsigned int *b, long long a_len, long long b_len)
{
	unsigned int k, t;
	long long i, j;
	
	for (i = 0; i < b_len; i++)
	{
		k = 0;
		for (j = 0; j < a_len; j++)
		{
			t = a[j] * b[i] + p[i + j] + k;	//multiplicacion + acarreo
			p[i + j] = t % 10000;		//4 digitos para un solo bloque
			k = t / 10000;				//acarreo para el siguiente bloque
		}
		p[i + a_len] = k;
	}
}

int main (int argc, char *argv[])
{
	//Proceso previo (conversion)
	long long bloques_p, i;
	unsigned int *p;
	int negativo;
	float t = clock();						//Inicio tiempo

	long long largo_1 = strlen (argv[1]);
	long long largo_2 = strlen (argv[2]);
	long long bloques_1 = techo (1.0 * largo_1 / 4);
	long long bloques_2 = techo (1.0 * largo_2 / 4);
	unsigned int *entr1 = (unsigned int*) calloc (bloques_1, sizeof(unsigned int));
	unsigned int *entr2 = (unsigned int*) calloc (bloques_2, sizeof(unsigned int));
	if ((argv[1][0] == '-' && argv[2][0] == '-') || (argv[1][0] != '-' && argv[2][0] != '-'))
		negativo = 0;
	else
		negativo = 1;

	convertir (entr1, argv[1], largo_1);
	convertir (entr2, argv[2], largo_2);
	bloques_p = bloques_1 + bloques_2;	//tamano del producto
	p = (unsigned int *) calloc (bloques_p, sizeof(unsigned int));
	
	//Algoritmo:
	multiplicacion (p, entr1, entr2, bloques_1, bloques_2);
	//Limpieza ceros a la izquierda y negativo
	while (p[bloques_p - 1] == 0) 	bloques_p -= 1;
	if (negativo)					p[bloques_p - 1] *= -1;

	//Tiempo:
	printf("%0.8f\n",(double)(clock()-t)/CLOCKS_PER_SEC);
	
	//Resultado multiplicacion
	if (argc == 4 && strcmp(argv[3],"r") == 0)
	{
		printf("Resultado: ");
		for (i = bloques_p - 1; i >= 0; i--)
			printf("%04d", p[i]);
		printf("\n");
	}
		
	free (entr1);
	free (entr2);
	free (p);

	return 1;
}
