// Tipo Abstrato de Dados

typedef struct pilha Pilha;

// retorna uma pilha vazia
Pilha *criar();

Pilha *inserir(Pilha *p, int valor);

int ver_topo(Pilha *p);

Pilha *remover(Pilha *p);
