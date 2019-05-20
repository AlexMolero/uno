//
// Created by Alex on 30/04/2019.
//
#include "juego.h"

void juego(){
    Deck baraja = NULL;

    baraja = crear_baraja(); //Creamos la baraja con las cartas incluidas

    if(baraja!=NULL){
        printf("Baraja generada con exito\n");

        /* LEER BARAJA
          while (baraja->sig!=NULL){
              printf("Contador: %d",baraja->cont);
              printf("Valor: %d",baraja->valor);
              printf("Coolor: %d \n",baraja->color);
              baraja = baraja->sig;
          }
        */
    }

    printf("EMPIEZA A BARAJAR");
    barajar(&baraja);
}
int validar_jugada(Deck *p, ListaCarta *lista){

    //TODO lista???????? se debe llevar previamente a la posicion de la lista para validar
    if((*p)->valor==(*lista).ant->valor || (*p)->color == (*lista).ant->color || (*lista).ant->color == 4){
        //SE puede jugar la carta
        return 1;
    }else{
        //No es valida la jugada.
        return 0;
    }
}
/**
 * Repartir carta: Se pasa por referencia la baraja y una lista de cartas para insertar la cantidad indicada en la lista de cartas
 * del usuario
 * @param p
 * @param lista
 * @param cantidad
 * @return
 */
int repartir_carta(Deck *p, ListaCarta *lista, int cantidad){

    Nodo *aux;
    aux = (*p);
    for(int i=0;i<cantidad;i++){
        LISTACARTA_inserta((*lista),(*aux));
        baraja_pop(p);
    }
    return 1;
}