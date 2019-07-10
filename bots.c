#include "bots.h"

Bots BOTS_crea() {
    Bots b;
    b.nombre = "";
    b.caracter = ' ';
    b.carta_maxima = 0;
    b.cartas = LISTACARTA_crea();
    b.cartas = LISTACARTA_vesInicio(b.cartas);
    return b;
}

void BOTS_insertaNombre(Bots *b, char *nombre) {
    (*b).nombre = nombre;
}

void BOTS_insertaCaracter(Bots *b, char caracter) {
    (*b).caracter = caracter;
}

void BOTS_insertaCartaMax(Bots *b, int cartaMax) {
    (*b).carta_maxima = cartaMax;
}

void BOTS_insertaCartas(Bots *b, ListaCarta cartas) {
    (*b).cartas = cartas;
}

char *BOTS_consultaNombre(Bots b) {
    return b.nombre;
}
int BOTS_consultaNBots(Bots b){
    return b.n_bots;
}

char BOTS_consultaCaracter(Bots b) {
    return b.caracter;
}
char * BOTS_consultaNombreCaracter(Bots b) {
    if(b.caracter == 'a'){
        return "Agresivo";
    }
    else {
        return "Calmado";
    }
}

int BOTS_consultaCartaMax(Bots b) {
    return b.carta_maxima;
}
int BOTS_consultaPartidasGanadas(Bots b){
    return b.partidas_ganadas;
}
int BOTS_consultaPartidasPerdidas(Bots b){
    return b.partidas_ganadas;
}

ListaCarta BOTS_consultaCartas(Bots b) {
    return b.cartas;
}
