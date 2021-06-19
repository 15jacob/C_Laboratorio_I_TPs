#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "listing.h"
#include "input.h"

//--------------------------------------------------//

/**
 * Pide el Ingreso de un Entero para seleccionar como opcion
 * @return
 */
int input_option(int* opcion)
{
	int respuesta;

	printf("Ingrese Opcion: ");
	respuesta = input_unsigned_int(opcion, 0);

	return respuesta;
}

/**
 * Recibe un puntero a numero y la cantidad de reintentos disponibles
 * @param numero
 * @param reintentos
 * @param pValidacion
 * @return
 */
int input_unsigned_int(int* numero, int reintentos)
{
	int respuesta;
	respuesta = -1;

	int numeroIngresado;
	int i;

	for(i = reintentos; i >= 0; i--)
	{
		if(validation_int(&numeroIngresado) == 1 && numeroIngresado >= 0)
		{
			*numero = numeroIngresado;
			respuesta = 1;
			break;
		}
		else
		{
			intentos_restantes(&i);
		}
	}

	return respuesta;
}

/**
 * Valida un Int ante los siguientes casos:
 * -Ingreso de un Caracter o String
 * -Ingreso de un Numero seguido de cualquier caracter y o string
 * @param numeroValidar
 * @return
 */
int validation_int(int* numeroValidar)
{
	int respuesta;
	respuesta = -1;

	char checker;//Se usa para corrobororar que seguido al numero no haya algun caracter

	fflush(stdin);
	if(scanf("%d%c", numeroValidar, &checker) == 2 && checker == '\n')
	{
		respuesta = 1;
	}

	return respuesta;
}

/**
 * Recibe un puntero a char y la cantidad de reintentos disponibles
 * @param caracter
 * @return
 */
int input_char(char* caracter, int reintentos)
{
	int respuesta;
	respuesta = -1;

	char caracterIngresado;
	int i;

	for(i = reintentos; i >= 0; i--)
	{
		if(validation_char(&caracterIngresado) == 1)
		{
			*caracter = caracterIngresado;
			respuesta = 1;
			break;
		}
		else
		{
			intentos_restantes(&i);
		}
	}

	return respuesta;
}

/**
 * Valida un Char ante los siguientes casos:
 * Ingreso de un caracter especial
 * @param charValidar
 * @return
 */
int validation_char(char* charValidar)
{
	int respuesta;
	respuesta = -1;

	fflush(stdin);
	if(scanf("%c", charValidar) == 1 && isalpha(*charValidar))
	{
		respuesta = 1;
	}

    return respuesta;
}

/**
 * Recibe un puntero a char y la cantidad de reintentos disponibles
 * @param string
 * @param reintentos
 * @return
 */
int input_string_no_special_char(char* string, int reintentos)
{
	int respuesta;
	respuesta = 0;

	char stringIngresado[128];
	int i;

	for(i = reintentos; i >= 0; i--)
	{
		if(validation_string_no_special_char(stringIngresado) == 1)
		{
			strcpy(string, stringIngresado);
			respuesta = 1;
			break;
		}
		else
		{
			intentos_restantes(&i);
		}
	}

	return respuesta;
}

/**
 * Valida un String ante los siguientes casos:
 * Ingreso de Numeros en la Cadena
 * Ingreso de Caracteres especiales en la cadena
 * @param stringValidar
 * @return
 */
int validation_string_no_special_char(char* stringValidar)
{
	int respuesta;
	respuesta = -1;

	int i;
	int contador;
	contador = 0;

	fflush(stdin);
	if(scanf("%s", stringValidar) == 1)
	{
		for(i = 0; i < strlen(stringValidar); i++)
		{
			if(isalpha(stringValidar[i]) == 0 || isspace(stringValidar[i]) == 1)
			{
				contador++;
			}
		}
	}

	//Si no se encuentran caracteres especiales se devuelve un 1;
	if(contador == 0)
	{
		respuesta = 1;
	}

	return respuesta;
}

/**
 * Muestra los intentos restantes
 * @param reintentos
 */
void intentos_restantes(int* reintentos)
{
	if(*reintentos > 0)
	{
		printf("Se han ingresado caracteres invalidos, reingrese (%d intentos restantes)\n", *reintentos);
	}
	else
	{
		printf("Se han ingresado caracteres invalidos\n");
	}
}

//--------------------------------------------------//

/**
 * Muestra un Empleado y pregunta una confirmacion para borrarlo
 * @param this
 * @param reintentos
 * @return
 */
int input_employee_confirmation(Employee* this, int reintentos)
{
	int respuesta;
	char confirmacion;

    show_employee(this);
    printf("¿Esta seguro que desea continuar? (S/N): ");
    respuesta = input_char(&confirmacion, 2);

    return respuesta;
}

/**
 * Valida una confirmacion por medio de un Char (S/N). Devuelve 1 si es un Si. Devuelve 0 Si es un No.
 * @param confirmacionValidar
 * @return
 */
int validation_confirmation(char* confirmacionValidar)
{
	int respuesta;
	respuesta = -1;

	*confirmacionValidar = tolower(*confirmacionValidar);
	if(*confirmacionValidar == 's')
	{
		respuesta = 1;
	}
	else
	{
		if(*confirmacionValidar == 'n')
		{
			respuesta = 0;
		}
	}

	return respuesta;
}

//--------------------------------------------------//

int menu_employee_modification(LinkedList* pArrayListEmployee, Employee* this, int* id, int* posicionEmpleado)
{
	int respuesta;
	respuesta = 0;

	int opcionSeleccionada;

	char nombreAux[128];
	int horasTrabajadasAux;
	int sueldoAux;

	int checkerDato; //Se utiliza para conocer si un dato se ha ingresado correctamente o no
	int banderaNombre;
	int banderaHoras;
	int banderaSueldo;

	banderaHoras = 0;
	banderaNombre = 0;
	banderaSueldo = 0;

	do
	{
		fflush(stdin);

		printf("MODIFICAR DATOS DE EMPLEADO Nº%d\n", *id);
		printf("1. Seleccionar Otro Empleado\n");

		if(banderaNombre == 1)
		{
			printf("2. Modificar Nombre*\n");
		}
		else
		{
			printf("2. Modificar Nombre\n");
		}

		if(banderaHoras == 1)
		{
			printf("3. Modificar Horas Trabajadas*\n");
		}
		else
		{
			printf("3. Modificar Horas Trabajadas\n");
		}

		if(banderaSueldo == 1)
		{
			printf("4. Modificar Haberes*\n");
		}
		else
		{
			printf("4. Modificar Haberes\n");
		}

		printf("5. Confirmar Cambios\n");
		printf("6. Volver al Menu Anterior\n");

		if(banderaNombre == 1 || banderaHoras == 1 || banderaSueldo == 1)
		{
			printf("*Campos Modificados Aguardando Confirmacion (Opcion Nº5)\n");
		}

		opcionSeleccionada = 0;
		input_option(&opcionSeleccionada);

		if(opcionSeleccionada != -1)
		{
			switch(opcionSeleccionada)
			{
				case 1:
					respuesta = -1;
					break;

				case 2:
					printf("Ingrese el nuevo nombre del empleado:\n");
					checkerDato = input_string_no_special_char(nombreAux, 2);

					switch(checkerDato)
					{
						case 0:
							printf("No se ha ingresado un nombre correcto\n");
							break;

						case 1:
							banderaNombre = employee_setNombre(this, nombreAux);

							if(banderaNombre == 1)
							{
								printf("Nombre ingresado correctamente\n");
							}

							break;
					}

					break;

				case 3:
					printf("Ingrese la nueva cantidad de horas trabajadas del empleado:\n");
					checkerDato = input_unsigned_int(&horasTrabajadasAux, 2);

					switch(checkerDato)
					{
						case 0:
							printf("No se ha ingresado una cantidad correcta\n");
							break;

						case 1:
							banderaHoras = employee_setHorasTrabajadas(this, horasTrabajadasAux);

							if(banderaHoras == 1)
							{
								printf("Horas trabajadas ingresadas correctamente\n");
							}

							break;
					}

					break;

				case 4:
					printf("Ingrese la nueva remuneracion del empleado:\n");
					checkerDato = input_unsigned_int(&sueldoAux, 2);

					switch(checkerDato)
					{
						case 0:
							printf("No se ha ingresado un sueldo correcto\n");
							break;

						case 1:
							banderaSueldo = employee_setSueldo(this, sueldoAux);

							if(banderaSueldo == 1)
							{
								printf("Haberes ingresados correctamente\n");
							}

							break;
					}

					break;

				case 5:
					if(banderaNombre == 1 || banderaHoras == 1 || banderaSueldo == 1)
					{
						printf("Nuevos datos del empleado\n");
						checkerDato = input_employee_confirmation(this, 2);

						if(checkerDato == 1)
						{
							respuesta = 1;
							ll_set(pArrayListEmployee, *posicionEmpleado, this);
							opcionSeleccionada = 6;//Fuerza la salida del submenu
						}
					}
					else
					{
						printf("No hay cambios a la espera de ser confirmados\n");
					}

					break;

				case 6:
					printf("Volviendo al Menu Principal...\n");
					break;

				default:
					printf("Esa opcion es incorrecta. Intente nuevamente\n");
					break;
			}
			system("pause");
		}
	}
	while(opcionSeleccionada != 6);

	return respuesta;
}

int menu_sort_employees(LinkedList* pArrayListEmployee, int len)
{
	int respuesta;
	respuesta = 1;

	int opcionSeleccionada;

	do
	{
		fflush(stdin);

		printf("MENU ORDENAMIENTO\n");
		printf("1. Ordenar empleados por ID\n");
		printf("2. Ordenar empleados por Nombre\n");
		printf("3. Ordenar empleados por Horas Trabajadas\n");
		printf("4. Ordenar empleados por Sueldo\n");
		printf("5. Volver al Menu Anterior\n");

		opcionSeleccionada = 0;
		input_option(&opcionSeleccionada);

		if(opcionSeleccionada != -1)
		{
			switch(opcionSeleccionada)
			{
				case 1:
					printf("Aguarde unos momentos por favor...");
					respuesta = ll_sort(pArrayListEmployee, order_by_id, 1);
					break;
				case 2:
					printf("Aguarde unos momentos por favor...");
					respuesta = ll_sort(pArrayListEmployee, order_by_name, 1);
					break;
				case 3:
					printf("Aguarde unos momentos por favor...");
					respuesta = ll_sort(pArrayListEmployee, order_by_workhours, 1);
					break;
				case 4:
					printf("Aguarde unos momentos por favor...");
					respuesta = ll_sort(pArrayListEmployee, order_by_salary, 1);
					break;
			}

			opcionSeleccionada = 5;
		}
	}
	while(opcionSeleccionada != 5);

	return respuesta;
}

int comparar_numeros(int* numeroA, int* numeroB)
{
	int respuesta;
	respuesta = 0;

	if(*numeroA > *numeroB)
	{
		respuesta = 1;
	}
	else
	{
		if(*numeroA < *numeroB)
		{
			respuesta = -1;
		}
	}

	return respuesta;
}

//--------------------------------------------------//





