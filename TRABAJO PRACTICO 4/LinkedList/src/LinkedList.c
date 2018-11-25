#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this =(LinkedList*)malloc(sizeof (LinkedList));
    if(this != NULL ){

        this->size=0;
        this->pFirstNode=NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux=-1;

    if(this != NULL ){
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o
                    (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this  , int nodeIndex)
{
        int i;
        Node* pNode = NULL;

    if ( this  !=NULL  && nodeIndex >= 0 && nodeIndex<ll_len(this) )
    {

        pNode=this->pFirstNode;

        for(i=0; i<nodeIndex; i++)
        {
            pNode = pNode->pNextNode;
        }

    }

    return pNode;
}

    /*Node* pNode = NULL;
    int i;

    if(list != NULL && nodeIndex >= 0 && nodeIndex<ll_len(list)){

        if(nodeIndex == 0){
            pNode =list->pFirstNode;
        }
        if(nodeIndex > 0 ){
            for(i=0; i<ll_len(list); i++){
                if(i==0){
                    pNode= list->pFirstNode;
                }
                else{
                    pNode=pNode->pNextNode;
                }
            }
        }

     }
    return pNode;
}*/

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL
            o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* list, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nodeNuevo;
    Node* auxiliar;

    if(list != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(list)){

        nodeNuevo =(Node*)malloc(sizeof (Node));

        if(nodeIndex == 0 && nodeNuevo!= NULL){
            nodeNuevo->pNextNode=list->pFirstNode;
            list->pFirstNode=nodeNuevo;
            list->size++;
            nodeNuevo->pElement=pElement;

        }
        if(nodeIndex > 0 && nodeIndex < (ll_len(list))&& nodeNuevo!= NULL ){
            nodeNuevo->pNextNode =getNode(list,(nodeIndex));
            auxiliar= getNode(list,(nodeIndex-1));
            auxiliar->pNextNode=nodeNuevo;
            list->size++;
            nodeNuevo->pElement=pElement;
        }
        if(nodeIndex == ll_len(list) && nodeNuevo!= NULL){
            auxiliar= getNode(list,(nodeIndex-1));
            auxiliar->pNextNode=nodeNuevo;
            nodeNuevo->pNextNode=NULL;
            list->size++;
            nodeNuevo->pElement=pElement;
        }

        returnAux=0;
    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* list, void* pElement)
{
    int returnAux = -1;

    if(list != NULL ){
        addNode(list, ll_len(list ), pElement);
        returnAux=0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* list, int index)
{
    void* returnAux = NULL;
    Node* pNode;

    if(list!= NULL && index >= 0 && index<ll_len(list) ){
        pNode= getNode(list,index);
        returnAux= pNode->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* list, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodeAux;
    if(list!= NULL&& index >= 0 && index<ll_len(list)){ ///SI LE PONGO EL = SE ROMPE ¿MAL LA VALIDACION?
        if(index == ll_len(list)){
            ll_add(list, pElement);
        }
        else{
        nodeAux=getNode(list,index);
        nodeAux->pElement=pElement;

        }
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* list,int index)
{
    Node* auxiliar;
    Node* ABorrar;

    int returnAux = -1;
    if(list!= NULL&& index >= 0 && index < ll_len(list)){

        if(index ==0){
            ABorrar = getNode(list, index);
            list->pFirstNode= getNode(list, 1);
        }
        else{
            ABorrar = getNode(list,index);
            auxiliar = getNode (list,index -1);

            if(ABorrar->pNextNode == NULL){
                 auxiliar->pNextNode=NULL;

            }
            else{
                auxiliar->pNextNode=getNode(list,index+1);
            }

        }
        free(ABorrar);
        list->size--;
        returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* list)
{
    int returnAux = -1;
    int i;

    if(list != NULL){
        if(list->size != 0){
            for(i=0;i<ll_len(list); i++){
                ll_remove(list, i);
                returnAux = 0;
            }
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* list)
{
    int returnAux = -1;

    if(list !=  NULL){
        if(list->size == 0){
        free(list);

        returnAux = 0;
        }
        else{
        ll_clear(list);
        free(list);
        returnAux = 0;
        }

    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* list, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* auxiliar;


    if(list != NULL){
        for(i=0;i<ll_len(list); i++){
            auxiliar = getNode(list,i);
            if(auxiliar->pElement == pElement){
                returnAux = i;
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
int ll_isEmpty(LinkedList* list)
{
    int returnAux = -1;
    if( list != NULL){
        if(list->size == 0){
            returnAux =1;
        }
        else{
            returnAux =0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* list, int index, void* pElement)
{
    int returnAux = -1;

    if(list != NULL && index >=0 && index <= ll_len(list)){ ///list->size > index
        addNode(list ,index, pElement);
        returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* list,int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;

    if(list != NULL && index >= 0 && index < ll_len(list)){
        pNode = getNode(list, index);

        if(pNode != NULL){


            returnAux = pNode->pElement;
            ll_remove(list, index);
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* list, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* auxiliar;

    if(list != NULL ){
        returnAux = 0;
        for(i=0;i<ll_len(list);i++){
            auxiliar = getNode(list,i);
            if(auxiliar->pElement == pElement){
                returnAux = 1;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* list,LinkedList* this2)
{
    int returnAux = -1;
    int i, control;
    Node* AuxThis2;

    if(list != NULL && this2 != NULL){
        returnAux =0;
        for(i=0;i<ll_len(this2);i++){
            AuxThis2= getNode(this2, i);
            control = ll_contains(list,AuxThis2->pElement);
            if(control==1){
                returnAux = 1;
            }
            if(control==0){
                returnAux =0;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* list,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    Node* auxiliar;


    if(list != NULL && from >= 0 && from <ll_len(list) && to > from && to <= ll_len(list)){
        cloneArray = ll_newLinkedList();
        for (i=from;i<to;i++){
            auxiliar = getNode(list, i);
            ll_add(cloneArray, auxiliar->pElement );
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
LinkedList* ll_clone(LinkedList* list)
{
    LinkedList* cloneArray = NULL;
    Node* auxiliar;
    int i;

    if (list != NULL){
        cloneArray = ll_newLinkedList();
        for (i=0;i<ll_len(list);i++){
            auxiliar = getNode(list, i);
            ll_add(cloneArray, auxiliar->pElement );
        }
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* list, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i, j;
    void* elemento;
    int loQueGuardaPFunc;

    if(list != NULL && pFunc != NULL && (order == 1 || order == 0)){
        returnAux =0;

        for (i=0; i<ll_len(list)-1;i++){
            for(j=i+1;j<ll_len(list);j++){

                loQueGuardaPFunc = pFunc(ll_get(list, i), ll_get(list, j));

                if(loQueGuardaPFunc > 0 && order){
                    elemento = ll_get(list, i);
                    ll_set(list,i,ll_get(list, j));
                    ll_set(list,j,elemento);
                }
                else{
                    if(loQueGuardaPFunc < 0 ){
                        elemento = ll_get(list, i);
                        ll_set(list,i,ll_get(list, j));
                        ll_set(list,j,elemento);
                    }
                }
            }
        }
    }
    return returnAux;
}

