#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista-ligada.h"

int main()
{
    NODO_LL *pAux;
    NODO_LL *inicio=NULL;    // lista vazia no início

    char matricula[TAM_MATRIC] = "X";
    NODO_LL *nodoConsulta;
    int tam;

    printf("\n*** Vamos preencher a lista ligada com alguns registros ***\n\n");
    pAux=(NODO_LL *) malloc(1*sizeof(NODO_LL));
    if (pAux==NULL)
    {
        printf("Falha na alocacao na area de heap\n");
        exit(1);
    }
    while (le_registro(pAux))
    {
        inclui_em_ordem_nome(&inicio, pAux);
        pAux=(NODO_LL *) malloc(1*sizeof(NODO_LL));
        if (pAux==NULL)
        {
            printf("Falha na alocacao na area de heap\n");
            exit(1);
        }
    }
    free(pAux);  // foi alocado mas não foi preenchido (usuario encerrou a entrada)

    printf("\n*** Veja como a lista ligada ficou ***\n\n");
    imprime_lista(inicio);

    printf("\n\n*** Vamos consultar alguns da registros lista ligada ***\n\n");
    while (1) {
        printf("Matricula (digite <Enter> para encerrar): ");
        fgets(matricula, TAM_MATRIC, stdin);
        tam=strlen(matricula);
        if (matricula[tam-1]=='\n') matricula[tam-1]='\0';
        if (strlen(matricula)==0) break;      // interrompe o loop infinito
        nodoConsulta=consulta_matric(inicio, matricula);
        if (nodoConsulta != NULL) imprime_nodo(nodoConsulta);
        else printf("Registro inexistente na lista :(\n");
    }

    printf("\n\n*** Vamos excluir alguns da registros lista ligada ***\n\n");
    while (1) {
        printf("Matricula (digite <Enter> para encerrar): ");
        fgets(matricula, TAM_MATRIC, stdin);
        tam=strlen(matricula);
        if (matricula[tam-1]=='\n') matricula[tam-1]='\0';
        if (strlen(matricula)==0) break;      // interrompe o loop infinito
        if (exclui_matric(&inicio, matricula)) imprime_lista(inicio);
        else printf("Registro inexistente na lista :(\n");
    }

    return 0;

}
