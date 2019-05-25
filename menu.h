//
// Created by Alex on 30/04/2019.
//
#ifndef UNO_MENU_H
#define UNO_MENU_H

#include <stdio.h>
#include "baraja.h"
#include "jugador.h"
#include "bots.h"

void muestraMenu();
int getOption();
void selectOption(int option, char **argv);
Jugador loadPlayer(char *fileUser);
Bots *loadBots(char *fileBots);
void selectFirstAction(char option,ListaCarta lista);
char getGameOption(char name_player);
void convertirCarta(int valor, int color);
#endif //UNO_MENU_H
