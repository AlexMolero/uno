//
// Created by Alex on 30/04/2019.
//
#include "juego.h"
#include "jugador.h"
#include "listaJuego.h"
#include "menu.h"

void estadisticas(char **argv){
    muestraMenuEstadisticas();
    int option = getOption();
    while (option!=3){
        selectOptionEstadisticas(option, argv);
        muestraMenuEstadisticas();
        option = getOption();
    }
}
void estadisticas_jugador(char **argv){
    Jugador j = loadPlayer(argv[1]);
    printf("\nUNO - Estadísticas del jugador\n");
    printf("Nombre: %s\n", JUGADOR_consultaNombre(j));
    printf("Estadisticas de partidas: \n");
    int partidas = JUGADOR_consultaPartidasGanadas(j) + JUGADOR_consultaPartidasPerdidas(j);

    printf("\t Ganadas:  ... \t %d (%d%%)\n", JUGADOR_consultaPartidasGanadas(j), (JUGADOR_consultaPartidasGanadas(j)*100)/partidas);
    printf("\t Perdidas:  ... \t %d (%d%%)\n", JUGADOR_consultaPartidasPerdidas(j), (JUGADOR_consultaPartidasPerdidas(j)*100)/partidas);
//presiona enter para volver al menú principal
}
void estadisticas_bots(char **argv){
    int numBots;
    Bots *b = loadBots(argv[2], &numBots);
    printf("\nUNO - Estadísticas de Bots\n");
    printf("Nombre \t P.Ganadas \t P.Perdidas\n");
    for (int i = 0; i < numBots ; ++i) {
        printf("%s \t P.Ganadas \t P.Perdidas\n", BOTS_consultaNombre(b[i]));
    }
    printf("------------------------------------\n");


}