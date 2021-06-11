#include <stdio.h>
#include <stdlib.h>

#define size 5

typedef struct fila 
{
  int dado[size];
  int start,end;

}line;

struct fila fila;

void push_back(int element[]);
void desenfileirar();

//main
int main(void) {
  
  int inf[size],d,i;

  printf("\n   informe numeros \n");
  
	for(i=0; i < size; i++)
	{
		printf("\n :");
		scanf("%d",&inf[i]);
	}

	push_back(inf);

	printf("fila :");
	for(int i=0; i < size && fila.dado != 0; i++)
		printf(" %d ",fila.dado[i]);
	
	
	desenfileirar();
	
	printf("\n\n");
	printf("fila :");
	for(int i=0; i < size; i++)
		printf(" %d ",fila.dado[i]);
	
	return 0;
}

//Enfileirar
void push_back(int element[])
{
  if(fila.end == size)
  {
    printf("Line Full!!\n");
  }
  else
  {
  	int i;
  	for(i = 0; i < size; i++)
  	{
    	fila.dado[fila.end] = element[i];
    	fila.end++;
    }
  }
}

//Desenfileirar
void desenfileirar()
{
  int element;
  if(fila.end == fila.start)
  {
    printf("Erro!!\nFila está cheia");
  }
  else
  {
    for(int i =0; i< size;i++)
    {
      fila.dado[i] = fila.dado[i+1];
    }
    fila.dado[fila.end] = 0;
    fila.end--;
  }
}

