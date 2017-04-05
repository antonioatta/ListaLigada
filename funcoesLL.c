#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista-ligada.h"

int le_registro(NODO_LL *pNodo)
{
    int tam;

    strcpy(pNodo->matric,"");
    printf("Matricula (digite <Enter> para encerrar): ");
    fgets(pNodo->matric, TAM_MATRIC, stdin);
    fflush(stdin);
    tam=strlen(pNodo->matric);
    if (pNodo->matric[tam-1]=='\n') pNodo->matric[tam-1]='\0'; //fgets mantem o <Enter> como parte do dado lido
    if (strlen(pNodo->matric)==0) return 0;

    printf("Nome:      ");
    fgets(pNodo->nome, TAM_NOME, stdin);
    fflush(stdin);
    tam=strlen(pNodo->nome);
    if (pNodo->nome[tam-1]=='\n') pNodo->nome[tam-1]='\0';

    printf("Media:     ");
    scanf("%f", &(pNodo->media));
    fflush(stdin);

    printf("Situacao:  ");
    fgets(pNodo->status, TAM_STATUS, stdin);
    fflush(stdin);
    tam=strlen(pNodo->status);
    if (pNodo->status[tam-1]=='\n') pNodo->status[tam-1]='\0';

    printf("----------------------------\n");
    return 1;
}

void inclui_em_ordem_nome(NODO_LL **pInicio, NODO_LL *pReg)
{
    NODO_LL *pAux, *pAnt=NULL;

    pAux=*pInicio;
    while (pAux!=NULL) {
        if (strcmp(pAux->nome, pReg->nome)>0) break;
        pAnt=pAux;
        pAux=pAux->prox;
    }
    if (pAnt==NULL)
    {
        pReg->prox=*pInicio;
        *pInicio=pReg;
    }
    else
    {
        pReg->prox=pAux;
        pAnt->prox=pReg;
    }
}


int exclui_matric(NODO_LL **pInicio, char matric[])
{
    NODO_LL *pAux, *pAnt=NULL;

    pAux=*pInicio;
    while (pAux!=NULL) {
        if (strcmp(pAux->matric, matric) == 0) break;
        pAnt=pAux;
        pAux=pAux->prox;
    }
    if (pAux==NULL) return 0;
    if (pAnt==NULL) *pInicio=pAux->prox;
    else pAnt->prox=pAux->prox;
    free(pAux);
    return 1; // 1 se conseguiu excluir e 0 caso contrario (nao encontrou?).
}


NODO_LL *consulta_matric(NODO_LL *inicio, char matricula[])
{

    NODO_LL *pAux;

    pAux=inicio;
    while (pAux!=NULL) {
        if (strcmp(pAux->matric, matricula) == 0) break; // Encontrou!
        pAux=pAux->prox;
    }
    if (pAux==NULL) return NULL;
    return pAux;
}


void imprime_lista(NODO_LL *pInicio) {

    NODO_LL *pAux;

    pAux=pInicio;
    printf("=== Conteudo da Lista ================\n");
    while (pAux!=NULL) {
        printf("%s, %s, %4.1f, %s\n", pAux->matric, pAux->nome, pAux->media, pAux->status);
        pAux=pAux->prox;
    }
    printf("======================================\n");
}


void imprime_nodo(NODO_LL *pReg) {

    printf("=== Conteudo do Registro =============\n");
    printf("%s, %s, %4.1f, %s\n", pReg->matric, pReg->nome, pReg->media, pReg->status);
    printf("======================================\n");
}

