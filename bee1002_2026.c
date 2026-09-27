/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : João Rubens Rezende Monteiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1002
Data        : 24/09/2026
Objetivo    : Calcular a área de um círculo a partir do raio informado
Dificuldade : Simples erros de sintaxe
Uso de IA   : Usei IA apenas como auxílio simples para identificação do erro de
sintaxe
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

double potencia(double n, int expoente) {
    for (int i = 1; i < expoente; i++) {
        n = n * n;
    }
    return n;
};

double areaCirculo(double raio) {
    double pi = 3.14159;
    double area = pi * (potencia(raio, 2));

    return area;
}

int main() {
    double raio;
    double area;
    scanf("%lf", &raio);
    area = areaCirculo(raio);

    printf("A=%.4f\n", area);
}
