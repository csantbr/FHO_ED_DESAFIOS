#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "A12header.h"

void inicializaPilha (Pilha **lista) {	
	*lista = NULL;
}

int pilhaVazia (Pilha *lista) {
	if(lista == NULL)
		return 1;
	
	return 0;
}

void imprimePilha (Pilha *lista) {
	Pilha *atual = lista;
	
	if(pilhaVazia(lista)){
		printf("Estacionamento vazio!!!\n");
		return;
	}
	
	printf("Veiculos no estacionamento: [ ");
	
	while(atual != NULL) {
		printf("%s ", atual->placa);
		atual = atual->proximo;
	}
	
	printf("]\n"); 
}

void veiculos(Pilha **lista) {
	char string[8];
	
	strcpy(string,gerarPlaca());
	insereTopo(lista, string);
}

/* funcao que insere um elemento Pilha inicio da lista -------------------- */
void insereTopo (Pilha **lista, char placa[]) {
	Pilha *novo;
	
	/* reserva espaco na memoria */
	novo = (Pilha *) malloc(sizeof(Pilha));
	strcpy(novo->placa, placa);
	
	/*se a lista está vazia, o próximo do novo nó aponta para nulo */
	if(pilhaVazia(*lista))
	    novo->proximo = NULL;
	    
	/* o próximo do novo nó aponta para o antigo primeiro nó da lista */    
	else
	    novo->proximo = *lista;
	
	/* o inicio da lista recebe o endereco do novo nó */
	*lista = novo;
}

void removeTopo (Pilha **lista) {
	Pilha *aux = *lista;
	
	if(pilhaVazia(*lista)) {
		printf("Nao eh possivel remover elemento. A lista esta vazia\n");
		return;	
	}
	 
	/* apontando o inicio para o segundo nó */
	*lista = aux->proximo;
	
	/* liberar mem�ria do antigo primeiro nó para o SO */
	free(aux);
}
 
void contagemPilha(Pilha *lista) {
	Pilha *atual = lista;
	int cont = 0;
	while ((atual != NULL)) {
    	
      	cont++;
        atual = atual->proximo; 
        	
	}

	printf("%d veiculos estacionados no momento\n", cont);
}

/* funcao que pesquisa por um elemento na lista ----------------------- */
void pesquisaElemento (Pilha **lista) {
    Pilha *atual = *lista;
    Pilha *anterior = *lista;
    
	Pilha *aux;
	Pilha *anteriorAux = aux;
    inicializaPilha(&aux);
	char valorPesquisar[8];
	
	gets(valorPesquisar);
    printf(" -> Pesquisando pela placa: %s\n", valorPesquisar);
    /* caso contrario, caminha na lista ate encontrar o elemento */
    while ((atual != NULL) && strcmp(atual->placa,valorPesquisar)) {
        insereTopo(&aux,atual->placa); 
        anterior = atual; 
        atual = atual->proximo; 
		removeTopo(&anterior);	
	}

	if(atual == NULL) {
		printf("Placa n�o encontrada\n");
	} else {
		printf("Veiculo removido\n");
		removeTopo(&atual);
		
		while ((aux != NULL)){
	        insereTopo(&atual,aux->placa);
	        anteriorAux = aux;
	        aux = aux->proximo;
	        removeTopo(&anteriorAux);
		   	
		}

		*lista = atual;
	}
} /* fim da funcao pesquisaElemento */

char placa[8];
char* gerarPlaca() {
	int i, r;
	
	for(i = 0; i < 3; i++) {
		r = rand() % 25;	
		placa[i] = r + 65;
	}
	
	for(i = 3; i < 7; i++) {
		r = rand() % 9;	
		placa[i] = r + 48;
	}
	
	printf("Gerada a Placa: %s\n", placa);
	return placa;
}
