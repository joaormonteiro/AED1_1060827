/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : João Rubens Rezende Monteiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 27/09/2026
Objetivo    : Verificar, usando uma pilha, se o balanceamento de parenteses
              de cada expressao esta correto.
Dificuldade : Perceber que a pilha so precisa guardar os '(' abertos, e
              tratar o caso de um ')' aparecer com a pilha ja vazia.
Uso de IA   : IA fez os  comentarios do código.
-------------------------------------------------------------------------- */

#include <stdio.h>

int main() {
    char expr[1010];  // expressao lida (ate 1000 caracteres)
    char pilha[1010];
    int topo;

    // le linha por linha ate o fim da entrada (nao ha N na entrada)
    while (fgets(expr, sizeof(expr), stdin) != NULL) {
        topo = 0;
        int erro = 0;

        for (int i = 0; expr[i] != '\0'; i++) {
            char c = expr[i];

            if (c == '(') {
                pilha[topo] = c;  // empilha o '('
                topo++;
            } else if (c == ')') {
                if (topo == 0) {
                    erro = 1;  // fechou sem ter um '(' correspondente
                    break;
                }
                topo--;  // desempilha o '(' que esse ')' fecha
            }
        }

        // se sobrou algo na pilha, ficou '(' sem fechar
        if (erro == 0 && topo == 0) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
