/*
 ============================================================================
 Name        : Sp_Lab_Bianca.c
 Author      : Bianca
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "movie.h"
#include "menu.h"
#include "LinkedList.h"


int main()
{
	setbuf(stdout, NULL);

    LinkedList* lista= ll_newLinkedList();
    LinkedList* listaFiltrada=NULL;


    char path[50];
    int flagCarga=0;
    char confirma='n';
    int opcion=0;

    do{

    switch(menu(opcion)){
        case 1:
            printf("---> Ingrese el nombre del archivo[movies.csv]: ");
            fflush(stdin);
            gets(path);
            if(!controller_loadFromText(path, lista)){
                flagCarga=1;
            }
        break;

        case 2:
            if(!flagCarga){
                printf(" [!!! Primero debe cargar un archivo !!!! ]\n");
            }else{
                controller_listMovies(lista);
            }

        break;

        case 3:
            if(!flagCarga){
            	 printf(" [!!! Primero debe cargar un archivo !!!! ]\n");
            }else{
                controller_asignarTiempo(lista);
            }

        break;

        case 4:
            if(!flagCarga){
            	 printf(" [!!! Primero debe cargar un archivo !!!! ]\n");
            }else{
                controller_asignarGeneros(lista);
            }

        break;

        case 5:
            if(!flagCarga){
            	 printf(" [!!! Primero debe cargar un archivo !!!! ]\n");
            }else{
                switch(menu_generoPeliculas()){
                    case 1:
                        listaFiltrada=ll_filter(lista, controller_filterTerror);
                        controller_listMovies(listaFiltrada);
                        break;
                    case 2:
                        listaFiltrada=ll_filter(lista,controller_filterAccion);
                        controller_listMovies(listaFiltrada);
                        break;
                    case 3:
                        listaFiltrada=ll_filter(lista,controller_filterRomance);
                         controller_listMovies(listaFiltrada);
                        break;
                    case 4:
                        listaFiltrada=ll_filter(lista,controller_filterComedia);
                         controller_listMovies(listaFiltrada);
                        break;
                    default:
                        printf("ERROR , Ingrese una opcion Valida!! \n");
                        break;
                    }
            }
        break;

        case 6:
            if(!flagCarga){
            	 printf(" [!!! Primero debe cargar un archivo !!!! ]\n");
            }else{
            	 controller_listDuraciones(lista);

            }

        break;

        case 7:
            if(!flagCarga){
            	 printf(" [!!! Primero debe cargar un archivo !!!! ]\n");
            }else{
                printf("Ingrese el nombre del archivo donde se gardara la lista de peliculas: ");
                fflush(stdin);
                gets(path);
                if(!controller_saveAsText(path, lista)){
                    printf("TODO OK , se pudo guardar el archivo.\n");
                }else{
                    printf("OOPS !! Ocurrio un error al cargar el archivo !!!!. \n");
                }
            }

        break;

        case 8:
            printf(" ---- Confirma salida? [s/n] \n");
            fflush(stdin);
            scanf("%c", &confirma);
            if(ll_len(lista)){
                 ll_deleteLinkedList(lista);
            }
            if(ll_len(listaFiltrada)){
                ll_deleteLinkedList(listaFiltrada);
            }

        break;

        default:
            printf("ERROR!!! --- OPCION INVALIDA ---\n");
            break;

    }
        system("pause");

    }while(confirma!='s');
}
