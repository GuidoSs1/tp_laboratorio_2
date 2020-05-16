#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"


void hardcodearEmployees(eEmployee list[], int len)
{
    int id[5] = {1, 2, 3, 4, 5};
    char nombre[5][51] = {"Juan","Maria","Ana","Pedro","Luisa"};
    char apellido[5][51] = {"lalala","mamama","nanana","kakaka","kekeke"};                      // Inicializo el array con 5 empleados
    float salario[5] = {2000, 3000, 2500, 4000, 5000};
    int sector[5] = {3, 2, 1, 4, 4};

    int i;

    for(i=0; i<5; i++)
    {
        list[i].id = id[i];
        strcpy(list[i].name, nombre[i]);
        strcpy(list[i].lastName, apellido[i]);                                                  // asigno cada dato
        list[i].salary = salario[i];
        list[i].sector = sector[i];
        list[i].isEmpty = 1;
    }
}

int initEmployees(eEmployee* list, int len)
{
    int retornar;
    int i;
    if(list != NULL)
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty= 0;                     // Inicializo el array con la bandera isEmpty el 0 demostrando que esta vacio
        }
        retornar= 0;
    }
    else
    {
        retornar= -1;
    }
    return retornar;
}

int addEmployee(eEmployee list[], int len)
{
    int respuesta = -1;
    int index;
    int id;

    index = findSpace(list, len);
    id = getId(list, len);


    if(index != -1)
    {
        printf("\nIngrese el nombre del empleado: ");                                           // pido y valido datos para agregar un nuevo empleado al listado
        fflush(stdin);
        fgets(list[index].name, 51, stdin);
        list[index].name[strlen(list[index].name)-1] = '\0';

        printf("\nIngrese el apellido del empleado: ");
        fflush(stdin);
        fgets(list[index].lastName, 51, stdin);
        list[index].lastName[strlen(list[index].lastName)-1] = '\0';

        list[index].salary = getFloat("\nIngrese el salario del empleado: ");

        list[index].sector = getInt("\nIngrese el sector del empleado(1/2/3/4): ", "\nError. Ingrese el sector del empleado: ", 1, 4);

        list[index].isEmpty = 1;
        list[index].id = id;

        respuesta = 0;

        printf("\nEmpleado cargado con exito. ID: %d\n", list[index].id);       // si el empleado fue cargado con exito aviso el ID al usuario
    }

    if(respuesta == -1)
    {
        printf("No hay espacio disponible.");                                   // si no hay espacio muestro un mensaje avisandole al usuario
    }

    return respuesta;
}

int changeEmployeesData(eEmployee* list, int len)
{
    int respuesta = -1;
    int opcion;
    int id;
    int index;

    printEmployees(list, len);                          // muestro el listado de los empleados

    id = getInt("\nIngrese el ID del empleado a modificar: ", "\nError. Vuelva a intentarlo: ", 0, 1000);   // pido el ID del empleado a modificar algun dato

    index = findEmployeeById(list, len, id);

    if(index >= 0)
    {
        printf("\n¿Que dato desea modificar?\n");
        printf("\n1. Nombre.\n");
        printf("\n2. Apellido.\n");                                 // menu de opciones para modificar un dato a eleccion del usuario
        printf("\n3. Salario.\n");
        printf("\n4. Sector.\n");

        opcion = getInt("\nIngrese una opcion: ", "\nError. Ingrese una opcion: ", 1, 4);

        switch(opcion)
        {
        case 1:
            printf("\nIngrese el nombre del empleado: ");
            fflush(stdin);
            fgets(list[index].name, 51, stdin);
            list[index].name[strlen(list[index].name)-1] = '\0';
            break;
        case 2:
            printf("\nIngrese el apellido del empleado: ");                                         // tomo el dato que modifican y lo guardo en el array del empleado
            fflush(stdin);
            fgets(list[index].lastName, 51, stdin);
            list[index].lastName[strlen(list[index].lastName)-1] = '\0';
            break;
        case 3:
            list[index].salary = getFloat("\nIngrese el salario del empleado: ");
            break;
        case 4:
            list[index].sector = getInt("\nIngrese el sector del empleado(1/2/3/4): ", "Error. Ingrese el sector del empleado: ", 1, 4);
            break;
        }

        respuesta = 0;
        printf("\nLa modificacion fue realizada con exito. ID: %d\n", list[index].id);          // aviso al usuario si el empleado a sido modificado con exito y muestro su ID
    }

    if(respuesta == -1)
    {
        printf("\nHubo un error al modificar.\n");          // aviso al usuario si hubo algun problema al momento de modificar los datos del usuario
    }

    return respuesta;
}

int removeEmployee(eEmployee* list, int len)
{
    int respuesta = -1;
    int i;
    int id;


    printEmployees(list, len);          // muestro el listado de los empleados

    id = getInt("\nIngrese el ID del empleado a dar de baja: ", "Error. Vuelva a intentarlo: ", 0, 1000);                   // pido el ID del empleado a dar de baja

    for(i=0;i<len;i++)
    {
        if(id == list[i].id)                // busco el id del empleado ingresado en el listado
        {
            list[i].isEmpty = 0;                                                            // cambio la bandera isEmpty a 0 y se realiza la baja logica
            respuesta = 0;
            printf("\nLa baja del empleado ha sido realizada con exito.\n");
        }
    }
    if(respuesta == -1)
    {
        printf("\nEl empleado no se encuentra en el listado.\n");
    }

    return respuesta;
}

int findEmployeeById(eEmployee* list, int len, int id)
{
    int respuesta = -1;
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].id == id)                            // Busca el ID del empleado ingresado dentro del array y cuando lo encuentra lo retorna
        {
                respuesta = i;
                break;
        }
    }
    return respuesta;
}

int findSpace(eEmployee* list, int len)
{
    int respuesta = -1;
    int i;

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty == 0)            // busca espacio disponible para crear un nuevo empleado
        {
            respuesta = i;
            break;
        }
    }

    return respuesta;
}

int getId(eEmployee* list, int len)
{
    int respuesta = 0;
    int i;

    if(len > 0 && list != NULL)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == 1)                    // asigna el id del empleado anterior incrementado en 1
            {
                if(list[i].id > respuesta)
                {
                    respuesta = list[i].id;
                }
            }
        }
    }
    return respuesta+1;
}

void printAEmployee(eEmployee myEmployee)
{
    printf("%5d %15s %15s \t%10.2f %15d\n", myEmployee.id, myEmployee.name, myEmployee.lastName, myEmployee.salary, myEmployee.sector);     // ordena los datos de cada empleado para mostrarlos de manera encolumnada
}


void printEmployees(eEmployee list[], int len)
{
    printf("ID \tNombre \t\tApellido \tSalario \tSector\n");
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)            // recorre el array y muestra todos los espacios en los que isEmpty es 1
        {
            printAEmployee(list[i]);
        }
    }
}

void sortEmployees(eEmployee list[], int len)
{
    int i;
    int j;
    eEmployee auxEmployee;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(strcmp(list[i].name, list[j].name) > 0)
            {
                auxEmployee = list[i];                      // ordena el array por apellido de manera alfabetica
                list[i] = list[j];
                list[j] = auxEmployee;
            }
            else
            {
               if(strcmp(list[i].name, list[j].name) == 0)              // si hay alguna coincidencia
               {
                   if(list[i].sector > list[j].sector)
                   {
                        auxEmployee = list[i];                      // los ordena por sector de manera ascendente
                        list[i] = list[j];
                        list[j] = auxEmployee;
                   }
               }
            }
        }

    }
}


