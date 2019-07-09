//
// Created by Alex on 30/04/2019.
//

#ifndef UNO_BARAJA_H
#define UNO_BARAJA_H

#include <stdlib.h>
#include <stdio.h>

typedef struct N {
    int cont;
    int valor;
    int color;
    struct N *sig;
}Nodo;
typedef Nodo *Deck;

void barajar(Deck *baraja);

Deck crear_baraja();
void baraja_push(Deck *baraja, int valor, int color, int cont);
void baraja_pop(Deck *p);
void baraja_next(Deck *p);
Nodo baraja_top(Deck p);

#endif //UNO_BARAJA_H
