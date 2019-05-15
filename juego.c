//
// Created by Alex on 30/04/2019.
//
#include "juego.h"

void juego(){
    Deck baraja = NULL;

    baraja = crear_baraja(); //Creamos la baraja con las cartas incluidas
    /*for(int i=0;i<4;i++){
        baraja_push(&baraja,i,i);
    }*/
    if(baraja!=NULL){
        printf("Baraja generada con exito\n");
        while (baraja->sig!=NULL){
            printf("Valor: %d",baraja->valor);
            printf("   Color: %d \n",baraja->color);
            baraja = baraja->sig;
        }
    }
}