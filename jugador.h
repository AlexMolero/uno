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
    int partidas_empatadas;
    int cartas_partida_i;
    ListaCarta cartas;
} Jugador;

Jugador JUGADOR_crea();
void JUGADOR_insertaNombre(Jugador *j, char *nombre);
void JUGADOR_insertaManosGanadas(Jugador *j, int manosGanadas);
void JUGADOR_insertaManosPerdidas(Jugador *j, int manosPerdidas);
void JUGADOR_insertaManosEmpatadas(Jugador *j, int manosEmpatadas);
char * JUGADOR_consultaNombre(Jugador j);
int JUGADOR_consultaFichas(Jugador j);
int JUGADOR_consultaManosGanadas(Jugador j);
int JUGADOR_consultaManosPerdidas(Jugador j);
int JUGADOR_consultaManosEmpatadas(Jugador j);
#endif //INC_21BLACKJACK_JUGADOR_H
