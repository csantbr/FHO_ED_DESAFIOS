#ifndef LISTA_H
 
#define LISTA_H
struct tm *data_hora_atual;

typedef struct _fila {
    int senha;
    int tipo;
    struct tm *data_hora_atual;
    int tmp_atendimento;
    struct _fila *proximo;
} Fila;

typedef struct _caixa {
	int qnt_atendimentos;
	int data;
	int flag_caixa;
	int flag_ocupado;
	int senha_cliente;
} Caixa;


int gerarSenha();
int gerarNumero(int, int);

/* declaracoes das funcoes de lista */
void inicializaFila (Fila **);
int filaVazia (Fila *);
void distribuirFila(Fila **, Fila **, Fila **);
void inicializaCaixas();
void iniciar(Fila **, Fila **, Fila **);
int tempoFila(Fila *);
void abrirCaixa();
void tempoDia();

//Fila
void imprimeFila (Fila *);
void insereFinal (Fila **,int);
void removeInicio (Fila **);
Fila *pesquisaElemento (Fila *, int);

#endif