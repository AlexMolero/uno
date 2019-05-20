#include "jugador.h"

Jugador JUGADOR_crea() {
    Jugador j;
    j.nombre = "";
    j.cartas = LISTACARTA_crea();
    j.cartas = LISTACARTA_vesInicio(j.cartas);
    j.partidas_ganadas = 0;
    j.partidas_perdidas = 0;
    j.partidas_empatadas = 0;
    return j;
}
void JUGADOR_insertaNombre(Jugador *j, char *nombre) {
    (*j).nombre = nombre;
}


void JUGADOR_insertaPartidasGanadas(Jugador j, int partidasGanadas) {
    (j).partidas_ganadas = partidasGanadas;
}

void JUGADOR_insertaPartidasPerdidas(Jugador j, int partidasPerdidas) {
    (j).partidas_perdidas = partidasPerdidas;
}


char * JUGADOR_consultaNombre(Jugador j) {
    return j.nombre;
}

int JUGADOR_consultaPartidasGanadas(Jugador j) {
    return j.partidas_ganadas;
}

int JUGADOR_consultaPartidasPerdidas(Jugador j) {
    return j.partidas_perdidas;
}

int JUGADOR_insertaCartasPartida(Jugador *j, int cartas){

}
int JUGADOR_consultaCartasPartida(Jugador j, int cartas){

}
/*void JUGADOR_elimina(Jugador j) {
    free(j);
}*/