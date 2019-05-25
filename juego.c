//
// Created by Alex on 30/04/2019.
//
#include "juego.h"
#include "jugador.h"
#include "listaJuego.h"
#include "menu.h"

void juego(char **argv){
    ListaJuego lista_jugadores = LISTAJUEGO_crea();

    Jugador j = loadPlayer(argv[1]);
    Nodo_jugador nodo;
    nodo.jugador = j;
    nodo.type = 0;
    LISTAJUEGO_insertaDerecha(&lista_jugadores,nodo);
    int numBots;
    Bots *b = loadBots(argv[2],&numBots);

    Deck baraja = NULL;
    //Jugador jugador, bot1,bot2,bot3;
    baraja = crear_baraja(); //Creamos la baraja con las cartas incluidas
    ListaCarta descarte = LISTACARTA_crea(); //Creamos la baraja de descartes
    lista_jugadores = LISTAJUEGO_crea();   //Creamos una lista de los jugadores



    /*INSERTAMOS NOMBRE PRUEBA*/


    /*REPARTIMOS LAS CARTAS A CADA JUGADOR*/
     repartir_carta(&baraja,&lista_jugadores.pri->jugador.cartas,7);


    //Jugador j = LISTAJUEGO_consulta(lista_jugadores);

    ver_menu_jugadores(lista_jugadores);
    printf("EMPIEZA A BARAJAR");
    //barajar(&baraja);
}
int validar_jugada(Deck *p, ListaCarta *lista){

    //TODO lista???????? se debe llevar previamente a la posicion de la lista para validar
    if((*p)->valor==(*lista).ant->valor || (*p)->color == (*lista).ant->color || (*lista).ant->color == 4){
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
       /* printf("****************************\n");
        printf("Carta que inserta:\n");
        printf("Valor: %d Color: %d \n",(*p)->valor, (*p)->color);*/
        (*lista) = LISTACARTA_inserta(lista,(*p));
        baraja_pop(p);
       /* printf("Carta que se ha insertado:\n");
        printf("Valor: %d Color: %d\n",(*lista).ant->valor, (*lista).ant->color);
        printf("****************************\n");*/
    }

    return 1;
}
void ver_menu_jugadores(ListaJuego lista_jugadores){
    LISTAJUEGO_vesInicio(&lista_jugadores);
    while(lista_jugadores.pdi->sig != NULL){ //MAL isEmpty usar LISTAJUEGO_final
        Nodo_jugador j = LISTAJUEGO_consulta(lista_jugadores);
        //printf("%s \n", j.nombre);
        //ver_lista_cartas(j.cartas);
        LISTAJUEGO_avanza(&lista_jugadores);
    }
}
void ver_lista_cartas(ListaCarta lista){
    lista = LISTACARTA_vesInicio(lista);
    int count=1;
    while (lista.ant->sig!=NULL){
        Nodo carta = LISTACARTA_consulta(lista);
        printf("%d . " ,count);
        convertirCarta(carta.valor,carta.color);
        lista = LISTACARTA_avanza(lista);
        count++;
    }
}
