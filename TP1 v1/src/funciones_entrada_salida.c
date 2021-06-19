#include <stdio.h>
#include <stdlib.h>

/**
 * @fn void MenuCalculadora(int, int, int, float, float)
 * @brief //Funcion para mostrar el menu en pantalla. Se le pasa algunas variables que pueden modificar los mensajes a mostrar
 *
 * @param banderaValorA //Si existe valor en A se mostrara un mensaje diferente al por defecto
 * @param banderaValorB //Si existe valor en B se mostrara un mensaje diferente al por defecto
 * @param banderaResultados //Si los resultados ya fueron calculados se mostrara otro mensaje
 * @param valorA //Si banderaValorA es igual a 1 se mostrara junto al mensaje cuanto vale A
 * @param valorB//Si banderaValorB es igual a 1 se mostrara junto al mensaje cuanto vale B
 */
void MenuCalculadora(int banderaValorA, int banderaValorB, int banderaResultados, float valorA, float valorB)
{
	//Dependiendo las banderas de los operandos y los resultados, se mostrara un mensaje diferente
	if(banderaValorA == 0)
	{
		printf("1. Ingresar Primer Operando\n");
	}
	else
	{
		printf("1. Modificar Primer Operando (A = %.2f)\n", valorA);
	}

	if(banderaValorB == 0)
	{
		printf("2. Ingresar Segundo Operando\n");
	}
	else
	{
		printf("2. Modificar Segundo Operando (B = %.2f)\n", valorB);
	}

	if(banderaResultados == 0)
	{
		printf("3. Calcular Operaciones\n");
	}
	else
	{
		printf("3. Calcular Operaciones (OK)\n");
	}

	printf("4. Mostrar Resultados\n");
	printf("5. Salir\n");
}

/**
 * @fn int IngresarOpcion()
 * @brief //Funcion que pide Ingreso de opcion para el Menu
 *
 * @return //Devuelve la opcion seleccionada
 */
int IngresarOpcion()
{
	int opcionSeleccionada;

	printf("Ingrese Opcion: ");
	scanf("%d", &opcionSeleccionada);

	return opcionSeleccionada;
}

/**
 * @fn float IngresarOperando(char)
 * @brief //La funcion recibe un Char, que puede ser A o B.
 * Dependiendo cual sea el caso, se mostrara un mensaje diferente pidiendo el dato,
 * y se pedira el ingreso de un numero con posibilidad de ser decimal
 *
 * @param valor //A o B
 * @return //Revuelve el Numero Ingresado
 */
float IngresarOperando(char valor)
{
	float numeroIngresado;

	if(valor == 'A')
	{
		printf("Por favor Ingrese un valor para el Primer Operando: ");
	}
	else //Si no es A, es B
	{
		printf("Por favor Ingrese un valor para el Segundo Operando: ");
	}
	//Post-Mensaje se pide el numero
	scanf("%f", &numeroIngresado);

	return numeroIngresado;
}

/**
 * @fn void BarraSeparadora(void)
 * @brief //Una funcion sencilla para poder llamar a una Barra Delimitadora
 * y un nuevo renglon a continuacion cada vez que se lo necesite
 *
 */
void BarraSeparadora(void)
{
	printf("--------------------------------\n");
}
