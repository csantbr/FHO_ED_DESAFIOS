#include <stdio.h>
#include "A12operac.c"
 
 /*Grupo: 
 	Caio Santoro    RA 105891
 	Guilherme Viola RA 88206
 	Leandro Silva   RA 88617
 */
int main () {
    Pilha *inicio;
    
	srand((unsigned)time(NULL));
	
	//Iniciaza Pilha
    inicializaPilha(&inicio);
    
    //Adiciona veiculos
   	veiculos(&inicio);
   	veiculos(&inicio);
   	veiculos(&inicio);
   	veiculos(&inicio);
   	veiculos(&inicio);
   	veiculos(&inicio);
   	veiculos(&inicio);
   	veiculos(&inicio);
   	veiculos(&inicio);
   	veiculos(&inicio);
   	veiculos(&inicio);
   	veiculos(&inicio);
   	veiculos(&inicio);
   	veiculos(&inicio);
   	veiculos(&inicio);
   	veiculos(&inicio);
   	veiculos(&inicio);
   	veiculos(&inicio);

    // Informa as placas dos veiculos no sentido port�o at� o final do estacionamento
    imprimePilha(inicio);
    
    //Procura o carro que ser� removido e faz a remo��o
   	pesquisaElemento(&inicio);
   	
   	//Conta a quantidade de carros no estacionamento
   	contagemPilha(inicio);

    return 0;
}