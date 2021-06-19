#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//ESTILOS
void Barra_Separadora(int);
void Nueva_Linea();

//ESTRUCTURAS
typedef struct
{
	int idEmpleado; //PK
	char nombreEmpleado[51];
	char apellidoEmpleado[51];
	float salarioEmpleado;
	int idSector; //FK
	int estado; //0 = Vacio //1 = Ocupado
} eEmpleado;

typedef struct
{
	int idSector; //PK
	char nombreSector[51];
} eSector;

int Inicializar_Empleados(eEmpleado[], int);

//INGRESOS
int Ingreso_Opcion();
int Ingreso_Entero(int, int);
float Ingreso_Float(int, int);
int Ingreso_Char();
int Ingreso_String(char[]);
int Validar_String(char[]);
eEmpleado Ingreso_Datos(eSector[], int, int*);

//MENU
void Menu_Principal(eEmpleado[], int, eSector[], int, int*);

//ALTAS
int Carga_Empleado(eEmpleado[], int, eSector[], int, int*);
int Buscador_Libres(eEmpleado[], int);
int Buscador_Ocupados(eEmpleado[], int);

//BAJAS
int Baja_Empleado(eEmpleado[], int, eSector[], int);

//MODIFICACIONES
int Modificar_Empleado(eEmpleado[], int, eSector[], int);
eEmpleado Menu_Modificaciones(eEmpleado, eSector[], int);

//SECTORES
int Seleccionar_Sector(eSector[], int);
int Buscar_Sector_Por_Id(int, eSector[], int);

//EMPLEADOS
int Buscar_Empleado_Por_Id(int, eEmpleado[], int);

//ORDENAMIENTOS
int Ordenar_Empleados_Nombre_Sector(eEmpleado[], int, eSector[], int);

//LISTADOS
int Listar_Empleados(eEmpleado[], int, eSector[], int);
int Mostrar_Empleado(eEmpleado, eSector[], int);
int Swap_Listas(eEmpleado[], int, int);
void Promedio_Salarios(eEmpleado[], int);


#endif /* ARRAYEMPLOYEES_H_ */
