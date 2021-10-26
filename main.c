/*
Author: Juan José Osorio 202021720 j.osorioc@uniandes.edu.cp
*/

#include <stdio.h>
#include <stdlib.h>



/*
Recorre el vector, elemento por elemento, imprimiéndolos en hexa. Uno por línea 
descompuesto en sus bytes de más a menos significativo
*/
void procedimientoEmpaquetamiento(int *apuntador, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
        {
            unsigned char bytes[4];
            bytes[0] = (apuntador[i] >> 24) & 0xFF; // Primer byte
            bytes[1] = (apuntador[i] >> 16) & 0xFF; // Segundo byte
            bytes[2] = (apuntador[i] >> 8) & 0xFF; // Tercer byte
            bytes[3] = apuntador[i] & 0xFF; // Cuarto byte

            // Los valores se cambian a hexadecimal, como el número más grande posible es FF
            // El primer valor es ==  (num//16)%16
            // El segundo valor es == (num%16)
            int separados[] = {
                (bytes[0]/16)%16,
                bytes[0]%16,
                (bytes[1]/16)%16,
                bytes[1]%16,
                (bytes[2]/16)%16,
                bytes[2]%16,
                (bytes[3]/16)%16,
                bytes[3]%16,
            };

            // Vector con los valores de 'separados' como chars
            // Si es mayor a 9 se cambia su valor a base hexa
            char specificFormat[8];
            
            for (int indice=0; indice < 8; indice++)
            {
                int valorComoNum = separados[indice];
                if (valorComoNum == 10)
                {
                    specificFormat[indice] = 'A';
                } else if (valorComoNum == 11)
                {
                    specificFormat[indice] = 'B';
                }else if (valorComoNum == 12)
                {
                    specificFormat[indice] = 'C';
                }else if (valorComoNum == 13)
                {
                    specificFormat[indice] = 'D';
                }else if (valorComoNum == 14)
                {
                    specificFormat[indice] = 'E';
                }else if (valorComoNum == 15)
                {
                    specificFormat[indice] = 'F';
                }else {
                    specificFormat[indice] = valorComoNum + '0';
                }

            }

            /**
             * Se pone en el formato final con los '0x' y el espacio entre cada valor
            */
            char finalFormat[] = {
                '0',
                'x',
                specificFormat[0],
                specificFormat[1],
                ' ',
                '0',
                'x',
                specificFormat[2],
                specificFormat[3],
                ' ',
                '0',
                'x',
                specificFormat[4],
                specificFormat[5],
                ' ',
                '0',
                'x',
                specificFormat[6],
                specificFormat[7]
            };

            // Se imprimen los valores
            printf("\nv[%d] = %s", i, finalFormat); 
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
        procedimientoEmpaquetamiento(elVector, tamanho);
    }
    return 0;
}

