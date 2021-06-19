#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

//--------------------------------------------------//

//Input Opcion Generico
int input_option(int*);

//Input Int Generico
int input_unsigned_int(int*, int);
int validation_int(int*);

//Input Char Generico
int input_char(char*, int);
int validation_char(char*);

//Input String Sin Caracteres Especiales Generico
int input_string_no_special_char(char*, int);
int validation_string_no_special_char(char*);

//Informa los intentos restantes
void intentos_restantes(int*);

//--------------------------------------------------//

//Input confirmacion borrar empleado
int input_employee_confirmation(Employee*, int);
int validation_confirmation(char*);

//--------------------------------------------------//

int menu_employee_modification(LinkedList*, Employee*, int*, int*);
int menu_sort_employees(LinkedList* pArrayListEmployee, int);
int comparar_numeros(int*, int*);

//--------------------------------------------------//

#endif /* INPUT_H_ */
