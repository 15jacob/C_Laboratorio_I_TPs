#include <stdio.h>
#include <stdlib.h>


/**
 * @fn float Sumar(float, float)
 * @brief //La funcion recibe ambos operandos y devuelve la suma A + B
 *
 * @param valorA //Primer Operando
 * @param valorB //Segundo Operando
 * @return //Resultado de la Suma
 */
float Sumar(float valorA, float valorB)
{
	float resultadoSuma;
	resultadoSuma = valorA + valorB;

	return resultadoSuma;
}

/**
 * @fn float Restar(float, float)
 * @brief //La funcion recibe ambos operandos y devuelve la resta A - B
 *
 * @param valorA //Primer Operando
 * @param valorB //Segundo Operando
 * @return //Resultado de la Resta
 */
float Restar(float valorA, float valorB)
{
	float resultadoResta;
	resultadoResta = valorA - valorB;

	return resultadoResta;
}

/**
 * @fn float Multiplicar(float, float)
 * @brief //La funcion recibe ambos operandos y devuelve la multiplicacion A * B
 *
 * @param valorA //Primer Operando
 * @param valorB //Segundo Operando
 * @return //Resultado de la Multiplicacion
 */
float Multiplicar(float valorA, float valorB)
{
	float resultadoMultiplicacion;
	resultadoMultiplicacion = valorA * valorB;

	return resultadoMultiplicacion;
}

/**
 * @fn float Dividir(float, float)
 * @brief //La funcion recibe ambos operandos y devuelve la division A / B en tanto B no sea igual a 0
 *
 * @param valorA //Primer Operando
 * @param valorB //Segundo Operando
 * @return //Resultado de la Division
 */
float Dividir(float valorA, float valorB)
{
	float resultadoDivision;

	if(valorB != 0)
	{
		resultadoDivision = valorA / valorB;
	}
	else
	{
		resultadoDivision = 0;
	}

	return resultadoDivision;
}

/**
 * @fn int Factorial(float)
 * @brief //La funcion recibe un operando y determina si el numero es menor que 13 y mayor que 0.
 * Despues determina si es un decimal, por medio de un int auxiliar que toma el valor del float.
 * Si la resta entre ambos no es igual a 0, la funcion sabra que el numero ingresado es un decimal
 *
 * @param valorA //Primer Operando
 * @return //Resultado Factorial //Devuelve 0 si es un numero Decimal //Devuelve -1 si es un numero mayor que 12 o menor a 0
 */
int Factorial(float valor)
{
	int enteroDelFloat;
	int resultadoFactorial;
	int i;

	if(valor < 13 && valor >= 0)
	{
		enteroDelFloat = valor;
		resultadoFactorial = valor;

		if(enteroDelFloat - valor == 0)
		{
			for(i = valor - 1;i != 0; i--)
			{
				resultadoFactorial *= i;
			}
		}
		else
		{
			resultadoFactorial = 0;
		}
	}
	else
	{
		resultadoFactorial = -1;
	}

	return resultadoFactorial;
}
