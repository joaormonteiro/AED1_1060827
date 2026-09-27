/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : João Rubens Rezende Monteiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 27/09/2026
Objetivo    : Calcular o tempo total que um carteiro leva para entregar
              encomendas em ordem, usando busca binaria para achar a posicao
              de cada casa na rua.
Dificuldade : <<<Qual foi o principal desafio neste problema?>>>
Uso de IA   : <<<Se usou, descreva brevemente o uso de IA na solucao>>>
-------------------------------------------------------------------------- */

#include <stdio.h>

// buscaBinaria: acha o indice de x no vetor v (v tem que estar ordenado)
// e = extremo esquerdo da maior posicao onde v[e] < x
// d = extremo direito da menor posicao onde v[d] >= x
// m = posicao do meio entre "e" e "d"
int buscaBinaria(int x, int n, int v[]) {
    int e, m, d;
    e = -1;
    d = n;
    while (e < d - 1) {
        m = (e + d) / 2;
        if (v[m] < x)
            e = m;
        else
            d = m;
    }
    return d;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int casas[45000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &casas[i]);
    }

    long long total = 0;
    int posAtual = 0;  // carteiro comeca na casa de indice 0 (menor numero)

    for (int i = 0; i < m; i++) {
        int encomenda;
        scanf("%d", &encomenda);

        // acha em que posicao da rua fica a casa dessa encomenda
        int posEncomenda = buscaBinaria(encomenda, n, casas);

        // soma a distancia (em indices) ate a proxima entrega
        int diferenca = posEncomenda - posAtual;
        if (diferenca < 0) {
            diferenca = -diferenca;
        }
        total += diferenca;

        posAtual = posEncomenda;
    }

    printf("%lld\n", total);

    return 0;
}
