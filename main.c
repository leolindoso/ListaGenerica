#include <stdio.h>
#include <stdlib.h>
#include "CofoAluno.h"

int main() {
    //DECLARAÇÃO DAS VARIÁVEIS
    cofo *c;
    int b,d,tam;
    int resp,modo = 100;
    //INICIO DO MENU
    while(modo != 0){
        //IMPRIME TODAS AS OPÇÕES NA TELA
        if (modo == 100){
            modo = 101;
            printf("1 - Criar Coleção\n");
            printf("2 - Criar e Inserir Aluno na Coleção\n");
            printf("3 - Procurar Aluno na Coleção\n");
            printf("4 - Remover Ultimo Aluno da Coleção\n");
            printf("5 - Remover Aluno Escolhido da Coleção\n");
            printf("6 - Destruir Coleção\n");
            printf("0 - Sair\n");
            printf("Escolha uma Opção: ");
            scanf("%i",&modo);
        }
        //ESCOLHE A OPÇÃO DE CRIAR A COLEÇÃO
        if(modo == 1){
            if(c == NULL){
                printf("Informe o tamanho do Cofo: \n");
                scanf("%i",&tam);
                if(tam > 0){
                    c = cofoCreate(tam);
                }

                modo = 100;
            }else{
                printf("Cofo ja foi criado com %i elementos\n",tam);
                modo = 100;
            }
        }
        //ESCOLHE A OPÇÃO DE CRIAR E INSERIR UM ALUNO NA COLEÇÃO
        if(modo == 2){
            aluno *a;
            a = (aluno*)malloc(sizeof(aluno));
            long cpf;
            char nome[60];
            int idade;
            printf("Informe o nome do Aluno: \n");
            scanf("%s",nome);
            fflush(stdin);
            printf("Informe o CPF do Aluno: \n");
            scanf("%li",&cpf);
            //scanf("%c",&nome);
            printf("Informe a idade do Aluno: \n");
            scanf("%i",&idade);
            a = alunoCreate(cpf,nome,idade);
            cofoInsert(c,(void*)a);
            modo = 100;
        }
        //ESCOLHE A OPÇÃO DE PROCURAR UM ALUNO NA COLEÇÃO
        if(modo == 3){
            aluno *alunoAux;
            printf("Pelo o quê você quer procurar?\n1- Nome\n2-CPF\n");
            scanf("%i",&b);
            //ESCOLHE A OPÇÃO DE PROCURAR POR NOME
            if(b == 1){
                char nomeProcurado[60];
                printf("Qual o nome pelo qual quer procurar? ");
                scanf("%s",nomeProcurado);
                fflush(stdin);
                alunoAux = (aluno*)cofoQuery(c,(void*)&nomeProcurado,CmpNomeAluno);
                if(alunoAux != NULL){
                    printf("Aluno: %s\t Cpf: %li\t Idade: %i\n",alunoAux->nome,alunoAux->CPF,alunoAux->idade);
                }else{
                    printf("Nao Encontrado\n");
                }
                modo = 100;
                //ESCOLHE A OPÇÃO DE PROCURAR POR CPF
            }else if(b == 2){
                long int cpfProcurado;
                printf("Qual o cpf pelo qual quer procurar? ");
                scanf("%li",&cpfProcurado);
                alunoAux = (aluno*)cofoQuery(c,(void*)&cpfProcurado,CmpCPFAluno);
                if(alunoAux != NULL){
                    printf("Aluno: %s\t Cpf: %li\t Idade: %i\n",alunoAux->nome,alunoAux->CPF,alunoAux->idade);
                }else{
                    printf("Nao Encontrado\n");
                }
                modo = 100;
            }
            modo = 100;

        }
        //ESCOLHE A OPÇÃO DE REMOVER O ULTIMO ALUNO DA COLEÇÃO
        if(modo == 4){
            void *x = cofoRemoveLast(c);
            if(x != NULL){
                printf("Ultimo Elemento Removido\n");
            }else{
                printf("Ultimo Elemento Não Foi Removido\n");
            }
            modo = 100;
        }
        //ESCOLHE A OPÇÃO DE REMOVER O ALUNO SELECIONADO DA COLEÇÃO
        if(modo == 5){
            aluno *alunoAux2;
            printf("Pelo o quê você quer procurar?\n1- Nome\n2-CPF\n");
            scanf("%i",&b);
            //ESCOLHE A OPÇÃO DE PROCURAR POR NOME
            if(b == 1){
                char nomeProcurado[60];
                printf("Qual o nome pelo qual quer procurar? ");
                scanf("%s",nomeProcurado);
                fflush(stdin);
                alunoAux2 = (aluno*)cofoRemove(c,(void*)&nomeProcurado,CmpNomeAluno);
                if(alunoAux2 != NULL){
                    printf("Aluno: %s\t Cpf: %li\t Idade: %i\n",alunoAux2->nome,alunoAux2->CPF,alunoAux2->idade);
                }else{
                    printf("Nao Encontrado\n");
                }
                modo = 100;
                //ESCOLHE A OPÇÃO DE PROCURAR POR CPF
            }else if(b == 2){
                long int cpfProcurado;
                printf("Qual o cpf pelo qual quer procurar? ");
                scanf("%li",&cpfProcurado);
                alunoAux2 = (aluno*)cofoRemove(c,(void*)&cpfProcurado,CmpCPFAluno);
                if(alunoAux2 != NULL){
                    printf("Aluno: %s\t Cpf: %li\t Idade: %i\n",alunoAux2->nome,alunoAux2->CPF,alunoAux2->idade);
                }else{
                    printf("Nao Encontrado\n");
                }
                modo = 100;
            }
            modo = 100;

        }
        //ESCOLHE A OPÇÃO DE DESTRUIR A COLEÇÃO
        if(modo == 6){
            if(c != NULL){
                if(c->elm == 0){
                    int flag = cofoDestroy(c);
                    if (flag == 1){
                        printf("Cofo destruído com Sucesso!\n");
                    }else{
                        printf("Falha ao destruir o Cofo!\n");
                    }
                }else{
                    printf("Ainda tem %d elementos dentro do Cofo\n",c->elm);
                }
            } else{
                printf("Coleção não existe!\n");
            }

            modo = 100;
        }
    }
}