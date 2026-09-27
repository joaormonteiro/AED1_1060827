# AED_1 — Instruções do projeto

Repositório de exercícios de Algoritmos e Estrutura de Dados (UNIFESP), majoritariamente
soluções de problemas do Beecrowd/URI em C.

## Regra principal: não codar por mim

Este é um ambiente de **estudo**. Não escreva nem edite a lógica dos arquivos `.c` diretamente
— o objetivo é eu aprender resolvendo os exercícios. Quando eu mostrar um arquivo com bug:

1. Leia o arquivo e explique o(s) problema(s) com clareza.
2. Teste/compile para demonstrar o bug quando ajudar a evidenciar o erro.
3. Sugira a correção em texto/exemplo — mas não aplique a mudança no arquivo, a menos que eu
   peça explicitamente ("aplica", "corrige o arquivo", etc).

Exceção: cabeçalhos de metadados (nome, data, número do problema, objetivo) podem ser
preenchidos diretamente quando eu pedir — preencher isso não é "resolver o exercício" por mim.

## Cabeçalho padrão dos arquivos .c

Todo arquivo de código novo neste repositório deve começar com este bloco:

```c
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : João Rubens Rezende Monteiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<numeroDoProblema>>
Data        : DD/MM/2026
Objetivo    : <<<Resumo de uma linha do que o programa faz>>>
Dificuldade : <<<Qual foi o principal desafio neste problema?>>>
Uso de IA   : <<<Se usou, descreva brevemente o uso de IA na solução>>>
-------------------------------------------------------------------------- */
```

- `Nome` é sempre "João Rubens Rezende Monteiro".
- `Problema` usa o número do Beecrowd correspondente ao nome do arquivo (ex.: `bee1080.c` → `.../view/1080`). Para arquivos que não são de um problema do Beecrowd (ex.: `mdc.c`, `sudoku.c`, `tempo.c`), omitir a linha `Problema` ou adaptar conforme o contexto.
- `Dificuldade` e `Uso de IA` são reflexão pessoal — não inventar o conteúdo desses campos por mim; deixar como placeholder para eu preencher, a menos que eu peça para redigir com base numa sessão específica.
