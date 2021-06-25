#include <stdio.h>
#include <stdlib.h>

#define maximo 10

int definirtamanho = 0;
int grafo[maximo];
int matrizAbjacencia[maximo] [maximo];

//Define o número de vértices do grafo
int grafotamanho(){
    printf("Escolha a quantidade de vertices do grafo: ");
    scanf("%d", &definirtamanho);
    return definirtamanho;
}

void grafoinsercao();
void desenhargrafo();
void grafodesenharmatriz();
void menumostrar();

int main(void) {

	grafotamanho();
	menumostrar();
	desenhargrafo();
    grafodesenharmatriz();
	grafoinsercao();
	grafodesenharmatriz();
	desenhargrafo();

    return 0;
}

void grafoinsercao(){
    int numero1, numero2;
    printf("Escolha o primeiro destino que deseja inserir no vértice entre 0 a %d :", definirtamanho-1);
    scanf("%d",&numero1);
    printf("Escolha o segundo destino que deseja inserir no vértice entre 0 a %d :" ,definirtamanho-1);
    scanf("%d",&numero2);

    if(numero1 > definirtamanho-1 || numero2 > definirtamanho-1 || numero1 < 0 || numero2 < 0){
        printf("Destino invalido!!.\n As coordenadas devem ser menor que %d e maior que 0.", definirtamanho-1);
    }
	else{
        matrizAbjacencia[numero1][numero2] = 1;
		matrizAbjacencia[numero1][numero2] = 1;
    }
}

void graforemover(){
	int numero1, numero2;
	
	printf("Escolha o primeiro destino que deseja remover no vértice entre 0 a %d :",definirtamanho -1);
	scanf("%d",&numero1);

	printf("Escolha o segundo destino que deseja remover no vértice entre 0 a %d :",definirtamanho -1);
	scanf("%d",&numero2);

	if(numero1 < definirtamanho-1 || numero2 < definirtamanho-1 || numero1 < 0 || numero2 < 0){
		printf("Destino invalido!!.\n As coordenadas devem ser menor que %d e maior que 0.", definirtamanho-1);
	}
	else{
		matrizAbjacencia[numero1][numero2] = 0;
		matrizAbjacencia[numero1][numero2] = 0;
	}
}

void desenhargrafo(){
	//desenhando lista de vértices
	printf("Listas de vértices \n |");
	for(int i = 0; i < definirtamanho; i++){
		printf(" %d ",grafo[i]);
	}
	printf(" |\n\n");
}

void grafodesenharmatriz(){
	//desenhando a matriz de abjacencia
	printf("Matriz de Abjacencia\n| \n");
	for(int i = 0; i < definirtamanho; i ++){
		for(int j = 0; j < definirtamanho; j++){
			printf("  %d ",matrizAbjacencia[i][j]);
		}
		printf("\n");
	}
	printf(" |\n\n");
}

void menumostrar(){
	printf("\nEscolha uma opção: \n");
	printf("1 - Inserir aresta\n");
	printf("2 - Remover aresta\n");
	printf("0 - Sair\n\n");
}