//
// Created by Alex on 21/05/2019.
//
#ifndef UNO_LISTAJUEGO_H
#define UNO_LISTAJUEGO_H

#include "jugador.h"
#include "bots.h"

typedef struct Node {
    int type; // Si es 0 es Jugador y si es 1 es Bot
    int direccion; //Si es 1 el juego es hacia abajo, si es 0 el juego es hacia arriba
    Jugador jugador;
    Bots bots;
    struct Node *sig;
    struct Node *ant;
}Nodo_jugador;

typedef struct {
    Nodo_jugador *pri;
    Nodo_jugador *ult;
    Nodo_jugador *pdi;
}ListaJuego;


ListaJuego LISTAJUEGO_crea();
void LISTAJUEGO_insertaJugador(ListaJuego *l, Jugador jugador);
void LISTAJUEGO_insertaBot(ListaJuego *l, Bots bot);
void LISTAJUEGO_insertaDerecha(ListaJuego *l, Nodo_jugador nodo);
Nodo_jugador LISTAJUEGO_consulta(ListaJuego l);
int LISTAJUEGO_consultaNBots(Nodo_jugador j);
char *LISTAJUEGO_consultaNombre(Nodo_jugador nodo);
char * LISTAJUEGO_consultaCaracter(Nodo_jugador nodo);
int LISTAJUEGO_consultaTipo(Nodo_jugador nodo);
int LISTAJUEGO_consultaPartidasGanadas(Nodo_jugador nodo);
int LISTAJUEGO_consultaPartidasPerdidas(Nodo_jugador nodo);
int LISTAJUEGO_consultaCartasPartida(Nodo_jugador j, int partida);
void LISTAJUEGO_elimina(ListaJuego *l);
void LISTAJUEGO_avanza(ListaJuego *l);
void LISTAJUEGO_retrocede(ListaJuego *l);
void LISTAJUEGO_vesInicio(ListaJuego *l);
void LISTAJUEGO_vesFinal(ListaJuego *l);
int  LISTAJUEGO_inicio(ListaJuego l);
int  LISTAJUEGO_final(ListaJuego l);
int  LISTAJUEGO_vacia(ListaJuego l);
int LISTAJUEGO_count(ListaJuego l);
void LISTAJUEGO_destruye(ListaJuego *l);
//char *LISTAJUEGO_consultaNombre(ListaJuego l);
ListaCarta *LISTAJUEGO_consultaListaCarta(ListaJuego *l);
ListaCarta *LISTAJUEGO_consultaLista(ListaJuego l);
ListaCarta LISTAJUEGO_consultaCartas(Nodo_jugador nodo);
int LISTAJUEGO_consultaCartaMax(Nodo_jugador j);
int LISTAJUEGO_esJugador(ListaJuego l);
int LISTAJUEGO_finJuego(ListaJuego l);
int LISTAJUEGO_siguienteTurno(ListaJuego *l);
int LISTAJUEGO_anteriorTurno(ListaJuego *l);
//sig turno
#endif //UNO_LISTAJUEGO_H
