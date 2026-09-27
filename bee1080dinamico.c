/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : João Rubens Rezende Monteiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 27/09/2026
Objetivo    : Ler 100 inteiros numa lista encadeada e exibir o maior e sua posição
Dificuldade : <<<Qual foi o principal desafio neste problema?>>>
Uso de IA   : <<<Se usou, descreva brevemente o uso de IA na solução>>>
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

#define TOTAL 100

struct cel {
    int data;
    struct cel* next;
};

typedef struct cel celula;

void insere(int y, celula* list) {
    celula* new;  // ponteiro para o nó a ser criado

    new = malloc(
        sizeof(celula));  // aloca espaço para o nó inteiro (dado mais ponteiro)

    new->data = y;  // abastece o dado com o valor y
    new->next =
        list->next;    // o novo nó aponta para quem era o primeiro elemento
    list->next = new;  // a cabeça aponta para o novo nó
}

// Como insere() coloca cada valor no início, a lista fica na ordem inversa da
// entrada: o elemento de índice i na lista (0-based) foi o (n - i)-ésimo lido.
int buscaPosicaoMaior(celula* list, int n) {
    celula* p;       // cursor auxiliar
    p = list->next;  // começa na primeira celula lista (pula a cabeça)
    int maiorValor = p->data;
    int indiceMaior = 0;
    int i = 0;

    while (p != NULL) {
        if (p->data > maiorValor) {
            maiorValor = p->data;
            indiceMaior = i;
        }
        i++;
        p = p->next;
    }

    return n - indiceMaior;  // converte índice da lista em posição da entrada
}

int buscaMaior(celula* list, int posicao, int n) {
    celula* p;
    p = list->next;

    // a posição de entrada "posicao" está no índice (n - posicao) da lista
    for (int i = 0; i < n - posicao; i++) {
        p = p->next;
    }
    return p->data;
}

void libera(celula* list) {
    celula* p = list->next;
    while (p != NULL) {
        celula* prox = p->next;
        free(p);
        p = prox;
    }
    list->next = NULL;
}

int main() {
    celula cabeca;  // célula cabeça (não guarda dado)
    cabeca.next = NULL;
    celula* lista = &cabeca;
    int posicao;

    for (int i = 0; i < TOTAL; i++) {
        int x;
        scanf("%d", &x);
        insere(x, lista);
    }

    posicao = buscaPosicaoMaior(lista, TOTAL);
    printf("%d\n%d\n", buscaMaior(lista, posicao, TOTAL), posicao);

    libera(lista);
    return 0;
}
