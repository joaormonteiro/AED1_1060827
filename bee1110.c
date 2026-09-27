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

int main() {
    int data;

    struct pilha* pilha = criar_pilha();

    for (int i = 0; i < TAM_MAX; i++) {
        scanf("%d", &data);

        if (data == 0) break;

        push(pilha, data);
    }

    

    return 0;
}