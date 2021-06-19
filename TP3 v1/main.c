#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"
#include "listing.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);

	int respuesta;
	int opcionSeleccionada;

	LinkedList* listaEmpleados;
    listaEmpleados = ll_newLinkedList(); //Crear Espacio en el heap

    if(listaEmpleados != NULL)
    {
    	do
    	{
    		fflush(stdin);

    		printf("MENU PRINCIPAL\n");
    		printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    		printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
   			printf("3. Alta de empleado\n");
   			printf("4. Modificar datos de empleado\n");
   			printf("5. Baja de empleado\n");
   			printf("6. Listar empleados\n");
   			printf("7. Ordenar empleados\n");
   			printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
   			printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
    		printf("10. Salir\n");

    		opcionSeleccionada = 0;
    		input_option(&opcionSeleccionada);

    		if(opcionSeleccionada != -1)
    		{
				switch(opcionSeleccionada)
				{
					case 1:
						respuesta = controller_loadFromText("data.csv", listaEmpleados);

						switch(respuesta)
						{
							case -2:
								printf("Parece que no hay mas espacio en la memoria para realizar esta accion\n");
								break;
							case -1:
								printf("No se ha encontrado el archivo indicado\n");
								break;
							case 0:
								printf("Ese archivo no contiene una lista compatible!\n");
								break;
							default:
								printf("Se han cargado %d empleados con exito!\n", respuesta);
								break;
						}

						break;

					case 2:
						respuesta = controller_loadFromBinary("data.bin", listaEmpleados);

						switch(respuesta)
						{
							case -2:
								printf("Parece que no hay mas espacio en la memoria para realizar esta accion\n");
								break;
							case -1:
								printf("No se ha encontrado el archivo indicado\n");
								break;
							case 0:
								printf("Ese archivo no contiene una lista compatible!\n");
								break;
							default:
								printf("Se han cargado %d empleados con exito!\n", respuesta);
								break;
						}

						break;

					case 3:
						respuesta = controller_addEmployee(listaEmpleados);

						switch(respuesta)
						{
							case 0:
								printf("No existe ninguna lista cargada\n");
								break;
							case 1:
								printf("No hay mas memoria disponible para realizar esta accion\n");
								break;
							case 2:
								printf("Se ha ingresado mal el nombre del empleado demasiadas veces\n");
								break;
							case 3:
								printf("Se ha ingresado mal las horas trabajadas del empleado demasiadas veces\n");
								break;
							case 4:
								printf("Se ha ingresado mal el sueldo del empleado demasiadas veces\n");
								break;
							default:
								printf("Se ha cargado al empleado en la lista exitosamente!\n");
								break;
						}

						break;

					case 4:
						respuesta = controller_editEmployee(listaEmpleados);

						switch(respuesta)
						{
							case 0:
								printf("No existe ninguna lista cargada\n");
								break;
							case 1:
								printf("No hay mas memoria disponible para realizar esta accion\n");
								break;
							case 2:
								printf("Se ha ingresado un ID incorrecto demasiadas veces\n");
								break;
							case 3:
								printf("No existe ningun empleado en la lista con ese ID\n");
								break;
							case 4:
								printf("No se han realizado modificaciones\n");
								break;
							default:
								printf("Modificaciones realizadas exitosamente!\n");
								break;
						}

						break;

					case 5:
						respuesta = controller_removeEmployee(listaEmpleados);

						switch(respuesta)
						{
							case 0:
								printf("No existe ninguna lista cargada\n");
								break;
							case 1:
								printf("No hay mas memoria disponible para realizar esta accion\n");
								break;
							case 2:
								printf("Se ha ingresado mal el id del empleado demasiadas veces\n");
								break;
							case 3:
								printf("No se ha encontrado al empleado indicado\n");
								break;
							case 4:
								printf("No se ha borrado al empleado\n");
								break;
							default:
								printf("Se ha borrado al empleado de la lista exitosamente!\n");
								break;
						}

						break;

					case 6:
						respuesta = controller_ListEmployee(listaEmpleados);

						switch(respuesta)
						{
							case 0:
								printf("No existe ninguna lista cargada\n");
								break;
							default:
								printf("Se han listado %d empleados con exito!\n", respuesta);
								break;
						}

						break;

					case 7:
						respuesta = controller_sortEmployee(listaEmpleados);

						switch(respuesta)
						{
							case -1:
								printf("No existe ninguna lista cargada\n");
								break;
							case 0:
								printf("Lista ordenada exitosamente\n");
								break;
							case 1:
								printf("No se han realizado cambios en el orden\n");
								break;
						}

						break;

					case 8:
						respuesta = controller_saveAsText("data.csv", listaEmpleados);

						switch(respuesta)
						{
							case -2:
								printf("No existe ninguna lista cargada\n");
								break;
							case -1:
								printf("No se ha podido crear el archivo\n");
								break;
							default:
								printf("Se han guardado %d empleados con exito!\n", respuesta);
								break;
						}

						break;

					case 9:
						respuesta = controller_saveAsBinary("data.bin", listaEmpleados);

						switch(respuesta)
						{
							case -2:
								printf("No existe ninguna lista cargada\n");
								break;
							case -1:
								printf("No se ha podido crear el archivo\n");
								break;
							default:
								printf("Se han guardado %d empleados con exito!\n", respuesta);
								break;
						}

						break;

					case 10:
						printf("Saliendo del Programa\n");
						break;

					default:
						printf("Esa opcion es incorrecta. Intente nuevamente\n");
						break;
				}
    		}
    		system("pause");
    	}
    	while(opcionSeleccionada != 10);
    }

    return 0;
}

