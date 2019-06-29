//
// Created by root on 5/25/19.
//

#include "final.h"

void salir(ListaJuego *lista_jugadores, char **argv){
    int numPlayers = LISTAJUEGO_count(*lista_jugadores);
    printf("num players %d\n", numPlayers);

    //save Jugador
    savePlayer(lista_jugadores, argv[1]);
    saveBots(lista_jugadores, argv[2]);
    //save bots
}
void savePlayer(ListaJuego *listaJuego, char *filePlayer){
    printf("Guardando resultados del jugador en archivo %s \n", filePlayer);
    FILE *f;
    f = fopen(filePlayer, "r+");

    if (f == NULL) {
        printf("\nError en obrir fitxer...\n");
    } else {
        LISTAJUEGO_vesInicio(listaJuego);
        char *nombre = LISTAJUEGO_consultaNombre(LISTAJUEGO_consulta(*listaJuego));

        int winP = LISTAJUEGO_consultaPartidasGanadas(LISTAJUEGO_consulta(*listaJuego));
        winP = winP + 1;
        char *winPs; sprintf(winPs,"%d", winP);

        int losP = LISTAJUEGO_consultaPartidasPerdidas(LISTAJUEGO_consulta(*listaJuego));
        char *losPs; sprintf(winPs,"%d", losP);
        int p = winP + losP;

        fwrite(nombre, sizeof(nombre), 1, f);
        fwrite(LISTAJUEGO_consultaNombre(LISTAJUEGO_consulta(*listaJuego)), sizeof(LISTAJUEGO_consultaNombre(LISTAJUEGO_consulta(*listaJuego))), 1, f);
        fwrite(&winPs, sizeof(winPs), 1, f);
        fwrite(&losPs, sizeof(losPs), 1, f);

        int partida_i = 0;
        char partida_is[2];
        for (int i = 0; i < p; ++i) {
            partida_i =  LISTAJUEGO_consultaCartasPartida(LISTAJUEGO_consulta(*listaJuego),i);
            sprintf(partida_is,"%d", partida_i);
            fwrite(partida_is, sizeof(partida_is), 1, f);
        }

        fclose(f);
    }
}
void saveBots(ListaJuego *listaJuego, char *fileBots){
    printf("Guardando resultados de los bots en archivo %s \n", fileBots);
    FILE *f;
    f = fopen(fileBots, "r+");
    if (f == NULL) {
        printf("\nError en obrir fitxer...\n");
    } else {
        int nbots = LISTAJUEGO_consultaNBots(LISTAJUEGO_consulta(*listaJuego));
        char *nbotss;
        sprintf(nbotss,"%d", nbots);
        fwrite(&nbotss, sizeof(nbotss), 1, f);
        LISTAJUEGO_vesInicio(listaJuego);
        char *nombre;
        char *caracter;
        int cartas = 0;
        char *cartass;
        while(!LISTAJUEGO_final(*listaJuego)){
            if(LISTAJUEGO_consultaTipo(LISTAJUEGO_consulta(*listaJuego))){
                nombre = LISTAJUEGO_consultaNombre(LISTAJUEGO_consulta(*listaJuego));
                fwrite(&nombre, sizeof(nombre), 1, f);
                caracter = LISTAJUEGO_consultaCaracter(LISTAJUEGO_consulta(*listaJuego));
                fwrite(&caracter, sizeof(caracter), 1, f);
                cartas = LISTAJUEGO_consultaCartas(LISTAJUEGO_consulta(*listaJuego));
                sprintf(cartass,"%d", cartas);
                fwrite(&cartass, sizeof(cartass), 1, f);
            }
            LISTAJUEGO_avanza(listaJuego);
        }

    }
}