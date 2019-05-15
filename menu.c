//
// Created by Alex on 30/04/2019.
//
#include <memory.h>
#include "menu.h"
#include "juego.h"
#include "jugador.h"

#define JUGAR            1
#define ESTADISTICAS     2

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
            juego();
            break;
        case ESTADISTICAS:

            break;
        default:
            printf("Opcion erronea, seleccione otra\n");
            break;
    }
}
void loadFiles(char *fileUser, char *fileBots){
    printf("%s",fileUser);
    //Load player and save it in memory
    FILE *f;
    f = fopen("fichero_usuario.uno", "r");

    if (f == NULL) {
        printf("\nError en obrir fitxer...\n");
    } else {
    	Jugador *j;
    	*j = JUGADOR_crea();
	    char *nombre = malloc(sizeof(char) * 1024);

	    fgets(nombre, 25, f);
	    strtok(nombre, "\n");
	    JUGADOR_insertaNombre(j, nombre);

	    printf("%s\n", JUGADOR_consultaNombre(*j));

	    int manos_ganadas, manos_perdidas, manos_empatadas;

	    fscanf(f, "%d", &manos_ganadas);
	    JUGADOR_insertaManosGanadas(j, manos_ganadas);
	    printf("%d\n", JUGADOR_consultaManosGanadas(*j));

	    fscanf(f, "%d", &manos_perdidas);
	    JUGADOR_insertaManosPerdidas(j, manos_perdidas);
	    printf("%d\n", JUGADOR_consultaManosPerdidas(*j));

	    fscanf(f, "%d", &manos_empatadas);
	    JUGADOR_insertaManosEmpatadas(j, manos_empatadas);
	    printf("%d\n", JUGADOR_consultaManosEmpatadas(*j));

    }
}