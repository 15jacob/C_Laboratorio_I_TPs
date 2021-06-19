#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Employee.h"
#include "input.h"
#include "listing.h"

/**
 * Constructor Por Defecto
 * @return
 */
Employee* employee_new()
{
	Employee* pEmpleado;
	pEmpleado = (Employee*)calloc(sizeof(Employee), 1);

	return pEmpleado;
}

/**
 * Constructor por Parametros
 * @param idStr
 * @param nombreStr
 * @param horasTrabajadasStr
 * @param sueldoStr
 * @return
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pEmpleado;
	pEmpleado = employee_new();

    int id;
    int horasTrabajadas;
    int sueldo;

	if(pEmpleado != NULL)
	{
		//Parseo
		id = atoi(idStr);
		horasTrabajadas = atoi(horasTrabajadasStr);
		sueldo = atoi(sueldoStr);

		//Si alguno de los datos no se puede setear correctamente se devolvera un NULL
		if(employee_setId(pEmpleado, id) == 0 ||
		   employee_setNombre(pEmpleado, nombreStr) == 0 ||
		   employee_setHorasTrabajadas(pEmpleado, horasTrabajadas) == 0 ||
		   employee_setSueldo(pEmpleado, sueldo) == 0)
		{
			pEmpleado = NULL;
		}
	}

	return pEmpleado;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/**
 * Busca en la Lista de Empleados el Id correspondiente y devuelve su posicion. Si el empleado no existe devolvera -1
 * @param pArrayListEmployee
 * @param id
 * @return
 */
int employee_getPosition(LinkedList* pArrayListEmployee, int* id)
{
	int respuesta;
	respuesta = -1;

	int idAuxiliar;

	Employee* pEmpleado;
	pEmpleado = employee_new();

	int i;
	int len;
	len = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			pEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(pEmpleado, &idAuxiliar);

			//Si la funcion anterior retorna [1] significa que el ID se ha encontrado en la lista
			if(idAuxiliar == *id)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

/**
 * Busca en la lista de empleados, y devuelve el ultimo ID que corresponderia para el siguiente empleado en la lista
 * @param pArrayListEmployee
 * @return
 */
int employee_getEmptyId(LinkedList* pArrayListEmployee, Employee* pEmpleado)
{
	int mayorId;
	mayorId = -1;

	int id;

	int i;
	int len;
	len = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && pEmpleado != NULL)
	{
		for(i = 0; i < len; i++)
		{
			pEmpleado = (Employee*)ll_get(pArrayListEmployee, i);

			if(pEmpleado != NULL)
			{
				employee_getId(pEmpleado, &id);
			}

			if(mayorId < id)
			{
				mayorId = id;
			}

			/* Testeo: Este Codigo devuelve si existen huecos entre los ID. No deberia de tener mas utilidad que esa
			if(pEmpleado != NULL)
			{
				employee_getId(pEmpleado, &id);
				ultimoId++;

				//Si hay una diferencia entre el nuevo Id y el Ultimo Id Analizado, se devolvera el ultimo
				if(id > ultimoId)
				{
					break;
				}
			}
			*/
		}

		//Si no hay empleados dados de baja se devolvera el Id siguiente al ultimo
		if(mayorId == -1)
		{
			printf("Uso el Len\n");
			mayorId = len+1;
		}
		else
		{
			printf("Tuvo que recurrir a esto\n");
			mayorId++;
		}
	}

	return mayorId;
}

//Getters y Setters
int employee_setId(Employee* this, int id)
{
	int respuesta;
	respuesta = 0;

	if(this != NULL && id > 0)
	{
		this->id = id;
		respuesta = 1;
	}

	return respuesta;
}

int employee_getId(Employee* this, int* id)
{
	int respuesta;
	respuesta = 0;

    if(this != NULL)
    {
        *id = this->id;
        respuesta = 1;
    }

    return respuesta;
}

int employee_setNombre(Employee* this, char* nombre)
{
	int respuesta;
	respuesta = 0;

	if(this != NULL)
	{
		strcpy(this->nombre, nombre);
		respuesta = 1;
	}

	return respuesta;
}

int employee_getNombre(Employee* this, char* nombre)
{
	int respuesta;
	respuesta = 0;

    if(this != NULL)
    {
    	strcpy(nombre, this->nombre);
    	respuesta = 1;
    }

    return respuesta;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int respuesta;
	respuesta = 0;

	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		respuesta = 1;
	}

	return respuesta;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int respuesta;
	respuesta = 0;

    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        respuesta = 1;
    }

    return respuesta;
}

int employee_setSueldo(Employee* this, int sueldo)
{
	int respuesta;
	respuesta = 0;

	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		respuesta = 1;
	}

	return respuesta;
}

int employee_getSueldo(Employee* this, int* sueldo)
{
	int respuesta;
	respuesta = 0;

    if(this != NULL)
    {
        *sueldo = this->sueldo;
        respuesta = 1;
    }

    return respuesta;
}
