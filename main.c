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
        baraja      = crear_baraja();
        barajar(&baraja);

        Jugador j   = loadPlayer(argv[1]);
        repartir_carta(&baraja,&j.cartas,1,&descarte); // El 1 son las cartas que se le reparten al jugador
        LISTAJUEGO_insertaJugador(&lista_jugadores,j);
        int numBots;
        Bots *b = loadBots(argv[2], &numBots);
        for (int i = 0; i < numBots; ++i) {
            repartir_carta(&baraja,&b[i].cartas,b[i].carta_maxima,&descarte);
            LISTAJUEGO_insertaBot(&lista_jugadores,b[i]);
        }
        repartir_carta(&baraja, &descarte,1,&descarte);
        LISTAJUEGO_vesInicio(&lista_jugadores);

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