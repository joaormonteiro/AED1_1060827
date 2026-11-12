#include <stdio.h>
#include <stdlib.h>

struct fila {
    struct elemento* inicio;
    struct elemento* final;
};
typedef struct fila Fila;

struct elemento {
    int carta;
    struct elemento* prox;
};
typedef struct elemento Elem;

Fila* criar_fila() {
    Fila* fi = (Fila*)malloc(sizeof(Fila));
    if (fi != NULL) {
        fi->final = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

int insere_fila(Fila* fi, int n) {
    if (fi == NULL) return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->carta = n;
    no->prox = NULL;
    if (fi->final == NULL)
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    return 1;
};

int remove_fila(Fila* fi) {
    if (fi == NULL) return 0;
    if (fi->inicio == NULL) return 0;
    Elem* no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if (fi->inicio == NULL) fi->final = NULL;
    free(no);
    return 1;
}

int jogando_cartas_fora(Fila* fi) {
    if (fi == NULL) return 0;
    remove_fila(fi);
    if (fi->inicio == NULL) return 0;
    insere_fila(fi, fi->inicio->carta);
    remove_fila(fi);
    return 1;
}

int main() {
    int n = -1;
    Fila *fi;
    while (n != 0) {
        scanf("%d\n", &n);
        insere_fila(fi, n);
    }

    return 0;
}
