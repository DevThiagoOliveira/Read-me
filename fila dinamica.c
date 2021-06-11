#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
	int dado;
	struct NO* prox;
	
}NO;

typedef struct FILA{
	NO* inicio;
	NO* fim;
}FILA;

FILA* f;

void enfileirar(); //push_back
int desenfileirar(); //pop

int main(void){
	
	
	printf(" %d ",f->fim);
	
	system("pause");
	return 0;
}

void enfileirar(NO* p,){  // push_back
	NO* novo_element = (NO *) malloc(sizeof(NO));
	
	novo_element->dado = rand()%100;
	novo_element->prox = NULL;
	if(f->inicio == NULL){
		f->inicio = novo_element;
	}else{
		f->fim->prox = novo_element;
	}
	f->fim = novo_element;
}

int desenfileirar(){ // pop
	NO* novo_element = f->inicio;
	int dado;
	if(novo_element != NULL){
		f->inicio = novo_element->prox;
		novo_element->prox = NULL;
		dado = novo_element->dado;
		free(novo_element);
		return dado;
	}
}


