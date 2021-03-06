/*
 * controller.h
 *
 *  Created on: 1 jul. 2022
 *      Author: bianky
 */

#include "movie.h"
#include "LinkedList.h"

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

/** \brief lista la duracion de varias peliculas
 *  \param LinkedList* lista
 *  \return int 0 sin errores 1 con errores]
*/
int controller_listDuraciones(LinkedList* lista);
/** \brief Lista la duracion de una pelicula
 * \ param eMovie* elemento
 */
void controller_listDuracion(eMovie* aux);
/** \brief Lista una pelicula
 * \ param eMovie* elemento
 */
void controller_listMovie(eMovie* aux);

/** \brief lista peliculas
 *  \param LinkedList* lista
 *  \return int error 0 [sin erroreS], 1[con error]
*/
int controller_listMovies(LinkedList* lista);

/** \brief Genera un numero random entre 100 y 240
 * \param puntero a void
 * \return puntero a void pasandole la duracion
 */
void* controller_generarDuracion(void* aux);
/** \brief Genera un numero random entre 100 y 240 y se lo asigna a genero setteandolo.
 * \param puntero a void
 * \return puntero a void pasa la duracion
 */
void* controller_generarGenero(void* aux);

/** \brief llama a ll_map y le pasa un puntero a funcion
 * \param linkedList* lista
 * \return 0 sin errores  -1 con error
 */
int controller_asignarTiempo(LinkedList* lista);

/** \brief llama a ll_map y le pasa un puntero a funcion
 * \param linkedList* lista
 * \return 0 sin errores || -1 con error
 */
int controller_asignarGeneros(LinkedList* lista);


/** \brief funcion que filtra lista segun genero elegido por el usuario
 * \param puntero a void
 * \return 1 o 0 segun corresponda a la listado o no
 */
int controller_filterComedia(void* aux);
/** \brief funcion que filtra lista segun genero elegido por el usuario
 * \param puntero a void
 * \return 1 o 0 segun corresponda a la listao o no
 */
int controller_filterTerror(void* aux);
/** \brief funcion que filtra lista segun genero elegido por el usuario
 * \param puntero a void
 * \return 1 o 0 segun corresponda a la listao o no
 */
int controller_filterAccion(void* aux);
/** \brief funcion que filtra lista segun genero elegido por el usuario
 * \param puntero a void
 * \return 1 o 0 segun corresponda a la listao o no
 */
int controller_filterRomance(void* aux);

/** \brief Funcion para ordenamiento segun genero y duracion descendente
 * \param  dos punteros a void para realizar la comparacion
 * \return 1 o 0 segun corresponda
 */
int controller_sortGeneroDuracion(void* auxI, void* auxJ);

/** \brief Carga los datos de las peliculas desde el archivo csv (modo texto).
 * \param char* path
 * \param LinkedList* lista
 * \return int error 0sin error  1con errores
 */

int controller_loadFromText(char* path, LinkedList* lista);
/** \brief Guarda los datos de las peliculas en un archivo csv (modo texto).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int error 0sin error  1con errores
 */
int controller_saveAsText(char* path, LinkedList* lista);
