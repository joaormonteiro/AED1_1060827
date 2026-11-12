#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 50

struct pilha {
    int topo;
    int items[TAM_MAX];
};

void push(struct pilha* pilha, int item) {
    if ((pilha->topo + 1) < TAM_MAX) {
        pilha->items[pilha->topo + 1] = item;
        pilha->topo++;
    }
    return;
}

int pop(struct pilha* pilha) {
    if (pilha->topo != -1) {
        int topo = pilha->items[pilha->topo];
        pilha->topo--;
        return topo;
    }
    return -1;
}

void preeche(struct pilha* pilha, int n) {
    for (int i = n; i > 0; i--) {
        push(pilha, i);
    }
    return;
}

void topobase(struct pilha* pilha) {
    int aux = pilha->items[pilha->topo];
    for (int i = pilha->topo + 1; i > 0; i--) {
        pilha->items[i] = pilha->items[i - 1];
    }
    pilha->items[0] = aux;
}

int main() {
    int n = -1;
    int descartadas[TAM_MAX];
    while (n != 0) {
        scanf("%d", &n);
        struct pilha pilha;
        pilha.topo = -1;
        preeche(&pilha, n);
        for (int i = 0; i < n - 1; i++) {
            descartadas[i] = pop(&pilha);
            topobase(&pilha);
        }
        pilha.topo = -1;
    }
    printf("Discarded cards: ");
    for (int i = 0; i < n - 2; i++) {
        printf("Discarded cards: %d", descartadas[i]);
    }
    printf("Remaining card: %d", pilha.items[0]);
}
