//
// Created by Alex on 30/04/2019.
//
#include "juego.h"
#include "jugador.h"
#include "listaJuego.h"
#include "menu.h"

void ver_resumen(ListaJuego *lista_jugadores, ListaCarta *descarte){
    ver_jugadores((*lista_jugadores),(*descarte));
    Nodo carta_descarte = LISTACARTA_consulta((*descarte));

    printf("### ");
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
           // printf("ENTRA EN BOT \n");
        }
        LISTAJUEGO_avanza(lista_jugadores);

        if(LISTAJUEGO_final(*lista_jugadores)){
            LISTAJUEGO_vesInicio(lista_jugadores);
        }
        //funcion comprobar si hay un jugador con 0 cartas, final = 0:

}
int  validar_jugada(Nodo carta_jugador, Nodo carta_descarte){

    if(carta_jugador.color==carta_descarte.color || carta_jugador.valor==carta_descarte.valor|| carta_jugador.color==4){
        //Se puede jugar la carta
        return 1;
    }else{
        //No es valida la jugada.
        return 0;
    }
}
int  repartir_carta(Deck *p, ListaCarta *lista, int cantidad){

    Nodo *aux;
    aux = (*p);
    for(int i=0;i<cantidad;i++){
        (*lista) = LISTACARTA_inserta(lista,(*p));
        baraja_pop(p);
    }
    return 1;
}
void ver_jugadores(ListaJuego lista_jugadores, ListaCarta descarte){
    LISTAJUEGO_vesInicio(&lista_jugadores);
    while(!LISTAJUEGO_final(lista_jugadores)){ //MAL isEmpty usar LISTAJUEGO_final
        Nodo_jugador j = LISTAJUEGO_consulta(lista_jugadores);
        ListaCarta lista = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(lista_jugadores));

        printf("%s - %d \n", LISTAJUEGO_consultaNombre(j), LISTACARTA_contarCartas(lista));

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
        if(!strcmpi(&opcion_robo, "S")){
            //Desea jugar la carta robada.
            int cantidad = LISTACARTA_contarCartas(lista);
            LISTACARTA_eliminaPosicion(&lista,descarte,cantidad);
        }
    }else{
        printf(". No se puede jugar.\n");
    }
}
void logica_jugar_carta(Nodo carta_jugada,ListaJuego *lista_jugadores, Deck *p, int sel_carta, ListaCarta *descarte){
    ListaCarta lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));

    if(es_roba_4(carta_jugada)){ // Si es roba 4 mas color
        LISTAJUEGO_avanza(lista_jugadores);
        lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));
        repartir_carta(p,&lista,4);
        LISTAJUEGO_retrocede(lista_jugadores);
        int sel_color = getColor();
        lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));
        LISTACARTA_cambiaColorComodin(&lista,sel_carta,sel_color,descarte);
    }else if(es_comodin_color(carta_jugada)){
        int sel_color = getColor();
        LISTACARTA_cambiaColorComodin(&lista,sel_carta,sel_color,descarte);
    }else if(es_suma_2(carta_jugada)){
        LISTAJUEGO_avanza(lista_jugadores);
        lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));
        repartir_carta(p,&lista,2);
        LISTAJUEGO_retrocede(lista_jugadores);
        LISTACARTA_eliminaPosicion(&lista,descarte,sel_carta);

    }else if(es_saltar_turno(carta_jugada)){
        LISTAJUEGO_avanza(lista_jugadores);
        if(LISTAJUEGO_final(*lista_jugadores)){
            LISTAJUEGO_vesInicio(lista_jugadores);
        }
    }else{
        //Se juega una carta normal
        LISTACARTA_eliminaPosicion(&lista,descarte,sel_carta);
    }
}
int  carta_preferencia_bot(ListaCarta lista, ListaCarta descarte, Nodo_jugador j){
    //Busca una carte de preferencia
    /*
     *1- Ceros
     *      Agresivos:  si el color no les favorece, tiran comodin, si es comodin de color eligen el color que mas les favorece.
     *2- Mismo color
     *      Calmados: Tiran comodin
     *3- Roban carta
     *4- Si la carta robada la pueden tirar la tiran.
     *
     * */
    char *caracter      = LISTAJUEGO_consultaCaracter(j);
    int  posicion_carta = 0;
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
    if(!strcmpi(caracter, "Agresivo")){
        if(!LISTACARTA_favoreceColor(lista,carta_descarte)){
            //Aqui la carta no favorece, mejor jugar el comodin.

            printf("Juega el comodin, no favorece \n");
        }
        printf("El bot es agresivo \n");
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
    if(!strcmpi(caracter, "Calmado")){
        printf("El bot es calmado \n");
    }
    //Aqui calmados tiran comodin
    //Roban carta
    //Si la carta robada se puede tirar la tiran.

    return posicion_carta;

}
void logica_jugar_bot(ListaJuego *lista_jugadores, ListaCarta *descarte,Deck *p){
    Nodo_jugador j = LISTAJUEGO_consulta(*lista_jugadores);
    ListaCarta lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));

    int sel_carta = 0;
    printf("Bot: %s \n",j.bots.nombre);
    ver_lista_cartas(*lista_jugadores,*descarte);
    sel_carta = carta_preferencia_bot(lista,*descarte,j);
    if(sel_carta!=0){
        printf("El bot puede jugar una carta de la posicion: %d \n", sel_carta);
    }else{
        //Robar carta
    }

    //printf("%s juega un 9 Azul. \n", LISTAJUEGO_consultaNombre(j));


}
void jugar_carta(ListaJuego *lista_jugadores, ListaCarta *descarte,Deck *p){
    int sel_carta =  selectCarta();
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
