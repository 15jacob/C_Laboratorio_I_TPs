#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"
#include "listing.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int respuesta;
	respuesta = -2;

	FILE *pArchivoTexto;

	if(pArrayListEmployee != NULL)
	{
		respuesta = -1;
		pArchivoTexto = fopen(path,"r");

		//A Partir de este momento la respuesta puede ser seteada en 0 en adelante dependiendo la cantidad de empleados que existen en el archivo
		if(pArchivoTexto != NULL)
		{
			respuesta = parser_EmployeeFromText(pArchivoTexto , pArrayListEmployee);
		}
	}

	fclose(pArchivoTexto);

    return respuesta;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int respuesta;
	respuesta = -2;

	FILE *pArchivoTexto;

	if(pArrayListEmployee != NULL)
	{
		respuesta = -1;
		pArchivoTexto = fopen(path,"rb");

		//A Partir de este momento la respuesta puede ser seteada en 0 en adelante dependiendo la cantidad de empleados que existen en el archivo
		if(pArchivoTexto != NULL)
		{
			respuesta = parser_EmployeeFromBinary(pArchivoTexto , pArrayListEmployee);
		}
	}

	fclose(pArchivoTexto);

    return respuesta;
}

/** \brief Alta de empleados
 * Devuelve:
 * 0 Si no existe una lista cargada
 * 1 Si no existe mas memoria para crear un nuevo empleado
 * 2 Si se ingreso mal el nombre del empleado pasados los tres intentos
 * 3 Si se ingreso mal las horas trabajadas del empleado pasados los tres intentos
 * 4 Si se ingreso mal el sueldo del empleado pasados los tres intentos
 * 5 Si se pudo cargar al empleado exitosamente
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int respuesta;
	respuesta = 0;

	Employee* pNuevoEmpleado;
	int idAux;
	int checkerDato;

	char nombreAux[128];
	int horasTrabajadasAux;
	int sueldoAux;

	int len;
	len = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && len > 0)
	{
		respuesta = 1;
		pNuevoEmpleado = employee_new();

		if(pNuevoEmpleado != NULL)
		{
			respuesta = 2;
			idAux = employee_getEmptyId(pArrayListEmployee, pNuevoEmpleado);

			printf("Alta de Empleado | ID Nº%d\n", idAux);
			printf("Ingrese el nombre del empleado:\n");
			checkerDato = input_string_no_special_char(nombreAux, 2);

			//Si se Ingreso un nombre valido, continua
			if(checkerDato != 0)
			{
				respuesta = 3;
				printf("Ingrese las horas trabajadas del empleado:\n");
				checkerDato = input_unsigned_int(&horasTrabajadasAux, 2);

				//Si se Ingreso un numero de horas valido, continua
				if(checkerDato != 0)
				{
					respuesta = 4;
					printf("Ingrese el sueldo del empleado:\n");
					checkerDato = input_unsigned_int(&sueldoAux, 2);

					//Si se Ingreso un sueldo valido, se cargan los datos
					if(checkerDato != 0)
					{
						respuesta = 5;
						employee_setId(pNuevoEmpleado, idAux);
						employee_setNombre(pNuevoEmpleado, nombreAux);
						employee_setHorasTrabajadas(pNuevoEmpleado, horasTrabajadasAux);
						employee_setSueldo(pNuevoEmpleado, sueldoAux);
						ll_add(pArrayListEmployee, pNuevoEmpleado);
					}
				}
			}
		}
	}

    return respuesta;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int respuesta;
	respuesta = 0;

	Employee* pEmpleadoAuxiliar;
	int idIngresado;
	int posicionEmpleado;
	int idAux;

	int banderaCambios;

	int len;
	len = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && len > 0)
	{
		respuesta = 1;
		pEmpleadoAuxiliar = employee_new();

		if(pEmpleadoAuxiliar != NULL)
		{
			respuesta = 2;
			list_employees(pArrayListEmployee);
			printf("Por favor ingrese el ID del Empleado a Modificar: ");
			input_unsigned_int(&idIngresado, 2);

			if(idIngresado != -1)
			{
				respuesta = 3;
				posicionEmpleado = employee_getPosition(pArrayListEmployee, &idIngresado);
				pEmpleadoAuxiliar = (Employee*)ll_get(pArrayListEmployee, posicionEmpleado);

				if(posicionEmpleado != -1)
				{
					employee_getId(pEmpleadoAuxiliar, &idAux);

					//Teniendo al empleado y su posicion, se llama a un menu que tomara estos datos para un menu "personalizado" del empleado
					banderaCambios = menu_employee_modification(pArrayListEmployee, pEmpleadoAuxiliar, &idAux, &posicionEmpleado);

					switch(banderaCambios)
					{
						//Se vuelve a llamar a la funcion
						case -1:
							controller_editEmployee(pArrayListEmployee);
							break;

						//Confirma que no se realizaron cambios sobre el empleado indicado
						case 0:
							respuesta = 4;
							break;

						//Confirma que se han realizado cambios sobre el empleado indicado
						case 1:
							respuesta = 5;
							break;
					}
				}
			}
		}
	}

    return respuesta;
}

/** \brief Baja de empleado
 * Devuelve:
 * 0 Si no existe una lista cargada
 * 1 Si no existe mas memoria para crear un nuevo empleado
 * 2 Si no existen empleados cargados en la lista
 * 3 Si no se encontro al empleado indicado
 * 4 Si no se ha borrado al empleado
 * 5 Si se ha borrado al empleado exitosamente
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int respuesta;
	respuesta = 0;

	Employee* pEmpleadoAuxiliar;
	int idBorrar;
	int posicionEmpleado;
	int confirmacion;

	int len;
	len = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && len > 0)
	{
		respuesta = 1;
		pEmpleadoAuxiliar = employee_new();

		if(pEmpleadoAuxiliar != NULL)
		{
			respuesta = 2;
			list_employees(pArrayListEmployee);
			printf("Por favor ingrese el ID del Empleado a Eliminar: ");
			input_unsigned_int(&idBorrar, 2);

			if(idBorrar != -1)
			{
				respuesta = 3;
				posicionEmpleado = employee_getPosition(pArrayListEmployee, &idBorrar);
				pEmpleadoAuxiliar = (Employee*)ll_get(pArrayListEmployee, posicionEmpleado);

				if(pEmpleadoAuxiliar != NULL)
				{
					respuesta = 4;

				    printf("Empleado a Eliminar\n");
					confirmacion = input_employee_confirmation(pEmpleadoAuxiliar, 2);

					if(confirmacion == 1)
					{
						respuesta = 5;

						//Baja al Empleado de la LinkedList
						ll_remove(pArrayListEmployee, posicionEmpleado);

						//Libera la Memoria del auxiliar
						employee_delete(pEmpleadoAuxiliar);
					}
				}
			}
		}
	}

    return respuesta;
}

/** \brief Listar empleados
 * Devuelve 0 Si no hay empleados cargados en la lista
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int contadorEmpleados;
	contadorEmpleados = 0;

	int len;
	len = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && len > 0)
	{
		contadorEmpleados = list_employees(pArrayListEmployee);
	}

    return contadorEmpleados;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int respuesta;
	respuesta = -1;

	int len;
	len = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && len > 0)
	{
		respuesta = menu_sort_employees(pArrayListEmployee, len);
	}

	return respuesta;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int contadorEmpleados;
	contadorEmpleados = -2;

	FILE *pArchivoTexto;

	Employee *pEmpleado;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	int i;
	int len;
	len = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && len > 0)
	{
		contadorEmpleados = -1;
		pArchivoTexto = fopen(path,"w");

		if(pArchivoTexto != NULL)
		{
			contadorEmpleados = 0;
			fprintf(pArchivoTexto, "id,nombre,horasTrabajadas,sueldo");

			for(i = 0; i < len; i++)
			{
				pEmpleado = (Employee*)ll_get(pArrayListEmployee, i);

				if(pEmpleado != NULL)
				{
					employee_getId(pEmpleado, &id);
					employee_getNombre(pEmpleado, nombre);
					employee_getHorasTrabajadas(pEmpleado, &horasTrabajadas);
					employee_getSueldo(pEmpleado, &sueldo);

					fprintf(pArchivoTexto, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);

					contadorEmpleados++;
				}
			}
		}

		fclose(pArchivoTexto);
	}

    return contadorEmpleados;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int contadorEmpleados;
	contadorEmpleados = -2;

	FILE *pArchivoTexto;
	Employee *pEmpleado;

	int i;
	int len;
	len = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && len > 0)
	{
		contadorEmpleados = -1;
		pArchivoTexto = fopen(path,"wb");

		if(pArchivoTexto != NULL)
		{
			contadorEmpleados = 0;
			//fprinf(pArchivoTexto, "id,nombre,horasTrabajadas,sueldo");

			for(i = 0; i < len; i++)
			{
				pEmpleado = (Employee*)ll_get(pArrayListEmployee, i);

				if(pEmpleado != NULL)
				{
					fwrite((Employee*)pEmpleado, sizeof(Employee), 1, pArchivoTexto);

					contadorEmpleados++;
				}
			}
		}

		fclose(pArchivoTexto);
	}

    return contadorEmpleados;
}

