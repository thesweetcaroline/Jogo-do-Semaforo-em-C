//CAROLINA FERREIRA
//2018018459

#include <stdio.h>
#include <stdlib.h>

#include "Jogo.h"
#include "utils.h"
#include "opcoes.h"


void jogo_semaforo(tabuleiro **tab){

    int win=0, num_jogada=1;
    char jogadorA[15],jogadorB[15];

    phist historico = NULL;


    printf("Nome do Jogador A ---> ");
    scanf("%s",&jogadorA);

    printf("Nome do Jogador B ---> ");
    scanf("%s",&jogadorB);

    printf("\n************************");
    printf("\nJOGO DO SEMAFORO\n");


    inicializacao_tabuleiro(&(*tab));
    printf("\n************************");

    for(num_jogada=1;win==0;num_jogada++){

        (*tab)->jogadas_efetuadas = num_jogada;// guarda no campo da estrutura o num_jogadas até ao momento

        if (num_jogada%2!=0) //jogadorA joga sempre em turno impar porque começa o jogo
            printf("\nJOGADOR A");
        else
            printf("\nJOGADOR B");

        selecionar_jogada(&(*tab),num_jogada, &win, &historico); // (&(*tab) porque está a receber um ponteiro e tb a passar um ponteiro

        //printf("Sorry, cant do it");

        if(win==1){
            if(num_jogada%2!=0){
                printf("\n %s venceu o jogo! :)\n",jogadorA);
            }
            else{
                printf("\n%s venceu o jogo! :)\n",jogadorB);
            }

            // o jogo termina
            guarda_txt(historico);
        }

        //o numero de jogadas possiveis varia consoante as pedras foram ou não jogadas
         if( (*tab)->pedra1 == 0 && (*tab)->pedra2 == 0){
            if(num_jogada==((*tab)->coluna)*((*tab)->linha)*3){
                win=1;
                printf("Empataram!");
            }
        }

        else if( (*tab)->pedra1 == 1 && (*tab)->pedra2 == 1){
            if(num_jogada==(((*tab)->coluna)*((*tab)->linha)*3)-6){
                win=1;
                printf("Empataram!");
            }
        }

        else{
            if(num_jogada==(((*tab)->coluna)*((*tab)->linha)*3)-3){
                win=1;
                printf("Empataram!");
            }
        }

    }

}

void jogo_semaforo_vs_PC(tabuleiro **tab){

    int win=0, num_jogada=1;
    char jogadorA[15];
    char jogadorB[3] = "PC";

    phist historico = NULL;


    printf("Nome do Jogador A ---> ");
    scanf("%s",&jogadorA);

    printf("\n************************");
    printf("\nJOGO DO SEMAFORO\n");


    inicializacao_tabuleiro(&(*tab));
    printf("\n************************");

    for (num_jogada=1;win==0;num_jogada++){

        (*tab)->jogadas_efetuadas = num_jogada;

        if (num_jogada%2!=0)
            printf("\nJOGADOR A");
        else
            printf("\nPC TURN\n");

        if(num_jogada%2==0) //PC joga em turno par
            gera_jogada_automatica(&(*tab), &win);

        else
            selecionar_jogada(&(*tab),num_jogada, &win, &historico);

            if(win==1){
            if(num_jogada%2!=0){
                printf("\n%s venceu o jogo! :)\n",jogadorA);
            }
            else{
                printf("\nPERDEU O JOGO! :(\n");
            }

            guarda_txt(historico);
        }

        //pelas regras do jogo, o empate é impossivel (?)
        if( (*tab)->pedra1 == 0 && (*tab)->pedra2 == 0){
            if(num_jogada==((*tab)->coluna)*((*tab)->linha)*3){
                win=1;
                printf("Empataram!");
            }
        }

        else if( (*tab)->pedra1 == 1 && (*tab)->pedra2 == 1){
            if(num_jogada==(((*tab)->coluna)*((*tab)->linha)*3)-6){
                win=1;
                printf("Empataram!");
            }
        }

        else{
            if(num_jogada==(((*tab)->coluna)*((*tab)->linha)*3)-3){
                win=1;
                printf("Empataram!");
            }
        }

    }

}


