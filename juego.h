//
// Created by Alex on 30/04/2019.
//

#ifndef UNO_JUEGO_H
#define UNO_JUEGO_H

#include "baraja.h"
#include <rpcndr.h>

void juego();
boolean validar_jugada();
boolean validar_juego(Deck *p, int valor, int color);
#endif //UNO_JUEGO_H
