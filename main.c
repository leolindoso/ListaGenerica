#include <stdio.h>
#include <stdlib.h>
#include "CofoAluno.h"

int main() {
    //DECLARAÇÃO DAS VARIÁVEIS
    sllist *l;
    int b,d;
    int resp,modo = 100;

    l = sllCreate();

    //INICIO DO MENU
    while(modo != 0){
        //IMPRIME TODAS AS OPÇÕES NA TELA
        if (modo == 100){
            modo = 101;
            printf("\n");
            //printf("1 - Criar Lista\n");
            printf("1 - Inserir no Começo da Lista\n");
            printf("2 - Inserir no Fim da Lista\n");
            printf("3 - Inserir no Antes do Especificado da Lista\n");
            printf("4 - Inserir no Depois do Especificado da Lista\n");
            printf("5 - Procurar Elemento na Lista\n");
            printf("6 - Remover Primeiro Elemento da Lista\n");
            printf("7 - Remover Ultimo Elemento da Lista\n");
            printf("8 - Remover Elemento Escolhido da Lista\n");
            printf("9 - Destruir Lista\n");
            printf("10 - Imprimir Lista\n");
            printf("11 - Numero de Nos na Lista\n");
            printf("0 - Sair\n");
            printf("Escolha uma Opção: ");
            scanf("%i",&modo);
            printf("\n");
        }
        //ESCOLHE A OPÇÃO DE CRIAR A LISTA
        /*if(modo == 1){
            if(l != NULL){
                    l = sllCreate();
            }else if (l->first != NULL){
                printf("Lista ja foi criado com %i elementos\n", sllNumNodes(l));
                modo = 100;
            }
        modo = 100;
        }*/
        //ESCOLHE A OPÇÃO DE INSERIR UM ELEMENTO NO COMEÇO DA LISTA
        if(modo == 1){
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
        //INSERE NO FINAL DA LISTA
        if(modo == 2){
            int x;
            printf("Informe o numero que quer inserir: \n");
            scanf("%i",&x);
            int stat = sllInsertLast(l,(void*)x);
            if(stat == 1){
                printf("Elemento Inserido com Sucesso!\n");
            }else{
                printf("Falha ao Inserir Elemento\n");
            }
            modo = 100;
        }
        //INSERE ANTES DO NO ESPECIFICADO
        if(modo == 3){
            int numProcurado;
            printf("Informe qual numero quer achar: ");
            scanf("%i",&numProcurado);
            int x;
            printf("Informe o numero que quer inserir: \n");
            scanf("%i",&x);
            int stat = sllInsertBeforeSpec(l,(void*)numProcurado, CmpData,(void*)x);
            if(stat == 1){
                printf("Elemento Inserido com Sucesso!\n");
            }else{
                printf("Falha ao Inserir Elemento\n");
            }
            modo = 100;
        }
        //INSERE DEPOIS DO NÓ ESPECIFICADO
        if(modo == 4){
            int numProcurado;
            printf("Informe qual numero quer achar: ");
            scanf("%i",&numProcurado);
            int x;
            printf("Informe o numero que quer inserir: \n");
            scanf("%i",&x);
            int stat = sllInsertAfterSpec(l,(void*)numProcurado, CmpData,(void*)x);
            if(stat == 1){
                printf("Elemento Inserido com Sucesso!\n");
            }else{
                printf("Falha ao Inserir Elemento\n");
            }
            modo = 100;
        }
        //ESCOLHE A OPÇÃO DE PROCURAR UM ELEMENTO NA LISTA
        if(modo == 5){
            int data;
            int ocorrencia;
            int numProcurado;
            printf("Qual o numero pelo qual quer procurar? ");
            scanf("%i",&numProcurado);
            data = (int)sllquery(l,(void*)numProcurado, CmpData);
            ocorrencia = sllNumOcurr(l,(void*)numProcurado, CmpData);
            if(ocorrencia != NULL){
                printf("Numero Encontrado %d vezes!\n", ocorrencia);
            }else{
                printf("Nao Encontrado\n");

            }

            modo = 100;
        }
        //ESCOLHE A OPÇÃO DE REMOVER O PRIMEIRO ELEMENTO DA LISTA
        if(modo == 6){
            void *x = sllRemoveFirst(l);
            if(x != NULL){
                printf("Primeiro Elemento Removido\n");
            }else{
                printf("Primeiro Elemento Não Foi Removido\n");
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
        //IMPRIME A LISTA
        if(modo == 10){
            int n = sllNumNodes(l);
            if(n == -1){
                printf("Não há elementos na lista!");
            }else{
                sllImprime(l);
            }
            modo = 100;
        }
        //QUANTOS NÓS TEM A LISTA
        if(modo == 11){
            int n = sllNumNodes(l);
            if(n == -1){
                printf("Não há elementos na lista!");
            }else{
                printf("A Lista tem %i Elementos\n",sllNumNodes(l));
            }

            modo = 100;
        }

    }
}