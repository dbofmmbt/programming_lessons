#include <stdio.h>
#include "lista.h"

void main()
{
    Lista *lista = criar();

    inserir_fim(lista, 1);
    inserir_fim(lista, 2);
    inserir_fim(lista, 3);

    int tam = tamanho(lista);

    printf("[");
    for (int i = 0; i < tam; i++)
    {
        int valor = acessar(lista, i);
        printf("%d ", valor);
    }
    printf("]\n");

    liberar(lista);
}