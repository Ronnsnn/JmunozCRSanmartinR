/*
*	README MULTIPLICACIÓN CLÁSICA
*	Metodologia de la investigación - LCC - DMCC
*	Integrantes:	Joao Munoz C.
*					Ronny San Martín R.
*	Profesor:		Ruben Carvajal S.
*
*/

ARCHIVOS:

La carpeta contiene en total cuatro implementaciones de la multiplicación clásica:
- mui.c 	Multiplicación con arreglos de tipo unsigned int.
- mlong.c 	Multiplicación con arreglos de tipo long long.
- mnueve.c 	Multiplicación con arreglos de tipo long long (de valor 999999999 cada espacio).

Además se encuentran los archivos de prueba (scripts de shell)
- script_mui.sh 	Prueba la implementación mui.c
- script_mlong.sh 	Prueba la implementación mlong.c
- script_mnueve.sh 	Prueba la implementación mnueve.c


COMPILACIÓN Y EJECUCIÓN:

Para compilar individualmente cada código fuente en c, en la consola debe ingresar lo siguiente (sin guion ni comentario entre paréntesis, debe hacerse estando en la carpeta donde se encuentran los programas):
- gcc mui.c -o mui  		(compilación del código fuente mui.c)
- gcc mlong.c -o mlong  	(compilación del código fuente mlong.c)
- gcc mnueve.c -o mnueve 	(compilación del código fuente mnueve.c)

Y se ejecutan de la forma (sin guion ni comentario entreparéntesis, estando en la carpeta donde se encuentran los ejecutables):
- ./mui A B r 		(A y B enteros de largo arbitrario, 'r' fijo)
- ./mlong A B r 	(A y B enteros de largo arbitrario, 'r' fijo)
- ./mnueve C r 	(C entero de largo no mayor a 2^(63)-1, 'r' fijo)

En caso de no querer la impresión del producto obtenido, se deben ejecutar sin el último argumento (siguiendo las mismas especificaciones mencionadas en el punto anterior), o sea:
- ./mui A B
- ./mlong A B
- ./mnueve C

La forma mostrada aquí sólo retorna el tiempo de respuesta; la anterior (con el argumento 'r'), el tiempo de respuesta y el producto en líneas distintas.

Los scripts de prueba deben tener los permisos necesarios, para eso, en la línea de comandos, en la carpeta donde se encuentran los archivos ingrese (sin guion):
- chmod u+x script_mui.sh
- chmod u+x script_mlong.sh
- chmod u+x script_mnueve.sh

Para ejecutar cada uno, respectivamente, ingrese (sin guion y en la carpeta donde se encuentran los archivos):
- ./script_mui.sh
- ./script_mlong.sh
- ./script_mnueve.sh

Cada uno generará un archivo .txt donde se encuentran los tiempos de ejecución pruebas de distinto largo. Puede que el sistema no realice algunas de las pruebas por ser una lista de argumentos demasiado extensa. Los archivos generados irán acumulando los valores de las pruebas realizadas.
Los archivos que genera cada uno (respectivamente) son:
- t_mui.txt
- t_mlong.txt
- t_mnueve.txt
