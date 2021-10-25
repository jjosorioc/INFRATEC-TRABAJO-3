/*
Author: Juan José Osorio 202021720 j.osorioc@uniandes.edu.cp
*/

#include <stdio.h>
#include <stdlib.h>



/*
Recorre el vector, elemento por elemento, imprimiéndolos en hexa. Uno por línea 
descompuesto en sus bytes de más a menos significativo
*/
void procedimientoEmpaquetamiento(int (**apuntador), int tamanho) // Es ** porque es un apuntador a un apuntador
{
    for (int i = 0; i < tamanho; i++)
        {
            printf("\nIndex %d: %d", i, (*apuntador)[i]);
        }
}


/*
Sigue la estructura, paso por paso, del PDF
*/
int main(void)
{
    int tamanho; // El tamaño del vector
    
    printf("\nIngrese el tamaño del vector (Este debe ser mayor a 0)\n~ ");
    scanf("%d", &tamanho);
    
    if (!(tamanho > 0)) // Se valida que el tamaño sea mayor que 0
    {
        printf("\n¡El tamaño del vector no puede ser 0!\n");
    }

    else
    {
        printf("\nSize válido");
        int * elVector; // se declara e inicializa el apuntador al vector de int
        elVector = (int*)calloc(tamanho, sizeof(int));

        // No está en el PDF: Revisar que la memoria haya sido asignada correctamente
        if (elVector == NULL)
        {
            printf("\nEl espacio en memoria no fue asignado.\n");
            exit(0); // Se termina el programa
        }

        int ingresoUsuario; // Int: Input del usuario
        printf("\nIngrese cada elemento en su respectivo índice\n");

        for (int i = 0; i < tamanho; i++)
        {
            printf("\nIngrese el elemento para el índice %d: ", i);
            scanf("%d", &ingresoUsuario);
            elVector[i] = ingresoUsuario; // Se ingresa el input al vector
        }

        // Se invoca el procedimiento que imprime el vector
        procedimientoEmpaquetamiento(&elVector, tamanho);
    }
    return 0;
}

