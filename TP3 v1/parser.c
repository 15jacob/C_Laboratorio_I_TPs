#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int contadorEmpleados;
	contadorEmpleados = 0;

	int contadorCampos;
	int banderaEmpleadoAgregado;

	Employee* pEmpleado;
    char id[8];
    char nombre[128];
    char horasTrabajadas[8];
    char sueldo[16]; //Es una Empresa que paga asi de mucho

    while(!feof(pFile))
	{
		//Separa la Data del Empleado en Cadenas
		contadorCampos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

		//Si se consiguieron los cuatro campos se Carga al Empleado en el tipo de dato Empleado
		if(contadorCampos == 4)
		{
			//Pasa a la funcion los punteros de cada dato para que los cargue en una estructura Empleado
			pEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

			//Si la funcion anterior no devuelve nulo, dicho empleado se carga en la LinkedList
			if(pEmpleado != NULL)
			{
				banderaEmpleadoAgregado = ll_add(pArrayListEmployee, (Employee*)pEmpleado);

				if(banderaEmpleadoAgregado == 0)
				{
					contadorEmpleados++;
				}
			}
		}
	}

    return contadorEmpleados;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int contadorEmpleados;
	contadorEmpleados = 0;

	int banderaEmpleadoAgregado;

	Employee* pEmpleado;

    while(!feof(pFile))
	{
        pEmpleado = employee_new();
        fread((Employee*)pEmpleado, sizeof(Employee), 1, pFile);

        if(pEmpleado != NULL)
        {
        	banderaEmpleadoAgregado = ll_add(pArrayListEmployee, (Employee*)pEmpleado);

        	if(banderaEmpleadoAgregado == 0)
        	{
        		contadorEmpleados++;
        	}
		}
	}

    return contadorEmpleados;
}
