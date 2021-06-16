#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Constante
#define tamanho 100
#define E 0
#define D 1
#define R -1

//Estrutura
struct No{
	char Dado;
	int Esquerda;
	int Direita;
	int Pai;	
};

//Variaveis
struct No Arvore[tamanho];
int lado, indice = 0;
int escolha=-1;
char pai, no;

//Prototipação
void ArvoreInserir(int pai, char dado, int lado);
int ArvoreProcura(char dado);
void MenuMostrar();

int main(){
	setlocale(LC_ALL, "Portuguese");	
	
	int temp;
	do {
		MenuMostrar();
		scanf("%d",&escolha);
		switch(escolha){
			
			case 1:
				printf("Digite o valor do Pai: ");
				scanf("%c",&pai);
				scanf("%c",&pai);
				printf("Digite o valor do NO: ");
				scanf("%c",&no);
				scanf("%c",&no);
				printf("Digite o lado da subarvore (E=%d/D=%d/R=%d) : ",E,D,R);
				scanf("%d",&lado);
				
				temp = ArvoreProcura(pai);
				ArvoreInserir(temp,no,lado);
				break;
			
			case 2:
				printf("Digite o valor do No: ");
				scanf("%c",&no);
				scanf("%c",&no);
				temp = ArvoreProcura(no);
				printf("No %c\nFilho Esquerda: %c\nFilho Direita: %c\n\n",Arvore[temp].Dado,Arvore[Arvore[temp].Esquerda].Dado,Arvore[Arvore[temp].Direita].Dado);
				system("pause");
				break;
		}
	}while(escolha != 0);
	system("pause");
	
	return 0;
}

void ArvoreInserir(int pai, char dado, int lado){
	
	switch(lado){
		
		case E:
			Arvore[pai].Esquerda = indice;
			Arvore[indice].Dado = dado;
			Arvore[indice].Pai = pai;
			Arvore[indice].Esquerda = -1;
			Arvore[indice].Direita = -1;
			indice++;
			break;
		
		case D:
			Arvore[pai].Direita = indice;
			Arvore[indice].Dado = dado;
			Arvore[indice].Pai = pai;
			Arvore[indice].Esquerda = -1;
			Arvore[indice].Direita = -1;
			indice++;
			break;
		
		case R:
			Arvore[pai].Dado = dado;
			Arvore[indice].Pai = -1;
			Arvore[indice].Esquerda = -1;
			Arvore[indice].Direita = -1;
			indice++;
			break;
	}
}


int ArvoreProcura(char dado){
	int i;
	
	if(indice != 0){
		for(i = 0; i < indice; i++){
			if(Arvore[i].Dado == dado){
				return i;
			}
		}
	}
	else{
		return 0;
	}
}

void MenuMostrar(){
	system("cls");
	int i;
	printf("\n| ");
	for(i = 0; i < indice; i++){
		printf(" %c ",Arvore[i].Dado);
	}
	printf(" |\n");
	printf("\n1 - Inserir um No na Arvore");
	printf("\n2 - Pesquisar um No na Arvore");
	printf("\n0 - Sair...\n\n");

}
