//CAROLINA FERREIRA
//2018018459

#include <stdio.h>
#include <stdlib.h>

#include "Jogo.h"
#include "utils.h"
#include "opcoes.h"
#include "historico.h"



phist add_historico(phist historico, char peca, int linha, int coluna, char player) {


    phist new = NULL, aux = NULL;
    new = malloc(sizeof(historico_S)); // lista ligada portanto é so 1
    new->peca = peca;
    new->linha = linha;
    new->coluna = coluna;
    new->player = player;
    new->prox = NULL;

    if(historico == NULL) {
        historico = new;
        return historico;
    }

    aux = historico;
    while( aux->prox != NULL ) {
        aux = aux->prox;
    }

    aux->prox = new;

    return historico;

}


void show_historico(phist historico) {

    while( historico != NULL ) {
        printf("%c - %d - %d - %c\n", historico->peca, historico->linha, historico->coluna, historico->player);
        historico = historico->prox;
    }

}

void ultimas_k_jogadas(phist historico, int jogada) { // jogada = numero de jogada atual - k
    for(int i = 0; i < jogada; i++) {
        historico = historico->prox;
    }

    while( historico != NULL ) {
        printf("%c - %d - %d - %c\n",
               historico->peca, historico->linha, historico->coluna,
               historico->player);

        historico = historico->prox;
    }
}

void guarda_txt(phist phistorico){
    FILE *f;
    char filename[15];

    printf("\nNome para o ficheiro a criar?");
    printf("\n-->");
    scanf("%14s", &filename);

    f = fopen(filename, "w");
    if(f == NULL){
        printf("\nOcorreu um problema.\n");
        return;
    }

    else{
        while (phistorico != NULL){
            fprintf(f, "%c-%d-%d-%c\n", phistorico->peca, phistorico->linha, phistorico->coluna, phistorico->player);
            phistorico = phistorico->prox;
        }
    }
}
