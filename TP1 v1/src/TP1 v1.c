//Jacob Cristopher 1F | TP1 - Programacion I

#include <stdio.h>
#include <stdlib.h>
#include "funciones_entrada_salida.h"
#include "funciones_matematicas.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcionSeleccionada;

	//Operandos
	float valorA;
	float valorB;

	//Resultados
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	int resultadoFactorialA;
	int resultadoFactorialB;

	//Banderas
	int banderaValorA;
	int banderaValorB;
	int banderaResultados;

	banderaValorA = 0;
	banderaValorB = 0;
	banderaResultados = 0;

	printf("Jacob Cristopher 1F | TP1 - Programacion I\n");
	BarraSeparadora();

	do
	{
		fflush(stdin);
		printf("MENU PRINCIPAL\n");

		MenuCalculadora(banderaValorA, banderaValorB, banderaResultados, valorA, valorB);
		BarraSeparadora();
		opcionSeleccionada = IngresarOpcion();

		switch(opcionSeleccionada)
		{
			case 1:
				system("cls");

				valorA = IngresarOperando('A');
				banderaValorA = 1;
				//Si se llegara a modificar el valor del operando despues de calcular los resultados, la bandera de resultados vuelve a ser 0
				banderaResultados = 0;

				BarraSeparadora();
				break;
			case 2:
				system("cls");

				valorB = IngresarOperando('B');
				banderaValorB = 1;
				//Si se llegara a modificar el valor del operando despues de calcular los resultados, la bandera de resultados vuelve a ser 0
				banderaResultados = 0;

				BarraSeparadora();
				break;
			case 3:
				system("cls");

				if(banderaValorA == 1 && banderaValorB == 1)
				{
					resultadoSuma = Sumar(valorA, valorB);
					resultadoResta = Restar(valorA, valorB);
					resultadoMultiplicacion = Multiplicar(valorA, valorB);
					resultadoDivision = Dividir(valorA, valorB);
					resultadoFactorialA = Factorial(valorA);
					resultadoFactorialB = Factorial(valorB);
					banderaResultados = 1;

					printf("Calculos realizados con exito!\n");
				}
				else
				{
					printf("Parece que todavia no ingresaste todos los datos necesarios\n");

					if(banderaValorA == 0)
					{
						valorA = IngresarOperando('A');
						banderaValorA = 1;
					}

					if(banderaValorB == 0)
					{
						valorB = IngresarOperando('B');
						banderaValorB = 1;
					}
				}

				BarraSeparadora();
				break;
			case 4:
				system("cls");

				if(banderaResultados == 1)
				{
					printf("Primer Operando = %.2f\n", valorA);
					printf("Segundo Operando = %.2f\n", valorB);
					BarraSeparadora();

					printf("El resultado de la Suma es: %.2f\n", resultadoSuma);
					printf("El resultado de la Resta es: %.2f\n", resultadoResta);
					printf("El resultado de la Multiplicacion es: %.2f\n", resultadoMultiplicacion);

					if(valorB != 0)
					{
						printf("El resultado de la Division es: %.2f\n", resultadoDivision);
					}
					else
					{
						printf("No se puede dividir por 0\n");
					}

					if(resultadoFactorialA > 0)
					{
						printf("El resultado del Factorial del Primer Operando es: %d\n", resultadoFactorialA);
					}
					else
					{
						if(resultadoFactorialA == 0)
						{
							printf("No se puede sacar factorial del Primer Operando porque es un decimal\n");
						}
						else
						{
							printf("Esta calculadora no puede calcular factorial de numeros mayores a 12 ni menores a 1\n");
						}
					}

					if(resultadoFactorialB > 0)
					{
						printf("El resultado del Factorial del Segundo Operando es: %d\n", resultadoFactorialB);
					}
					else
					{
						if(resultadoFactorialB == 0)
						{
							printf("No se puede sacar factorial del Segundo Operando porque es un decimal\n");
						}
						else
						{
							printf("Esta calculadora no puede calcular factorial de numeros mayores a 12 ni menores a 1\n");
						}
					}
				}
				else
				{
					printf("Parece que todavia no hay resultados! Asegurate de hacer los calculos primero desde la opcion 3\n");
				}

				BarraSeparadora();
				break;
			case 5:
				//Salida del Programa
				return EXIT_SUCCESS;
				break;
			default:
				//Error
				printf("Numero ingresado erroneo. Reingrese\n");
				BarraSeparadora();
				break;
		}
	}
	//La unica forma de salir del programa es seleccionando 5
	while(opcionSeleccionada != 5);
}
