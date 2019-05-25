//
// Created by Alex on 30/04/2019.
//
#include "juego.h"
#include "jugador.h"
#include "listaJuego.h"
#include "menu.h"

void juego(char **argv){
    Jugador j = loadPlayer(argv[1]);
    Bots *b = loadBots(argv[2]);
    Deck baraja = NULL;
    Jugador jugador, bot1,bot2,bot3;
    baraja = crear_baraja(); //Creamos la baraja con las cartas incluidas
    ListaCarta descarte = LISTACARTA_crea(); //Creamos la baraja de descartes
    ListaJuego lista_jugadores = LISTAJUEGO_crea();   //Creamos una lista de los jugadores

    /*CREAMOS LOS JUGADORES DEL JUEGO*/
    jugador = JUGADOR_crea();
    bot1 = JUGADOR_crea();
    bot2 = JUGADOR_crea();
    bot3 = JUGADOR_crea();

    /*INSERTAMOS NOMBRE PRUEBA*/
    JUGADOR_insertaNombre(&bot1, "Obra Dinn");
    JUGADOR_insertaNombre(&bot2, "Olivia Colomar");
    JUGADOR_insertaNombre(&bot3, "Syrio Forel");
    JUGADOR_insertaNombre(&jugador, "Alex Molero");

    /*REPARTIMOS LAS CARTAS A CADA JUGADOR*/
     repartir_carta(&baraja,&jugador.cartas,7);
     repartir_carta(&baraja,&bot1.cartas,7);
     repartir_carta(&baraja,&bot2.cartas,7);
     repartir_carta(&baraja,&bot3.cartas,7);
    /*INSERTAMOS CADA JUGADOR A LA LISTA DE JUEGO*/
    LISTAJUEGO_insertaDerecha(&lista_jugadores,jugador);
    LISTAJUEGO_insertaDerecha(&lista_jugadores,bot1);
    LISTAJUEGO_insertaDerecha(&lista_jugadores,bot2);
    LISTAJUEGO_insertaDerecha(&lista_jugadores,bot3);
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
