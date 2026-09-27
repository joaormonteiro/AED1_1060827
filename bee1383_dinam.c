/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : João Rubens Rezende Monteiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 27/09/2026
Objetivo    : Verificar se matrizes 9x9, guardadas numa lista encadeada
dinâmica, são soluções válidas de Sudoku (linhas, colunas e quadrantes 3x3).
Dificuldade : <<<Qual foi o principal desafio neste problema?>>>
Uso de IA   : O Claude Code me ajudou a encontrar um erro relacionado
a liberação da memória.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

// Cada célula da lista guarda uma instância inteira (uma matriz 9x9)
struct cel {
    int conteudo[9][9];
    struct cel* seguinte;
};

typedef struct cel celula;

// Lê uma matriz, cria uma nova célula com ela, pendura depois de ult e
// devolve a nova célula (que passa a ser o último elemento da lista)
celula* insere(celula* ult) {
    celula* nova = malloc(sizeof(celula));

    for (int j = 0; j < 9; j++) {
        for (int k = 0; k < 9; k++) {
            scanf("%d", &nova->conteudo[j][k]);
        }
    }
    nova->seguinte = NULL;
    ult->seguinte = nova;
    return nova;
}

// Libera todas as células a partir de p
void libera(celula* p) {
    while (p != NULL) {
        celula* prox = p->seguinte;
        free(p);
        p = prox;
    }
}

void zerarvisto(int v[]) {
    // Zera o vetor que verifica se houve repetiçao de algum número
    for (int j = 0; j < 10; j++) {
        v[j] = 0;
    }
}

// Devolve 1 se a matriz é solução de Sudoku, 0 caso contrário
int verif(int v[9][9]) {
    int visto[10];  // Vetor que verifica se houve repetiçao de algum número

    // Verifica se todas as linhas estão válidas
    for (int j = 0; j < 9; j++) {
        zerarvisto(visto);
        for (int k = 0; k < 9; k++) {
            if (v[j][k] < 1 || v[j][k] > 9 || visto[v[j][k]] == 1) {
                return 0;
            }
            visto[v[j][k]] = 1;
        }
    }

    // Verifica se todas as colunas estão válidas
    for (int k = 0; k < 9; k++) {
        zerarvisto(visto);
        for (int j = 0; j < 9; j++) {
            if (v[j][k] < 1 || v[j][k] > 9 || visto[v[j][k]] == 1) {
                return 0;
            }
            visto[v[j][k]] = 1;
        }
    }

    // Verifica se todos os quadrantes estão válidos
    for (int l = 0; l < 9; l += 3) {
        for (int m = 0; m < 9; m += 3) {
            zerarvisto(visto);
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    int x = v[l + j][m + k];
                    if (x < 1 || x > 9 || visto[x] == 1) {
                        return 0;
                    }
                    visto[x] = 1;
                }
            }
        }
    }

    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    // Célula cabeça: não guarda dado, só marca o início da lista
    celula cabeca;
    cabeca.seguinte = NULL;
    celula* ult = &cabeca;

    // Inserir sempre no fim mantém as instâncias na ordem da entrada
    for (int i = 0; i < n; i++) {
        ult = insere(ult);
    }

    int i = 1;
    for (celula* p = cabeca.seguinte; p != NULL; p = p->seguinte, i++) {
        printf("Instancia %d\n", i);
        if (verif(p->conteudo)) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    libera(cabeca.seguinte);
    return 0;
}
