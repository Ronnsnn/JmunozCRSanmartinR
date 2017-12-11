/*
*	MULTIPLICACION CLASICA
*	Metodologia de la investigacion - LCC - DMCC
*	Integrantes:	Joao Munoz C.
*					Ronny San Martin R.
*	Profesor:		Ruben Carvajal S.
*
*	Resumen:
*		Multiplicacion de dos numeros de largo arbitrario con uso de arreglos de
*		variable long long cuyo valor se compone solamente de nueves (bloques de
*		9 digitos).	
*
*	Compilacion:	gcc mnueve.c -o mnueve
*	Ejecucion:		./mnueve L r
*					(L numero entero positivo, corresponde al largo de la entrada,
*					r es opcional (producto)).
*	Salida:			Tiempo de ejecucion en segudos y producto
*					(en caso de ingresar r como tercer argumento).
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


//Convierte un string (numero hexadecimal) en un long long dinamico
void crear (long long *n_factor, long long largo)
{
	long long i;
	for (i = 0; i < largo; i++)
		n_factor[i] = 999999999;	//int_entrada[k] <-aux
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
	unsigned long long bloques_p, i;
	long long largo;
	long long *p;
	largo = atoll (argv[1]);
	float t = clock();						//Inicio tiempo

	long long *entr1 = (long long*) calloc (largo, sizeof(long long));
	long long *entr2 = (long long*) calloc (largo, sizeof(long long));
	crear (entr1, largo);
	crear (entr2, largo);
	bloques_p = 2 * largo;	//tamano del producto
	p = (long long *) calloc (bloques_p, sizeof(long long));
	
	//Algoritmo:
	multiplicacion (p, entr1, entr2, largo, largo);

	//Tiempo:
	printf("%0.8f\n",(double)(clock()-t)/CLOCKS_PER_SEC);
	
	//Resultado multiplicacion
	if (argc == 3 && strcmp(argv[2],"r") == 0)
	{
		printf("Resultado: ");
		for (i = bloques_p; i > 0; i--)
			printf("%09lld", p[i - 1]);
		printf("\n");
	}
		
	free (entr1);
	free (entr2);
	free (p);

	return 1;
}
