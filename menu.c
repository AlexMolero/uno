//
// Created by Alex on 30/04/2019.
//
#include "menu.h"
#define JUGAR  1
#define ESTADISTICAS     2
#define SALIR  3
void muestraMenu(){
    printf("*********MENU PRINCIPAL*********\n");
    printf("1- Jugar\n");
    printf("2- Mostrar estadísticas\n");
    printf("3- Salir\n");
}

int getOption(){
    int option;
    printf("Selecciona una opcion: \n");
    scanf("%d",&option);
    return option;
}

void selectOption(int option){

    switch (option) {
        case JUGAR:

            break;
        case ESTADISTICAS:

            break;
        default:
            printf("Opcion erronea, seleccione otra\n");
            break;
    }
}