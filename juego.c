//
// Created by Alex on 30/04/2019.
//
#include "juego.h"
#include "jugador.h"
#include "listaJuego.h"
#include "menu.h"


void jugar_por_turnos(ListaJuego *lista_jugadores, ListaCarta *descarte, Deck *p){
    int final=0; //Cuando final sea 1, significa que uno de los jugadores se ha quedado sin cartas y ha ganado la partida
    LISTAJUEGO_vesInicio(lista_jugadores);
    while(final!=1){
        (*descarte) = LISTACARTA_vesInicio((*descarte));
        ver_jugadores((*lista_jugadores),(*descarte));
        Nodo carta_descarte = LISTACARTA_consulta((*descarte));

        printf("### ");
        convertirCarta(carta_descarte.valor,carta_descarte.color);
        printf(" ### \n");

        //Aqui selecciona ver mano o robar

        char *name = LISTAJUEGO_consultaNombre((LISTAJUEGO_consulta(*lista_jugadores)));
        selectFirstAction(getGameOption(name),lista_jugadores,descarte, p);

        final++;
    }
}
//int validar_jugada(ListaCarta lista_jugador, ListaCarta descarte){
int validar_jugada(Nodo carta_jugador, Nodo carta_descarte){

    //Nodo carta_jugador = LISTACARTA_consulta(lista_jugador);
    //Nodo carta_descarte = LISTACARTA_consulta(descarte);

    if(carta_jugador.color==carta_descarte.color || carta_jugador.valor==carta_descarte.valor|| carta_jugador.color==4){
        //SE puede jugar la carta
        return 1;
    }else{
        //No es valida la jugada.
        return 0;
    }
}
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
            //ver_lista_cartas(j.jugador.cartas, descarte);
        }else{
            //print bot
            printf("%s \n", j.bots.nombre);
            //ver_lista_cartas(j.bots.cartas, descarte);
        }
        LISTAJUEGO_avanza(&lista_jugadores);
    }
}
void ver_lista_cartas(ListaJuego lista_jugadores, ListaCarta descarte){
    Nodo_jugador j = LISTAJUEGO_consulta(lista_jugadores);

    //ListaCarta lista = LISTACARTA_devolverLista(j);
    ListaCarta lista;
    if(j.type==0){
        lista =  j.jugador.cartas;
    }else{
        lista =  j.bots.cartas;
    }

    lista = LISTACARTA_vesInicio(lista);
    int count=1;

    while (lista.ant->sig!=NULL){
        Nodo carta = LISTACARTA_consulta(lista);
        Nodo carta_descarte = LISTACARTA_consulta(descarte);
        printf("%d . " ,count);
        convertirCarta(carta.valor,carta.color);
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
     *
     * Recuperar carta de la baraja
     * Insertarla en lista de carta
     * comprobar si se puede jugar
     * jugar o no
     */
        if(LISTAJUEGO_esJugador((*lista_jugadores))==0){

            LISTACARTA_roba(&lista_jugadores->pdi->jugador.cartas,(*p)); //insertamos una carta de la baraja
            Nodo carta_robada = baraja_top(*p);
            Nodo carta_descarte = LISTACARTA_consulta(*descarte);
            baraja_pop(p); //eliminamos la carta que hemos insertado de la baraja
            printf("Se ha robado un ");
            convertirCarta(carta_robada.valor,carta_robada.color);

            if(validar_jugada(carta_robada,carta_descarte)==1){
                printf(". Deseas jugarlo? [S/N]\n");
                char opcion_robo = opcion_robar();
                if(strcmp(&opcion_robo, "S") == 0){
                    //Desea jugar la carta robada.

                    int cantidad = LISTACARTA_contarCartas(lista_jugadores->pdi->jugador.cartas);
                    LISTACARTA_eliminaPosicion(&lista_jugadores->pdi->jugador.cartas,descarte,cantidad);

                    printf("ENTRA AQUI -- SI");

                }else{
                    printf("ENTRA AQUI -- NO");
                    //No desea jugar la carta.
                    //PASAR AL SIGUIENTE JUGADOR
                }
            }else{
                printf(". No se puede jugar.\n");
            }

        }else{
            LISTACARTA_roba(&lista_jugadores->pdi->bots.cartas,(*p)); //insertamos una carta de la baraja
            baraja_pop(p); //eliminamos la carta que hemos insertado de la baraja
        }

}
