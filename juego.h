//
// Created by Alex on 30/04/2019.
//

#ifndef UNO_JUEGO_H
#define UNO_JUEGO_H

#include "baraja.h"
#include "listaCarta.h"
#include "listaJuego.h"
#include "bots.h"

int validar_jugada(Nodo carta_jugador, Nodo carta_descarte);
int repartir_carta(Deck *p, ListaCarta *lista, int cantidad);
void ver_jugadores(ListaJuego lista_jugadores, ListaCarta descarte);
void ver_lista_cartas(ListaJuego lista_jugadores, ListaCarta descarte);
void jugar_por_turnos(ListaJuego *lista_jugadores, ListaCarta *descarte, Deck *p);
void robar_carta(ListaJuego *lista_jugadores, ListaCarta *descarte, Deck *p);
void jugar_carta(ListaJuego *lista_jugadores, ListaCarta *descarte, Deck *p);
void logica_jugar_carta(Nodo carta_jugada,ListaJuego *lista_jugadores, Deck *p, int sel_carta, ListaCarta *descarte);
void logica_jugar_bot(ListaJuego *lista_jugadores, ListaCarta *descarte,Deck *p);
int carta_preferencia_bot(ListaCarta lista, ListaCarta descarte, Nodo_jugador j);
#endif //UNO_JUEGO_H
