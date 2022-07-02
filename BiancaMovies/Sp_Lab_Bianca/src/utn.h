/*
 * utn.h
 *
 *  Created on: 1 jul. 2022
 *      Author: bianky
 */

#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */

int utn_pedirNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);
int utn_pedirfloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_pedirChar(char* mensaje, char* mensajeError, char* pResultado,int reintentos);
int utn_pedirNombre(char* pResultado, int longitud, char* mensaje,char* mensajeError, int reintentos);
int utn_pedirAlfaNumerico(char* pResultado, int longitud, char* mensaje, char* mensajeError);

int utn_getCuit(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
void getString(char cadena[],char mensaje[],int tam);
