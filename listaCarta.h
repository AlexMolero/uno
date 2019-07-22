//
// Created by xavivg on 5/12/19.
//

#ifndef UNO_LISTACARTA_H
#define UNO_LISTACARTA_H


#include "baraja.h"

typedef struct {
    Nodo *pri;
    Nodo *ant;
}ListaCarta;

ListaCarta LISTACARTA_crea();
ListaCarta LISTACARTA_inserta(ListaCarta *l, Nodo *elemento);
void LISTACARTA_elimina(ListaCarta *l, int posicion);
Nodo LISTACARTA_consulta(ListaCarta l);
ListaCarta LISTACARTA_avanza(ListaCarta l);
ListaCarta LISTACARTA_vesInicio(ListaCarta l);
int LISTACARTA_final(ListaCarta l);
int LISTACARTA_vacia(ListaCarta l);
ListaCarta LISTACARTA_destruye(ListaCarta l);
ListaCarta LISTACARTA_unir(ListaCarta l1, ListaCarta l2);
int LISTACARTA_modificar(ListaCarta l, Nodo valor, int * posicion);
int LISTACARTA_contarCartas(ListaCarta l);
void LISTACARTA_eliminaPosicion(ListaCarta *l, ListaCarta *descarte, int posicion);
void LISTACARTA_roba(ListaCarta *l, Nodo *elemento);
Nodo LISTACARTA_consultaByPosicion(ListaCarta l, int posicion);
void LISTACARTA_cambiaColorComodin(ListaCarta *l, int posicion, int color, ListaCarta *descarte);
int LISTACARTA_hayCero(ListaCarta l);
int LISTACARTA_mismoColor(ListaCarta l, ListaCarta descarte);
int LISTACARTA_favoreceColor(ListaCarta l, Nodo carta);
int LISTACARTA_devolverColorFavorecido(ListaCarta l);
int LISTACARTA_comodin(ListaCarta l);
int LISTACARTA_posicionComodin(ListaCarta lista, int posicion_carta, Nodo carta_descarte, Nodo carta_juego);
#endif //UNO_LISTACARTA_H
