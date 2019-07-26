#include <stdio.h>
#include "menu.h"
#include "juego.h"


int main(int argc, char **argv) {
    setbuf(stdout,0);
    if(argc == 3){
        /*Inicio: Creacion de lista y pilas*/
        ListaJuego lista_jugadores = LISTAJUEGO_crea();
        Deck baraja = NULL;
        ListaCarta descarte = LISTACARTA_crea(); //Creamos la baraja de descartes
        crear_partida(&lista_jugadores,&baraja,&descarte,argv);

        /*Fin: Creacion de lista y pilas*/
        muestraMenu();
        int option = getOption();
        while (option!=3){
            selectOption(option, argv, &lista_jugadores,&descarte,&baraja);
            muestraMenu();
            option = getOption();
        }
        selectOption(option, argv, &lista_jugadores,&descarte,&baraja);
    }else{
        printf("Error con los argumentos del programa.\n");
    }
    printf("Has salido del programa\n");
    return 0;
}