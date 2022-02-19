//CAROLINA FERREIRA
//2018018459

#include <stdio.h>
#include <stdlib.h>

#include "opcoes.h"
#include "Jogo.h"

void opcoes(int* opcao){

    printf("Prima uma das seguintes teclas:");
    printf("\n\n******************************");
    printf("\n 1 Novo Jogo");
    if( fopen("jogo.bin", "rb") != NULL )
        printf("\n 2 Retomar Jogo");
    printf("\n 3 Exit");
    printf("\n******************************");
    printf("\n\n-----> ");
    scanf("%d",opcao);

}

int game_options(int opcao,tabuleiro *tab){

    int jogo=0;
    int retomar_jogo=0;


    switch (opcao)
    {
        case 1:
            do{
                printf("\nOPCOES DE JOGO");
                printf("\n\n******************************");
                printf("\n1 Multiplayer");
                printf("\n2 Player vs. PC");
                printf("\n3 Voltar ao menu principal");
                printf("\n******************************");
                printf("\n\n-----> ");
                scanf("%d",&jogo);

                if(jogo==1){
                    jogo_semaforo(&tab);
                    break;
                }
                else if(jogo==2){
                    jogo_semaforo_vs_PC(&tab);
                    break;
                }
                else if(jogo==3){
                    return 1;
                }
                else{
                    printf("\nA opcao nao existe. Try again\n\n");
                    }

            }while (jogo!=1 || jogo!=2);
        break;

    case 2:

      // Confirmar se jogo existe
      //jogoanterior=confirmajogo();
      if(retomar_jogo==1){ //Existe jogo anterior

      }
      break;

    case 3:
        exit(0);

    default:
      return 0;
    }
}
