/*
 * controller.c
 *
 *  Created on: 1 jul. 2022
 *      Author: bianky
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "movie.h"
#include "menu.h"
#include "parser.h"
#include "controller.h"
#include <time.h>


int controller_loadFromText(char* path, LinkedList* lista){

    int retorno =-1;
    FILE* f=fopen(path, "r");
    char confirma='n';

    if(f==NULL){
        printf("ERROR ! El path ingresado no existe\n");
        printf(">> Oops !!Ocurrio un error >>\n");
        retorno =-1;
    }else{
        if(ll_len(lista)){
            printf(">> Los datos cargados actualmente se van a sobreescribir. Confirma? [s/n] \n");
            fflush(stdin);
            scanf("%c", &confirma);
        }


        if(confirma =='s' || !ll_len(lista)){
            ll_clear(lista);
            if(!(parser_movieFromText(f, lista))){
                fclose(f);
                retorno =0;
            }else {
                printf("ERROR! Ocurrio un error al cargar las peliculas\n");
                retorno =-1;
            }
        }
    }
    return retorno ;
}
int controller_listDuraciones(LinkedList* lista){

	int retorno = -1;
    eMovie* aux = movie_new();
    int tam= ll_len(lista);


    if(lista!=NULL){

    	printf("\n\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
        printf("\n<><><><><><><><><><><><>     LISTA DE PELICULAS      <><><><><><><><><><><><><>\n");
        printf("-------------------------------------------------------------------------------\n");

        printf("  ID                   NOMBRE          DURACION          \n");
        printf("----------------------------------------------------------------------------\n\n");

        for(int i=0; i<tam; i++){

            aux= (eMovie*) ll_get(lista,i);
            controller_listDuracion(aux);
        }
        retorno =0;
    }

    return retorno ;
}
void controller_listDuracion(eMovie* aux){

    printf("%3d %30s  %d\n", aux->id, aux->titulo, aux->duracion);
}



int controller_listMovies(LinkedList* lista){

	int retorno = -1;
    eMovie* aux = movie_new();
    int tam= ll_len(lista);


    if(lista!=NULL){

    	printf("\n\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
        printf("\n<><><><><><><><><><><><>     LISTA DE PELICULAS      <><><><><><><><><><><><><>\n");
        printf("-------------------------------------------------------------------------------\n");

        printf("  ID                   NOMBRE                GENERO       DURACION          \n");
        printf("----------------------------------------------------------------------------\n\n");

        for(int i=0; i<tam; i++){

            aux= (eMovie*) ll_get(lista,i);
            controller_listMovie(aux);
        }
        retorno =0;
    }

    return retorno ;
}


void controller_listMovie(eMovie* aux){

    printf("%3d %30s %20s   %d\n", aux->id, aux->titulo, aux->genero, aux->duracion);
}

int controller_saveAsText(char* path, LinkedList* lista)
{
    FILE* punteroArchivo;
    punteroArchivo= fopen(path, "w");
    eMovie* aux;

    int tam;
    int retorno=-1;
    char auxString[100];
    int auxInt;
    int auxIntD;


    if(lista!=NULL && punteroArchivo!=NULL)
    {
        tam= ll_len(lista);
        fprintf(punteroArchivo,"id,titulo,genero,duracion\n");

        for(int i=0; i< tam; i++)
        {
            aux= (eMovie*) ll_get(lista,i);

            movie_getId(aux, &auxInt);
            fprintf(punteroArchivo, "%d,", auxInt);

            movie_getTitulo(aux, auxString);
            fprintf(punteroArchivo, "%s,", auxString);

            movie_getGenero(aux, auxString);
            fprintf(punteroArchivo, "%s,", auxString);

            movie_getDuracion(aux, &auxIntD);
            fprintf(punteroArchivo, "%d,", auxIntD);
        }

        fclose(punteroArchivo);
        retorno=0;
    }
    return retorno;
}

int controller_asignarTiempo(LinkedList* lista)
{
    int error=-1;

    if(lista!=NULL)
    {
        if(ll_map(lista, controller_generarDuracion)!=NULL)
        {
            printf("\n--- Duracion asignados con exitos!!! ---\n");
        }
        error=0;
    }

    return error;
}


int controller_asignarGeneros(LinkedList* lista)
{
    int error=-1;

    if(lista!=NULL)
    {
        if(ll_map(lista, controller_generarGenero)!=NULL)
        {
            printf("\n--- Generos asignados con exito!! ---.\n");
        }
        error=0;
    }

    return error;
}



void* controller_generarDuracion(void* pelicula)
{
    eMovie* auxPelicula=(eMovie*) pelicula;
    int tiempo;
    int min=100;
    int max=240;

    if(pelicula!=NULL)
    {
        tiempo = rand () % (min-max+1) + max;
        movie_setDuracion(auxPelicula, tiempo);
    }

    return (void*)auxPelicula;
}



void* controller_generarGenero(void* pelicula)
{
    eMovie* auxPelicula=NULL;
    int numGenero;
    int min=1;
    int max=4;

    if(pelicula!=NULL)
    {
        auxPelicula= (eMovie*) pelicula;
        numGenero=rand()%(max-min+1)+min;


        if(numGenero==1)
        {
            movie_setGenero(auxPelicula, "ROMANCE");
        }
        else if(numGenero==2)
        {
            movie_setGenero(auxPelicula, "COMEDIA");
        }
        else if(numGenero==3)
        {
            movie_setGenero(auxPelicula, "ACCION");
        }
        else if(numGenero==4)
        {
            movie_setGenero(auxPelicula, "TERROR");
        }
    }

    return (void*)auxPelicula;
}



int controller_filterRomance(void* aux)
{
    int retorno;
    eMovie* pMovie=NULL;

    if(aux !=NULL)
    {
        pMovie= (eMovie*) aux;
        if(stricmp(pMovie->genero, "romance")==0)
        {
            retorno=1;
        }
        else
        {
            retorno=0;
        }

    }
    return retorno;
}



int controller_filterTerror(void* aux)
{
    int retorno;
    eMovie* pMovie=NULL;

    if(aux !=NULL)
    {
        pMovie= (eMovie*) aux;
        if(stricmp(pMovie->genero, "terror")==0)
        {
            retorno=1;
        }
        else
        {
            retorno=0;
        }

    }
    return retorno;
}



int controller_filterAccion(void* aux)
{
    int retorno;
    eMovie* pMovie=NULL;

    if(aux !=NULL)
    {
        pMovie= (eMovie*) aux;
        if(stricmp(pMovie->genero, "accion")==0)
        {
            retorno=1;
        }
        else
        {
            retorno=0;
        }

    }
    return retorno;
}



int controller_filterComedia(void* aux)
{
    int retorno;
    eMovie* pMovie=NULL;

    if(aux !=NULL)
    {
        pMovie= (eMovie*) aux;
        if(stricmp(pMovie->genero, "comedia")==0)
        {
            retorno=1;
        }
        else
        {
            retorno=0;
        }

    }
    return retorno;
}


int controller_sortGeneroDuracion(void* auxI, void* auxJ)
{
    int retorno=0;
    eMovie* pAuxI=NULL;
    eMovie* pAuxJ=NULL;

    if(auxI!= NULL && auxJ!=NULL)
    {
        pAuxI= (eMovie*) auxI;
        pAuxJ= (eMovie*) auxJ;
        if(stricmp(pAuxI->genero, pAuxJ->genero)<0)
        {
            retorno=1;
        }
        else if((stricmp(pAuxI->genero, pAuxJ->genero)==0) && pAuxI->duracion<pAuxJ->duracion)
        {
            retorno=1;
        }
    }

    return retorno;
}

