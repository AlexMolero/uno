//
// Created by Alex on 30/04/2019.
//
#include "juego.h"
#include "jugador.h"
#include "listaJuego.h"
#include "menu.h"

void estadisticas(ListaJuego *lista_jugadores, char **argv){
    muestraMenuEstadisticas();
    int option = getOption();
    while (option!=3){
        selectOptionEstadisticas(option, argv, lista_jugadores);
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
void estadisticas_bots(ListaJuego *lista_jugadores, char **argv){
    //int numBots;
    //Bots *b = loadBots(argv[2], &numBots);
    printf("\nUNO - Estadísticas de Bots\n");
    printf("%-25s \t %-3s \t %-3s \n", "Nombre", "P.Ganadas", "P.Perdidas");
    LISTAJUEGO_vesInicio(lista_jugadores);
    while(!LISTAJUEGO_final(*lista_jugadores)){
        if(LISTAJUEGO_consultaTipo(LISTAJUEGO_consulta(*lista_jugadores))){
            printf("%-25s \t %-3d \t %-3d \n", LISTAJUEGO_consultaNombre(LISTAJUEGO_consulta(*lista_jugadores)), LISTAJUEGO_consultaPartidasGanadas(LISTAJUEGO_consulta(*lista_jugadores)), LISTAJUEGO_consultaPartidasPerdidas(LISTAJUEGO_consulta(*lista_jugadores)));
        }
        LISTAJUEGO_avanza(lista_jugadores);
    }
    printf("------------------------------------\n");

}