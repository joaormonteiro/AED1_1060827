/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : João Rubens Rezende Monteiro
Linguagem   : C
Data        : 29/08/2026
Objetivo    : Operacoes basicas de lista encadeada com celula-cabeca
              (imprime, busca, insere, buscaEremove, removeSeguinte)
Dificuldade : <<<Qual foi o principal desafio neste problema?>>>
Uso de IA   : <<<Se usou, descreva brevemente o uso de IA na solucao>>>
-------------------------------------------------------------------------- */

#include <stdlib.h>   /* malloc, free  */
#include <stdio.h>    /* printf        */

/* Celula: um no da lista encadeada. */
struct cel {
    int conteudo;         /* valor inteiro guardado no no                       */
    struct cel* seguinte; /* ponteiro para o proximo no (NULL se for o ultimo)  */
};

typedef struct cel celula;  /* apelido: usar 'celula' em vez de 'struct cel' */

/* Convencao: a lista tem CELULA-CABECA. A primeira celula nao guarda dado
   valido, serve so de ponto de entrada; os dados comecam em lst->seguinte. */


/* imprime: percorre a lista do inicio ao fim e mostra o conteudo de cada no. */
void imprime(celula* lst) {
    celula* p;   /* cursor auxiliar: caminha pela lista sem alterar 'lst' */

    /* inicializacao: p comeca na 1a celula real (pula a cabeca)
       condicao   : repete enquanto nao chegou ao fim (p != NULL)
       passo      : a cada volta, avanca para o proximo no                */
    for (p = lst->seguinte; p != NULL; p = p->seguinte)
        printf("%d \n", p->conteudo);   /* imprime o inteiro do no atual, um por linha */
}


/* busca: procura o valor x na lista.
   Retorna o ponteiro para o no que contem x, ou NULL se nao existir. */
celula* busca(int x, celula* lst) {
    celula* p;              /* cursor auxiliar */

    p = lst->seguinte;      /* comeca na 1a celula real (pula a cabeca) */

    /* anda enquanto AINDA HA no (p != NULL) E o no atual nao contem x.
       o teste p != NULL vem antes para nao acessar p->conteudo com p nulo. */
    while (p != NULL && p->conteudo != x)
        p = p->seguinte;    /* avanca para o proximo no */

    return p;               /* NULL = nao achou; caso contrario = no que contem x */
}


/* insere: cria um no com o valor y e o coloca no inicio da lista,
   logo apos a celula-cabeca. */
void insere(int y, celula* lst) {
    celula* nova;                     /* ponteiro para o no que sera criado */

    nova = malloc(sizeof(celula));    /* aloca espaco para um no INTEIRO (int + ponteiro) */

    nova->conteudo = y;               /* guarda o valor no campo de dados         */
    nova->seguinte = lst->seguinte;   /* o novo no aponta para quem era o 1o elem. */
    lst->seguinte = nova;             /* a cabeca aponta para o novo no: ele vira o 1o */
}


/* buscaEremove: procura x e remove da lista a 1a celula que o contem.
   Se x nao estiver na lista, nada muda. */
void buscaEremove(int x, celula* lst) {
    celula *p, *q;          /* p = no anterior; q = no atual (sempre adjacentes) */

    p = lst;                /* o 'anterior' comeca na propria cabeca   */
    q = lst->seguinte;      /* o 'atual' comeca na 1a celula real      */

    /* anda com os dois em par enquanto ha no e ele nao contem x */
    while (q != NULL && q->conteudo != x) {
        p = q;              /* o anterior passa a ser o no atual */
        q = q->seguinte;    /* o atual avanca uma posicao        */
    }

    if (q != NULL) {                 /* achou: q e o no a remover                  */
        p->seguinte = q->seguinte;   /* o anterior 'salta' por cima de q           */
        free(q);                     /* libera a memoria do no (depois de religar) */
    }
}


/* removeSeguinte: remove o no que vem logo DEPOIS de p.
   O chamador deve garantir que esse no existe (p e p->seguinte nao nulos).
   Nome diferente de 'remove' para nao colidir com a funcao de <stdio.h>. */
void removeSeguinte(celula* p) {
    celula* lixo;                  /* segura o endereco do no a descartar */

    lixo = p->seguinte;            /* no a remover = sucessor de p                */
    p->seguinte = lixo->seguinte;  /* p passa a apontar para o sucessor do lixo   */
    free(lixo);                    /* devolve a memoria (a lista ja esta religada) */
}
