#include <stdlib.h>

#include "lista.h"

struct lista
{
    int tamanho, capacidade;
    int *valores;
};

#define CAPACIDADE_INICIAL 100

Lista *criar()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista == NULL)
    {
        exit(1);
    }
    lista->valores = (int *)malloc(CAPACIDADE_INICIAL * sizeof(int));
    lista->capacidade = CAPACIDADE_INICIAL;
    lista->tamanho = 0;
    return lista;
}

void liberar(Lista *lista)
{
    free(lista->valores);
    free(lista);
}

void inserir_inicio(Lista *lista, int valor)
{
    if (lista->tamanho == lista->capacidade)
    {
        lista->capacidade *= 2;
        lista->valores = realloc(lista->valores, lista->capacidade * sizeof(int));
        if (lista->valores == NULL)
        {
            exit(1);
        }
    }

    lista->valores[lista->tamanho] = valor;
    lista->tamanho++;
}

void inserir_fim(Lista *, int);

void inserir(Lista *, int valor, int posicao);

void remover(Lista *, int posicao);

int acessar(Lista *, int posicao);

int tamanho(Lista *);