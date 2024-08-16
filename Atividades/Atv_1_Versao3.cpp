#include <stdio.h>
#include <locale.h>
 /* Ver:1 -- O maior e menor idade + media
 	Ver:2 -- calcule a moda e a mediana
 */
 
 void calcModa(float Qtds[], int valor, float *moda) {
    int maxCount = 0;
    for (int i = 0; i < valor; ++i) {
        int count = 0;
        for (int j = 0; j < valor; ++j) {
            if (Qtds[j] == Qtds[i])
                ++count;
        }
        if (count > maxCount) {
            maxCount = count;
            *moda = Qtds[i];
        }
    }
}

void calcMediana(float Qtds[], int valor, float *mediana) {
    for (int i = 0; i < valor - 1; ++i) {
        for (int j = i + 1; j < valor; ++j) {
            if (Qtds[i] > Qtds[j]) {
                float temp = Qtds[i];
                Qtds[i] = Qtds[j];
                Qtds[j] = temp;
            }
        }
    }
    if (valor % 2 == 0)
        *mediana = (Qtds[valor / 2 - 1] + Qtds[valor / 2]) / 2;
    else
        *mediana = Qtds[valor / 2];
}

int main() {
    setlocale(LC_ALL, "portuguese");
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
