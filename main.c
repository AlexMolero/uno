#include <stdio.h>
#include "menu.h"
#include "juego.h"


int main(int argc, char **argv) {
    setbuf(stdout,0);
    if(argc == 3){
        muestraMenu();
        int option = getOption();
        while (option!=3){
            selectOption(option, argv);
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