#ifndef CofoAluno_C_INCLUDED
#define CofoAluno_C_INCLUDED
#include "CofoAluno.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

//CRIA LISTA SIMPLESMENTE ENCADEADA if(c != NULL){
sllist *sllCreate(){
    sllist *l;
    l = (sllist *)malloc(sizeof(sllist ));
    if (l != NULL){
        l -> first = NULL;
        l->cur = NULL;
        return l;
    }
    return NULL;
}

//DESTROI A LISTA SE A LISTA ESTIVER VAZIA
int sllDestroy(sllist *l){
    if (l -> first == NULL){
        free(l);
        return TRUE;
    }
    return FALSE;
}



//REMOVE O PRIMEIRO DA LISTA
void *sllRemoveFirst( sllist *l){
    slnode *aux;
    void *data;
    if(l != NULL){
        if(l -> first != NULL){
            aux = l -> first;
            data = aux -> data;
            l -> first = aux -> next;
            free(aux);
            return data;
        }
    }
    return NULL;
}

void *sllRemoveLast(sllist *l){
    slnode *cur;
    void *data;
    if(l != NULL){
        if(l->first != NULL){
            l->cur = l->first;
            cur = l->cur;
            while(cur->next != NULL){
                cur = cur->next;
            }
            data = cur->data;
            free(cur);
            return data;
        }
    }
    return NULL;
}

//PROCURA NA LISTA ELEMENTO ESPECIFICADO POR UMA CHAVE
void *sllquery(sllist *l, void *key, int (*cmp)( void *, void *)){
    slnode *cur;
    int stat;
    if (l != NULL){
        if (l -> first != NULL){
            cur = l -> first;
            stat = cmp (key, cur -> data);
            while (stat != TRUE && cur -> next != NULL){
                cur = cur -> next;
                stat = cmp(key, cur -> data);
            }
            if (stat == TRUE){
                return cur -> data;
            }
        }
    }
    return NULL;
}
//INSERE COMO PRIMEIRO NA LISTA
int sllInsertFirst(sllist *l, void *data){
    slnode *newnode;
    if (l != NULL){
        newnode = (slnode *) malloc (sizeof(slnode));
        if (newnode != NULL){
            newnode -> data = data;
            newnode -> next = l -> first;
            l -> first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}

//INSERE COMO ULTIMO NA LISTA
int sllInsertLast(sllist *l, void *data){
    slnode *newnode,*aux;
    if(l != NULL){
        if(l->first != NULL){
            aux = l->first;
            while(aux->next != NULL){
                aux = aux->next;
            }
            newnode = (slnode*)malloc(sizeof(slnode));
            if(newnode != NULL){
                newnode->data = data;
                newnode->next = aux->next;
                aux->next = newnode;
            }
            return TRUE;
        }
    }
    return FALSE;
}

// INSERE ANTES DO NÓ ESPECIFICADO
int sllInseAfterSpec(sllist *l, void *key, int (*cmp)(void *, void *), void *data){
    slnode *cur, *newnode;
    int stat;
    if (l != NULL){
        if (l -> first != NULL){
            cur = l -> first;
            stat = cmp (key, cur -> data);
            while (stat != TRUE && cur -> next != NULL){
                cur = cur -> next;
                stat = cmp(key, cur -> data);
            }
            if (stat == TRUE){
                newnode = (slnode *)malloc (sizeof(slnode));
                if(newnode != NULL){
                    newnode -> data = data;
                    newnode -> next = cur -> next;
                    cur -> next = newnode;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

int sllInsertBeforeSpec(sllist *l, void *key, int(*cmp)(void*,void*),void* data){
    slnode *cur,*newnode,*prev;
    int stat;
    if(l != NULL){
        if(l->first != NULL){
            cur = l->first;
            prev = NULL;
            stat = cmp(key,cur->data);
            while(stat != TRUE && cur->next != NULL){
                prev = cur;
                cur = cur->next;
                stat = cmp(key, cur->data);
            }
            if(stat == TRUE){
                newnode = (slnode*)malloc(sizeof(slnode));
                if(newnode != NULL){
                    newnode->data = data;
                    newnode->next = cur;
                }
                if(prev != NULL){
                    prev->next = newnode;
                }else{
                    l->first = newnode;
                }
                return TRUE;
            }
        }
    }
    return FALSE;
}

void *sllRemoveSpec(sllist *l,void *key,int(*cmp)(void*,void*)){
    slnode *cur,*newnode,*prev;
    void *data;
    int stat;
    if(l != NULL) {
        if (l->first != NULL) {
            cur = l->first;
            prev = NULL;
            stat = cmp(key, cur->data);
            while (stat != TRUE && cur->next != NULL) {
                prev = cur;
                cur = cur->next;
                stat = cmp(key, cur->data);
            }
            if (stat == TRUE) {
                if(prev != NULL){
                    prev->next = cur->next;
                }else{
                    l->first = cur->next;
                }
                data = cur->data;
                free(cur);
                return data;
            }
        }
    }
    return NULL;
}


int sllNumNodes(sllist *l){
    int i = 0;
    if(l != NULL){
        if(l->first != NULL){
            slnode *aux;
            aux = l->first;
            while(aux != NULL){
                i++;
                aux = aux->next;
            }
        }
        return i;
    }
    return NULL;
}

void sllImprime(sllist *l){
    if(l != NULL){
        if(l->first != NULL){
            l->cur = l->first;
            while(l->cur != NULL){
                printf("[%d]   ->\t",(int)l->cur->data);
                l->cur = l->cur->next;
            }
        }
    }
}


//COMPARA O CPF DO ALUNO COM A CHAVE ENVIADA
int CmpData(void *a, void *b){
    int *pa;
    int *pb;
    pa = (int*)a;
    pb = (int*)b;
    if(pb == pa){
        return TRUE;
    }
    return FALSE;
}

#endif


