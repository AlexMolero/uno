//
// Created by Alex on 21/05/2019.
//
#ifndef UNO_LISTAJUEGO_H
#define UNO_LISTAJUEGO_H

#include "jugador.h"
#include "bots.h"

typedef struct Node {
    int type;
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
void LISTAJUEGO_insertaIzquierda(ListaJuego *l, Jugador jugador);
void LISTAJUEGO_insertaDerecha(ListaJuego *l, Jugador jugador);
Nodo_jugador LISTAJUEGO_consulta(ListaJuego l);
void LISTAJUEGO_elimina(ListaJuego *l);
void LISTAJUEGO_avanza(ListaJuego *l);
void LISTAJUEGO_retrocede(ListaJuego *l);
void LISTAJUEGO_vesInicio(ListaJuego *l);
void LISTAJUEGO_vesFinal(ListaJuego *l);
int  LISTAJUEGO_inicio(ListaJuego l);
int  LISTAJUEGO_final(ListaJuego l);
int  LISTAJUEGO_vacia(ListaJuego l);
void LISTAJUEGO_destruye(ListaJuego *l);
#endif //UNO_LISTAJUEGO_H
