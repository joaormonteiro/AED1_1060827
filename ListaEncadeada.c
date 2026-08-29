#include <stdlib.h>
/* FALTA: #include <stdio.h> -- necessario para printf (ver funcao imprime) */

struct cel {
    int conteudo;
    struct cel* seguinte;
};

typedef struct cel celula;

celula c;
celula* p;   /* PROBLEMA GERAL: lista apoiada na variavel global 'p' e fragil;
                insere() depende desse global em vez de receber o no por parametro */

void imprime(celula* lst) {
    celula* p;
    for (p = lst; p != NULL; p = p->seguinte) print("%d \n", p->conteudo);
    /* BUG: 'print' nao existe -> deveria ser 'printf'. Alem disso falta #include <stdio.h>. */
}

void* busca(int x, celula* lst) {
    celula* p;
    p = lst->seguinte;   /* OBS: pula o primeiro no; so faz sentido se 'lst' for celula-cabeca (sentinela) */
    while (p != NULL && p->conteudo != x) p->seguinte;
    /* BUG: o corpo do while ('p->seguinte;') nao faz nada -- calcula o valor e descarta.
       'p' nunca avanca -> loop infinito. Falta a atribuicao que move 'p' para o proximo no. */
    return p;
    /* OBS: o tipo de retorno 'void*' deveria ser 'celula*' */
}

void insere(int y, celula lst) {
    /* PROBLEMA: parametro 'lst' passado por valor e nunca usado; a funcao opera no
       global 'p' em vez de receber 'celula* lst' e inserir em relacao a ele */
    celula* nova;
    nova = malloc(sizeof(int));
    /* BUG: sizeof(int) reserva espaco so para o campo 'conteudo'. 'celula' tem int +
       ponteiro, entao escrever 'nova->seguinte' grava fora do bloco alocado
       (comportamento indefinido). Deveria ser sizeof(celula) ou sizeof(*nova). */
    nova->conteudo = y;
    nova->seguinte = p->seguinte;
    p->seguinte = nova;
    /* OBS: sem checagem de malloc ter retornado NULL */
}

void buscaEremove(int x, celula* lst) {
    /* PROBLEMA: funcao incompleta. Assinatura e o acesso a 'seguinte' agora estao ok,
       mas 'x' nunca e usado, 'q' fica sem uso e nada e removido.
       Ideia: andar com p (anterior) e q (atual) em par ate q == NULL ou q->conteudo == x;
       se q != NULL, o no a remover esta depois de 'p' -> chamar remove(p). */
    celula *p, *q;
    p = lst;
    q = lst->seguinte;
}

void remove(celula* p) {
    /* PROBLEMA: 'remove' e o nome de uma funcao da biblioteca padrao (<stdio.h>, apaga
       arquivo). Redefinir esse identificador da conflito se stdio.h for incluido -> usar
       outro nome (ex.: removeSeguinte).
       PROBLEMA: sem checagem de 'p == NULL' nem de 'p->seguinte == NULL' -> se nao houver
       proximo no, 'lixo->seguinte' desreferencia NULL. */
    celula* lixo;
    lixo = p->seguinte;
    p->seguinte = lixo->seguinte;   /* religa a lista por cima do no removido */
    free(lixo);                     /* ordem correta: religa antes, free depois */
}
