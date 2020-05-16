#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

int getInt(char mensaje[], char error[], int min, int max)
{
    int dato;
    printf("%s", mensaje);
    scanf("%d", &dato);
    while(dato < min || dato > max)
    {
        printf("%s", mensaje);
        scanf("%d", &dato);
    }
    return dato;
}

/*char getStr(char mensaje[])
{
    char dato[30];
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &dato);

    return  dato;
}*/

float getFloat(char mensaje[])
{
    float dato;
    printf("%s", mensaje);
    scanf("%f", &dato);

    return dato;
}
