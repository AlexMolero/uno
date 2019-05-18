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
Jugador loadPlayer(char *fileUser){
    printf("%s",fileUser);
    //Load player and save it in memory
    FILE *f;
    f = fopen("fichero_usuario.uno", "r");

    if (f == NULL) {
        printf("\nError en obrir fitxer...\n");
    } else {
    	Jugador j = JUGADOR_crea();

	    char *nombre = malloc(sizeof(char) * 1024);
	    fgets(nombre, 25, f);
	    strtok(nombre, "\n");
	    JUGADOR_insertaNombre(&j, nombre);

	    printf("\n Hola %s\n", JUGADOR_consultaNombre(j));

	    int partidas_ganadas, partidas_perdidas;

	    fscanf(f, "%d", &partidas_ganadas);
	    JUGADOR_insertaPartidasGanadas(j, partidas_ganadas);
	    printf("%d\n", JUGADOR_consultaPartidasGanadas(j));

	    fscanf(f, "%d", &partidas_perdidas);
	    JUGADOR_insertaPartidasPerdidas(j, partidas_perdidas);
	    printf("%d\n", JUGADOR_consultaPartidasPerdidas(j));

	    int partidas =
			    JUGADOR_consultaPartidasGanadas(j) + JUGADOR_consultaPartidasPerdidas(j);
	    int res;

	    for (int i = 0; i < partidas; i++) {
		    fscanf(f, "%d", &res);
//		    JUGADOR_insertaCartasPartida(&j, res);
//		    printf("%d", JUGADOR_consultaCartasPartida(j, i));
	    }

	    fclose(f);
		return j;
    }
}