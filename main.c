#include <stdio.h>
#include <stdlib.h>
#include "CofoAluno.h"

int main() {
    //DECLARAÇÃO DAS VARIÁVEIS
    sllist *l;
    int b,d;
    int resp,modo = 100;
    //INICIO DO MENU
    while(modo != 0){
        //IMPRIME TODAS AS OPÇÕES NA TELA
        if (modo == 100){
            modo = 101;
            printf("1 - Criar Lista\n");
            printf("2 - Inserir no Começo da Lista\n");
            printf("3 - Inserir no Fim da Lista\n");
            printf("4 - Inserir no Antes do Especificado da Lista\n");
            printf("5 - Inserir no Depois do Especificado da Lista\n");
            printf("6 - Procurar Elemento na Lista\n");
            printf("7 - Remover Ultimo Elemento da Lista\n");
            printf("8 - Remover Elemento Escolhido da Lista\n");
            printf("9 - Destruir Lista\n");
            printf("10 - Imprimir Lista\n");
            printf("11 - Numero de Nos na Lista\n");
            printf("0 - Sair\n");
            printf("Escolha uma Opção: ");
            scanf("%i",&modo);
        }
        //ESCOLHE A OPÇÃO DE CRIAR A LISTA
        if(modo == 1){
            if(l != NULL){
                    l = sllCreate();
            }else if (l->first != NULL){
                printf("Cofo ja foi criado com %i elementos\n", sllNumNodes(l));
                modo = 100;
            }
        modo = 100;
        }
        //ESCOLHE A OPÇÃO DE INSERIR UM ELEMENTO NO COMEÇO DA LISTA
        if(modo == 2){
            int x;
            printf("Informe o numero que quer inserir: \n");
            scanf("%i",&x);
            int stat = sllInsertFirst(l,(void*)x);
            if(stat == 1){
                printf("Elemento Inserido com Sucesso!\n");
            }else{
                printf("Falha ao Inserir Elemento\n");
            }
            modo = 100;
        }
        //ESCOLHE A OPÇÃO DE PROCURAR UM ELEMENTO NA LISTA
        if(modo == 6){
            int data;
            int numProcurado;
            printf("Qual o numero pelo qual quer procurar? ");
            scanf("%i",&numProcurado);
            data = (int)sllquery(l,(void*)&numProcurado, CmpData);
            if(data != NULL){
                printf("Numero Encontrado!\n");
            }else{
                printf("Nao Encontrado\n");

            }
            modo = 100;

        }
        //ESCOLHE A OPÇÃO DE REMOVER O ULTIMO ELEMENTO DA LISTA
        if(modo == 7){
            void *x = sllRemoveLast(l);
            if(x != NULL){
                printf("Ultimo Elemento Removido\n");
            }else{
                printf("Ultimo Elemento Não Foi Removido\n");
            }
            modo = 100;
        }
        //ESCOLHE A OPÇÃO DE REMOVER O ELEMENTO SELECIONADO DA LISTA
        if(modo == 8){
            int data;
            int numProcurado;
            //numProcurado = (int*)malloc(sizeof(int));
            printf("Qual o numero que quer procurar? ");
            scanf("%i",&numProcurado);
            data = (int)sllRemoveSpec(l,(void*)numProcurado,CmpData);
            if(data != NULL){
                printf("Elemento %d removido\n",data);
            }else{
                printf("Elemento %d Nao Encontrado\n",numProcurado);
            }
            modo = 100;

        }
        //ESCOLHE A OPÇÃO DE DESTRUIR A LISTA
        if(modo == 9){
            if(l != NULL){
                if(sllNumNodes(l) == 0){
                    int flag = sllDestroy(l);
                    if (flag == 1){
                        printf("Lista destruída com Sucesso!\n");
                    }else{
                        printf("Falha ao destruir a Lista!\n");
                    }
                }else{
                    printf("Ainda tem %d elementos dentro da Lista\n",sllNumNodes(l));
                }
            } else{
                printf("Lista não existe!\n");
            }

            modo = 100;
        }
        if(modo == 10){
            sllImprime(l);
            modo = 100;
        }
        if(modo == 11){
            printf("A Lista tem %i Elementos\n",sllNumNodes(l));
            modo = 100;
        }
    }
}