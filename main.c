#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define T 1000

int main()
{
    eEmployee list[T];
    int opcion;                     // planteo la entidad, un entero para seleccionar una opcion del menu y un entero como bandera para cuando ya se haya ingresado un empleado
    int employeeAdded = 0;

    initEmployees(list, T);     // inicializo el array

    hardcodearEmployees(list, T);  // inicializo con 5 empleados para pruebas

    do
    {
        printf("1. Cargar un empleado.");
        printf("\n2. Modificar datos de empleado.");        // menu de opciones
        printf("\n3. Dar de baja un empleado.");
        printf("\n4. Listar empleados.");
        printf("\n5. Mostrar listado ordenado.");
        printf("\n6. Salir.");

        opcion = getInt("\nIngrese una opcion: ", "\nError. Ingrese una opcion: ", 1, 6);

        switch(opcion)
        {
            case 1:
                    addEmployee(list, T);
                    employeeAdded = 1;
                break;
            case 2:
                if(employeeAdded != 1)
                {
                    printf("\nError.Primero debe ingresar un empleado.");
                } else {
                    changeEmployeesData(list, T);
                }
                break;
            case 3:
                if(employeeAdded != 1)
                {
                    printf("\nError.Primero debe ingresar un empleado.");
                } else {
                    removeEmployee(list,T);
                }
                break;
            case 4:
                    printEmployees(list, T);
                break;
            case 5:
                //
                sortEmployees(list, T);
                printEmployees(list, T);
                break;
            case 6:
                printf("\nAdios...\n");
                break;
        }

        system("\npause");
        system("\ncls");
    }while(opcion != 6);            // si se preciona 6 se termina el programa

    return 0;
}
