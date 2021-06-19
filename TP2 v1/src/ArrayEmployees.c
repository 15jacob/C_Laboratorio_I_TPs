#include "ArrayEmployees.h"


//ESTILOS
void Barra_Separadora(int tipo)
{
	switch(tipo)
	{
		//32 Guiones
		case 1:
			printf("--------------------------------\n");
			break;
		//64 Guiones
		case 2:
			printf("----------------------------------------------------------------\n");
			break;
		//96 Guiones
		case 3:
			printf("------------------------------------------------------------------------------------------------\n");
			break;
	}
}

void Nueva_Linea()
{
	printf("\n");
}



//ESTRUCTURAS
int Inicializar_Empleados(eEmpleado listaEmpleados[], int max_empleados)
{
	int respuesta;
	respuesta = -1;

	int i;

	if(listaEmpleados != NULL && max_empleados > 0)
	{
		for(i=0; i < max_empleados; i++)
		{
			listaEmpleados[i].estado = 0;
		}

		respuesta = 0;
	}

	return respuesta;
}



//INGRESOS
int Ingreso_Opcion()
{
	int opcionIngresada;

	printf("Ingrese Opcion: ");

	if(scanf("%d", &opcionIngresada) == 0)
	{
		opcionIngresada = -1;
	}

	return opcionIngresada;
}

int Ingreso_Entero(int minimo, int maximo)
{
	int reintentos;
	int numeroIngresado;

	reintentos = 3;
	numeroIngresado = -1;

	for(reintentos = 3; reintentos > 0; reintentos--)
	{
		fflush(stdin);

		if(scanf("%d", &numeroIngresado) == 1 && (numeroIngresado > minimo-1 && numeroIngresado < maximo+1))
		{
			break;
		}
		else
		{
			if(reintentos == 1)
			{
				printf("Ha fallado muchas veces, volviendo al menu principal");
				Nueva_Linea();
				numeroIngresado = -1;
			}
			else
			{
				printf("Numero invalido, reingrese (%d reintentos disponibles)", reintentos-1);
			}
		}
	}

	return numeroIngresado;
}

float Ingreso_Float(int minimo, int maximo)
{
	int reintentos;
	float numeroIngresado;

	reintentos = 3;
	numeroIngresado = -1;

	for(reintentos = 3; reintentos > 0; reintentos--)
	{
		fflush(stdin);

		if(scanf("%f", &numeroIngresado) == 1 && (numeroIngresado > minimo-1 && numeroIngresado < maximo+1))
		{
			break;
		}
		else
		{
			if(reintentos == 1)
			{
				printf("Ha fallado muchas veces, volviendo al menu principal");
				Nueva_Linea();
				numeroIngresado = -1;
			}
			else
			{
				printf("Numero invalido, reingrese (%d reintentos disponibles)", reintentos-1);
			}
		}
	}

	return numeroIngresado;
}

int Ingreso_Char()
{
	fflush(stdin);

	int respuesta;
	respuesta = -1;

	int reintentos;
	char caracterIngresado;

	reintentos = 3;

	for(reintentos = 3; reintentos > 0; reintentos--)
	{
		fflush(stdin);
		if(scanf("%c", &caracterIngresado) == 1)
		{
			caracterIngresado = toupper(caracterIngresado);

			switch(caracterIngresado)
			{
				case 'S':
					respuesta = 1;
					break;
				case 'N':
					respuesta = 0;
					break;
				default:
					if(reintentos == 1)
					{
						printf("Ha fallado muchas veces, volviendo al menu principal");
						Nueva_Linea();
					}
					else
					{
						printf("Respuesta no valida, reingrese (%d reintentos disponibles): ", reintentos-1);
					}
					break;
			}

			if(respuesta == 0 || respuesta == 1)
			{
				break;
			}
		}
	}

	return respuesta;
}

int Ingreso_String(char string[])
{
	int respuesta;
	respuesta = -1;

	int reintentos;
	reintentos = 3;

	for(reintentos = 3; reintentos > 0; reintentos--)
	{
		fflush(stdin);

		if(scanf("%[^\n]", string) == 1 && Validar_String(string) == 0)
		{
			respuesta = 0;
			break;
		}
		else
		{
			if(reintentos == 1)
			{
				printf("Ha fallado muchas veces, volviendo al menu principal");
				Nueva_Linea();
				respuesta = -1;
			}
			else
			{
				printf("Nombre ingresado invalido, reingrese (%d reintentos disponibles)", reintentos-1);
			}
		}
	}

	return respuesta;
}

int Validar_String(char string[])
{
	int respuesta;
	respuesta = 0;

	int i;

	for(i = 0; i < strlen(string); i++)
	{
		if(!isalpha(string[i]) && !isspace(string[i]))
		{
			respuesta = -1;
			break;
		}
	}

	return respuesta;
}

eEmpleado Ingreso_Datos(eSector listaSectores[], int max_sectores, int* idEmpleado)
{
	eEmpleado empleadoAuxiliar;

	int resultadoNombre;
	int resultadoApellido;

	//ID
	empleadoAuxiliar.idEmpleado = *idEmpleado;
	(*idEmpleado)++;

	//NOMBRE
	system("cls");
	printf("Ingrese el Nombre del Empleado: ");
	resultadoNombre = Ingreso_String(empleadoAuxiliar.nombreEmpleado);

	if(resultadoNombre == 0)
	{
		//APELLIDO
		system("cls");
		printf("Ingrese el Apellido del Empleado: ");
		resultadoApellido = Ingreso_String(empleadoAuxiliar.apellidoEmpleado);

		if(resultadoApellido == 0)
		{
			//SALARIO
			system("cls");
			printf("Ingrese el Salario del Empleado: ");
			empleadoAuxiliar.salarioEmpleado = Ingreso_Float(0, 999999);

			if(empleadoAuxiliar.salarioEmpleado != -1)
			{
				//ID SECTOR
				system("cls");
				printf("Ingrese el Id del sector: ");
				empleadoAuxiliar.idSector = Seleccionar_Sector(listaSectores, max_sectores);
			}
		}
	}

	if(resultadoNombre != -1 || resultadoApellido != -1 || empleadoAuxiliar.salarioEmpleado != -1 || empleadoAuxiliar.idSector != -1)
	{
		empleadoAuxiliar.estado = 1;
	}
	else
	{
		empleadoAuxiliar.estado = 0;
	}

	return empleadoAuxiliar;
}



//MENU
void Menu_Principal(eEmpleado listaEmpleados[], int max_empleados, eSector listaSectores[], int max_sectores, int* idEmpleado)
{
	int opcionIngresada;
	int resultado;
	int banderaEmpleadosCargados;

	banderaEmpleadosCargados = 0;

	do
	{
		system("cls");
		fflush(stdin);

		printf("Nómina de Empleados\n");
		Barra_Separadora(2);

		printf("1. Alta de Empleado\n");
		printf("2. Modificar Empleado\n");
		printf("3. Baja de Empleado\n");
		printf("4. Listar Empleados por Nombre y Sector\n");
		printf("5. Total y Promedio de Salarios\n");
		printf("6. Salir\n");
		Barra_Separadora(2);

		Nueva_Linea();
		opcionIngresada = Ingreso_Opcion();

		switch(opcionIngresada)
		{
			case 1:
				//ALTAS
				resultado = Carga_Empleado(listaEmpleados, max_empleados, listaSectores, max_sectores, idEmpleado);

				switch(resultado)
				{
					case 0:
						banderaEmpleadosCargados = 1;
						printf("Empleado cargado con exito!");
						break;
					case -1:
						printf("No se ha cargado al empleado");
						break;
					case -2:
						printf("No hay mas espacio disponible en la base de datos!");
						break;
				}

				break;

			case 2:
				//MODIFACIONES
				if(banderaEmpleadosCargados == 1)
				{
					resultado = Modificar_Empleado(listaEmpleados, max_empleados, listaSectores, max_sectores);
				}
				else
				{
					printf("No hay empleados cargados en la base de datos");
				}

				break;

			case 3:
				//BAJAS
				if(banderaEmpleadosCargados == 1)
				{
					resultado = Baja_Empleado(listaEmpleados, max_empleados, listaSectores, max_sectores);

					switch(resultado)
					{
						case 0:
							printf("Empleado dado de baja con Exito!");
							banderaEmpleadosCargados = Buscador_Ocupados(listaEmpleados, max_empleados);
							break;
						case -1:
							printf("No se ha encontrado un empleado con ese Id");
							break;
						case -2:
							printf("No se ha dado de baja al empleado");
							break;
					}
				}
				else
				{
					printf("No hay empleados cargados en la base de datos");
				}

				break;

			case 4:
				//LISTAR EMPLEADOS
				if(banderaEmpleadosCargados == 1)
				{
					resultado = Ordenar_Empleados_Nombre_Sector(listaEmpleados, max_empleados, listaSectores, max_sectores);

					switch(resultado)
					{
						case 0:
							resultado = Listar_Empleados(listaEmpleados, max_empleados, listaSectores, max_sectores);
							break;
						case -1:
							printf("No hay empleados cargados!");
							break;
					}
				}
				else
				{
					printf("No hay empleados cargados en la base de datos");
				}

				break;

			case 5:
				if(banderaEmpleadosCargados == 1)
				{
					Promedio_Salarios(listaEmpleados, max_empleados);
				}
				else
				{
					printf("No hay empleados cargados en la base de datos");
				}

				break;

			case 6:
				printf("SALIENDO...\n");
				break;

			default:
				printf("Opcion ingresada no valida, reingrese\n");
				break;
		}

		Nueva_Linea();
		system("pause");
	}
	while(opcionIngresada != 6);
}

void Promedio_Salarios(eEmpleado listaEmpleados[], int max_empleados)
{
	int i;

	float totalSalarios;
	float promedioSalario;

	int empleadosQueSuperanElPromedio;
	int cantidadEmpleados;

	totalSalarios = 0;
	cantidadEmpleados = 0;
	empleadosQueSuperanElPromedio = 0;

	for(i = 0; i < max_empleados; i++)
	{
		if(listaEmpleados[i].estado == 1)
		{
			cantidadEmpleados++;
			totalSalarios += listaEmpleados[i].salarioEmpleado;
		}
	}

	if(cantidadEmpleados > 0)
	{
		promedioSalario = totalSalarios / cantidadEmpleados;

		printf("El Total de los Salarios es de: $%.2f", totalSalarios);
		Nueva_Linea();

		printf("El Promedio de los Salarios es de: $%.2f", promedioSalario);
		Nueva_Linea();

		for(i = 0; i < max_empleados; i++)
		{
			if(listaEmpleados[i].salarioEmpleado > promedioSalario)
			{
				empleadosQueSuperanElPromedio++;
			}
		}

		printf("La cantidad de empleados que superan el salario promedio es: %d", empleadosQueSuperanElPromedio);
	}
}



//ALTA
int Carga_Empleado(eEmpleado listaEmpleados[], int max_empleados, eSector listaSectores[], int max_sectores, int* idEmpleado)
{
	system("cls");
	int respuesta;
	respuesta = -1;

    int espacioDisponible;
    espacioDisponible = Buscador_Libres(listaEmpleados, max_empleados);

    if(espacioDisponible != -1)
    {
    	listaEmpleados[espacioDisponible] = Ingreso_Datos(listaSectores, max_sectores, idEmpleado);
    	respuesta = 0;
    }
    else
    {
    	respuesta = -2;
    }

    return respuesta;
}

int Buscador_Libres(eEmpleado listaEmpleados[], int max_empleados)
{
	int resultado;
	resultado = -1;

	int i;

	for(i=0; i < max_empleados; i++)
	{
		if(listaEmpleados[i].estado == 0)
		{
			resultado = i;
			break;
		}
	}

	return resultado;
}



//BAJA
int Baja_Empleado(eEmpleado listaEmpleados[], int max_empleados, eSector listaSectores[], int max_sectores)
{
    int respuesta;
    respuesta = -1;

    int idEmpleado;
    int posicionEmpleado;
    int confirmarBaja;

    Listar_Empleados(listaEmpleados, max_empleados, listaSectores, max_sectores);

    Barra_Separadora(2);
    printf("Ingrese el Id del Empleado a dar de baja: ");
    idEmpleado = Ingreso_Entero(0, max_empleados);

    posicionEmpleado = Buscar_Empleado_Por_Id(idEmpleado, listaEmpleados, max_empleados);

    if(posicionEmpleado == -1)
    {
        printf("No existe un empleado con ese Id\n");
    }
    else
    {
    	respuesta = -2;

    	Mostrar_Empleado(listaEmpleados[posicionEmpleado], listaSectores, max_sectores);
    	printf("Esta seguro que desea dar de baja al siguiente empleado? (s/n): ");

    	confirmarBaja = Ingreso_Char();

    	if(confirmarBaja == 1)
    	{
    		listaEmpleados[posicionEmpleado].estado = 0; //Se vacia
    		respuesta = 0;
    	}
    }

    return respuesta;
}

int Buscador_Ocupados(eEmpleado listaEmpleados[], int max_empleados)
{
	int resultado;
	resultado = 0;

	int i;

	for(i=0; i < max_empleados; i++)
	{
		if(listaEmpleados[i].estado == 1)
		{
			resultado = 1;
			break;
		}
	}

	return resultado;
}



//MODIFICAR
int Modificar_Empleado(eEmpleado listaEmpleados[], int max_empleados, eSector listaSectores[], int max_sectores)
{
    int respuesta;
    respuesta = -1;

    int idEmpleado;
    int posicionEmpleado;

    Listar_Empleados(listaEmpleados, max_empleados, listaSectores, max_sectores);

    Barra_Separadora(2);
    printf("Ingrese el Id del Empleado a dar de baja: ");
    idEmpleado = Ingreso_Entero(0, max_empleados);

    posicionEmpleado = Buscar_Empleado_Por_Id(idEmpleado, listaEmpleados, max_empleados);

    if(posicionEmpleado == -1)
    {
        printf("No existe un empleado con ese Id\n");
    }
    else
    {
    	listaEmpleados[posicionEmpleado] = Menu_Modificaciones(listaEmpleados[posicionEmpleado], listaSectores, max_sectores);
    }

    return respuesta;
}

eEmpleado Menu_Modificaciones(eEmpleado empleado, eSector listaSectores[], int max_sectores)
{
	int resultado;
	int opcionIngresada;

	int auxiliarIdSector;
	char auxiliarNombreApellido[51];
	float auxiliarSalario;

	do
	{
		fflush(stdin);

		printf("1. Modificar Nombre\n");
		printf("2. Modificar Apellido\n");
		printf("3. Modificar Salario\n");
		printf("4. Modificar Sector\n");
		printf("5. Volver al Menu Principal\n");

		Barra_Separadora(1);
		opcionIngresada = Ingreso_Opcion();

		switch(opcionIngresada)
		{
			case 1:
				//NOMBRE
				system("cls");
				printf("Ingrese el nuevo Nombre del Empleado: ");
				Nueva_Linea();
				resultado = Ingreso_String(auxiliarNombreApellido);

				if(resultado == 0)
				{
					strcpy(empleado.nombreEmpleado, auxiliarNombreApellido);
					printf("Nombre modificado con exito!");
				}
				else
				{
					printf("No se han hecho modificaciones");
				}

				break;
			case 2:
				//APELLIDO
				system("cls");
				printf("Ingrese el nuevo Apellido del Empleado: ");
				resultado = Ingreso_String(auxiliarNombreApellido);

				if(resultado == 0)
				{
					strcpy(empleado.apellidoEmpleado, auxiliarNombreApellido);
					printf("Apellido modificado con exito!");
				}
				else
				{
					printf("No se han hecho modificaciones");
				}

				break;
			case 3:
				//SALARIO
				system("cls");
				printf("Ingrese el nuevo salario del Empleado: ");
				auxiliarSalario = Ingreso_Float(0, 999999);

				if(auxiliarSalario != -1)
				{
					printf("Salario modificado con exito!");
					empleado.salarioEmpleado = auxiliarSalario;
				}
				else
				{
					printf("No se han hecho modificaciones");
				}

				break;
			case 4:
				//ID SECTOR
				system("cls");
				printf("Ingrese el nuevo Id del sector: ");
				auxiliarIdSector = Seleccionar_Sector(listaSectores, max_sectores);

				if(auxiliarIdSector != -1)
				{
					empleado.idSector = auxiliarIdSector;
				}

				break;

			case 5:
				printf("Volviendo al menu principal...");
				break;
			default:
				printf("Opcion ingresada no valida, reingrese");
				break;
		}

		Nueva_Linea();
		Barra_Separadora(2);
		system("pause");
	}
	while(opcionIngresada != 5);

	return empleado;
}



//EMPLEADOS
int Buscar_Empleado_Por_Id(int IdEmpleado, eEmpleado listaEmpleados[], int max_empleados)
{
	int indiceEmpleado;
	indiceEmpleado = -1;

	int i;

	for(i = 0; i < max_empleados; i++)
	{
		if(listaEmpleados[i].idEmpleado == IdEmpleado && listaEmpleados[i].estado == 1)
		{
			indiceEmpleado = i;
			break;
		}
	}

	return indiceEmpleado;
}



//SECTORES
int Seleccionar_Sector(eSector listaSectores[], int max_sectores)
{
	int id;
	int i;

	int primerIdSector;
	int ultimoIdSector;

	Nueva_Linea();
	printf("%5s %20s\n", "ID", "SECTOR");

	for(i=0; i < max_sectores; i++)
	{
		printf("%5d %20s\n", listaSectores[i].idSector,
							 listaSectores[i].nombreSector);

		//Variables necesarias para la funcion Ingreso_Entero
		if(i == 0)
		{
			primerIdSector = listaSectores[i].idSector;
		}

		if(i == max_sectores-1)
		{
			ultimoIdSector = listaSectores[i].idSector;
		}
	}

	Nueva_Linea();
	printf("Id: ");
	id = Ingreso_Entero(primerIdSector, ultimoIdSector);

	return id;
}

int Buscar_Sector_Por_Id(int IdSectorEmpleado, eSector listaSectores[], int max_sectores)
{
	int indiceSector;
	indiceSector = -1;

	int i;

	for(i = 0; i < max_sectores; i++)
	{
		if(listaSectores[i].idSector == IdSectorEmpleado)
		{
			indiceSector = i;
			break;
		}
	}

	return indiceSector;
}



//ORDENAMIENTO
int Ordenar_Empleados_Nombre_Sector(eEmpleado listaEmpleados[], int max_empleados, eSector listaSectores[], int max_sectores)
{
	system("cls");
	int respuesta;
	respuesta = -1;

	int i;
	int j;

	int sectorI;
	int sectorJ;

	if(listaEmpleados != NULL && listaSectores != NULL && max_empleados > 0 && max_sectores > 0)
	{
		respuesta = 0;

		for(i = 0; i < max_empleados-1; i++)
		{
			for(j = i+1; j < max_empleados; j++)
			{
				if(strcmp(listaEmpleados[i].apellidoEmpleado, listaEmpleados[j].apellidoEmpleado) > 0)
				{
					Swap_Listas(listaEmpleados, i, j);
				}
				else
				{
					if(strcmp(listaEmpleados[i].apellidoEmpleado, listaEmpleados[j].apellidoEmpleado) == 0)
					{
						sectorI = Buscar_Sector_Por_Id(listaEmpleados[i].idSector, listaSectores, max_sectores);
						sectorJ = Buscar_Sector_Por_Id(listaEmpleados[j].idSector, listaSectores, max_sectores);

						if(strcmp(listaSectores[sectorI].nombreSector, listaSectores[sectorJ].nombreSector) > 0)
						{
							Swap_Listas(listaEmpleados, i, j);
						}
					}
				}
			}
		}
	}

	return respuesta;
}

int Swap_Listas(eEmpleado listaEmpleados[], int posicion_a, int posicion_b)
{
	eEmpleado auxiliar;

	auxiliar = listaEmpleados[posicion_a];
	listaEmpleados[posicion_a] = listaEmpleados[posicion_b];
	listaEmpleados[posicion_b] = auxiliar;

	return 0;
}



//LISTADOS
int Listar_Empleados(eEmpleado listaEmpleados[], int max_empleados, eSector listaSectores[], int max_sectores)
{
	int respuesta;
	respuesta = -1;

	int banderaPrimerEmpleado;
	banderaPrimerEmpleado = 0;
	int i;

	for(i=0; i < max_empleados; i++)
	{
		if(listaEmpleados[i].estado == 1)
		{
			if(banderaPrimerEmpleado == 0)
			{
				Barra_Separadora(2);
				printf("%5s %10s %10s %10s %15s\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
				banderaPrimerEmpleado = 1;
			}

			respuesta = Mostrar_Empleado(listaEmpleados[i], listaSectores, max_sectores);
		}
	}

	if(banderaPrimerEmpleado == 0)
	{
		respuesta = -2;
	}

	return respuesta;
}

int Mostrar_Empleado(eEmpleado empleado, eSector listaSectores[], int max_sectores)
{
	int respuesta;
	respuesta = -1;

	int i;
	char nombreSector[51];

	//FK Tipos
	for(i=0; i < max_sectores; i++)
	{
		if(empleado.idSector == listaSectores[i].idSector)
		{
			strcpy(nombreSector, listaSectores[i].nombreSector);

			printf("%5d %10s %10s %10.2f %15s\n", empleado.idEmpleado,
												empleado.nombreEmpleado,
												empleado.apellidoEmpleado,
												empleado.salarioEmpleado,
												nombreSector);

			respuesta = 0;
			break;
		}
	}

	return respuesta;
}
