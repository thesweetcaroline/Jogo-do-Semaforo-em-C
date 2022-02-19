//CAROLINA FERREIRA
//2018018459

#include <stdio.h>
#include <stdlib.h>

#include "Jogo.h"
#include "utils.h"
#include "opcoes.h"
#include "historico.h"

void inicializacao_tabuleiro(tabuleiro **tab){

    for(int i=0;i<((*tab)->linha);i++){
        for(int j=0;j<((*tab)->coluna);j++){
            (*tab)->tabuleiro[i][j]='_';
            printf(" ");
            printf("%c",(*tab)->tabuleiro[i][j]);
        }
        printf("\n");
    }

}

void show_tabuleiro(tabuleiro **tab){

    for(int i=0;i<((*tab)->linha);i++){
        for(int j=0;j<((*tab)->coluna);j++){
            printf(" ");
            printf("%c",(*tab)->tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int verifica_tentativa(tabuleiro **tab, int peca){
    int empty_spaces=0, conta_g=0, conta_y=0;

    for(int i=0;i<((*tab)->linha);i++){
        for(int j=0;j<((*tab)->coluna);j++){

        if((*tab)->tabuleiro[i][j]=='_')
            empty_spaces++;
        if((*tab)->tabuleiro[i][j]=='G')
            conta_g++;
        if((*tab)->tabuleiro[i][j]=='Y')
            conta_y++;
    }
    }
    if(peca==1 && empty_spaces>0)
        return 1;
    if(peca==4 && empty_spaces>0)
        return 1;
    if(peca==2 && conta_g>0)
        return 1;
    if(peca==3 && conta_y>0)
        return 1;
    if(peca==0)
        return 1;

    return 0;

}


 void selecionar_jogada(tabuleiro **tab, int num_jogada, int *win, phist *historico){


    int line, column, validade=0, invalido, peca=0, k=0;
    char pecinha;

    do{
        invalido = 0;
        printf("\nQue peca pretende jogar?\n ");
        printf("\n1 Verde");
        printf("\n2 Amarelo");
        printf("\n3 Vermelho");

        if( (num_jogada%2!=0 && ((*tab)->pedra1) < 1 ) || (num_jogada%2 == 0 && (((*tab)->pedra2)) < 1))
            printf("\n4 Pedra");

        if(num_jogada>1)
            printf("\n0 Ver Historico de jogadas");

        printf("\n--> ");
        scanf("%d",&peca);


        if(peca==0){

            do{
            printf("\nDeseja visualizar o historico de quantas ultimas jogadas?");
            printf("\n-->");
            scanf("%d",&k);
            }while (k>num_jogada);

            //show_historico(*historico);
           ultimas_k_jogadas(*historico, num_jogada-k-1);
        }

        if(peca==4) { //colocar pedras a 1 quando são jogadas
            if(num_jogada%2!=0 && ((*tab)->pedra1) < 1 )
                ((*tab)->pedra1)=1;
            else if(num_jogada%2 == 0 && ((*tab)->pedra2) < 1)
                ((*tab)->pedra2)=1;
            else {
                invalido = 1;
                printf("Nao tem pedras para jogar!");
            }
        }


        if(verifica_tentativa(&(*tab),peca)==0){
            printf("Acao Impossivel!\n\n");
        }

    } while(peca>4 || peca<1 || (verifica_tentativa(&(*tab),peca)==0) || invalido == 1);


    do{
        printf("\n\nEm que linha deseja jogar?");
        printf("\n-->");
        scanf("%d",&line);
        line -= 1;

        printf("\nEm que coluna deseja jogar?");
        printf("\n-->");
        scanf("%d",&column);
        column -= 1;

        //ifs para escrever peças no tabuleiro
        if(peca==1){

            if((*tab)->tabuleiro[line][column]=='_'){
                (*tab)->tabuleiro[line][column]='G';
                pecinha = 'G';

                validade=1;
            }else
                printf("Acao Impossivel");
        }

        else if(peca==2){

            if((*tab)->tabuleiro[line][column]=='G'){
                (*tab)->tabuleiro[line][column]='Y';
                validade=1;
                pecinha = 'Y';
            }else
                printf("Acao Impossivel");
        }

        else if(peca==3){

            if((*tab)->tabuleiro[line][column]=='Y'){
                (*tab)->tabuleiro[line][column]='R';
                pecinha = 'R';
                validade=1;
            }else
                printf("Acao Impossivel");}

        else if(peca==4){

            if((*tab)->tabuleiro[line][column]=='_'){
                (*tab)->tabuleiro[line][column]='P';
                pecinha = 'P';
                validade=1;
            }
            else
                printf("Acao Impossivel");
        }

    }while (validade==0);

    if(num_jogada%2!=0) {

        *historico = add_historico(*historico, pecinha, line+1, column+1, 'A');
    }
    else {


        *historico = add_historico(*historico, pecinha, line+1, column+1, 'B');
    }

    //show_historico(historico);

    printf("\n");
    show_tabuleiro(&(*tab));
    if (verifica_linha(&(*tab),line)==1 || verifica_coluna(&(*tab),column)==1 || verifica_diagonal(&(*tab))==1)
            *win=1;



}


int verifica_linha(tabuleiro **tab, int line){

    int g=0,y=0,r=0;

        for(int j=0;j<((*tab)->coluna);j++){
            if ((*tab)->tabuleiro[line][j]=='G')
                g++;
            if ((*tab)->tabuleiro[line][j]=='Y')
                y++;
            if ((*tab)->tabuleiro[line][j]=='R')
                r++;
        }


        //ifs que verificam se numero de peças de cada cor é igual ao numero de colunas - linha preenchida

        if(g==((*tab)->coluna))
            return 1;
        if(y==((*tab)->coluna))
            return 1;
        if(r==((*tab)->coluna))
            return 1;

        g=0;
        y=0;
        r=0;

    return 0;

}

int verifica_coluna(tabuleiro **tab, int column){

    int g=0,y=0,r=0;


    for(int i=0;i<((*tab)->linha);i++){

            if ((*tab)->tabuleiro[i][column]=='G')
                g++;
            if ((*tab)->tabuleiro[i][column]=='Y')
                y++;
            if ((*tab)->tabuleiro[i][column]=='R')
                r++;

            }


        //ifs que verificam se numero de peças de cada cor é igual ao numero de linhas - coluna preenchida


        if(g==((*tab)->linha))
            return 1;
        if(y==((*tab)->linha))
            return 1;
        if(r==((*tab)->linha))
            return 1;

        g=0;
        y=0;
        r=0;

    return 0;

}

int verifica_diagonal(tabuleiro **tab){

    int g=0,y=0,r=0;

    for(int j=0;j<((*tab)->coluna);j++){
            if ((*tab)->tabuleiro[j][j]=='G')
                g++;
            if ((*tab)->tabuleiro[j][j]=='Y')
                y++;
            if ((*tab)->tabuleiro[j][j]=='R')
                r++;
            }

        if(g==((*tab)->coluna))
            return 1;
        if(y==((*tab)->coluna))
            return 1;
        if(r==((*tab)->coluna))
            return 1;
        g=0;
        y=0;
        r=0;

    for(int j=((*tab)->coluna)-1, i=0;j>=0;j--,i++){

            if ((*tab)->tabuleiro[i][j]=='G')
                g++;
            if ((*tab)->tabuleiro[i][j]=='Y')
                y++;
            if ((*tab)->tabuleiro[i][j]=='R')
                r++;

    }

        if(g==((*tab)->coluna))
            return 1;
        if(y==((*tab)->coluna))
            return 1;
        if(r==((*tab)->coluna))
            return 1;
        g=0;
        y=0;
        r=0;
    return 0;

}


 void gera_jogada_automatica(tabuleiro **tab, int num_jogada, int *win, phist *historico){
    int line, column, validade=0, peca_auto=0;
    char pecinha;


    //printf("im in");
    do{
        if(((*tab)->pedra2)< 1){
            initRandom();
            peca_auto = intUniformRnd(1,4);
            //printf("im in");
        }

        else {
            initRandom();
            peca_auto = intUniformRnd(1,3);
        }

        if(peca_auto==4 && ((*tab)->pedra2) < 1){
                ((*tab)->pedra2)=1;
        }


    } while((verifica_tentativa(&(*tab),peca_auto)==0));
    //printf("im out");

    //printf("%d", peca_auto);

    do{
        //linha
        initRandom();
        line = intUniformRnd(0,((*tab)->linha)-1);

        //coluna
        initRandom();
        column = intUniformRnd(0,((*tab)->coluna)-1);

        if(peca_auto==1){

            if((*tab)->tabuleiro[line][column]=='_'){
                (*tab)->tabuleiro[line][column]='G';

                validade=1; // verifica se a linha escolhida nao ta preenchida
                pecinha = 'G';

            }
        }

        else if(peca_auto==2){

            if((*tab)->tabuleiro[line][column]=='G'){
                (*tab)->tabuleiro[line][column]='Y';
                validade=1;
                pecinha = 'Y';
            }
        }

        else if(peca_auto==3){

            if((*tab)->tabuleiro[line][column]=='Y'){
                (*tab)->tabuleiro[line][column]='R';
                validade=1;
                pecinha = 'R';
            }
        }

        else if(peca_auto==4){

            if((*tab)->tabuleiro[line][column]=='_'){
                (*tab)->tabuleiro[line][column]='P';
                validade=1;
                pecinha = 'P';
            }
        }

    }while (validade==0);

    //if(num_jogada%2==0) {
        *historico = add_historico(*historico, pecinha, line+1, column+1, 'M'); //Maquina
    /*}
    else {
        *historico = add_historico(*historico, pecinha, line+1, column+1, 'A'); //automatico
    }*/

   show_tabuleiro(&(*tab));

    if (verifica_linha(&(*tab),line)==1 || verifica_coluna(&(*tab),column)==1 || verifica_diagonal(&(*tab))==1)
            *win=1;


}
