#include <stdio.h>
#include <locale.h>

// Escreva um algoritimo que solicite ao usuario N valores numericos e ao final apresente:
// Vers�o 1: O maior e menor

int main () {
	setlocale(LC_ALL, "portuguese");
	float Valor, Maior, Menor;
	int Resposta, Qtd=0;
	
	do {
		Qtd++;
		// Entrada de dados
		printf(" Informe o %i Valor: ", Qtd);
		scanf("%f", &Valor);
		// Processamento de dados
		if (Qtd==1 || Valor > Maior)
			Maior = Valor;
		if(Qtd ==1 || Valor < Menor)
			Menor = Valor;
		printf(" Deseja informar o proximo? (1)Sim - (2)N�o \n");
		scanf("%i", &Resposta);
	} while(Resposta==1);
	
	// Saida de dados   
	printf("\n O maior numero �: %0.2f", Maior);
	printf("\n O menor numero �: %0.2f", Menor);
}
