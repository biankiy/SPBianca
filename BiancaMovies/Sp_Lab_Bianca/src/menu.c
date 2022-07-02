/*
 * menu.c
 *
 *  Created on: 1 jul. 2022
 *      Author: bianky
 */
#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "movie.h"
#include "menu.h"
#include "LinkedList.h"


int menu()
{
    int opcion;

    printf("--------------------------------\n ");
    printf("------   MENU OPCIONES   ------\n");
    printf("------------------------------\n");
    printf("[1]- CARGAR ARCHIVO \n");
    printf("[2]- IMPRIMIR LISTA \n");
    printf("[3]- ASIGNAR TIEMPO \n");
    printf("[4]- ASIGNAR GENERO \n");
    printf("[5]- FILTRAR POR TIPO \n");
    printf("[6]- MOSTRAR DURACION  \n");
    printf("[7]- GUARDAR PELICULAS \n");
    printf("[8]- Salir \n");
    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}



int menu_generoPeliculas()
{
    int opcion;

    printf("\n-----------------------------------");
    printf("\n--------    MENU GENERO    -------\n");
    printf("\n--------    MENU GENERO    -------\n");
    printf("[1]- TERROR \n");
    printf("[2]- ACCION \n");
    printf("[3]- ROMANCE \n");
    printf("[4]- COMEDIA \n");

    printf("\n ---> Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}



