//
// Created by Alex on 30/04/2019.
//
#include "juego.h"
#include "jugador.h"
#include "listaJuego.h"

void juego(Jugador j, Bots *b){
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
       repartir_carta(&baraja,&jugador.cartas,20);
    // repartir_carta(&baraja,&bot1.cartas,7);
    // repartir_carta(&baraja,&bot2.cartas,7);
    // repartir_carta(&baraja,&bot3.cartas,7);
    /*INSERTAMOS CADA JUGADOR A LA LISTA DE JUEGO*/
    LISTAJUEGO_insertaDerecha(&lista_jugadores,jugador);
    LISTAJUEGO_insertaDerecha(&lista_jugadores,bot1);
    LISTAJUEGO_insertaDerecha(&lista_jugadores,bot2);
    LISTAJUEGO_insertaDerecha(&lista_jugadores,bot3);
    //ver_menu_jugadores(lista_jugadores);
    //Nodo carta = LISTACARTA_consulta(jugador.cartas);
    //printf("%d", carta.valor);
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
        printf("****************************\n");
        printf("Carta que inserta:\n");
        printf("Valor: %d Color: %d \n",(*p)->valor, (*p)->color);
        (*lista) = LISTACARTA_inserta(lista,(*p));

        baraja_pop(p);
        printf("Carta que se ha insertado:\n");
        printf("Valor: %d Color: %d\n",(*lista).ant->valor, (*lista).ant->color);
        printf("****************************\n");
    }

    /*(*lista) = LISTACARTA_vesInicio((*lista));
    Nodo carta = LISTACARTA_consulta((*lista));
    printf("%d ",carta.color);
    printf("%d ",carta.valor);
    (*lista) = LISTACARTA_avanza((*lista));
    carta = LISTACARTA_consulta((*lista));
    printf("%d ",carta.color);
    printf("%d ",carta.valor);*/

    return 1;
}
void ver_menu_jugadores(ListaJuego lista_jugadores){
    LISTAJUEGO_vesInicio(&lista_jugadores);
    while(lista_jugadores.pri != NULL){ //MAL isEmpty usar LISTAJUEGO_final
        Jugador j = LISTAJUEGO_consulta(lista_jugadores);
        printf("%s \n", j.nombre);
        ver_lista_cartas(j.cartas);
        LISTAJUEGO_avanza(&lista_jugadores);
    }
}
void ver_lista_cartas(ListaCarta lista){
    lista = LISTACARTA_vesInicio(lista);
   // while (lista.ant!=NULL){
        Nodo carta = LISTACARTA_consulta(lista);
        printf("Valor: %d ",carta.valor);
        printf("Color: %d \n",carta.color);
        lista = LISTACARTA_avanza(lista);
        carta = LISTACARTA_consulta(lista);
        printf("Valor: %d ",carta.valor);
        printf("Color: %d \n",carta.color);
   // }
}
