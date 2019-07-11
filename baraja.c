//
// Created by Alex on 30/04/2019.
//
#include "menu.h"
#include "baraja.h"

#define COLORES 4
#define NUM_MAX_CARTA 13

Deck crear_baraja() {
    /*
     * Valor 10 y color -->Saltar turno
     * Valor 11 y color -->Cambiar dirección
     * Valor 12 y color -->Suma dos
     * Valor 13         -->Comodín color
     * Valor 14         -->Sumar 4 mas color
     */
    Deck p;
    p = NULL;
    int cont = 0;
    int j = 0;
    for(int b=0;b<2;b++){
        for(int i=0;i<COLORES;i++){
            // 0=Rojo, 1=Amarillo, 2=Verde, 3=Azul y 4 = Comodin
            for (int j = 0; j < NUM_MAX_CARTA; j++) {
                if(b==1 && j==0){
                    //Aqui entra cuando es el 0 en la segunda baraja
                }else{
                    cont++;
                    baraja_push(&p, j, i, cont);
                }
            }
        }
    }
    //Insertamos los comodines
    int value_comodin = NUM_MAX_CARTA;
    for(int i=0;i<8;i++){
        if(i>=4){
            baraja_push(&p, value_comodin+1, COLORES, cont);
        }else{
            baraja_push(&p, value_comodin, COLORES, cont);
        }
        cont++;
    }
    return p;
}
void baraja_push(Deck *p, int elemento, int color, int cont) {
    Nodo *aux;
    aux = (Nodo*)malloc(sizeof(Nodo));
    if (aux == NULL){
        printf("\nError al hacer push...\n");
    }else{
        aux->cont = cont;
        aux->valor = elemento;
        aux->color = color;
        aux->sig = *p;
        *p = aux;
    }
}
void baraja_pop(Deck *p) {
    Nodo *aux;
    if (*p == NULL) {
        printf("\nError al hacer pop, la pila està vacía.\n");
    } else {
        aux = *p;
        *p = (*p)->sig;
        free(aux);
    }
}
void swap(Deck *a, Deck *b) {
    Deck temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void barajar(Deck *p) {
    printf("Valor: %d",(*p)->valor);
    printf("   Color: %d \n",(*p)->color);
    Deck *aux;
    aux = (Nodo*)malloc(sizeof(Nodo));
    aux = (*p)->sig;
    int j = 0;
     for (int i = 51; i > 0; i--) {
         j = rand() % (i + 1);

         swap((*p)->sig, (*p)->sig);
     }
}
void baraja_next(Deck *p){
    if(p != NULL) {
        (*p) = (*p)->sig;
    }else{
        printf("Esta en el final de la baraja \n");
    }

}
Nodo baraja_top(Deck p){
    Nodo aux;
    if (p==NULL) {
        printf("\nError al hacer top, la pila está vacía.\n");
    } else {
        aux.valor = p->valor;
        aux.color = p->color;
    }
    return aux;
}
int es_roba_4(Nodo carta){
    if(carta.valor==14 && carta.color==4){
        return 1;
    } else{
        return 0;
    }
}
int es_comodin_color(Nodo carta){
    if(carta.valor==13 && carta.color==4){
        return 1;
    }else{
        return 0;
    }
}
int es_suma_2(Nodo carta){
    if(carta.valor==12){
        return 1;
    }else{
        return 0;
    }
}
int es_cambio_direccion(Nodo carta){
    if(carta.valor==11){
        return 1;
    }else{
        return 0;
    }
}
int es_saltar_turno(Nodo carta){
    if(carta.valor==10){
        return 1;
    }else{
        return 0;
    }
}

