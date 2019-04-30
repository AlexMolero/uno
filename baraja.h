//
// Created by Alex on 30/04/2019.
//

#ifndef UNO_BARAJA_H
#define UNO_BARAJA_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct BarajaStruct_t {
    int n_cartas;
    int* cartas;
    int index;
};
typedef struct BarajaStruct_t * BarajaPtr_t;

int crearBaraja(BarajaPtr_t *baraja);
void barajar(BarajaPtr_t *baraja);

#endif //UNO_BARAJA_H
