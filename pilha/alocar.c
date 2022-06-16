#include <stdio.h>

void *alocar(int size)
{
    void *memory = malloc(size);

    if (!memory)
    {
        fprintf(stderr, "Sem memória!");
        exit(1);
    }

    return memory;
}