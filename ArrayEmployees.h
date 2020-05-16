#include "input.h"

typedef struct
{
   int id;
   char name[51];
   char lastName[51];           // Entidad de empleados.
   float salary;
   int sector;
   int isEmpty;
} eEmployee;

/** \brief Funcion para incializar con datos.
 *
 * \param recibe un listado de la entidad eEmployee
 * \param int recibe el tamaño del array
 */
void hardcodearEmployees(eEmployee list[], int len);

/** \brief Inicializa el array con la bandera isEmpty en 0
 *
 * \param recibe un listado del array.
 * \param int recibe el tamaño del array
 * \return retorna un 0 si pudo inicializar el array y un -1 si hubo algun error
 *
 */
int initEmployees(eEmployee* list, int len);

/** \brief Esta funcion permite al usuario agregar un empleado a la lista
 *
 * \param recibe un listado del array
 * \param int recibe el tamaño del array
 * \return si se pudo cargar el empleado retorna 0 / si hubo algun error -1
 *
 */
int addEmployee(eEmployee list[], int len);

/** \brief Esta funcion busca un espacio vacio en el array para cargar un usuario
 *
 * \param recibe un listado del array
 * \param int recibe el tamaño del array
 * \return retorna un indice en el array si encontro un lugar disponible y retorna -1 si no pudo hacerlo
 *
 */
int findSpace(eEmployee* list, int len);

/** \brief Esta funcion busca a un empleado en el array por su ID asignado
 *
 * \param recibe un puntero del listado del array
 * \param int recibe el tamaño del array
 * \param recibe el id del empleado a buscar
 * \return retorna un indice del array donde se encuentra el empleado con el ID ingresado / retorna -1 si hubo un error
 *
 */
int findEmployeeById(eEmployee* list, int len, int id);

/** \brief Esta opcion permite al usuario modificar la informacion de un empleado
 *
 * \param recibe un puntero del listado del array
 * \param int recibe el tamaño del array
 * \return retorna 0 si el empleado a sido modificado con exito / retorna -1 si hubo un error en la modificacion
 *
 */
int changeEmployeesData(eEmployee* list, int len);

/** \brief Esta funcion permite al usuario eliminar un empleado de la lista de forma logica
 *
 * \param recibe un puntero del listado del array
 * \param int recibe el tamaño del array
 * \return retorna 0 si el empleado se ha eliminado con exito / retorna -1 si hubo un error en la eliminacion
 *
 */
int removeEmployee(eEmployee* list, int len);

/** \brief Esta funcion ordena el listado de los empleados alfabeticamente o por sector de haber una coincidencia
 *
 * \param recibe un listado del array
 * \param int recibe el tamaño del array
 *
 */
void sortEmployees(eEmployee list[], int len);

/** \brief Esta funcion ordena los datos de cada empleado para mostrarlos de manera encolumnada
 *
 * \param recibe un listado del array
 *
 */
void printAEmployee(eEmployee myEmployee);

/** \brief Esta funcion muestra el listado de todos los empleados registrados
 *
 * \param recibe un listado del array
 * \param int recibe el tamaño del array
 *
 */
void printEmployees(eEmployee list[], int len);

/** \brief Esta funcion asigna un ID de forma incremental a cada empleado
 *
 * \param recibe un puntero del listado del array
 * \param int recibe el tamaño del array
 * \return retorna el id+1 del empleado al que se lo asigna / retorna -1 si hubo un error
 *
 */
int getId(eEmployee* list, int len);



