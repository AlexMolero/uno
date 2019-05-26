//
// Created by Alex on 30/04/2019.
//

#ifndef UNO_JUEGO_H
#define UNO_JUEGO_H

#include "baraja.h"
#include "listaCarta.h"
#include "listaJuego.h"
#include "bots.h"

void juego(char **argv, ListaJuego *lista_jugadores);
int validar_jugada(Deck *p, ListaCarta *lista);
int repartir_carta(Deck *p, ListaCarta *lista, int cantidad);
void ver_menu_jugadores(ListaJuego lista_jugadores);
void ver_lista_cartas(ListaCarta lista);
#endif //UNO_JUEGO_H
