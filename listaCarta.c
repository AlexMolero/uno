//#include <libnet.h>
#include "listaCarta.h"

ListaCarta LISTACARTA_crea() {
    ListaCarta l;

    l.pri = (Nodo*)malloc(sizeof(Nodo));
    if (l.pri == NULL) {
        printf("\nError al crear la lista...\n");
    } else {
        l.ant = l.pri;
        l.pri->sig = NULL;
        l.pri->valor = -1; // FANTASMA, ELEMENTO_indefinido();
    }
    return l;
}
ListaCarta LISTACARTA_inserta(ListaCarta *l, Nodo *elemento) {
    Nodo *aux;
    aux = (Nodo*)malloc(sizeof(Nodo));
    if (aux == NULL) {
        printf("\nError al insertar en la lista...\n");
    } else {
        aux->valor = (*elemento).valor;
        aux->color = (*elemento).color;
        aux->sig = (*l).ant->sig;
        (*l).ant->sig = aux;
        (*l).ant = aux; // para mantener el PDI
    }
    return (*l);
}
ListaCarta LISTACARTA_elimina(ListaCarta l) {
    Nodo *aux;

    if (l.ant->sig == NULL) {
        printf("\nError al eliminar, el PDI está al final...\n");
    } else {
        aux = l.ant->sig;
        l.ant->sig = aux->sig; // l.ant->sig->sig;
        free(aux);
    }
    return l;
}
Nodo LISTACARTA_consulta(ListaCarta l) {
    Nodo *aux;
    if (l.ant->sig == NULL) {
        printf("\nError al consultar, el PDI está al final...\n");
    } else {
        aux = l.ant->sig;
    }
    return *aux;
}
ListaCarta LISTACARTA_avanza(ListaCarta l) {
    if (l.ant->sig == NULL) {
        printf("\nError al avanzar, el PDI está al final...\n");
    } else {
        l.ant = l.ant->sig;
    }
    return l;
}
ListaCarta LISTACARTA_vesInicio(ListaCarta l) {
    l.ant = l.pri;
    return l;
}
int LISTACARTA_final(ListaCarta l) {
    return l.ant->sig==NULL;
}
int LISTACARTA_vacia(ListaCarta l) {
    return l.pri->sig == NULL;
}
ListaCarta LISTACARTA_destruye(ListaCarta l) {
    Nodo *aux;

    while (l.pri!=NULL) {
        aux = l.pri;
        l.pri = l.pri->sig;
        free(aux);
    }
    return l;
}
void LISTACARTA_eliminaPosicion(ListaCarta *l, ListaCarta *descarte, int posicion){
    /**
     * Elimina la posición de la lista y inserta en descartes
     *
     * */
    Nodo *aux;
    (*l) = LISTACARTA_vesInicio((*l));

    if ((*l).ant->sig == NULL) {
        printf("\nError al eliminar, el PDI está al final...\n");
    } else {
        for(int i=0;i<(posicion-1);i++){
            (*l) = LISTACARTA_avanza((*l));

        }
        Nodo nodo_carta = LISTACARTA_consulta((*l));//Recuperamos la carta que queremos jugar.
        LISTACARTA_inserta(descarte,&nodo_carta);//Insertar en la lista de descartes la carta seleccionada.

        aux = (*l).ant->sig;
        (*l).ant->sig = aux->sig; // Eliminamos la carta que hemos jugado de la lista de cartas.
        free(aux);
    }
}
int LISTACARTA_contarCartas(ListaCarta l){
    l = LISTACARTA_vesInicio(l);
    int count=0;
    while (l.ant->sig!=NULL){
        count++;
        l = LISTACARTA_avanza(l);
    }
    return count;
}
void LISTACARTA_roba(ListaCarta *l, Nodo *elemento) {
    Nodo *aux;
    aux = (Nodo*)malloc(sizeof(Nodo));
    if (aux == NULL) {
        printf("\nError al insertar en la lista...\n");
    }else{
        aux->valor = (*elemento).valor;
        aux->color = (*elemento).color;
        aux->sig = (*l).ant->sig;
        (*l).ant->sig = aux;
        (*l).ant = aux; // para mantener el PDI
    }
}
Nodo LISTACARTA_consultaByPosicion(ListaCarta l, int posicion) {
    Nodo *aux;
    if (l.pri->sig == NULL) {
        printf("\nError al consultar, el PDI está al final...\n");
    } else {
        l = LISTACARTA_vesInicio(l);
        for(int i=0;i<(posicion-1);i++){
            l = LISTACARTA_avanza(l);
        }
        aux = l.ant->sig;
    }
    return *aux;
}
void LISTACARTA_cambiaColorComodin(ListaCarta *l, int posicion, int color){
    (*l) = LISTACARTA_vesInicio((*l));

    if ((*l).ant->sig == NULL) {
        printf("\nError al eliminar, el PDI está al final...\n");
    } else {
        for(int i=0;i<(posicion-1);i++){
            (*l) = LISTACARTA_avanza((*l));
        }
        Nodo carta = LISTACARTA_consulta(*l);
        cambiar_color(&carta, color);
    }
}

