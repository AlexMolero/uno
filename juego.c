//
// Created by Alex on 30/04/2019.
//
#include <stdbool.h>
#include "juego.h"

void juego(){
    Deck baraja = NULL;

    baraja = crear_baraja(); //Creamos la baraja con las cartas incluidas
    /*for(int i=0;i<4;i++){
        baraja_push(&baraja,i,i);
    }*/
    if(baraja!=NULL){
        printf("Baraja generada con exito\n");
        baraja->cont=0;

         while (baraja->sig!=NULL){
              printf("Contador: %d",baraja->cont);
              printf("Valor: %d",baraja->valor);
              printf("   Coolor: %d \n",baraja->color);
              baraja = baraja->sig;
          }
    }

    printf("EMPIEZA A BARAJAR");
    barajar(&baraja);
}
boolean validar_juego(Deck *p, int valor, int color){

    //TODO Valor y color son de la lista del jugador
    if((*p)->valor==valor || (*p)->color == color || color == 4){
        //SE puede jugar la carta
        return true;
    }else{
        //No es valida la jugada.
        return false;
    }

}