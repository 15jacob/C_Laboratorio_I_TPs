//Jacob Cristopher 1F | TP2 - Programacion I

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define MAX_EMPLEADOS 1000
#define MAX_SECTORES 3

int main()
{
	setbuf(stdout, NULL);

	int Inicializar;
	int idEmpleado;
	idEmpleado = 1;

	/*
	eEmpleado listaEmpleados[MAX_EMPLEADOS] = {{1, "Paula", "Rodriguez", 20000, 2, 1},
											   {2, "Apu", "Rodriguez", 20000, 3, 1},
											   {3, "Nahuel", "Rodriguez", 20000, 2, 1},
											   {4, "Vlad", "Gonzales", 20000, 1, 1},
											   {5, "Apu", "Rodriguez", 20000, 1, 1},
											   {6, "Boris", "Rodriguez", 20000, 3, 1}};
											   */

	eEmpleado listaEmpleados[MAX_EMPLEADOS];
	eSector listaSectores[MAX_SECTORES] = {{1, "Marketing"}, {2, "Sistemas"}, {3, "Ingenieria"}};

	Inicializar = Inicializar_Empleados(listaEmpleados, MAX_EMPLEADOS);

	if(Inicializar == 0)
	{
		Menu_Principal(listaEmpleados, MAX_EMPLEADOS, listaSectores, MAX_SECTORES, &idEmpleado);
	}
	else
	{
		printf("Error al Inicializar");
		Barra_Separadora(2);

		printf("Saliendo...");
		Nueva_Linea();

		system("pause");
	}

	return 0;
}
