//#include <libnet.h>
#include "listaCarta.h"
#define COLOR_COMODIN  4

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
void LISTACARTA_elimina(ListaCarta *l, int posicion){
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
        aux = (*l).ant->sig;
        (*l).ant->sig = aux->sig; // Eliminamos la carta que hemos jugado de la lista de cartas.
        free(aux);
    }
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
ListaCarta LISTACARTA_vesFinal(ListaCarta l) {
    l.ant->sig=NULL;
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
void LISTACARTA_cambiaColorComodin(ListaCarta *l, int posicion, int color, ListaCarta *descarte){
    (*l) = LISTACARTA_vesInicio((*l));

    if ((*l).ant->sig == NULL) {
        printf("\nError al eliminar, el PDI está al final...\n");
    } else {
        for(int i=0;i<(posicion-1);i++){
            (*l) = LISTACARTA_avanza((*l));
        }
        Nodo carta = LISTACARTA_consulta(*l);
        cambiar_color(&carta, color);
        LISTACARTA_elimina(l,posicion);
        LISTACARTA_inserta(descarte,&carta);

    }
}
int LISTACARTA_hayCero(ListaCarta l){
    //Recorre la lista y busca si hay un cero para jugar, si devuelve algo distinto a 0 es que ha encontrado un cero.
    l = LISTACARTA_vesInicio(l);
    int posicion = 0;
    int cont     = 0;
    while (l.ant->sig!=NULL){
        cont++;
        if(LISTACARTA_consulta(l).valor==0){
            //Hay un cero
            posicion = cont;
        }
        l = LISTACARTA_avanza(l);
    }
    return posicion;
}
int LISTACARTA_mismoColor(ListaCarta l, ListaCarta descarte){
    l = LISTACARTA_vesInicio(l);
    Nodo carta_descarte = LISTACARTA_consulta(descarte);
    int posicion = 0;
    int cont     = 0;
    while (l.ant->sig!=NULL){
        cont++;
        if(LISTACARTA_consulta(l).color==carta_descarte.color){
            //Hay un cero
            posicion = cont;
        }
        l = LISTACARTA_avanza(l);
    }
    return posicion;
}
int LISTACARTA_comodin(ListaCarta l){
    l = LISTACARTA_vesInicio(l);
    int posicion = 0;
    int cont     = 0;
    while (l.ant->sig!=NULL){
        cont++;
        if(LISTACARTA_consulta(l).color==COLOR_COMODIN){
            posicion = cont;
        }
        l = LISTACARTA_avanza(l);
    }
    return posicion;
}
int LISTACARTA_contarColor(ListaCarta l, Nodo carta){
    //Cuenta las veces que está el color de juego en la baraja.
    l = LISTACARTA_vesInicio(l);
    int count=0;
    while (l.ant->sig!=NULL){
        Nodo carta_lista = LISTACARTA_consulta(l);

        if(carta.color==carta_lista.color){
            count++;
        }

        l = LISTACARTA_avanza(l);
    }
    return count;
}
int LISTACARTA_favoreceColor(ListaCarta l, Nodo carta){
    //Busca si el color que se debe jugar es el mayor de la mano.
    int rojo,azul,amarillo,verde;
    l = LISTACARTA_vesInicio(l);
    while (l.ant->sig!=NULL){
        Nodo carta_lista = LISTACARTA_consulta(l);
        // 0=Rojo, 1=Amarillo, 2=Verde, 3=Azul y 4 = Comodin
        switch(carta_lista.color){
            case 0:
                rojo++;
                break;
            case 1:
                amarillo++;
                break;
            case 2:
                verde++;
                break;
            case 3:
                azul++;
                break;
        }
        l = LISTACARTA_avanza(l);
    }
    int color = LISTACARTA_contarColor(l,carta);
    if(color>=rojo && color>=amarillo && color>=verde && color>=azul){
        return 1;
    } else{
        return 0;
    }

}




