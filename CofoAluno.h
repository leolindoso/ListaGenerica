#ifndef CofoAluno_H_INCLUDED
#define CofoAluno_H_INCLUDED

//CRIA ESTRUTURA NÓ
typedef struct _slnode_{
    struct _slnode_ *next;
    void *data;
}slnode;

//CRIA ESTRUTURA LISTA
typedef struct _sll_ {
    slnode *first;
}sllist;

//HEADERS DA LISTA SIMPLESMENTE ENCADEADA
cofo *cofoCreate(int max);
int cofoDestroy(cofo *c);
int cofoInsert(cofo *c, void *x);
void *cofoQuery(cofo *c,void* key,int (*cmp)(void*,void*));
void *cofoRemoveLast(cofo *c);
aluno *alunoCreate(long int cpf,char *nome,int idade);
void *cofoRemove(cofo *c,void *key,int (*cmp)(void*,void*));
//HEADERS DO ALUNO
int CmpCPFAluno(void *a, void *b);
int CmpNomeAluno(void *a, void*b);

#endif


