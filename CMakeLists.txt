cmake_minimum_required(VERSION 3.13)
project(uno C)

set(CMAKE_C_STANDARD 99)

add_executable(uno main.c menu.c menu.h baraja.c baraja.h jugador.c jugador.h juego.c juego.h estadisticas.c estadisticas.h listaCarta.c listaCarta.h)