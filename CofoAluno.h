#ifndef CofoAluno_H_INCLUDED
#define CofoAluno_H_INCLUDED

//CRIA ESTRUTURA NÓ
typedef struct _slnode_{
    struct _slnode_ *next;
    void *data;
}slnode;

//CRIA ESTRUTURA LISTA
typedef struct _sllist_ {
    slnode *first;
    slnode *cur;
}sllist;

//HEADERS DA LISTA SIMPLESMENTE ENCADEADA
sllist *sllCreate();
int sllDestroy(sllist *l);
int sllInsertFirst(sllist *l, void *data);
int sllInsertLast(sllist *l, void *data);
int sllInsertBeforeSpec(sllist *l, void *key, int(*cmp)(void*,void*),void* data);
int sllInsertAfterSpec(sllist *l, void *key, int (*cmp)(void *, void *), void *data);
void *sllquery(sllist *l, void *key, int (*cmp)( void *, void *));
void *sllRemoveFirst(sllist *l);
void *sllRemoveLast(sllist *l);
void *sllRemoveSpec(sllist *l,void *key,int(*cmp)(void*,void*));
int sllNumNodes(sllist *l);
int sllNumOcurr(sllist *l,void *key,int (*cmp)(void *,void *));
void sllImprime(sllist *l);
//HEADERS DO ALUNO
int CmpData(void *a, void *b);


#endif


