#define TAM_MATRIC 11
#define TAM_NOME 30
#define TAM_STATUS 3


/* Estrutura de um nodo da Lista Ligada  */
typedef
struct noh {
    char matric[TAM_MATRIC];
    char nome[TAM_NOME];
    float media;
    char status[TAM_STATUS];
    struct noh *prox;
} NODO_LL;


/* Prototipos das funcoes de gerencia da Lista Ligada */

int le_registro(NODO_LL *);
void inclui_em_ordem_nome(NODO_LL **, NODO_LL *);
int exclui_matric(NODO_LL **, char []);
NODO_LL *consulta_matric(NODO_LL *, char []);
void imprime_lista(NODO_LL *);
void imprime_nodo(NODO_LL *);


