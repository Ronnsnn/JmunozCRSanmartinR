/*
*	MULTIPLICACION CLASICA
*	Metodologia de la investigacion - LCC - DMCC
*	Integrantes:	Joao Munoz C.
*					Ronny San Martin R.
*	Profesor:		Ruben Carvajal S.
*
*	Resumen:
*		Multiplicacion de dos numeros de largo arbitrario con uso de arreglos de
*		variable long long (bloques de 9 digitos).	
*
*	Compilacion:	gcc mlong.c -o mlong
*	Ejecucion:		./mlong A B r
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

//Convierte un string (numero hexadecimal) en un long long dinamico
void convertir (long long *int_entrada, char *char_entrada, long long largo)
{
	long long i, j, k;
	char aux[10];

	for (i = largo-1, k = 0; i > -1; i -= 9, k++)
	{
		strcpy(aux, "         ");				//aux<--(000000000)
		for (j = 0; i - j > -1 && j < 9; j++)	//modificacion de cada digito de aux
			if(isdigit(char_entrada[i-j]))
				aux[8-j] = char_entrada[i-j];
		int_entrada[k] = (long long) atoll (aux);	//int_entrada[k] <-aux
	}
}

//Multiplicacion de dos numeros de largo arbitrario
void multiplicacion (long long *p, long long *a, long long *b, long long a_len, long long b_len)
{
	long long k, t, i, j;
	
	for (i = 0; i < b_len; i++)
	{
		k = 0;
		for (j = 0; j < a_len; j++)
		{
			t = a[j] * b[i] + p[i + j] + k;	//multiplicacion + acarreo
			p[i + j] = t % 1000000000;		//9 digitos para un solo bloque
			k = t / 1000000000;				//acarreo para el siguiente bloque
		}
		p[i + a_len] = k;
	}
}

int main (int argc, char *argv[])
{
	//Proceso previo (conversion)
	long long bloques_p, *p, i;
	int negativo;
	float t = clock();						//Inicio tiempo

	long long largo_1 = strlen (argv[1]);
	long long largo_2 = strlen (argv[2]);
	long long bloques_1 = techo (1.0 * largo_1 / 9);
	long long bloques_2 = techo (1.0 * largo_2 / 9);
	long long *entr1 = (long long*) calloc (bloques_1, sizeof(long long));
	long long *entr2 = (long long*) calloc (bloques_2, sizeof(long long));
	if ((argv[1][0] == '-' && argv[2][0] == '-') || (argv[1][0] != '-' && argv[2][0] != '-'))
		negativo = 0;
	else
		negativo = 1;
	convertir (entr1, argv[1], largo_1);
	convertir (entr2, argv[2], largo_2);
	bloques_p = bloques_1 + bloques_2;	//tamano del producto
	p = (long long *) calloc (bloques_p, sizeof(long long));
	
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
			printf("%09lld", p[i]);
		printf("\n");
	}
		
	free (entr1);
	free (entr2);
	free (p);

	return 1;
}
