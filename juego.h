//
// Created by Alex on 30/04/2019.
//

#ifndef UNO_JUEGO_H
#define UNO_JUEGO_H

#include "baraja.h"
#include "listaCarta.h"
void juego();
int validar_jugada(Deck *p, ListaCarta *lista);
int repartir_carta(Deck *p, ListaCarta *lista, int cantidad);
#endif //UNO_JUEGO_H
