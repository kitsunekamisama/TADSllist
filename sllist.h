#ifndef SLLIST_H_INCLUDED
#define SLLIST_H_INCLUDED

/*------------------------------------------------------------------------------
Especifica��o das opera��es do TAD SLLIST gen�rico:
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
Estrutura _sllist_: Declara��o de tipo que cont�m as vari�veis que comp�em a SLLIST.
------------------------------------------------------------------------------*/
typedef struct _slnode_ SLNode;
typedef struct _sllist_ SLList;
#endif // _sllist_h_
#ifdef _sllist_c_

SLList *sllCreate(void);
int sllInsertFirst( SLList *l, void *data );
int sllInsertLast( SLList *l, void *data );
void *sllRemoveFirst( SLList *l, void *key, int (*cmp)(void*,void*) );
void *sllRemoveLast( SLList *l);
void *sllRemoveSpec( SLList *l, void *key, int (*cmp)(void*,void*) );
int sllRemoveAll(SLList *l);
void *sllQuery( SLList *l, void *key, int (*cmp)(void*,void*) );
void *sllGetFirst( SLList *l );
void *sllGetNext( SLList *l );
int sllDestroy(SLList *l);

#else

/*------------------------------------------------------------------------------
Fun��o sllCreate: Cria um novo TAD SLLIST
Parametro: Recebe o n�mero de itens para o SLLIST ser criada
(l!=NULL)
Retorno: Ponteiro para um novo TAD SLLIST vazio;
         'NULL' - Caso contr�rio
------------------------------------------------------------------------------*/
extern SLList *sllCreate(void);

/*------------------------------------------------------------------------------
Fun��o sllInsertFirst: Insere um item no SLLIST
Parametros: TAD SLLIST existente, n�o cheio e o item a ser inserido (elm!=NULL)
Retorno: TRUE(1) - Item inclu�do no TAD SLLIST;
         FALSE(0) - Caso contr�rio
------------------------------------------------------------------------------*/
extern int sllInsertFirst( SLList *l, void *data );

/*------------------------------------------------------------------------------
Fun��o sllInsertLast: Insere um item no SLLIST
Parametros: TAD SLLIST existente, n�o cheio e o item a ser inserido (elm!=NULL)
Retorno: TRUE(1) - Item inclu�do no TAD SLLIST;
         FALSE(0) - Caso contr�rio
------------------------------------------------------------------------------*/
extern int sllInsertLast( SLList *l, void *data );

/*------------------------------------------------------------------------------
Fun��o sllRemove: Remove um item de um TAD SLLIST
Parametros: TAD SLLIST existente, n�o vazia e o item a ser removido (elm!=NULL)
Retorno: Ponteiro para o item removido do TAD SLLIST;
         'NULL' - Caso contr�rio
------------------------------------------------------------------------------*/
extern void *sllRemoveFirst( SLList *l, void *key, int (*cmp)(void*,void*) );

/*------------------------------------------------------------------------------
Fun��o sllRemove: Remove um item de um TAD SLLIST
Parametros: TAD SLLIST existente, n�o vazia e o item a ser removido (elm!=NULL)
Retorno: Ponteiro para o item removido do TAD SLLIST;
         'NULL' - Caso contr�rio
------------------------------------------------------------------------------*/
extern void *sllRemoveLast( SLList *l);

/*------------------------------------------------------------------------------
Fun��o sllRemove: Remove um item de um TAD SLLIST
Parametros: TAD SLLIST existente, n�o vazia e o item a ser removido (elm!=NULL)
Retorno: Ponteiro para o item removido do TAD SLLIST;
         'NULL' - Caso contr�rio
------------------------------------------------------------------------------*/
extern void *sllRemoveSpec( SLList *l, void *key, int (*cmp)(void*,void*) );

/*------------------------------------------------------------------------------
Fun��o cofRemoveAll: Remove todos os itens de um TAD SLLIST
Parametros: TAD Cole��o existente e n�o vazia
Retorno: TRUE(1) - Todos os itens retirados do TAD SLLIST;
         FALSE(0) - Caso contr�rio
------------------------------------------------------------------------------*/
extern int sllRemoveAll(SLList *l);

/*------------------------------------------------------------------------------
Fun��sll: Busca um item em um TAD SLLIST
Parametros: TAD SLLIST existente, n�o vazia e o item a ser buscado (key!=NULL)
Retorno: Ponteiro para o item buscado do TAD SLLIST;
         'NULL' - Caso contr�rio
------------------------------------------------------------------------------*/
extern void *sllQuery( SLList *l, void *key, int (*cmp)(void*,void*) );

/*------------------------------------------------------------------------------
Fun��o sllGetFirst: Pega o primeiro item de um TAD SLLIST
Parametros: TAD SLLIST existente e n�o vazia
Retorno: Ponteiro para o primeiro item do TAD SLLIST;
         'NULL' - Caso contr�rio
------------------------------------------------------------------------------*/
extern void *sllGetFirst( SLList *l );

/*------------------------------------------------------------------------------
Fun��o sllGetNext: pega o pr�ximo item de um TAD SLLIST
Parametros: TAD SLLIST existente, n�o vazia
Retorno: Ponteiro para o pr�ximo item do TAD SLLIST;
         'NULL' - Caso contr�rio
------------------------------------------------------------------------------*/
extern void *sllGetNext( SLList *l );

/*------------------------------------------------------------------------------
Fun��o sllDestroy: Destr�i um TAD SLLIST
Parametro: Ponteiro para um TAD SLLIST
Retorno: TRUE(1) - TAD SLLIST destru�do liberando seu espa�o da mem�ria;
         FALSE(0) - Caso contr�rio
------------------------------------------------------------------------------*/
extern int sllDestroy(SLList *l);



#endif // SLLIST_H_INCLUDED
