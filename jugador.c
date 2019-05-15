#include "jugador.h"

Jugador JUGADOR_crea() {
    Jugador j;
    j.cartas = LISTACARTA_crea();

    return j;
}
void JUGADOR_insertaNombre(Jugador *j, char *nombre) {
    (*j).nombre = nombre;
}

//void JUGADOR_insertaFichas(Jugador *j, int fichas) {
//    (*j).fichas = fichas;
//    printf("\n te quedan: %d\n",fichas);
//}

void JUGADOR_insertaManosGanadas(Jugador *j, int partidasGanadas) {
    (*j).partidas_ganadas = partidasGanadas;
}

void JUGADOR_insertaManosPerdidas(Jugador *j, int partidasPerdidas) {
    (*j).partidas_perdidas = partidasPerdidas;
}

void JUGADOR_insertaManosEmpatadas(Jugador *j, int partidasEmpatadas) {
    (*j).partidas_empatadas = partidasEmpatadas;
}

char * JUGADOR_consultaNombre(Jugador j) {
    return j.nombre;
}

int JUGADOR_consultaManosGanadas(Jugador j) {
    return j.partidas_ganadas;
}

int JUGADOR_consultaManosPerdidas(Jugador j) {
    return j.partidas_perdidas;
}

int JUGADOR_consultaManosEmpatadas(Jugador j) {
    return j.partidas_empatadas;
}

/*void JUGADOR_elimina(Jugador j) {
    free(j);
}*/