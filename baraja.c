//
// Created by Alex on 30/04/2019.
//
#include "menu.h"
#include "baraja.h"

#define NUM_VALOR_MAX 15

int crearBaraja(BarajaPtr_t *baraja) {
    *baraja = malloc(sizeof (struct BarajaStruct_t));
    if (*baraja == NULL) return 1;

    (*baraja)->n_cartas = 2*54; //Generamos 2 barajas de 54 cartas cada una
    printf("Generando pila con %i barajas (%i cartas)... \n",
           (*baraja)->n_cartas/54, (*baraja)->n_cartas);
    (*baraja)->cartas = malloc(sizeof(int) * (*baraja)->n_cartas);
    if ((*baraja)->cartas == NULL) return 1;
    int i;
    for (i = 0; i < (*baraja)->n_cartas; i++) {
        (*baraja)->cartas[i] = i%(NUM_VALOR_MAX) +1;
    }
    printf("Baraja generada con éxito\n\n");
    return 0;
}
void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void barajar(BarajaPtr_t *baraja) {
    srand(time(NULL));
    for (int i = (*baraja)->n_cartas - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&(*baraja)->cartas[i], &(*baraja)->cartas[j]);
    }
}