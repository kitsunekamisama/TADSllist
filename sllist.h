#ifndef SLLIST_H_INCLUDED
#define SLLIST_H_INCLUDED

/*------------------------------------------------------------------------------
Especificação das operações do TAD SLLIST genérico:
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
Estrutura _sllist_: Declaração de tipo que contém as variáveis que compõem a SLLIST.
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
Função sllCreate: Cria um novo TAD SLLIST
Parametro: Recebe o número de itens para o SLLIST ser criada
(l!=NULL)
Retorno: Ponteiro para um novo TAD SLLIST vazio;
         'NULL' - Caso contrário
------------------------------------------------------------------------------*/
extern SLList *sllCreate(void);

/*------------------------------------------------------------------------------
Função sllInsertFirst: Insere um item no SLLIST
Parametros: TAD SLLIST existente, não cheio e o item a ser inserido (elm!=NULL)
Retorno: TRUE(1) - Item incluído no TAD SLLIST;
         FALSE(0) - Caso contrário
------------------------------------------------------------------------------*/
extern int sllInsertFirst( SLList *l, void *data );

/*------------------------------------------------------------------------------
Função sllInsertLast: Insere um item no SLLIST
Parametros: TAD SLLIST existente, não cheio e o item a ser inserido (elm!=NULL)
Retorno: TRUE(1) - Item incluído no TAD SLLIST;
         FALSE(0) - Caso contrário
------------------------------------------------------------------------------*/
extern int sllInsertLast( SLList *l, void *data );

/*------------------------------------------------------------------------------
Função sllRemove: Remove um item de um TAD SLLIST
Parametros: TAD SLLIST existente, não vazia e o item a ser removido (elm!=NULL)
Retorno: Ponteiro para o item removido do TAD SLLIST;
         'NULL' - Caso contrário
------------------------------------------------------------------------------*/
extern void *sllRemoveFirst( SLList *l, void *key, int (*cmp)(void*,void*) );

/*------------------------------------------------------------------------------
Função sllRemove: Remove um item de um TAD SLLIST
Parametros: TAD SLLIST existente, não vazia e o item a ser removido (elm!=NULL)
Retorno: Ponteiro para o item removido do TAD SLLIST;
         'NULL' - Caso contrário
------------------------------------------------------------------------------*/
extern void *sllRemoveLast( SLList *l);

/*------------------------------------------------------------------------------
Função sllRemove: Remove um item de um TAD SLLIST
Parametros: TAD SLLIST existente, não vazia e o item a ser removido (elm!=NULL)
Retorno: Ponteiro para o item removido do TAD SLLIST;
         'NULL' - Caso contrário
------------------------------------------------------------------------------*/
extern void *sllRemoveSpec( SLList *l, void *key, int (*cmp)(void*,void*) );

/*------------------------------------------------------------------------------
Função cofRemoveAll: Remove todos os itens de um TAD SLLIST
Parametros: TAD Coleção existente e não vazia
Retorno: TRUE(1) - Todos os itens retirados do TAD SLLIST;
         FALSE(0) - Caso contrário
------------------------------------------------------------------------------*/
extern int sllRemoveAll(SLList *l);

/*------------------------------------------------------------------------------
Funçãsll: Busca um item em um TAD SLLIST
Parametros: TAD SLLIST existente, não vazia e o item a ser buscado (key!=NULL)
Retorno: Ponteiro para o item buscado do TAD SLLIST;
         'NULL' - Caso contrário
------------------------------------------------------------------------------*/
extern void *sllQuery( SLList *l, void *key, int (*cmp)(void*,void*) );

/*------------------------------------------------------------------------------
Função sllGetFirst: Pega o primeiro item de um TAD SLLIST
Parametros: TAD SLLIST existente e não vazia
Retorno: Ponteiro para o primeiro item do TAD SLLIST;
         'NULL' - Caso contrário
------------------------------------------------------------------------------*/
extern void *sllGetFirst( SLList *l );

/*------------------------------------------------------------------------------
Função sllGetNext: pega o próximo item de um TAD SLLIST
Parametros: TAD SLLIST existente, não vazia
Retorno: Ponteiro para o próximo item do TAD SLLIST;
         'NULL' - Caso contrário
------------------------------------------------------------------------------*/
extern void *sllGetNext( SLList *l );

/*------------------------------------------------------------------------------
Função sllDestroy: Destrói um TAD SLLIST
Parametro: Ponteiro para um TAD SLLIST
Retorno: TRUE(1) - TAD SLLIST destruído liberando seu espaço da memória;
         FALSE(0) - Caso contrário
------------------------------------------------------------------------------*/
extern int sllDestroy(SLList *l);



#endif // SLLIST_H_INCLUDED
