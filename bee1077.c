/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : João Rubens Rezende Monteiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 27/09/2026
Objetivo    : Converter expressoes da forma infixa para a forma posfixa
              usando uma pilha de operadores
Dificuldade : Chegar numa lógica rasoavel para a resolução do problema
Uso de IA   : <<<Se usou, descreva brevemente o uso de IA na solucao>>>
-------------------------------------------------------------------------- */

#include <stdio.h>

// prioridade: quanto maior o numero, antes o operador deve ser feito.
// O '(' recebe 0 para nunca sair da pilha por causa de outro operador.
int prioridade(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// ehOperando: devolve 1 se c for letra ou numero, 0 caso contrario.
int ehOperando(char c) {
    if (c >= 'a' && c <= 'z') return 1;
    if (c >= 'A' && c <= 'Z') return 1;
    if (c >= '0' && c <= '9') return 1;
    return 0;
}

int main() {
    int n;
    char expr[310];   // expressao infixa lida (ate 300 caracteres)
    char pilha[310];  // pilha de operadores
    int topo;         // quantidade de elementos na pilha

    scanf("%d", &n);

    for (int caso = 0; caso < n; caso++) {
        scanf("%s", expr);

        topo = 0;  // pilha comeca vazia

        for (int i = 0; expr[i] != '\0'; i++) {
            char c = expr[i];

            if (ehOperando(c)) {
                // letra ou numero: imprime direto
                printf("%c", c);
            } else if (c == '(') {
                // abre parenteses: empilha
                pilha[topo] = c;
                topo++;
            } else if (c == ')') {
                // fecha parenteses: desempilha e imprime ate achar o '('
                while (pilha[topo - 1] != '(') {
                    topo--;
                    printf("%c", pilha[topo]);
                }
                topo--;  // tira o '(' da pilha sem imprimir
            } else {
                // operador: antes de empilhar, desempilha e imprime os
                // operadores do topo com prioridade maior ou igual
                while (topo > 0 &&
                       prioridade(pilha[topo - 1]) >= prioridade(c)) {
                    topo--;
                    printf("%c", pilha[topo]);
                }
                pilha[topo] = c;
                topo++;
            }
        }

        // acabou a expressao: imprime o que sobrou na pilha
        while (topo > 0) {
            topo--;
            printf("%c", pilha[topo]);
        }

        printf("\n");
    }

    return 0;
}
