//
// Created by Alex on 30/04/2019.
//
#include "menu.h"
#include "baraja.h"

#define COLORES 4
#define NUM_MAX_CARTA 13


Deck crear_baraja() {
    Deck p;
    p = NULL;
    for(int i=0;i<COLORES;i++){ // 0=Rojo, 1=Amarillo, 2=Verde, 3=Azul
        for(int j=0;j<NUM_MAX_CARTA;j++){
            baraja_push(&p,j,i);
        }
    }
    return p;
}
void baraja_push(Deck *p, int elemento, int color) {
    Nodo *aux;
    aux = (Nodo*)malloc(sizeof(Nodo));
    if (aux == NULL){
        printf("\nError al hacer push...\n");
    }else{

        aux->valor = elemento;
        aux->color = color;
        aux->sig = *p;
        *p = aux;
    }
}

void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void barajar(BarajaPtr_t *baraja) {
    for (int i = (*baraja)->n_cartas - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&(*baraja)->cartas[i], &(*baraja)->cartas[j]);
    }
}