# Busca Binária — notas para a prova

Disciplina: Algoritmo e Estrutura de Dados 2026S1 (UNIFESP)

O professor avisou que busca binária pode cair na prova.

## 1. Busca binária clássica

- Pré-condição: o vetor precisa estar **ordenado**.
- Custo: O(log n). Recorrência: T(n) = T(n/2) + O(1).
- Invariante: "se o valor existe, está em `[ini, fim]`".
- Pior caso: ⌊log₂ n⌋ + 1 comparações.

```c
int busca(int v[], int n, int x) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        if (v[meio] == x) return meio;
        if (v[meio] < x) ini = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}
```

### Cuidados comuns

- Calcular o meio como `ini + (fim - ini) / 2` evita overflow de `(ini + fim) / 2`.
- Usar `while (ini <= fim)` com `meio + 1` e `meio - 1`. Sem o `+1` / `-1`, o loop pode ficar infinito.
- Quando não achar, retornar um sinal claro (ex.: -1).

## 2. Variações

- **Primeira / última ocorrência** de um valor repetido: ao achar, guardar `meio` e continuar buscando à esquerda (primeira) ou à direita (última).
- **Lower bound**: primeiro elemento `>= x`.
- **Upper bound**: primeiro elemento `> x`.
- Versões **iterativa** e **recursiva**.

## 3. Busca binária sobre a resposta

Não se busca num vetor: busca-se o menor valor `t` tal que `possivel(t)` é verdadeiro.
Funciona porque `possivel` é **monotônica** (se `t` serve, qualquer valor maior também serve).

Pistas no enunciado: "qual o menor/maior valor tal que...", "tempo mínimo para...".
Exemplo no repositório: o problema de tempo de entrega.

## 4. Perguntas teóricas típicas

- **Por que precisa estar ordenado?** Para descartar metade do intervalo a cada comparação.
- **Quantas comparações no pior caso?** ⌊log₂ n⌋ + 1.
- **Vale a pena em lista encadeada?** Não: acessar o meio custa O(n), então perde a vantagem.
