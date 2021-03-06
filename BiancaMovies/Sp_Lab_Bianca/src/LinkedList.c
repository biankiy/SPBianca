/*
 * LinkedList.c
 *
 *  Created on: 1 jul. 2022
 *      Author: bianky
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this= (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL){
        this->size=0;
        this->pFirstNode=NULL;
    }

    return this;
}

int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){
        returnAux= this->size;
    }

    return returnAux;
}

static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNodo = NULL;
    if(this!=NULL && nodeIndex>=0&&nodeIndex< ll_len(this))
    {
            pNodo= this->pFirstNode;
        while(nodeIndex>0){
            pNodo= pNodo->pNextNode;
            nodeIndex--;
        }

    }
    return pNodo;
}

Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodo=NULL;
    Node* pNodoAnterior=NULL;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
    {
        pNodo= (Node*) malloc(sizeof(Node));
        if(pNodo!=NULL){
            pNodo->pElement=pElement;
            if(nodeIndex==0){
                pNodo->pNextNode=this->pFirstNode;
                this->pFirstNode=pNodo;
            }else{
                pNodoAnterior=getNode(this,nodeIndex-1);
                pNodo->pNextNode=pNodoAnterior->pNextNode;
                pNodoAnterior->pNextNode=pNodo;
            }
            this->size++;
            returnAux=0;
        }
    }
    return returnAux;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


int ll_add(LinkedList* this, void* pElement)
{
    return addNode(this, ll_len(this), pElement);
}

void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    //Node* auxNode=NULL;
    if(this!=NULL && index >=0 && index < ll_len(this)){
        returnAux = getNode(this, index)->pElement;
    }

    return returnAux;
}

int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && index>=0 && index<ll_len(this)){

        getNode(this,index)->pElement = pElement;
        returnAux = 0;
    }

    return returnAux;
}


int ll_remove(LinkedList* this, int index){
    int returnAux=-1;
    Node* auxNode=NULL;
    Node* prevNode=NULL;

    if(this != NULL && index >=0 && index<ll_len(this)){
        auxNode=getNode(this, index);
        if(index==0){
            this->pFirstNode = auxNode->pNextNode;
        }else{
            prevNode=getNode(this, index-1);
            prevNode->pNextNode =auxNode->pNextNode;
        }

        free(auxNode);
        this->size --;
        returnAux=0;
   }
    return returnAux;


}

int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL){

        while(this->pFirstNode!=NULL){
            ll_remove(this,0);

        }
        returnAux=0;

    }

    return returnAux;
}

int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this !=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux=0;
    }
    return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tam;
    if(this != NULL){
            tam=ll_len(this);
            for(int i=0; i< tam; i++){
                if(ll_get(this,i)== pElement){
                    returnAux=i;
                    break;
                }
            }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this !=NULL){
        if(ll_len(this)){
            returnAux=0;
        }else{
            returnAux=1;
        }
    }

    return returnAux;
}

int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this, index, pElement);
}


void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this!=NULL && index>=0 && index<ll_len(this)){
        returnAux= ll_get(this, index);
        ll_remove(this, index);
    }

    return returnAux;
}

int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL){
        returnAux=0;
        if(ll_indexOf(this, pElement)!=-1){
            returnAux=1;
        }
    }
    return returnAux;
}

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int tam;

    if(this != NULL && this2 !=NULL){
        returnAux=1;
        tam=ll_len(this2);

        for(int i=0; i<tam;i++){
            if(!ll_contains(this, ll_get(this2,i))){
                returnAux=0;
                break;
            }
        }
    }
    return returnAux;
}

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL && from >=0 && from <ll_len(this) && to>from && to<=ll_len(this)){
        cloneArray=ll_newLinkedList();
        if(cloneArray!=NULL){
            for(int i=from; i<to ;i++){
                ll_add(cloneArray,ll_get(this,i));
            }
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{

    return ll_subList(this, 0, ll_len(this));
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int tam;
    void* auxI=NULL;
    void* auxJ=NULL;
    void* aux=NULL;

    if(this!=NULL &&pFunc!=NULL && order >=0 && order<=1){
        tam=ll_len(this);
        for(int i=0; i<tam-1 ;i++){
            for(int j=i+1; j<tam;j++){
                    auxI=ll_get(this,i);
                    auxJ=ll_get(this,j);
                if((pFunc(auxI, auxJ)>0 &&order)||
                    (pFunc(auxI, auxJ)<0 && !order)){
                    aux=auxI;
                    ll_set(this,i,auxJ);
                    ll_set(this,j,aux);
                }
            }
        }
        returnAux=0;
    }
    return returnAux;
}
/** \brief Devuelve un nuevo LinkedList cargado con los elementos que pasan la funcion filtro
 *
 * \param LinkedList* this a filtrar
/ * \param int (*pFunc) (void*) puntero a la funcion que filtra
 * \return nuevo puntero a LinkedList con los elementos que pasa la funcion
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc) (void*))
{

    int largo;
    void* aux=NULL;
    LinkedList* nuevaLista= NULL;

    if(this !=NULL && pFunc!=NULL)
    {
        nuevaLista= ll_newLinkedList();
        if(nuevaLista!=NULL)
        {
            largo=ll_len(this);

            for(int i=0; i<largo; i++)
            {
                aux= ll_get(this,i);
                if(pFunc(aux))
                {
                    if(ll_add(nuevaLista, aux))   // si falla el add
                    {
                        ll_deleteLinkedList(nuevaLista);
                        nuevaLista=NULL;
                        break;
                    }
                }
            }
            aux=NULL; // por que??
        }
    }
    return nuevaLista;
}

LinkedList* ll_map(LinkedList* this, void*(*pFunc) (void* element))
{
    int len;
    void* auxElement=NULL;

    if(this!=NULL && pFunc!=NULL)
    {
        len=ll_len(this);


        for(int i=0; i<len; i++)
        {
            auxElement=ll_get(this, i);
            auxElement=pFunc(auxElement);
            ll_set(this, i, auxElement);
        }
    }
    return this;
}

