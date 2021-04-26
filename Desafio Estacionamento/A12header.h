#ifndef pilha_H
 
#define pilha_H
/* estrutura do n� da pilha */
typedef struct _pilha {
    char placa[8];
    struct _pilha *proximo;
} Pilha;

/* declaracoes das funcoes de pilha */
void inicializaPilha (Pilha **);
int pilhaVazia (Pilha *);

void imprimePilha (Pilha *);
void insereTopo (Pilha **, char*);
void contagemPilha(Pilha *);
void removeTopo (Pilha **);
void veiculos(Pilha **);
void pesquisaElemento (Pilha **);
void esvaziaPilha (Pilha **);

/* funcoes estacionamento */
char* gerarPlaca();

#endif