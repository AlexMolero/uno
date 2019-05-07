//
// Created by Alex on 30/04/2019.
//
#include "juego.h"

void juego(){
    Deck baraja = NULL;

    baraja = crear_baraja();
    for(int i=0;i<4;i++){
        baraja_push(&baraja,i,i);
    }
    if(baraja!=NULL){
        printf("Baraja generada con exito\n");

       /* for(int i=0; i<108;i++){
            //printf((*baraja).cartas[i]);
       }*/
    }
}