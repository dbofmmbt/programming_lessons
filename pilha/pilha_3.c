#include "pilha.h"
#include <stdlib.h>
#include "alocar.h"

struct pilha
{
    int *dados;
    int tam;
};

#define MAX_SIZE 1000

// retorna uma pilha vazia
Pilha *criar()
{
    Pilha *p = (Pilha *)alocar(sizeof(Pilha));
    p->dados = (int *)alocar(MAX_SIZE * sizeof(int));
    p->tam = 0;

    return p;
}

Pilha *inserir(Pilha *p, int valor)
{
    p->dados[p->tam] = valor;
    p->tam++;
    return p;
}

int ver_topo(Pilha *p)
{
    return p->dados[p->tam - 1];
}

Pilha *remover(Pilha *p)
{
    p->tam--;
    return p;
}
