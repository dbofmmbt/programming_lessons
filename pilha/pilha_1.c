#include "pilha.h"
#include "alocar.h"
#include <stdlib.h>

struct pilha
{
    int valor;
    struct pilha *prox;
};

Pilha *criar()
{
    return NULL;
}

Pilha *inserir(Pilha *p, int valor)
{
    Pilha *novo = (Pilha *)alocar(sizeof(Pilha));
    novo->valor = valor;
    novo->prox = p;
    return novo;
}

int ver_topo(Pilha *p)
{
    return p->valor;
}

Pilha *remover(Pilha *p)
{
    Pilha *restante = p->prox;
    free(p);
    return restante;
}
