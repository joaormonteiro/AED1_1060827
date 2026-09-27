/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : João Rubens Rezende Monteiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 27/09/2026
Objetivo    : Simular o descarte de cartas usando pilhas
Dificuldade : <<<Qual foi o principal desafio neste problema?>>>
Uso de IA   : <<<Se usou, descreva brevemente o uso de IA na solução>>>
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 50

struct pilha {
    int topo;
    int items[TAM_MAX];
};

struct pilha* criar_pilha() {
    struct pilha* nova_pilha = (struct pilha*)malloc(sizeof(struct pilha));
    nova_pilha->topo = -1;
    return nova_pilha;
}

int is_empty(struct pilha* pilha) { return pilha->topo == -1; }

void push(struct pilha* pilha, int item) {
    if (pilha->topo == TAM_MAX - 1) {
        printf("Erro: pilha cheia.\n");
    } else {
        pilha->topo++;
        pilha->items[pilha->topo] = item;
    }
}

int pop(struct pilha* pilha) {
    if (is_empty(pilha)) {
        printf("Erro: pilha vazia.\n");
        return -1;
    } else {
        int item_removido = pilha->items[pilha->topo];
        pilha->topo--;
        return item_removido;
    }
}

// Coloca "item" na base de "pilha" usando "aux" como apoio:
// tira tudo para aux, empilha o item (vira a base) e devolve o resto por cima
void coloca_na_base(struct pilha* pilha, struct pilha* aux, int item) {
    while (!is_empty(pilha)) {
        push(aux, pop(pilha));
    }
    push(pilha, item);
    while (!is_empty(aux)) {
        push(pilha, pop(aux));
    }
}

int main() {
    int n;

    struct pilha* monte = criar_pilha();
    struct pilha* aux = criar_pilha();

    // cada linha é um caso de teste; 0 encerra
    while (scanf("%d", &n) == 1 && n != 0) {
        monte->topo = -1;

        // empilha de n até 1 para a carta 1 ficar no topo
        for (int i = n; i >= 1; i--) {
            push(monte, i);
        }

        printf("Discarded cards:");
        int primeira = 1;
        while (monte->topo >= 1) {  // 2 ou mais cartas
            int descartada = pop(monte);             // joga fora a do topo
            coloca_na_base(monte, aux, pop(monte));  // move a próxima p/ base

            if (primeira) {
                printf(" %d", descartada);
                primeira = 0;
            } else {
                printf(", %d", descartada);
            }
        }
        printf("\n");

        printf("Remaining card: %d\n", pop(monte));
    }

    free(monte);
    free(aux);
    return 0;
}
