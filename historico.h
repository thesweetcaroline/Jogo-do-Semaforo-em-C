//CAROLINA FERREIRA
//2018018459

#ifndef HISTORICO_H_INCLUDED
#define HISTORICO_H_INCLUDED


typedef struct historico historico_S, *phist;

struct historico{
    int linha;
    int coluna;
    char peca;
    char player;
    phist prox;
};


phist add_historico(phist historico, char peca, int linha, int coluna, char player);
void show_historico(phist historico);
void ultimas_k_jogadas(phist historico, int jogada);
void guarda_txt(phist phistorico);

#endif // HISTORICO_H_INCLUDED
