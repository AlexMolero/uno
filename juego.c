//
// Created by Alex on 30/04/2019.
//
#include <time.h>
#include "juego.h"
#include "jugador.h"
#include "listaJuego.h"
#include "menu.h"

void free_partida(ListaJuego *lista_jugadores, Deck *baraja, ListaCarta *descarte){
    free(lista_jugadores);
    free(baraja);
    free(descarte);
    *lista_jugadores = LISTAJUEGO_crea();
    baraja = NULL;
    *descarte = LISTACARTA_crea(); //Creamos la baraja de descartes
}
void crear_partida(ListaJuego *lista_jugadores, Deck *baraja, ListaCarta *descarte, char **argv){
    *baraja = crear_baraja();
    barajar(baraja);

    Jugador j   = loadPlayer(argv[1]);
    repartir_carta(baraja,&j.cartas,7,descarte); // El 1 son las cartas que se le reparten al jugador
    LISTAJUEGO_insertaJugador(lista_jugadores,j);
    int numBots;
    Bots *b = loadBots(argv[2], &numBots);
    for (int i = 0; i < numBots; ++i) {
        repartir_carta(baraja,&b[i].cartas,b[i].carta_maxima,descarte);
        LISTAJUEGO_insertaBot(lista_jugadores,b[i]);
    }
    //Aqui reparte una carta en la baraja de descartes.

    repartir_carta_inicial(baraja,descarte);
    LISTAJUEGO_vesInicio(lista_jugadores);
}
void ver_resumen(ListaJuego *lista_jugadores, ListaCarta *descarte){
    ver_jugadores((*lista_jugadores));
    Nodo carta_descarte = LISTACARTA_consulta((*descarte));

    printf("\n ### ");
    convertirCarta(carta_descarte);
    printf(" ### \n");
}
void jugar_por_turnos(ListaJuego *lista_jugadores, ListaCarta *descarte, Deck *p){

        (*descarte) = LISTACARTA_vesInicio((*descarte));
        char *name = LISTAJUEGO_consultaNombre((LISTAJUEGO_consulta(*lista_jugadores)));
        if(!LISTAJUEGO_esJugador(*lista_jugadores)){
            ver_resumen(lista_jugadores,descarte);
            selectFirstAction(getGameOption(name),lista_jugadores,descarte, p);
        }else{
            logica_jugar_bot(lista_jugadores,descarte,p);
        }
        LISTAJUEGO_siguienteTurno(lista_jugadores);

}
int  validar_jugada(Nodo carta_jugador, Nodo carta_descarte){
    if(carta_jugador.color==carta_descarte.color || carta_jugador.valor==carta_descarte.valor || carta_jugador.color==4 ){
        //Se puede jugar la carta
        if(carta_jugador.valor==10 && carta_jugador.color==carta_descarte.color){
            return 1;
        }else if(carta_jugador.valor==11 && carta_jugador.color==carta_descarte.color){
            return 1;
        }else if(carta_jugador.valor==12 && carta_jugador.color==carta_descarte.color){
            return 1;
        }else if(carta_jugador.valor!=12 && carta_jugador.valor!=11 && carta_jugador.valor!=10){
            return 1;
        }else{
            return 0;
        }
    }else{
        //No es valida la jugada.
        return 0;
    }

}
int  repartir_carta(Deck *p, ListaCarta *lista, int cantidad, ListaCarta *descarte){

    for(int i=0;i<cantidad;i++){
        if(PILA_vacia(*p)){
            LISTACARTA_descarteToBaraja(descarte,p);
        }

        (*lista) = LISTACARTA_inserta(lista,(*p));
        baraja_pop(p);
    }
    return 1;
}
int repartir_carta_inicial(Deck *p, ListaCarta *lista){
    //Repartimos la carta inicial con la que se empiez a jugar, si es un comodin se le asigna un color aleatorio.
    Nodo carta_robada = baraja_top(*p);
    if(es_comodin_color(carta_robada) || es_roba_4(carta_robada)){
        srand(time(NULL));
        int random = rand() % 4;

        cambiar_color(&carta_robada,random);
        (*lista) = LISTACARTA_inserta(lista,&carta_robada);

    }else{
        (*lista) = LISTACARTA_inserta(lista,*p);
    }
    baraja_pop(p);
}
void ver_jugadores(ListaJuego lista_jugadores){
    Nodo_jugador jugador_en_posicion = LISTAJUEGO_consulta(lista_jugadores);

    LISTAJUEGO_vesInicio(&lista_jugadores);
    while(!LISTAJUEGO_final(lista_jugadores)){
        Nodo_jugador j = LISTAJUEGO_consulta(lista_jugadores);
        ListaCarta lista = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(lista_jugadores));
        if(!strcmp(LISTAJUEGO_consultaNombre(j),LISTAJUEGO_consultaNombre(jugador_en_posicion))){
            printf("%-15s \t %-3d \t  ", LISTAJUEGO_consultaNombre(j), LISTACARTA_contarCartas(lista));
            LISTAJUEGO_direccion(jugador_en_posicion);
        } else{
            printf("%-15s \t %-3d \t  \n", LISTAJUEGO_consultaNombre(j), LISTACARTA_contarCartas(lista));
        }
        LISTAJUEGO_avanza(&lista_jugadores);
    }
}
void ver_lista_cartas(ListaJuego lista_jugadores, ListaCarta descarte){

    ListaCarta lista = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(lista_jugadores));

    lista = LISTACARTA_vesInicio(lista);
    printf("%d cartas: \n", LISTACARTA_contarCartas(lista));
    int count=1;

    while (!LISTACARTA_final(lista)){
        Nodo carta = LISTACARTA_consulta(lista);
        Nodo carta_descarte = LISTACARTA_consulta(descarte);
        printf("%d . " ,count);
        convertirCarta(carta);
        if(validar_jugada(carta,carta_descarte)==1){
            printf("*");
        }
        printf("\n");

        lista = LISTACARTA_avanza(lista);
        count++;
    }
}
void robar_carta(ListaJuego *lista_jugadores, ListaCarta *descarte, Deck *p){
    /**
     * Recuperar carta de la baraja
     * Insertarla en lista de carta
     * comprobar si se puede jugar
     * jugar o no
     */
    ListaCarta lista = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));
    LISTACARTA_roba(&lista,(*p)); //insertamos una carta de la baraja
    Nodo carta_robada = baraja_top(*p);
    Nodo carta_descarte = LISTACARTA_consulta(*descarte);
    baraja_pop(p); //eliminamos la carta que hemos insertado de la baraja
    printf("Se ha robado un ");
    convertirCarta(carta_robada);

    if(validar_jugada(carta_robada,carta_descarte)==1){ //la jugada es valida
        printf(". Deseas jugarlo? [S/N]\n");
        char opcion_robo;
        scanf(" %c", &opcion_robo);
        while(opcion_robo != 'S' && opcion_robo != 'N'){
            printf(". Escribe [S/N]\n");
            scanf(" %c", &opcion_robo);
        }
        if(opcion_robo == 'S'){
            //Desea jugar la carta robada.
            logica_jugar_carta(carta_robada, lista_jugadores,p,1,descarte);
        }
    }else{
        printf(". No se puede jugar.\n");
    }
}
void robar_bot(ListaJuego *lista_jugadores, ListaCarta *descarte, Deck *p){
    /*
     * El bot roba una carta, si la puede jugar la juega, en caso de elegir color, selecciona el que mas le convenga
     * */

    (*descarte) = LISTACARTA_vesInicio((*descarte));
    Nodo_jugador j = LISTAJUEGO_consulta(*lista_jugadores);

    ListaCarta lista = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));
    LISTACARTA_roba(&lista,(*p)); //insertamos una carta de la baraja
    Nodo carta_robada = baraja_top(*p);
    Nodo carta_descarte = LISTACARTA_consulta(*descarte);
    baraja_pop(p); //eliminamos la carta que hemos insertado de la baraja
    printf("%s ha robado un ",LISTAJUEGO_consultaNombre(j));
    convertirCarta(carta_robada);
    printf("\n");
    if(validar_jugada(carta_robada,carta_descarte)==1){ //la jugada es valida
        logica_jugar_carta(carta_robada, lista_jugadores,p,1,descarte);
    }

}
int  seleccionar_color(ListaJuego lista_jugadores){
    int sel_color;
    ListaCarta lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(lista_jugadores));

    if(LISTAJUEGO_esJugador(lista_jugadores)){
        sel_color = LISTACARTA_devolverColorFavorecido(lista);

    }else{
        sel_color = getColor();
    }
    return sel_color;
}
void logica_jugar_carta(Nodo carta_jugada,ListaJuego *lista_jugadores, Deck *p, int sel_carta, ListaCarta *descarte){
    ListaCarta lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));

    if(es_roba_4(carta_jugada)){ // Si es roba 4 mas color

        LISTAJUEGO_siguienteTurno(lista_jugadores);

        lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));
        repartir_carta(p,&lista,4,descarte);
        LISTAJUEGO_anteriorTurno(lista_jugadores);


        int sel_color = seleccionar_color(*lista_jugadores);
        lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));
        LISTACARTA_cambiaColorComodin(&lista,sel_carta,sel_color,descarte);
    }else if(es_comodin_color(carta_jugada)){
        int sel_color = seleccionar_color(*lista_jugadores);
        LISTACARTA_cambiaColorComodin(&lista,sel_carta,sel_color,descarte);
    }else if(es_suma_2(carta_jugada)){
        LISTAJUEGO_siguienteTurno(lista_jugadores);


        lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));
        repartir_carta(p,&lista,2,descarte);
        LISTAJUEGO_anteriorTurno(lista_jugadores);


        lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));
        LISTACARTA_eliminaPosicion(&lista,descarte,sel_carta);

    }else if(es_saltar_turno(carta_jugada)){
        LISTACARTA_eliminaPosicion(&lista,descarte,sel_carta);
        LISTAJUEGO_siguienteTurno(lista_jugadores);

    }else if(es_cambio_direccion(carta_jugada)){
         LISTAJUEGO_cambioDireccion(lista_jugadores);
        LISTACARTA_eliminaPosicion(&lista,descarte,sel_carta);

    }else{
        //Se juega una carta normal
        LISTACARTA_eliminaPosicion(&lista,descarte,sel_carta);
    }
}
int  carta_preferencia_bot(ListaCarta lista, ListaCarta descarte, Nodo_jugador j){

    char *caracter      = LISTAJUEGO_consultaCaracter(j);
    int  posicion_carta = 0;
    descarte = LISTACARTA_vesInicio(descarte);
    Nodo carta_descarte = LISTACARTA_consulta(descarte);
    Nodo carta_juego;

    posicion_carta      = LISTACARTA_hayCero(lista);
    if(posicion_carta!=0){
        carta_juego = LISTACARTA_consultaByPosicion(lista,posicion_carta);
        if(validar_jugada(carta_juego,carta_descarte)){
            //si la jugada es valida
            return  posicion_carta;
        }else{
            posicion_carta = 0;
        }
    }

    if(!strcmp(caracter, "Agresivo")){
        posicion_carta = LISTACARTA_posicionComodin(lista,posicion_carta,carta_descarte,carta_juego);
        if(posicion_carta!=0) {
            return posicion_carta;
        }
    }
    //Aqui si es agresivo juega color si no le favorece

    posicion_carta = LISTACARTA_mismoColor(lista,descarte);
    if(posicion_carta!=0){
        carta_juego = LISTACARTA_consultaByPosicion(lista,posicion_carta);
        if(validar_jugada(carta_juego,carta_descarte)){
            //si la jugada es valida
            return  posicion_carta;
        }else{
            posicion_carta = 0;
        }
    }

    if(!strcmp(caracter, "Calmado")){
        //Aqui el bot calmado tiene que jugar comodin si puede
        posicion_carta = LISTACARTA_posicionComodin(lista,posicion_carta,carta_descarte,carta_juego);
        if(posicion_carta!=0) {
            return posicion_carta;
        }
    }

    return posicion_carta;
}
void logica_jugar_bot(ListaJuego *lista_jugadores, ListaCarta *descarte,Deck *p){
    Nodo_jugador j = LISTAJUEGO_consulta(*lista_jugadores);
    ListaCarta lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));
    lista = LISTACARTA_vesInicio(lista);

    int sel_carta = 0;
    sel_carta = carta_preferencia_bot(lista,*descarte,j);
    if(sel_carta!=0){

        Nodo carta_jugador = LISTACARTA_consultaByPosicion(lista,sel_carta);
        logica_jugar_carta(carta_jugador,lista_jugadores,p,sel_carta,descarte);

        printf("%s juega un ", LISTAJUEGO_consultaNombre(j));

        convertirCarta(carta_jugador);
        printf(". \n");

    }else{
       // printf("El bot tiene que robar una carta.\n");
        robar_bot(lista_jugadores,descarte,p);
    }
}
void jugar_carta(ListaJuego *lista_jugadores, ListaCarta *descarte,Deck *p){
    int sel_carta =  selectCarta(*lista_jugadores);
    Nodo carta_descarte  = LISTACARTA_consulta((*descarte));
    ListaCarta lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));
    Nodo carta_jugador = LISTACARTA_consultaByPosicion(lista,sel_carta);

    if(validar_jugada(carta_jugador,carta_descarte)){
        logica_jugar_carta(carta_jugador,lista_jugadores,p,sel_carta,descarte);
    }else{
        printf("No se puede jugar el ");
        convertirCarta(carta_jugador);
        printf("\n");
    }
}
