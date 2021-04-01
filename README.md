#include<stdio.h>

#include<stdlib.h>

#include<locale.h>

#include<time.h>

#include<string.h>

#include<conio.h>


#define MAX 50

typedef struct cadastro{

	char nome[MAX];
	char nomeAutor[MAX];
	char editora[MAX];
	int edicao;
	int quantidade;
	int ISBN;
	int ano;
	char tipo[MAX];
	int caixa;
	
} Inserir;


void cabecalho();

void cadastrar();

void listarTodos();

void saindo();

void caixa();

void pesquisarNome();

void listarTipo();


int main(){

	Inserir cadastros[MAX];
	setlocale(LC_ALL,"Portuguese");
	
	int menu;
	char menu2 = 's';
	
	do{
		cabecalho();
		printf("\t1 - Abrir caixa\n");
		printf("\t2 - Inserir\n");
		printf("\t3 - Listar Todos\n");
		printf("\t4 - Pesquisar por nome\n");
		printf("\t5 - Listar por tipo\n");
		printf("\t0 - Sair\n\nComando:");
		fflush(stdin);
		scanf("%d",&menu);
		system("cls");
		switch(menu){
			
			case 1:
				do{
					caixa();
					system("cls");
					printf("\nDeseja pesquisar por caixa novamente ? [s] ou [n] \n\tComando:");
					fflush(stdin);
					scanf("%c",&menu2);
					system("cls");
				}while((menu2 == 's' ) || (menu2 == 'S'));
				break;
			case 2:
				do{
					cadastrar();
					system("cls");
					printf("\nDeseja cadastrar novamente ? [s] ou [n] \n\tComando:");
					fflush(stdin);
					scanf("%c",&menu2);
					system("cls");
				}while((menu2 == 's' ) || (menu2 == 'S'));
				break;
			case 3:
				do{
					listarTodos();
					system("cls");
					printf("\nDeseja listar todos novamente ? [s] ou [n] \n\tComando:");
					fflush(stdin);
					scanf("%c",&menu2);
					system("cls");
				}while((menu2 == 's' ) || (menu2 == 'S'));
				break;
			case 4:
				do{
					pesquisarNome();
					system("cls");
					printf("\nDeseja pesquisar por nome novamente ? [s] ou [n] \n\tComando:");
					fflush(stdin);
					scanf("%c",&menu2);
					system("cls");
				}while((menu2 == 's' ) || (menu2 == 'S'));
				break;
			case 5:
				do{
					listarTipo();
					system("cls");
					printf("\nDeseja pesquisar por tipo novamente ? [s] ou [n] \n\tComando:");
					fflush(stdin);
					scanf("%c",&menu2);
					system("cls");
				}while((menu2 == 's' ) || (menu2 == 'S'));
				break;
			case 0:
				saindo();
				break;
			default : printf("\n\tComando não reconhecido\n"); 
					getch();
					system("cls");
				break;
		}
		printf("\nDeseja retornar ao menu ?[s] ou [n]\n\tComando:");
		fflush(stdin);
		scanf("%c",&menu2);
		system("cls");
	}while((menu2 == 's' ) || (menu2 == 'S'));
	system("pause");
	return 0;
}

void listarTipo(){	

// Pesquisar por tipo de exemplar

	FILE* arquivo;
	
	arquivo = fopen("mapaAlgoritmo2.txt","r+");
	
	Inserir rtr;
	char tipo[30];
	char menu2 = 's';
	
		cabecalho();
		if(arquivo == NULL){
			printf("\n\tProblemas na abertura do arquivo!\n");
		}else{
			printf("\n\to que deseja listar livros ou revistas ? \n\n Listar: ");
			fflush(stdin);
			gets(tipo);
			
			while(fread(&rtr, sizeof(Inserir), 1,arquivo)==1){
				if(strcmp(tipo,rtr.tipo)==0 ){
					printf("\nNome:%s \n",rtr.nome);
					printf("NomeAutor: %s \n",rtr.nomeAutor);
					printf("Editora: %s \n",rtr.editora);
					printf("ISBN: %d \n",rtr.ISBN);
					printf("Ano: %d \n",rtr.ano);
					printf("Edição: %d \n",rtr.edicao);
					printf("Quantidade: %d \n",rtr.quantidade);
					printf("Tipo: %s \n",rtr.tipo);
					printf("Armazenado na caixa: %d \n",rtr.caixa);
					printf("\n-------------------------------------\n");
				}		
			}
		}
			getch();
			system("cls");
	fclose(arquivo);
}

void caixa(){                                                                                   //Pesquisar por caixa

	FILE* arquivo;
	
	arquivo = fopen("mapaAlgoritmo2.txt","r+");
	
	Inserir rtr;
	int pesquisaCaixa;
	char menu2 = 's';
	
		cabecalho();
		if(arquivo == NULL){
			printf("\n\tProblemas na abertura do arquivo!\n");
		}else{
			printf("\n\tQual caixa deseja abrir ?\n\n Caixa : ");
			fflush(stdin);
			scanf("%d",&pesquisaCaixa);
			
			while(fread(&rtr, sizeof(Inserir), 1,arquivo)==1){
				if(pesquisaCaixa == rtr.caixa){
					printf("\nNome:%s \n",rtr.nome);
					printf("NomeAutor: %s \n",rtr.nomeAutor);
					printf("Editora: %s \n",rtr.editora);
					printf("ISBN: %d \n",rtr.ISBN);
					printf("Ano: %d \n",rtr.ano);
					printf("Edição: %d \n",rtr.edicao);
					printf("Quantidade: %d \n",rtr.quantidade);
					printf("Tipo: %s \n",rtr.tipo);
					printf("Armazenado na caixa: %d \n",rtr.caixa);
					printf("\n-------------------------------------\n");
				}		
			}
		}
			getch();
			system("cls");
	fclose(arquivo);	
}

void cabecalho(){	

//Cabeçalho

	printf("+------------------------------------------------+");
	printf("\n| Nome:Thiago Augusto Querino de Oliveira        |\n| RA:20060357-5                                  |\n| Curso:Bacharelado em Engenharia de Software    |\n");  
	printf("+------------------------------------------------+\n");
	
}

void pesquisarNome(){	

//Pesquisar por nome

	FILE* arquivo;
	
	arquivo = fopen("mapaAlgoritmo2.txt","r+");
	
	Inserir rtr;
	char nome[30];
	char menu2 = 's';
	
		cabecalho();
		if(arquivo == NULL){
			printf("\n\tProblemas na abertura do arquivo!\n");
		}else{
			printf("\n\tDigite o nome do livro ou revista que queira pesquisar\n\n Pesquisa: ");
			fflush(stdin);
			gets(nome);
			
			while(fread(&rtr, sizeof(Inserir), 1,arquivo)==1){
				if(strcmp(nome,rtr.nome)==0 ){
					printf("\nNome:%s \n",rtr.nome);
					printf("NomeAutor: %s \n",rtr.nomeAutor);
					printf("Editora: %s \n",rtr.editora);
					printf("ISBN: %d \n",rtr.ISBN);
					printf("Ano: %d \n",rtr.ano);
					printf("Edição: %d \n",rtr.edicao);
					printf("Quantidade: %d \n",rtr.quantidade);
					printf("Tipo: %s \n",rtr.tipo);
					printf("Armazenado na caixa: %d \n",rtr.caixa);
					printf("\n-------------------------------------\n");
				}		
			}
		}
			getch();
			system("cls");
	fclose(arquivo);
}

void saindo(){		

//Encremento de Saida

	printf("\n\n\tSaindo.");
	Sleep (1000);
	system("cls");
	printf("\n\n\tSaindo..");
	Sleep (1000);
	system("cls");
	printf("\n\n\tSaindo...");
	Sleep (1000);
	system("cls");
}

void cadastrar(){	

//Cadastro de exemplares

	FILE* arquivo;
	Inserir rtr;
	
	arquivo = fopen("mapaAlgoritmo2.txt","a+");
	
	char menu2 = 's';
	
	if(arquivo == NULL){
		printf("\n\tProblemas na abertura do arquivo!\n");
	}else{ 
			printf("\n\n\t1 - Título :");
			fflush(stdin);
			gets(rtr.nome);
			printf("\n\n\t2 - Nome do Autor :");
			fflush(stdin);
			gets(rtr.nomeAutor);
			printf("\n\n\t3 - Editora :");
			fflush(stdin);
			gets(rtr.editora);
			printf("\n\n\t4 - ISBN :");
			fflush(stdin);
			scanf("%d",&rtr.ISBN);
			printf("\n\n\t5 - Ano :");
			fflush(stdin);
			scanf("%d",&rtr.ano);
			printf("\n\n\t6 - Edição :");
			fflush(stdin);
			scanf("%d",&rtr.edicao);
			printf("\n\n\t7 - Quantidade :");
			fflush(stdin);
			scanf("%d",&rtr.quantidade);
			printf("\n\n\t8 - Tipo(livro ou revista) :");
			fflush(stdin);
			gets(rtr.tipo);
			printf("\n\n\t9 - Armazenar em qual caixa :");
			fflush(stdin);
			scanf("%d",&rtr.caixa);
			
			fwrite(&rtr, sizeof(Inserir), 1,arquivo);
							
	}
	fclose(arquivo);
}

void listarTodos(){		

//Listar todos os exemplares

	FILE* arquivo;
	Inserir rtr;
	
	cabecalho();
	arquivo = fopen("mapaAlgoritmo2.txt","r+");
		if(arquivo == NULL){
			printf("\n\tProblemas na abertura do arquivo!\n");
		}else{
			while(fread(&rtr,sizeof(Inserir), 1,arquivo)==1){
				
				printf("\nNome:%s \n",rtr.nome);
				printf("NomeAutor: %s \n",rtr.nomeAutor);
				printf("Editora: %s \n",rtr.editora);
				printf("ISBN: %d \n",rtr.ISBN);
				printf("Ano: %d \n",rtr.ano);
				printf("Edição: %d \n",rtr.edicao);
				printf("Quantidade: %d \n",rtr.quantidade);
				printf("Tipo: %s \n",rtr.tipo);
				printf("Armazenado na caixa: %d \n",rtr.caixa);
				printf("\n-------------------------------------\n");
			}
		}
	fclose(arquivo);
	getch();
	system("cls");
}
