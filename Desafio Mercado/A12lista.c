#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "A12operac.c"

/*Grupo: 
 	Caio Santoro    RA 105891
 	Guilherme Viola RA 88206
 	Leandro Silva   RA 88617
*/

int main () {
	srand(time(NULL));
	
	//Cria as filas
	Fila *comum;
	Fila *rapido;
	Fila *preferencial;
	
	//Inicializa as Filas
	inicializaFila(&comum);
	inicializaFila(&rapido);
	inicializaFila(&preferencial);
	
	//Carrega as informaçoes dos caixas de 0 a 24
	inicializaCaixas(&caixa);
	
	//Cria os clientes e distribui entre as filas randomicamente
	distribuirFila(&comum, &rapido, &preferencial);
	
	//Inicia o atendimento	
	iniciar(&comum, &rapido, &preferencial);
	
	//Tempo médio de atendimento do dia
	tempoDia();

    return 0;
}
