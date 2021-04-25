#include <stdio.h>
#include <stdlib.h> // rand()
#include <time.h> // time()
#include <unistd.h> // sleep()
#include "A12header.h"

#define CLIENTES 20

Caixa *caixa;
int tempo_dia = 0;
int pass = 0;

//Gera a senha para o clientes
int gerarSenha() {
  return pass++;
}

//Auxilia na geração de numeros randomicos
int gerarNumero(int min, int max) {
  return min + (rand() % max);
}

//inicia a Fila
void inicializaFila (Fila **fila) {
	*fila = NULL;
}

//Verifica se a fila está vazia
int filaVazia (Fila *fila) {
	if(fila == NULL)
		return 1;

	return 0;
}

//Insere novos clientes no final da fila
void insereFinal (Fila **fila,int tipo) {
	int i;
	time_t segundos;
    time(&segundos);  
    Fila *novo;
    Fila *atual = *fila;

    novo = (Fila *) malloc (sizeof(Fila));
     
  	novo->data_hora_atual = localtime(&segundos);
    novo->senha = gerarSenha();
    novo->tmp_atendimento = gerarNumero(1, 10);
    novo->proximo = NULL;
    novo->tipo = tipo;

    if (filaVazia(*fila)) {
        *fila = novo;
        return;
    }

    while (atual->proximo != NULL)
        atual = atual->proximo;

    atual->proximo = novo;
}

//imprime a fila caso houver necessidade
void imprimeFila (Fila *fila) {
	Fila *atual = fila;

	if(filaVazia(fila)){
		printf("A fila esta vazia!!!\n");
		return;
	}

	printf("Conteudo da fila: [ ");

	while(atual != NULL) {
		printf("[caixa:  | senha: %d | tipo: %d | tempo: %d\n", atual->senha, atual->tipo, atual->tmp_atendimento);
		atual = atual->proximo;
	}

	printf("]\n");
}

//Distribui o total de clientes entre as filas rapido, preferencial, comum

void distribuirFila (Fila **comum, Fila **rapido, Fila **preferencial) {
	int i, number;

	for(i = 0; i < CLIENTES; i++) {
		number = gerarNumero(1,3);

		switch(number) {
			case 1: // 1 - Comum
				insereFinal(comum, 40);
			break;

			case 2: // 2 - Rapido
				insereFinal(rapido, 25);
			break;

			case 3: // 3 - Preferencial
				insereFinal(preferencial, 15);
			break;
		}
	}
}

//Inicializa todos os caixas com seus valores iniciais
void inicializaCaixas() {
	int i;
    
	caixa = (Caixa*) malloc (25 * sizeof(Caixa));
	
	for(i = 0; i < 25; i++) {
		caixa[i].qnt_atendimentos = 0;
		caixa[i].data = 0; 
		if(i < 3) {
			caixa[i].flag_caixa = 1;
		} else {
			caixa[i].flag_caixa = 0;
		}
		caixa[i].flag_ocupado = 0;
		caixa[i].senha_cliente = 0;
	}
}

//Remove o clientes após o antendimento
void removeInicio (Fila **fila){
	Fila *aux = *fila;

	if(filaVazia(*fila)){
		printf("Nao eh possivel remover elemento. A fila esta vazia\n");
		return;
	}

	*fila = aux->proximo;

	free(aux);
}

//Processa o tempo de atendimento a cada segundo e verifica a disponibilidade de caixas abertos
void iniciar(Fila** comumC, Fila** rapidoC, Fila** preferencialC){
	int tempo_total = 0;
    pass = 0;
    int i;
    Fila *comum = *comumC;
	Fila *rapido = *rapidoC;
	Fila *preferencial = *preferencialC;
		
    while (1) {
    	tempo_total++;
        int i;
        time_t segundos;
        data_hora_atual = localtime(&segundos);
		
		//Libera os caixas que terminaram de atender
		for(i = 0; i <25; i++) {
			if(caixa[i].flag_caixa == 1 && caixa[i].flag_ocupado == 1) {
				if(caixa[i].data == time(&segundos)) {
					caixa[i].flag_ocupado =0;
				}
			}
		}
		
		//Procura caixas disponiveis e chamam as senhas
		for(i=0;i<25;i++) {
			if(caixa[i].flag_caixa == 1 && caixa[i].flag_ocupado == 0) {
				if(pesquisaElemento(comum,pass)!=NULL) {
	        			printf("\n|------------------ Tempo de atendimento das Filas -------------------|\n");
						printf("|------- Fila comum: %d - Fila rapida: %d - Fila preferencial: %d ------|\n\n",tempoFila(comum),tempoFila(rapido),tempoFila(preferencial));
						printf("Caixa[%d] - senha: %d\n\n",i,pass);
						caixa[i].data = time(&segundos) + comum->tmp_atendimento;
						tempo_dia += comum->tmp_atendimento;
	        			caixa[i].flag_ocupado = 1;
	        			removeInicio(&comum);
	        			pass++;
				} else if(pesquisaElemento(rapido,pass) != NULL) {
						printf("\n|------------------ Tempo de atendimento das Filas -------------------|\n");
						printf("|------- Fila comum: %d - Fila rapida: %d - Fila preferencial: %d ------|\n\n",tempoFila(comum),tempoFila(rapido),tempoFila(preferencial));
						printf("Caixa[%d] - senha: %d\n\n",i,pass);
						caixa[i].data = time(&segundos) + rapido->tmp_atendimento;
						tempo_dia += rapido->tmp_atendimento;
						caixa[i].flag_ocupado =1;
						removeInicio(&rapido);
						pass++;
				} else if(pesquisaElemento(preferencial,pass) != NULL) {
					printf("\n|------------------ Tempo de atendimento das Filas -------------------|\n");
					printf("|------- Fila comum: %d - Fila rapida: %d - Fila preferencial: %d ------|\n\n",tempoFila(comum),tempoFila(rapido),tempoFila(preferencial));
					printf("Caixa[%d] - senha: %d\n\n",i,pass);
					caixa[i].data = time(&segundos) + preferencial->tmp_atendimento;
					tempo_dia += preferencial->tmp_atendimento;
					caixa[i].flag_ocupado = 1;
					removeInicio(&preferencial);
					pass++;	
				} else {
					printf("Atendimento do Dia finalizado\n\n");
					return ;
				}
			}
		}
		
		// Condição disparada a cada 15s 
		if(tempo_total == 15) {
			if(tempoFila(preferencial) > 15 ) {
				abrirCaixa();
			} else if(tempoFila(rapido) > 25) {
				abrirCaixa();
			} else if(tempoFila(comum) > 40) {
				abrirCaixa();
			}
		}
	
		Sleep(1000);
    }
}

//Abre um novo caixa
void abrirCaixa() {
	int i;
	for(i=0;i<25;i++) {
		if(caixa[i].flag_caixa == 0) {
			caixa[i].flag_caixa = 1;
			printf("Abriu caixa [%d]\n\n",i);
			break;
		}
	}
	
	return;
}
//Tempo de atendimento diario
void tempoDia() {
	printf("Tempo medio atendimento: %d\n",tempo_dia/CLIENTES); 
}

int tempoFila(Fila *fila) {
	Fila *atual = fila;
	int t_atendimento = 0;

	if(filaVazia(fila)) {
		return 0;
	}

	while(atual != NULL) {
		t_atendimento += atual->tmp_atendimento;
		atual = atual->proximo;
	}

	return t_atendimento;
}

Fila * pesquisaElemento(Fila *lista, int valorProcurar) {
	Fila *procura = lista;
	if(filaVazia(procura)){
		return NULL;
	}

	while(procura != NULL) {
		if(procura->senha == valorProcurar) {
			return procura;
		} else {
			procura = procura->proximo;
		}
	}
	
	return NULL;
}
