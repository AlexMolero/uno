#ifndef INC_21BACKJACK_JUGADOR_H
#define INC_21BACKJACK_JUGADOR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaCarta.h"

typedef struct {
    char *nombre;
    int partidas_ganadas;
    int partidas_perdidas;
    ListaCarta cartas;
	int num_partidas;
    int *cartas_partida_i;
} Jugador;

Jugador JUGADOR_crea();
void JUGADOR_insertaNombre(Jugador *j, char *nombre);
void JUGADOR_insertaPartidasGanadas(Jugador *j, int manosGanadas);
void JUGADOR_insertaPartidasPerdidas(Jugador *j, int manosPerdidas);
char * JUGADOR_consultaNombre(Jugador j);
int JUGADOR_consultaPartidasGanadas(Jugador j);
int JUGADOR_consultaPartidasPerdidas(Jugador j);
void JUGADOR_insertaCartasPartida(Jugador *j, int cartas);
int JUGADOR_consultaCartasPartida(Jugador j, int cartas);
int JUGADOR_consultaNumPartidas(Jugador j);
void JUGADOR_insertaNumPartidas(Jugador *j, int n_partidas);
ListaCarta * JUGADOR_consultaCartas(Jugador b);
#endif //INC_21BLACKJACK_JUGADOR_H
