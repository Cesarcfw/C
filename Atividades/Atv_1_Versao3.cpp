#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
 /* Ver:1 -- O maior e menor idade + media
 	Ver:2 -- calcule a moda e a mediana
 	ver:3 -- Implementar Nome, Idade, Sexo e três notas de N alunos 
 			 Percentual de alunos aprovados.
 			 fazer tudo em um struct só.
 			 colocar limite de idade quando solicitado aos alunos.
 			 limitar variaveis a respectivas formas de dados
 */
 
 struct Aluno{
 	char Nome[50];
 	int Idade;
 	char sexo;
 	float NotaAluno[10];
 	bool aprovacao;
 };
 
 int main() {
    setlocale(LC_ALL, "portuguese");
    struct Aluno Turma[100];
    float Valor, Maior, Menor, Soma = 0, Media, Moda, Mediana;
    int Resposta, Qtd = 0;
    float valores[100];

    do {
        Qtd++;
        do{
        printf("Informe a %i idade: \n", Qtd);
        scanf("%f", &Valor);
       
		
		if (Valor < 0 || Valor > 122){
        	printf("Digite novamente com um valor real \n");
		}
		
	} while(Valor < 0 || Valor > 122);   
        valores[Qtd - 1] = Valor;
        Soma += Valor;
        
        if (Qtd == 1 || Valor > Maior)
            Maior = Valor;
                                                                                                                                                                                                                                                                                                                                                                                       
        if (Qtd == 1 || Valor < Menor)
            Menor = Valor;
            
        printf("Deseja informar outra? (1)Sim (2)Não \n");
        scanf("%i", &Resposta);  
		     
	} while (Resposta == 1);

    Media = Soma / Qtd;

    calcModa(valores, Qtd, &Moda);

    calcMediana(valores, Qtd, &Mediana);
  
    printf("\nA maior idade é: %0.2f", Maior);
    printf("\nA menor idade é: %0.2f", Menor);
    printf("\nA média é: %0.2f", Media);
    printf("\nA moda é: %0.2f", Moda);
    printf("\nA mediana é: %0.2f", Mediana);

}
