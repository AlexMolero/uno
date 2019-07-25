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
void LISTAJUEGO_insertaJugador(ListaJuego *l, Jugador jugador){
    Nodo_jugador    nodo;
    nodo.jugador    = jugador;
    nodo.type       = 0;
    nodo.direccion  = 1;
    LISTAJUEGO_insertaDerecha(l,nodo);

}
void LISTAJUEGO_insertaBot(ListaJuego *l, Bots bot){
    Nodo_jugador    nodo;
    nodo.bots       = bot;
    nodo.type       = 1;
    nodo.direccion  = 1;
    LISTAJUEGO_insertaDerecha(l,nodo);

}
void LISTAJUEGO_insertaDerecha(ListaJuego *l, Nodo_jugador nodo){
    Nodo_jugador *aux;

    if (l->pdi == l->ult) { //l->pdi->sig == NULL
        printf("\nError al insertar a la derecha, el PDI está al final...\n");
    } else {
        aux = (Nodo_jugador*)malloc(sizeof(Nodo_jugador));
        if (aux == NULL) {
            printf("\nError al insertar a la derecha...\n");
        } else {
            if(nodo.type==0){
                aux->jugador = nodo.jugador;
                aux->type = 0;
            }else{
                aux->bots = nodo.bots;
                aux->type = 1;
            }
            aux->sig = l->pdi->sig;
            aux->ant = l->pdi;
            aux->sig->ant = aux;
            l->pdi->sig = aux;
            l->pdi = aux; // dejamos el PDI sobre el nuevo elemento
        }
    }
}
Nodo_jugador LISTAJUEGO_consulta(ListaJuego l){
    Nodo_jugador *nodo;
    if (l.pdi==l.pri || l.pdi==l.ult) {
        printf("\nError al consultar, PDI al incio o al final, ...\n");
    } else {
        nodo = l.pdi;
    }
    return (*nodo);
}
char *LISTAJUEGO_consultaNombre(Nodo_jugador nodo){

    if(nodo.type==0){
        return JUGADOR_consultaNombre(nodo.jugador);
    }
    else{
        return BOTS_consultaNombre(nodo.bots);
    }
}
char * LISTAJUEGO_consultaCaracter(Nodo_jugador nodo){
    char *c=NULL;
    if(nodo.type!=0){
        return BOTS_consultaNombreCaracter(nodo.bots);
    }
    return c;
}
int LISTAJUEGO_consultaTipo(Nodo_jugador nodo){

    return nodo.type;
}
int LISTAJUEGO_consultaPartidasGanadas(Nodo_jugador nodo){
    if(LISTAJUEGO_consultaTipo(nodo)){
        return BOTS_consultaPartidasGanadas(nodo.bots);
    }
    else{
        return JUGADOR_consultaPartidasGanadas(nodo.jugador);
    }
}
int LISTAJUEGO_consultaPartidasPerdidas(Nodo_jugador nodo){
    if(LISTAJUEGO_consultaTipo(nodo)){
        return BOTS_consultaPartidasPerdidas(nodo.bots);
    }
    else{
        return JUGADOR_consultaPartidasPerdidas(nodo.jugador);
    }
}
int LISTAJUEGO_consultaCartasPartida(Nodo_jugador j, int partida){
    if(!LISTAJUEGO_consultaTipo(j)){
        return JUGADOR_consultaCartasPartida(j.jugador, partida);
    }
    return -1;
}
int LISTAJUEGO_consultaNBots(Nodo_jugador j){
    return BOTS_consultaNBots(j.bots);
}
int LISTAJUEGO_consultaCartaMax(Nodo_jugador j){
    return BOTS_consultaCartaMax(j.bots);
}
ListaCarta LISTAJUEGO_consultaCartas(Nodo_jugador nodo){
    if(!LISTAJUEGO_consultaTipo(nodo)){
        return JUGADOR_consultaCartas(nodo.jugador);
        //return &nodo.jugador.cartas;
    }else{
        return BOTS_consultaCartas(nodo.bots);
    }
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
    }else{
        l->pdi = l->pdi->sig;
    }
}
void LISTAJUEGO_retrocede(ListaJuego *l){
    if (l->pdi == l->pri) {
        printf("\nError al retroceder...\n");
    }else{
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
int LISTAJUEGO_count(ListaJuego l){
    int count = 0;
    LISTAJUEGO_vesInicio(&l);
    while(!LISTAJUEGO_final(l)){
        LISTAJUEGO_avanza(&l);
        count++;
    }
    return count;
}
ListaCarta * LISTAJUEGO_consultaListaCarta(ListaJuego *l){
    if(l->pdi->type==0){
        return &l->pdi->jugador.cartas;
    }else{
        return &l->pdi->bots.cartas;
    }
}
int LISTAJUEGO_esJugador(ListaJuego l){
    return l.pdi->type;
}
int LISTAJUEGO_finJuego(ListaJuego l){
    int finJuego=0;
    LISTAJUEGO_vesInicio(&l);
    while(!LISTAJUEGO_final(l)){
        int cartas = LISTACARTA_contarCartas(LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(l)));
        LISTAJUEGO_avanza(&l);
        if(cartas==0){
            finJuego=1;
        }
    }
    return finJuego;
}
int LISTAJUEGO_siguienteTurno(ListaJuego *l){
    Nodo_jugador jugador = LISTAJUEGO_consulta(*l);
    if(jugador.direccion==1){
        LISTAJUEGO_avanza(l);
    }else{
        LISTAJUEGO_retrocede(l);
    }

    if(LISTAJUEGO_final(*l)){
        LISTAJUEGO_vesInicio(l);
    }else if(LISTAJUEGO_inicio(*l)){
        LISTAJUEGO_vesFinal(l);
    }
}
int LISTAJUEGO_anteriorTurno(ListaJuego *l){
    Nodo_jugador jugador = LISTAJUEGO_consulta(*l);
    if(jugador.direccion==1){
        LISTAJUEGO_retrocede(l);
    }else{
        LISTAJUEGO_avanza(l);

    }

    if(LISTAJUEGO_final(*l)){
        LISTAJUEGO_vesInicio(l);
    }else if(LISTAJUEGO_inicio(*l)){
        LISTAJUEGO_vesFinal(l);
    }
}
//sig turno