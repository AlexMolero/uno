#ifndef INC_21BLACKJACK_BOTS_H
#define INC_21BLACKJACK_BOTS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bots.h"
#include "listaCarta.h"

typedef struct {
    char *nombre;
    char caracter;
    int carta_maxima;
    int partidas_ganadas;
    int partidas_perdidas;
    ListaCarta cartas;
    int n_bots;
} Bots;
//typedef struct{
//    int n_bots;
//    Bots bots;
//}Bots;

Bots BOTS_crea();
void BOTS_insertaNombre(Bots *b, char *nombre);
void BOTS_insertaCaracter(Bots *b, char caracter);
void BOTS_insertaCartaMax(Bots *b, int cartaMax);
void BOTS_insertaCartas(Bots *b, ListaCarta cartas);
char * BOTS_consultaNombre(Bots b);
int BOTS_consultaNBots(Bots b);
char BOTS_consultaCaracter(Bots b);
char * BOTS_consultaNombreCaracter(Bots b);
int BOTS_consultaCartaMax(Bots b);
int BOTS_consultaPartidasGanadas(Bots j);
int BOTS_consultaPartidasPerdidas(Bots j);
ListaCarta * BOTS_consultaCartas(Bots b);
//n_bots BOTS_nBots(Bots b);

#endif //INC_21BLACKJACK_BOTS_H
