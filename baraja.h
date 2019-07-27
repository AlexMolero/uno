//
// Created by Alex on 30/04/2019.
//

#ifndef UNO_BARAJA_H
#define UNO_BARAJA_H

#include <stdlib.h>
#include <stdio.h>

typedef struct N {
    int valor;
    int color;
    struct N *sig;
}Nodo;
typedef Nodo *Deck;

void barajar(Deck *baraja);
Deck crear_baraja();
void baraja_push(Deck *baraja, int valor, int color);
void baraja_pop(Deck *p);
int PILA_vacia(Deck p);
int PILA_count(Deck p);
void baraja_next(Deck *p);
Nodo baraja_top(Deck p);
int es_roba_4(Nodo carta);
int es_comodin_color(Nodo carta);
int es_suma_2(Nodo carta);
int es_cambio_direccion(Nodo carta);
int es_saltar_turno(Nodo carta);
void cambiar_color(Nodo *carta, int color);
int es_cero (Nodo carta);
void ver_baraja(Deck p);
#endif //UNO_BARAJA_H
