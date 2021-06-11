#include <stdio.h>
#include <stdlib.h>
//para utilizar o malloc devese estar usando a biblioteca lib

#define MAX 30

void alocacaodinamica();
void alocacaodinamicavetor();

int main(){
	
	//alocação estatica > [int n = 10;]
	alocacaodinamica();
	
	alocacaodinamicavetor();
	
	system("pause");
	return 0;
}

void alocacaodinamica(){
	
	int *p;
	
	p = (int *)malloc(sizeof(int)); // alocar um bloco de bytes na memoria ou reservar um tamanho X na memoria
	if(p == NULL)
	{
		printf("\n\tErro!! (A memória em seu computador está cheia)\n");
	}
	else
	{
		printf("\n\tdigite um valor \n\t: ");
		scanf("%d",&*p);
		printf("\n\tp : %d\n\n", *p);
		free(p); // libera o bloco que eu reservei no metodo malloc() ou seja ele vai liberar 4 bytes que eu manti separado na minha memoria ram e ela voltara a ter o espaço total
	}
	
}

void alocacaodinamicavetor(){
	
	int * vetordinamico[MAX];
	int i ,tamanhovetor = 10;
	
	vetordinamico[MAX] = (int *)malloc(sizeof(int) * tamanhovetor); // caso eu queira um vetor de alocação dinamica basta multiplicar o tamanho do dados pelo tamanho do vetor
	if(vetordinamico == NULL)
	{
		printf("\n\tErro!! (A memória em seu computador está cheia)\n");
	}
	else
	{
		for(i = 0;i < 3;i++)
		{
			printf("\n\tdigite um valor \n\t: ");
			scanf("%d",&*vetordinamico[i]);
		}
		printf("\n\tp : [%d] [%d] [%d] \n\n", *vetordinamico[0],vetordinamico[1],vetordinamico[2]);
		free(vetordinamico); // liberando o espaço na memoria que eu reservei;
	}
	
}
