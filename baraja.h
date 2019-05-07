//
// Created by Alex on 30/04/2019.
//

#ifndef UNO_BARAJA_H
#define UNO_BARAJA_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct N {
    int valor;
    int color;
    struct N *sig;
}Nodo;
typedef Nodo *Deck;

struct BarajaStruct_t {
    int   n_cartas;
    char  *color;
    int   *cartas;
    int   index;
};
typedef struct BarajaStruct_t * BarajaPtr_t;

int crearBaraja(BarajaPtr_t *baraja);
void barajar(BarajaPtr_t *baraja);

Deck crear_baraja();

void baraja_push(Deck *baraja, int valor, int color);

#endif //UNO_BARAJA_H
