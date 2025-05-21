#include <stdio.h>
#include <locale.h>
/*
Escreva um algoritimo que permita ao usuario informar os vertices e valores de arestas em uma matriz de adjacencia (MA) 
e ao final o programa permita ao usuario percorrer rotas possiveis entre dois vertices
Apresentar um menu com opçoes ao usuario com as funcionalidades a seguir:
1: Inicializar Matriz;
2: Imprimir matriz;
3: Inserir valor na Matriz;
4: Identificar caminho;
5: Valor de teste;
6: Sair do programa;
*/

int Ordem, Matriz[100][100];

//função responsavel por limpar todas as arestas da matriz de adjacencia 
bool inicializarMatriz(int qtdVertices){
	for (int linhas=0; linhas<=qtdVertices; linhas++)
		for(int colunas=0; colunas<=qtdVertices; colunas++)
			Matriz[linhas][colunas] = 0; 
	return(true);
}

//Função responsavel por imprimir o menu de opções ao usuario
int imprimirMenu(){
	int Resposta;
	printf("\n Programa para percorrer Grafos");
	printf("\n 1: Inicializar Matriz;");
	printf("\n 2: Imprimir matriz;");
	printf("\n 3: Inserir valor na Matriz;");
	printf("\n 4: Identificar caminho;");
	printf("\n 5: Sair do programa;");
	printf("\n Informe a opção desejada: ");
	scanf("%i", &Resposta);
	return(Resposta);
}

bool inserirValorNaMatriz(int Origem, int Destino, int Valor){
	if (Origem == Destino){
		printf("\n Esse grafo não permite laços!");
		return (false);
	}
	if (Origem<1 or Destino<1 or Origem>Ordem or Destino>Ordem){
		printf("\n Origem ou Destino fora do Grafo!");
		return (false);
	}
	if (Valor<0 or Valor>100){
		printf("\n Valor da aresta fora do limite permitido!");
		return (false);
	}
	Matriz[Origem][Destino]= Valor;
	return(true);
}

void imprimirMatriz(int Ordem){
	/*
	REGRAS: 
			1: Precisa apresentar o cabeçalho de linhas e colunas
			2: Se o numero do cabeçalho for <10 imprimir com um 0 na frente
			3: Bloquear com XX os pontos iguais
			4: mostrar valor na conexão
	*/
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	int Opcao;
	do {
		Opcao = imprimirMenu();
		if(Opcao==1){ // Inicializar matriz
		printf("\n Informe a ordem do grafo: ");
		scanf("%i", &Ordem);
			if(inicializarMatriz(Ordem)){
				printf("\n Matriz inicializada com sucesso! \n");
	} else{
			printf("\n Matriz não inicializada!!! \n");
	}
		}else if(Opcao==2){ // Inserir valor na matriz
			printf("Informe o vértice de Origem: ");
			int Origem, Destino, Valor;
			scanf("%i", &Origem);
			printf("Informe o vértice de Destino: ");
			scanf("%i", &Destino);
			printf("Informe o valor da aresta: ");
			scanf("%i", &Valor);
			// Chamando a função que insere o valor na matriz
			if(inserirValorNaMatriz(Origem,Destino,Valor)){
				printf("\n Valor %i inserido na matriz na posição [%i, %i] com sucesso!", Valor, Origem, Destino);
			}
		}else if(Opcao==3){ // Imprimir a matriz
		/*
		ATIVIDADE: 
		OPÇÃO 3: IMPRIMIR A MATRIZ!
		*/
		}else if(Opcao==4){ // Identificar caminho
		
	
			
		}
		
	} while(Opcao<5); // Sair do programa
		
	
	
}
