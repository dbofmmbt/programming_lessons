#include <stdio.h>
#include <string.h>

/* 1. Uma empresa que organiza concursos está realizando um grande processo seletivo e conta com um sistema informatizado para auxiliar no gerenciamento de informações sobre os candidatos.
Nesse sistema, as informações referentes aos candidatos são armazenadas em um vetor de ponteiros para dados estruturados do tipo Candidato, conforme descrito a seguir: */

typedef struct data
{
    int dia, mes, ano;
} Data;

typedef struct local
{
    char ender[81]; /* endereço do local de provas */
    int sala;       /* numero sala */
} Local;

typedef struct notas
{
    float geral;      /* prova de conhecimentos gerais */
    float especifica; /* prova de conhecimentos especificos */
} Notas;

typedef struct candidato
{
    int inscr;     /* numero de inscricao */
    char nome[81]; /* nome do candidato */
    Data nasc;     /*data de nascimento*/
    Local *loc;    /*local de prova*/
    Notas nt;      /* notas de prova */
} Candidato;

/* a. Faça um programa que leia as informações de n candidatos. Crie uma variável alocada dinamicamente que armazene as informações lidas. */

int main(void)
{
    Candidato candidato;

    candidato.inscr = 123;

    char *nome = pegar_nome();
    strcpy(candidato.nome, nome);

    candidato.nasc.dia = 5;
    candidato.nasc.mes = 12;
    candidato.nasc.ano = 1998;

    // equivalente
    Data *end_nasc = &candidato.nasc;
    end_nasc->dia = 5;
    end_nasc->mes = 12;
    end_nasc->ano = 1998;

    candidato.loc = (Local *)malloc(sizeof(Local));
    if (!candidato.loc)
    {
        exit(1);
    }

    char *endereco = pegar_endereco();
    strcpy(candidato.loc->ender, endereco);

    candidato.loc->sala = 202;

    candidato.nt.geral = 10.0;
    candidato.nt.especifica = 11.0;

    //////////////////////////////////
    // '''
    // Fazer coisas com o candidato
    // ...
    /////////////////////////////////

    free(candidato.loc);
}

char *pegar_nome()
{
    return "Eduardo Canellas";
}

char *pegar_endereco()
{
    return "Rua dos bobos, 0";
}