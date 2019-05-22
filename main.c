#include <stdio.h>
#include "menu.h"
#include "juego.h"


int main(int argc, char **argv) {

    if(argc == 3){
	   Jugador j = loadPlayer(argv[1]);
	    Bots *b = loadBots(argv[2]);
        muestraMenu();
        int option = getOption();
        while (option!=3){
            selectOption(option);
            muestraMenu();
            option = getOption();
        }
    }
    else{
        printf("Error con los argumentos del programa.\n");
    }

    printf("Has salido del programa\n");
    return 0;
}