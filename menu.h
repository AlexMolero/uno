//
// Created by Alex on 30/04/2019.
//
#ifndef UNO_MENU_H
#define UNO_MENU_H

#include <stdio.h>
#include "baraja.h"
#include "jugador.h"
#include "bots.h"
#include "listaJuego.h"

void muestraMenu();
void muestraMenuEstadisticas();
int getOption();
void selectOption(int option, char **argv, ListaJuego *lista_jugadores, ListaCarta *descarte, Deck *p);
void selectOptionEstadisticas(int opcion, char **args, ListaJuego *lista_jugadores);
Jugador loadPlayer(char *fileUser);
Bots *loadBots(char *fileBots, int *numBots);
void selectFirstAction(char option, ListaJuego *lista_jugadores, ListaCarta *descarte, Deck *p);
void selectSecondAction(char option, ListaJuego *lista_jugadores, ListaCarta *descarte, Deck *p);
char getGameOption(char *name_player);
char getGame(char *name_player);
void convertirCarta(int valor, int color);
char opcion_robar();
#endif //UNO_MENU_H
