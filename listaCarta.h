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
ListaCarta LISTACARTA_inserta(ListaCarta l, Nodo elemento);
ListaCarta LISTACARTA_elimina(ListaCarta l);
Nodo LISTACARTA_consulta(ListaCarta l);
ListaCarta LISTACARTA_avanza(ListaCarta l);
ListaCarta LISTACARTA_vesInicio(ListaCarta l);
int LISTACARTA_final(ListaCarta l);
int LISTACARTA_vacia(ListaCarta l);
ListaCarta LISTACARTA_destruye(ListaCarta l);
ListaCarta LISTACARTA_unir(ListaCarta l1, ListaCarta l2);
int LISTACARTA_modificar(ListaCarta l, Nodo valor, int * posicion);
#endif //UNO_LISTACARTA_H
