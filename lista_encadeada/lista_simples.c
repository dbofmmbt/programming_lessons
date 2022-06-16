#include <stdlib.h>
#include <stdio.h>

#include "lista.h"

typedef struct node
{
    int valor;
    struct node *prox;
} Node;

struct lista
{
    int tam;
    Node *inicio;
};

Node *criar_node(int valor, Node *prox)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        exit(1);
    }
    node->valor = valor;
    node->prox = prox;
    return node;
}

Node *chegar_no_node(Lista *lista, int saltos)
{

    Node *atual = lista->inicio;
    for (int i = 0; i < saltos; i++)
    {
        atual = atual->prox;
    }
    Node *destino = atual;
    return destino;
}

Lista *criar()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista == NULL)
    {
        exit(1);
    }
    lista->tam = 0;
    lista->inicio = NULL;
    return lista;
}

void inserir_inicio(Lista *lista, int valor)
{
    Node *node = criar_node(valor, lista->inicio);

    lista->inicio = node;
    lista->tam++;
}

void inserir_fim(Lista *lista, int valor)
{
    if (lista == NULL)
    {
        return;
    }

    Node *novo_fim = criar_node(valor, NULL);

    if (lista->tam == 0)
    {
        lista->inicio = novo_fim;
        lista->tam++;
        return;
    }

    Node *atual = lista->inicio;
    while (atual->prox)
    {
        atual = atual->prox;
    }

    Node *fim = atual;
    fim->prox = novo_fim;

    lista->tam++;
}

void inserir(Lista *lista, int valor, int posicao)
{
    if (lista == NULL)
    {
        return;
    }

    if (posicao >= lista->tam)
    {
        fprintf(stderr, "Fora dos limites da lista");
        return;
    }

    Node *alvo = chegar_no_node(lista, posicao);
    Node *novo_node = criar_node(alvo->valor, alvo->prox);
    alvo->prox = novo_node;
    alvo->valor = valor;

    lista->tam++;
}

void remover(Lista *lista, int posicao)
{
    if (lista == NULL)
    {
        return;
    }

    if (posicao >= lista->tam)
    {
        fprintf(stderr, "Fora dos limites da lista");
        return;
    }

    if (posicao == 0)
    {
        Node *antigo_inicio = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(antigo_inicio);
        lista->tam--;
        return;
    }

    Node *antecessor = chegar_no_node(lista, posicao - 1);
    Node *alvo = antecessor->prox;

    antecessor->prox = alvo->prox;
    free(alvo);
    lista->tam--;
}

int acessar(Lista *lista, int posicao)
{
    Node *node = chegar_no_node(lista, posicao);
    return node->valor;
}

int tamanho(Lista *lista)
{
    return lista->tam;
}

void liberar(Lista *lista)
{
    Node *atual = lista->inicio;
    while (atual)
    {
        Node *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    free(lista);
}