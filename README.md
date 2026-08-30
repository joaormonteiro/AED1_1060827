# AED_1 — Data Structures & Algorithms coursework

First data-structures course (Algoritmos e Estruturas de Dados I), UNIFESP.
Everything here is in C.

## Contents

- **`Comparação de algoritmos de ordenação/`** — a small benchmark that runs
  Insertion Sort, Merge Sort and Quick Sort over the same random arrays and
  times each one (`clock()`). `main.c` times a single user-given size;
  `gerar_dados.c` sweeps sizes from 20k to 400k (3 runs averaged) and writes
  `dados.csv` for plotting.
- **`ListaEncadeada.c`** — singly linked list implementation.
- **`sudoku.c`**, **`mdc.c`**, **`tempo.c`** — smaller exercises (backtracking
  Sudoku solver, GCD, time arithmetic).
- **`bee*.c`** — solutions to [beecrowd](https://www.beecrowd.com.br/)
  (ex-URI Online Judge) problems, one file per problem number.

## Building

```bash
gcc -O2 -o main "Comparação de algoritmos de ordenação/main.c" \
    "Comparação de algoritmos de ordenação/insertion_sort.c" \
    "Comparação de algoritmos de ordenação/merge_sort.c" \
    "Comparação de algoritmos de ordenação/quick_sort.c" \
    "Comparação de algoritmos de ordenação/gerador_vetor.c"

# beecrowd problems build standalone:
gcc -O2 -o sol bee1002.c
```
