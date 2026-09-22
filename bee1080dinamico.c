#include <stdio.h>
#include <stdlib.h>

struct cel {
    int data;
    struct cel* next;
};

typedef struct cel celula;
celula c;
celula* p;

void insere(int y, celula* list) {
    celula* new;  // ponteiro para o nó a ser criado

    new = malloc(
        sizeof(celula));  // aloca espaço para o nó inteiro (dado mais ponteiro)

    new->data = y;  // abastece o dado com o valor y
    new->next =
        list->next;    // o novo nó aponta para quem era o primeiro elemento
    list->next = new;  // a cabeça aponta para o novo nó
}

int buscaPosicaoMaior(celula* list) {
    celula* p;       // cursos auxiliar
    p = list->next;  // começa na primeira celula lista (pula a cabeça)
    int maiorValor = 0;
    int posição = 1;

    while (p != NULL) {
        if (p->data > maiorValor) {
            maiorValor = p->data;
            posição = 0;
        }
        posição += 1;
        p = p->next;
    }

    return posição;
}

celula* buscaMaior(celula* list, int posicao) {
    celula* p;
    p = list->next;

    for (int i = 0; i < posicao; i++) {
        p = list->next;
        p = p->next;
    }
    return p->data;
}

int main() {
    celula* lista;
    int posicao;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        insere(x, lista);
    }

    posicao = N - buscaPosicaoMaior(lista);
    printf("%d \n %d", posicao, buscaMaior(lista, posicao));
}
