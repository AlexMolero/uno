//
// Created by Alex on 21/05/2019.
//


#include "listaJuego.h"

ListaJuego LISTAJUEGO_crea() {
    ListaJuego l;

    Nodo_jugador *fantasmaStart;
    Nodo_jugador *fantasmaEnd;

    fantasmaStart = (Nodo_jugador*)malloc(sizeof(Nodo_jugador));
    fantasmaEnd = (Nodo_jugador*)malloc(sizeof(Nodo_jugador));

    if (fantasmaStart == NULL || fantasmaEnd==NULL) {
        printf("\nError al crear la lista...\n");
        if (fantasmaStart!=NULL) free(fantasmaStart);
        if (fantasmaEnd!=NULL) free(fantasmaEnd);
    } else {
        fantasmaStart->sig = fantasmaEnd;
        fantasmaStart->ant = NULL;
        fantasmaEnd->sig = NULL;
        fantasmaEnd->ant = fantasmaStart;
        l.pri = fantasmaStart;
        l.ult = fantasmaEnd;
        l.pdi = fantasmaStart; // el 1er inserta debe ser a la derecha
    }

    return l;
}

void LISTAJUEGO_insertaIzquierda(ListaJuego *l, Jugador jugador){
    Nodo_jugador *aux;

    if (l->pdi == l->pri) {  // l->pdi->ant==NULL
        printf("\nError al insertar a la izquierda, estás sobre el inicio...\n");
    } else {
        aux = (Nodo_jugador *)malloc(sizeof(Nodo_jugador));

        if (aux==NULL) {
            printf("\nError al insertar a la izquierda...\n");
        } else {
            aux->jugador = jugador;
            aux->sig = l->pdi;
            aux->ant = l->pdi->ant;
            l->pdi->ant = aux;
            aux->ant->sig = aux;
            l->pdi = aux;
        }
    }
}

void LISTAJUEGO_insertaDerecha(ListaJuego *l, Jugador jugador){
    Nodo_jugador *aux;

    if (l->pdi == l->ult) { // l->pdi->sig == NULL
        printf("\nError al insertar a la derecha, el PDI está al final...\n");
    } else {
        aux = (Nodo_jugador*)malloc(sizeof(Nodo_jugador));
        if (aux == NULL) {
            printf("\nError al insertar a la derecha...\n");
        } else {
            aux->jugador = jugador;
            aux->sig = l->pdi->sig;
            aux->ant = l->pdi;
            aux->sig->ant = aux;
            l->pdi->sig = aux;
            l->pdi = aux; // dejamos el PDI sobre el nuevo elemento
        }
    }
}

Jugador LISTAJUEGO_consulta(ListaJuego l){
    Jugador jugador;

    if (l.pdi==l.pri || l.pdi==l.ult) {
        printf("\nError al consultar, PDI al incio o al final, ...\n");
    } else {
        jugador = l.pdi->jugador;
    }

    return jugador;
}

void LISTAJUEGO_elimina(ListaJuego *l){
    Nodo_jugador *aux;
    if (l->pdi == l->pri || l->pdi == l->ult) {
        printf("\nError al eliminar, PDI situado al principio o final...");
    } else {
        aux = l->pdi;
        aux->sig->ant = aux->ant;
        aux->ant->sig = aux->sig;
        l->pdi = aux->sig; // avanzamos el PDI una posición a la derecha
        free(aux);
    }
}

void LISTAJUEGO_avanza(ListaJuego *l){
    if (l->pdi == l->ult) {
        printf("\nError al avanzar...\n");
    } else {
        l->pdi = l->pdi->sig;
    }
}

void LISTAJUEGO_retrocede(ListaJuego *l){
    if (l->pdi == l->pri) {
        printf("\nError al retroceder...\n");
    } else {
        l->pdi = l->pdi->ant;
    }
}

void LISTAJUEGO_vesInicio(ListaJuego *l){
    l->pdi = l->pri->sig;
}

void LISTAJUEGO_vesFinal(ListaJuego *l){
    l->pdi = l->ult->ant;
}

int LISTAJUEGO_inicio(ListaJuego l) {
    return l.pdi == l.pri;
}

int LISTAJUEGO_final(ListaJuego l){
    return l.pdi == l.ult;
}

int LISTAJUEGO_vacia(ListaJuego l){
    return l.pri->sig == l.ult;
}

void LISTAJUEGO_destruye(ListaJuego *l) {
    Nodo_jugador *aux;
    while (l->pri != NULL) {
        aux = l->pri;
        l->pri = aux->sig;
        free(aux);
    }
    l->ult = l->pdi = NULL;
}

