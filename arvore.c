#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esq;
    struct No* dir;
} No;

/* Cria um novo nó com o valor informado */
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

/* Insere um valor na ABB (recursivo) */
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) { /* caso-base: posição vazia */
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

/* Percurso em ordem: esquerda, nó, direita */
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        emOrdem(raiz->dir);
    }
}

/* Libera toda a memória da árvore */
void liberar(No* raiz) {
    if (raiz != NULL) {
        liberar(raiz->esq);
        liberar(raiz->dir);
        free(raiz);
    }
}

int main(void) {
    No* raiz = NULL;
    int n, i, x;

    printf("Quantos numeros deseja inserir? ");
    scanf("%d", &n);

    printf("Digite os %d numeros inteiros distintos:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        raiz = inserir(raiz, x);
    }

    printf("Saida em ordem: ");
    emOrdem(raiz);
    printf("\n");

    liberar(raiz);
    return 0;
}