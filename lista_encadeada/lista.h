typedef struct lista Lista;

Lista *criar();

void liberar(Lista *);

void inserir_inicio(Lista *, int);

void inserir_fim(Lista *, int);

void inserir(Lista *, int valor, int posicao);

void remover(Lista *, int posicao);

int acessar(Lista *, int posicao);

int tamanho(Lista *);