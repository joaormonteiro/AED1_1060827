#include <stdio.h>
#include <stdlib.h>

int BuscaBinária(int x, int n, int v[]) {
    // x = valor a ser encontrado
    // n = tamanho do vetor
    // v[] = vetor a ser buscado
    // e = extremo esquerdo da maior posicao onde v[e] < x
    // d = extremo direito da menor posicao onde v[d] >= x
    // m = posicao exata do meio do vetor atual (entre "e" e "d")
    int e, m, d;
    e = -1;
    d = n;
    while (/*X*/ e < d - 1) {
        m = (e + d) / 2;
        if (v[m] < x)
            e = m;
        else
            d = m;
    }
    return d;
}