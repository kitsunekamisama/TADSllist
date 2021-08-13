/*------------------------------------------------------------------------------
sllist.l
Arquivo com a especificação de um Tipo Abstrato de Dados (TAD) para uma SLLIST genérico
------------------------------------------------------------------------------*/

#ifndef _sllist_c_
#define _sllits_c_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sllist.h"
#define TRUE 1
#define FALSE 0
#endif // _sllist_h_

/*------------------------------------------------------------------------------
Implementação das operações do TAD SLLIST genérico:
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
Estrutusllist: Declaração de tipo que contém as variáveis que compõem a SLLIST.
Variáveis: void **elms:  Vetor com os itens da SLLIST
           int max:      Tamanho máximo de itens da SLLIST
           int first:    Número atual de itens na SLLIST
           int cur:      Elemento atual na SLLIST
------------------------------------------------------------------------------*/
typedef struct _slnode_{
    struct _SLNode_*next;
    struct _SLNode_*prev;
    void *data;
}SLNode;

typedef struct _sllist_{
    SLNode *first;
    SLNode *cur;
}SLList;

SLList *sllCreate(void){
    SLList *l;
    l=(SLList *)malloc(sizeof(SLList));
    if(l!=NULL){
        l -> first = NULL;
        l -> cur = NULL;
        return l;
    }
    return NULL;
}

int sllInsertFirst(SLList *l, void *data){
    SLNode *newnode;

    if(l != NULL){
        newnode= (SLNode *)malloc(sizeof(SLNode));
        if(newnode != NULL){
            newnode -> data = data;
            newnode -> next = l -> first;
            l -> first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}

int sllInsertLast(SLList *l, void *data){
    SLNode *newnode, *last;

    if(l != NULL){
        newnode = (SLNode *)malloc(sizeof(SLNode));
        if(newnode != NULL){
           newnode -> data = data;
           newnode -> next = NULL;
           if(l -> first != NULL){
               last = l -> first;
               while(last -> next != NULL){
                   last = last -> next;
               }
               last -> next = newnode;
            }
            else{
                l -> first = newnode;
            }
            return TRUE;
        }
    }
    return FALSE;
}

void *sllRemoveFirst(SLList *l, void *key, int (*cmp)(void*,void*)){
    SLNode *aux;
    void *data;

    if(l != NULL){
        if( l -> first != NULL ){
            aux = l -> first;
            data = aux -> data;
            l -> first = aux -> next;
            free (aux);
            return data;
        }
    }
    return NULL;
}

void *sllRemoveLast(SLList *l){
    SLNode *last, *prev;
    void *data;

    if(l != NULL){
        if( l -> first != NULL ){
            last = l -> first;
            prev = NULL;
            while (last -> next != NULL){
                prev = last;
                last = last -> next;
            }
            if (prev != NULL){
                prev -> next = NULL;
            }
            else{
                l -> first = NULL;
            }
            data = last -> data;
            free (last);
            return data;
        }
    }
    return NULL;
}

void *sllRemoveSpec(SLList *l, void *key, int (*cmp)(void*,void*)){
    SLNode *spec, *prev;
    int stat;
    void *data;

    if(l != NULL){
        if( l -> first != NULL ){
            prev = NULL;
            spec = l -> first;
            stat = cmp(key, spec -> data);
            while( stat != TRUE && spec -> next != NULL){
                prev = spec;
                spec = spec -> next;
                stat = cmp(key, spec -> data);
            }
            if( stat == TRUE ){
                if( prev == NULL){
                    l -> first = spec -> next;
                }
                else{
                    prev -> next = spec -> next;
                }
                data = spec -> data;
                free (spec);
                return data;
            }
        }
    }
    return NULL;
}

void *sllQuery( SLList *l, void *key, int (*cmp)(void*, void*) ){
    SLNode *cur, *first;
    int stat;

    if(l != NULL){
        if(l -> first != NULL){
            cur = l > first;
            stat = cmp(key, cur -> data);
            while( stat != TRUE && cur -> next != NULL ){
                cur = cur -> next;
                stat = cmp(key, cur -> data);

            }
            if( stat == TRUE ){
                return cur -> data;
            }
        }
    }
    return NULL;
}

void *sllGetFirst(SLList *l){
    void *data;
    if(l!=NULL){
        if(l -> first != NULL){
            l -> cur = l -> first;
            data = l -> first -> data;
            return data;
        }
    }
    return NULL;
}

void *sllGetNext(SLList *l){
    if(l!=NULL){
        if(l -> cur != NULL){
            l -> cur = l -> cur -> next;
            return l -> cur;
        }
    }
    return NULL;
}

int sllRemoveAll(SLList *l){
    SLNode *aux;
    void *data;

    if(l != NULL){
        while( l -> first != NULL ){
            aux = l -> first;
            data = aux -> data;
            l -> first = aux -> next;
            free (aux);
            return data;
        }
    }
    return NULL;
}

int sllDestroy(SLList *l){

    if(l != NULL){
        if( l -> first == NULL ){ //SE A QUANTIDADE DE ELEMENTOS FOR IGUAL A ZERO
            free(l); // DESALOCA O SLLIST
            return TRUE;
        }
    }
    return FALSE;
}
