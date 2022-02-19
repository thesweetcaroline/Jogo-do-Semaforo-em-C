//CAROLINA FERREIRA
//2018018459

#include <stdio.h>
#include <stdlib.h>
#include "opcoes.h"
#include "utils.h"
#include "jogo.h"

int main()
{

    phist historico = NULL;

    tabuleiro tab;
    int opcao = 0;

    initRandom();
    tab.coluna=intUniformRnd(3, 5);
    tab.linha=tab.coluna;
    tab.pedra1=0;
    tab.pedra2=0;
    tab.jogadas_efetuadas=1;


    tab.tabuleiro=malloc(sizeof(tab.coluna*(sizeof(char *))));
    for(int i=0;i<tab.coluna;i++)
        tab.tabuleiro[i]=(char *)malloc(tab.linha * sizeof(char*));

    do{
    opcoes(&opcao);
    }while(game_options(opcao,&tab)==1);

}
