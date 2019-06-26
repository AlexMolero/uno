//
// Created by Alex on 30/04/2019.
//
#include "juego.h"
#include "jugador.h"
#include "listaJuego.h"
#include "menu.h"

void juego(char **argv, ListaJuego *lista_jugadores){
    /*Inicio:Insertamos los bots y jugador a la lista*/
    Deck baraja = NULL;
    baraja = crear_baraja();
    *lista_jugadores = LISTAJUEGO_crea();
    Jugador j = loadPlayer(argv[1]);
    repartir_carta(&baraja,&j.cartas,30);
    LISTAJUEGO_insertaJugador(lista_jugadores,j);
    /*int numBots;
    Bots *b = loadBots(argv[2], &numBots);
    for (int i = 0; i < numBots ; ++i) {
        //repartir_carta(&baraja,&b[i].cartas,b[i].carta_maxima);
        LISTAJUEGO_insertaBot(&lista_jugadores,b[i]);
    }*/
    /*Fin:Insertamos los bots y jugador a la lista*/

    /*REPARTIMOS LAS CARTAS A CADA JUGADOR Y A LA LISTA DE DESCARTES*/
    ListaCarta descarte = LISTACARTA_crea(); //Creamos la baraja de descartes
    repartir_carta(&baraja, &descarte,1);
    /*INICIAMOS EL JUEGO POR TURNOS*/
    jugar_por_turnos(lista_jugadores,&descarte,&baraja);
    //ver_jugadores(lista_jugadores);
    //barajar(&baraja);
}
void jugar_por_turnos(ListaJuego *lista_jugadores, ListaCarta *descarte, Deck *p){
    int final=0; //Cuando final sea 1, significa que uno de los jugadores se ha quedado sin cartas y ha ganado la partida
    LISTAJUEGO_vesInicio(lista_jugadores);
    while(final!=1){
        *descarte = LISTACARTA_vesInicio(*descarte);
        ver_jugadores((*lista_jugadores),(*descarte));
        Nodo carta = LISTACARTA_consulta(*descarte);
        convertirCarta(carta.valor,carta.color);

        char *name = LISTAJUEGO_consultaNombre((LISTAJUEGO_consulta(*lista_jugadores)));
        //*lista_jugadores->pdi. = LISTAJUEGO_consultaListaCarta((*lista_jugadores));

        selectFirstAction(getGameOption(name), LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*lista_jugadores)),descarte);

        final++;
    }
}
int validar_jugada(ListaCarta lista_jugador, ListaCarta descarte){

    Nodo carta_jugador = LISTACARTA_consulta(lista_jugador);
    Nodo carta_descarte = LISTACARTA_consulta(descarte);

    if(carta_jugador.color==carta_descarte.color || carta_jugador.valor==carta_descarte.valor|| carta_jugador.color==4){
        //SE puede jugar la carta
        return 1;
    }else{
        //No es valida la jugada.
        return 0;
    }
}
/**
 * Repartir carta: Se pasa por referencia la baraja y una lista de cartas para insertar la cantidad indicada en la lista de cartas
 * del usuario
 * @param p
 * @param lista
 * @param cantidad
 * @return
 */
int repartir_carta(Deck *p, ListaCarta *lista, int cantidad){

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
    while(lista_jugadores.pdi->sig != NULL){ //MAL isEmpty usar LISTAJUEGO_final
        Nodo_jugador j = LISTAJUEGO_consulta(lista_jugadores);
        if(j.type==0){
            //print jugador
            printf("%s - %d \n", j.jugador.nombre, LISTACARTA_contarCartas(j.jugador.cartas));
            ver_lista_cartas(j.jugador.cartas, descarte);
        }else{
            //print bot
            printf("%s \n", j.bots.nombre);
            ver_lista_cartas(j.bots.cartas, descarte);
        }
        LISTAJUEGO_avanza(&lista_jugadores);
    }
}
void ver_lista_cartas(ListaCarta lista, ListaCarta descarte){
    lista = LISTACARTA_vesInicio(lista);
    int count=1;
    while (lista.ant->sig!=NULL){
        Nodo carta = LISTACARTA_consulta(lista);
        printf("%d . " ,count);
        convertirCarta(carta.valor,carta.color);
        if(validar_jugada(lista,descarte)==1){
            printf("*");
        }
        printf("\n");

        lista = LISTACARTA_avanza(lista);
        count++;
    }

}
