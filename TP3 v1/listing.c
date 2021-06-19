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


int list_employees(LinkedList* pArrayListEmployee)
{
	int contadorEmpleados;
	contadorEmpleados = 0;

	int i;
	int len;

	Employee* pEmpleado;

	//Largo actual de la lista
	len = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && len > 0)
	{
		printf("Listando %d empleados\n", len);

		for(i = 0; i < len; i++)
		{
			pEmpleado = (Employee*)ll_get(pArrayListEmployee, i);

			if(show_employee(pEmpleado) == 1)
			{
				contadorEmpleados++;
			}
		}
	}

	return contadorEmpleados;
}

int show_employee(Employee* this)
{
	int respuesta;
	respuesta = 0;

	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	employee_getId(this, &id);
	employee_getNombre(this, nombre);
	employee_getHorasTrabajadas(this, &horasTrabajadas);
	employee_getSueldo(this, &sueldo);

	if(id != 0 && nombre != 0 && horasTrabajadas != 0 && sueldo != 0)
	{
		printf("%10d %20s %10d %10d\n", id, nombre, horasTrabajadas, sueldo);
		respuesta = 1;
	}

	return respuesta;
}

int order_by_id(void* empleadoA, void* empleadoB)
{
	int respuesta;
	respuesta = 0;

	int idEmpleadoA;
	int idEmpleadoB;

	if(empleadoA != NULL && empleadoB != NULL)
	{
		employee_getId(empleadoA, &idEmpleadoA);
		employee_getId(empleadoB, &idEmpleadoB);

		respuesta = comparar_numeros(&idEmpleadoA, &idEmpleadoB);
	}

	return respuesta;
}

int order_by_name(void* empleadoA, void* empleadoB)
{
	int respuesta;
	respuesta = 0;

	char nombreEmpleadoA[128];
	char nombreEmpleadoB[128];

	if(empleadoA != NULL && empleadoB != NULL)
	{
		employee_getNombre(empleadoA, nombreEmpleadoA);
		employee_getNombre(empleadoB, nombreEmpleadoB);

		respuesta = strcmpi(nombreEmpleadoA, nombreEmpleadoB);
	}

	return respuesta;
}

int order_by_workhours(void* empleadoA, void* empleadoB)
{
	int respuesta;
	respuesta = 0;

	int horasEmpleadoA;
	int horasEmpleadoB;

	if(empleadoA != NULL && empleadoB != NULL)
	{
		employee_getHorasTrabajadas(empleadoA, &horasEmpleadoA);
		employee_getHorasTrabajadas(empleadoB, &horasEmpleadoB);

		respuesta = comparar_numeros(&horasEmpleadoA, &horasEmpleadoB);
	}

	return respuesta;
}

int order_by_salary(void* empleadoA, void* empleadoB)
{
	int respuesta;
	respuesta = 0;

	int sueldoEmpleadoA;
	int sueldoEmpleadoB;

	if(empleadoA != NULL && empleadoB != NULL)
	{
		employee_getHorasTrabajadas(empleadoA, &sueldoEmpleadoA);
		employee_getHorasTrabajadas(empleadoB, &sueldoEmpleadoB);

		respuesta = comparar_numeros(&sueldoEmpleadoA, &sueldoEmpleadoB);
	}

	return respuesta;
}
