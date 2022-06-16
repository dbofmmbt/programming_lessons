#include "pilha.h"
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *prox;
} No;

struct pilha
{
    int total;
    No *topo;
};

// retorna uma pilha vazia
Pilha *criar()
{
    Pilha *p = malloc(sizeof(Pilha));
    p->total = 0;
    p->topo = NULL;

    return p;
}

Pilha *inserir(Pilha *p, int valor)
{
    No *novo_topo = (No *)alocar(sizeof(No));
    novo_topo->prox = p->topo;
    novo_topo->valor = valor;

    p->topo = novo_topo;
    p->total++;
    return p;
}

int ver_topo(Pilha *p)
{
    return p->topo->valor;
}

Pilha *remover(Pilha *p)
{
    if (p->total == 0)
    {
        return p;
    }

    No *removido = p->topo;
    p->topo = removido->prox;
    p->total--;

    free(removido);
    return p;
}
