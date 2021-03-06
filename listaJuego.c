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
                aux->jugador   = nodo.jugador;
                aux->type      = 0;
                aux->direccion = 1;
            }else{
                aux->bots      = nodo.bots;
                aux->type      = 1;
                aux->direccion = 1;
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
Nodo_jugador* LISTAJUEGO_consultaPuntero(ListaJuego l){
    Nodo_jugador *nodo;
    if (l.pdi==l.pri || l.pdi==l.ult) {
        printf("\nError al consultar, PDI al incio o al final, ...\n");
    } else {
        nodo = l.pdi;
    }
    return nodo;
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
int LISTAJUEGO_consultaDireccion(Nodo_jugador nodo){

    return nodo.direccion;
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
}
void LISTAJUEGO_insertaCartasPartida_i(Nodo_jugador *j, int cartas){
    if(!LISTAJUEGO_consultaTipo(*j)){
        JUGADOR_insertaCartasPartida_i(&j->jugador, cartas);
    }
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
void LISTAJUEGO_cambioDireccion(ListaJuego *l){
    Nodo_jugador j = LISTAJUEGO_consulta(*l);
    //LISTAJUEGO_vesInicio(l);
    int direccion_actual = LISTAJUEGO_consultaDireccion(j);

    if(direccion_actual==1){
        direccion_actual=0;
    } else{
        direccion_actual=1;
    }
    int count = LISTAJUEGO_count(*l);
    for (int i = 0; i < count; i++) {
         l->pdi->direccion=direccion_actual;
        if(l->pdi->direccion==1){
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
    /*
    while(!LISTAJUEGO_final(*l)){
        l->pdi->direccion=direccion_actual;
        LISTAJUEGO_avanza(l);
    }*/

}
void LISTAJUEGO_insertaPartidasGanadas(Nodo_jugador *nodo){
    if(LISTAJUEGO_consultaTipo(*nodo)){
        BOTS_insertaPartidasGanadas(&nodo->bots);
    }
    else{
        JUGADOR_insertaPartidasGanadas(&nodo->jugador, nodo->jugador.partidas_ganadas+1);
    }

}
void LISTAJUEGO_insertaPartidasPerdidas(Nodo_jugador *nodo){
    if(LISTAJUEGO_consultaTipo(*nodo)) {
        BOTS_insertaPartidasPerdidas(&nodo->bots);
    }
    else{
        JUGADOR_insertaPartidasPerdidas(&nodo->jugador, nodo->jugador.partidas_perdidas+1);
    }
}
void LISTAJUEGO_direccion(Nodo_jugador jugador){
    if(jugador.direccion==1){
        printf("v\n");
    }else{
        printf("^\n");

    }
}
int LISTAJUEGO_contarCartasJugador(ListaJuego lista_jugadores){
    LISTAJUEGO_inicio(lista_jugadores);
    while(!LISTAJUEGO_final(lista_jugadores)){
        if(LISTAJUEGO_esJugador(lista_jugadores)){
            ListaCarta lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(lista_jugadores));
            int numero_cartas = LISTACARTA_contarCartas(lista);
            return numero_cartas;
        }
        LISTAJUEGO_avanza(&lista_jugadores);
    }
}
int LISTAJUEGO_mostrarGanador(ListaJuego *lista_jugadores){
    LISTAJUEGO_inicio(*lista_jugadores);
    while(!LISTAJUEGO_final(*lista_jugadores)){
        ListaCarta lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));
        if(LISTACARTA_contarCartas(lista)==0){
            LISTAJUEGO_insertaPartidasGanadas(LISTAJUEGO_consultaPuntero(*lista_jugadores));
        }
        else{
            LISTAJUEGO_insertaPartidasPerdidas(LISTAJUEGO_consultaPuntero(*lista_jugadores));
        }
        if(LISTACARTA_contarCartas(lista)==0 && LISTAJUEGO_esJugador(*lista_jugadores)){
            Nodo_jugador j = LISTAJUEGO_consulta(*lista_jugadores);
            printf("%s ha ganado la partida. Te quedaban %d cartas en la mano",LISTAJUEGO_consultaNombre(j), LISTAJUEGO_contarCartasJugador(*lista_jugadores));
            //añade derrota a jugador y bots

            return 1;
        }else if(LISTACARTA_contarCartas(lista)==0 && !LISTAJUEGO_esJugador(*lista_jugadores)){
            //El jugador ha ganado la partida
            printf("¡Has ganado la partida!\n");

        }
        if(!LISTAJUEGO_esJugador(*lista_jugadores)){
            LISTAJUEGO_insertaCartasPartida_i(LISTAJUEGO_consultaPuntero(*lista_jugadores),LISTAJUEGO_contarCartasJugador(*lista_jugadores));
        }
        LISTAJUEGO_avanza(lista_jugadores);
    }
}


//sig turno