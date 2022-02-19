//CAROLINA FERREIRA
//2018018459

#ifndef FUNCOES_JOGOS_H_INCLUDED
#define FUNCOES_JOGOS_H_INCLUDED

#include "historico.h"

typedef struct tabuleiro tabuleiro;

struct tabuleiro{
    char **tabuleiro;
    int linha;
    int coluna;
    int pedra1;
    int pedra2;
    int jogadas_efetuadas;
};


void inicializacao_tabuleiro(tabuleiro **tab);
void show_tabuleiro(tabuleiro **tab);
int verifica_tentativa(tabuleiro **tab, int peca);
void selecionar_jogada(tabuleiro **tab, int jogador, int *win, phist *historico);
int verifica_linha(tabuleiro **tab, int line);
int verifica_coluna(tabuleiro **tab, int column);
int verifica_diagonal(tabuleiro **tab);
void gera_jogada_automaticagera_jogada_automatica(tabuleiro **tab, int num_jogada, int *win, phist *historico);




#endif // TABULEIRO_H_INCLUDED


