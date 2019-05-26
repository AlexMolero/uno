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
    f = fopen("fichero_usuarioTest.uno", "r+");

    if (f == NULL) {
        printf("\nError en obrir fitxer...\n");
    } else {

        fwrite(LISTAJUEGO_consultaNombre(LISTAJUEGO_consulta(*listaJuego)), sizeof(LISTAJUEGO_consultaNombre(LISTAJUEGO_consulta(*listaJuego))), 1, f);
        fwrite(LISTAJUEGO_consultaPartidasGanadas(LISTAJUEGO_consulta(*listaJuego)), sizeof(int), 1, f);
        fwrite(LISTAJUEGO_consultaPartidasPerdidas(LISTAJUEGO_consulta(*listaJuego)), sizeof(int), 1, f);


        fclose(f);
    }
}
void saveBots(ListaJuego *listaJuego, char *fileBots){
    printf("Guardando resultados de los bots en archivo %s \n", fileBots);

}