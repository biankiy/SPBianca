#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

typedef struct{

    int id;
    char titulo[50];
    char genero[20];
    int duracion;

}eMovie;

#endif // MOVIE_H_INCLUDED

eMovie* movie_new();
void movie_delete(eMovie* pMovie);
int movie_setId(eMovie* p,int id);
int movie_getId(eMovie* p,int* id);
int movie_setTitulo(eMovie* p, char* titulo);
int movie_getTitulo(eMovie* p,char* titulo);
int movie_setGenero(eMovie* p,char* genero);
int movie_getGenero(eMovie* p,char* genero);
int movie_setDuracion(eMovie* p,int duracion);
int movie_getDuracion(eMovie* p, int* duracion);

