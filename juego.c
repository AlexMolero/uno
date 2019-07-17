//
// Created by Alex on 30/04/2019.
//
#include "juego.h"
#include "jugador.h"
#include "listaJuego.h"
#include "menu.h"

void  ver_resumen(ListaJuego *lista_jugadores, ListaCarta *descarte){
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
void logica_jugar_carta(Nodo carta_jugada,ListaJuego *lista_jugadores, Deck *p, int sel_carta){
    ListaCarta lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));

    if(es_roba_4(carta_jugada)){ // Si es roba 4 mas color
        LISTAJUEGO_avanza(lista_jugadores);
        lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));
        repartir_carta(p,&lista,4);
        LISTAJUEGO_retrocede(lista_jugadores);
        int sel_color = getColor();
        LISTACARTA_cambiaColorComodin(&lista,sel_carta,sel_color);
    }
    if(es_comodin_color(carta_jugada)){
        int sel_color = getColor();
        LISTACARTA_cambiaColorComodin(&lista,sel_carta,sel_color);
    }
    if(es_suma_2(carta_jugada)){
        LISTAJUEGO_avanza(lista_jugadores);
        lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));
        repartir_carta(p,&lista,2);
        LISTAJUEGO_retrocede(lista_jugadores);
    }
    if(es_saltar_turno(carta_jugada)){
        LISTAJUEGO_avanza(lista_jugadores);
        if(LISTAJUEGO_final(*lista_jugadores)){
            LISTAJUEGO_vesInicio(lista_jugadores);
        }
    }
}
void logica_jugar_bot(ListaJuego *lista_jugadores, ListaCarta *descarte,Deck *p){
    Nodo_jugador j = LISTAJUEGO_consulta(*lista_jugadores);
    ListaCarta lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));
    //Nodo carta_jugador  = LISTACARTA_consulta(lista);

    if(es_cero(carta_jugador)){
        //Jugará el 0

    }
    printf("%s juega un 9 Azul. \n", LISTAJUEGO_consultaNombre(j));


}
void jugar_carta(ListaJuego *lista_jugadores, ListaCarta *descarte,Deck *p){
    int sel_carta =  selectCarta();
    Nodo carta_descarte  = LISTACARTA_consulta((*descarte));
    ListaCarta lista  = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores));
    Nodo carta_jugador = LISTACARTA_consultaByPosicion(lista,sel_carta);

    if(validar_jugada(carta_jugador,carta_descarte)){
        logica_jugar_carta(carta_jugador,lista_jugadores,p,sel_carta);
        LISTACARTA_eliminaPosicion(&lista,descarte,sel_carta);
    }else{
        printf("No se puede jugar el ");
        convertirCarta(carta_jugador);
        printf("\n");
    }
}
