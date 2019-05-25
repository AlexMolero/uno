//
// Created by Alex on 30/04/2019.
//
#include <memory.h>
#include "menu.h"
#include "juego.h"
#include "jugador.h"
#include "bots.h"

#define JUGAR            1
#define ESTADISTICAS     2
#define VER_MANO         'A'
#define ROBAR_CARTA      'B'

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
char getGameOption(char name_player){
    char option;
    printf("%s , escoge una acción\n",&name_player);
    printf("A. Ver mano\n");
    printf("B. Robar carta\n");
    scanf(" %c", &option);

    return option;
}
void selectFirstAction(char option, ListaCarta *lista){
    switch (option) {
        case VER_MANO:

            break;
        case ROBAR_CARTA:

            break;
        default:
            printf("Opcion erronea, seleccione otra\n");
            break;
    }
}
void selectOption(int option, char **argv){
    Jugador j;
    Bots *b;
    switch (option) {
        case JUGAR:
            j = loadPlayer(argv[1]);
            b = loadBots(argv[2]);
            juego(j, b);
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
    FILE *f;
    f = fopen(fileUser, "r");

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
	    JUGADOR_insertaPartidasGanadas(&j, partidas_ganadas);
	    printf("%d\n", JUGADOR_consultaPartidasGanadas(j));

	    fscanf(f, "%d", &partidas_perdidas);
	    JUGADOR_insertaPartidasPerdidas(&j, partidas_perdidas);
	    printf("%d\n", JUGADOR_consultaPartidasPerdidas(j));

	    int partidas =
			    JUGADOR_consultaPartidasGanadas(j) + JUGADOR_consultaPartidasPerdidas(j);
	    int res;
	    for (int i = 0; i < partidas; i++) {
		    fscanf(f, "%d", &res);
            JUGADOR_insertaNumPartidas(&j, i);
		    JUGADOR_insertaCartasPartida(&j, res);
	    }

	    fclose(f);
		return j;
    }
}
Bots *loadBots(char *fileBot){
    printf("%s",fileBot);

    FILE *f;
    f = fopen(fileBot, "r");

    if (f == NULL) {
        printf("\nError en obrir fitxer...\n");
    }else {
        int numBots;
        fscanf(f, "%d", &numBots);
        Bots bots[numBots];
        printf("%d\n", numBots);

        char aux;
        fscanf(f, "%c", &aux);

        char *nombre = malloc(sizeof(char) * 1024);
        fgets(nombre, 25, f);
        strtok(nombre, "\n");
        BOTS_insertaNombre(&bots[0], nombre);
        printf("%s\n", BOTS_consultaNombre(bots[0]));

        int i = 0;
        while (!feof(f)) {
            char *caracter = malloc(sizeof(char) * 1024);
            char car;
            fscanf(f, "%s", caracter);
            if (strcmp(caracter, "Agresivo") == 0) {
                car = 'a';
            } else if (strcmp(caracter, "Calmado") == 0) {
                car = 'c';
            }
            BOTS_insertaCaracter(&bots[i], car);
            printf("%c\n", BOTS_consultaCaracter(bots[i]));

            int cartaMax;
            fscanf(f, "%d", &cartaMax);
            BOTS_insertaCartaMax(&bots[i], cartaMax);
            printf("%d\n", BOTS_consultaCartaMax(bots[i]));

            i++;

            fscanf(f, "%c", &aux);
            nombre = malloc(sizeof(char) * 1024);
            fgets(nombre, 25, f);
            strtok(nombre, "\n");
            BOTS_insertaNombre(&bots[i], nombre);
            printf("%s\n", BOTS_consultaNombre(bots[i]));
        }

        return bots;
    }
}
