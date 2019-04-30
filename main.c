#include <stdio.h>
#include "menu.h"

int main() {
    muestraMenu();
    int option = getOption();
    while (option!=3){
        selectOption(option);
        muestraMenu();
        option = getOption();
    }
    printf("Has salido del programa\n");
    return 0;
}