#include "jugador.h"

Jugador JUGADOR_crea() {
    Jugador j;
    j.nombre = "";
    j.cartas = LISTACARTA_crea();
    j.partidas_ganadas = 0;
    j.partidas_perdidas = 0;
    j.num_partidas = 0;
    return j;
}
void JUGADOR_insertaNombre(Jugador *j, char *nombre) {
    (*j).nombre = nombre;
}

void JUGADOR_insertaPartidasGanadas(Jugador *j, int partidasGanadas) {
    j->partidas_ganadas = partidasGanadas;
}

void JUGADOR_insertaPartidasPerdidas(Jugador *j, int partidasPerdidas) {
    j->partidas_perdidas = partidasPerdidas;
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

void JUGADOR_insertaCartasPartida(Jugador *j, int cartas){
    j->cartas_partida_i = (int *) malloc(sizeof(int) * j->num_partidas+1);
    j->cartas_partida_i[j->num_partidas] = cartas;

}
int JUGADOR_consultaCartasPartida(Jugador j, int partida){
    return j.cartas_partida_i[partida];
}
int JUGADOR_consultaNumPartidas(Jugador j){
    return j.num_partidas;
}

void JUGADOR_insertaNumPartidas(Jugador *j, int n_partidas){
    j->num_partidas = n_partidas;
}