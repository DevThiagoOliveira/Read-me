#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define infinito 9999;
#define MAX 5

int G[MAX][MAX];

void dijkstra(int Grafo[MAX][MAX], int tamanhografo, int nodeinicial);

//Main
int main() {
	setlocale(LC_ALL, "portuguese");

	int nodeinicial;

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			G[i][j] = -1;
		}
	}

	G[0][1] = 2 * 100;
	G[0][2] = 0 * 100;
	G[1][3] = 0 * 100;
	G[1][4] = 6 * 100;
	G[2][1] = 0 * 100;
	G[2][4] = 3 * 100;
	G[3][4] = 5 * 100;

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			printf(" %d ", G[i][j]);
		}
		printf("\n");
	}

	nodeinicial = 0;

	dijkstra(G, MAX, nodeinicial);
	
	printf("\n\n\n");
	return 0;
}

void dijkstra(int Grafo[MAX][MAX], int tamanhografo, int nodeinicial) {

	int i, j;
	int custo[tamanhografo][tamanhografo], distancia[tamanhografo], pred[tamanhografo];
	int visitado[tamanhografo], cont, distanciaminima, proximono;

	// Busca valores e atribui a eles um valor muito alto
	for (i = 0; i < tamanhografo; i++)
		for (j = 0; j < tamanhografo; j++)
			if (Grafo[i][j] == -1) {
				custo[i][j] = infinito;
			}
			else {
				custo[i][j] = Grafo[i][j];
			}

	// Visita os nos e verifica quais não foram visitados
	for (int i = 0; i < tamanhografo; i++) {
		distancia[i] = custo[nodeinicial][i];
		pred[i] = nodeinicial;
		visitado[i] = 0;
	}

	// seta a distancia inicial como 0 e o primeiro visitado igual a 1
	distancia[nodeinicial] = 0;
	visitado[nodeinicial] = 1;
	cont = 1;

	// atribui os custos as distancias minimas
	while (cont < tamanhografo - 1) {
		distanciaminima = infinito;

		for (int i = 0; i < tamanhografo; i++)
			if (distancia[i] < distanciaminima && !visitado[i]) {// se a distancia for menor que 999999 e não visitado atribui o valor que está contido em custo
				distanciaminima = distancia[i];
				proximono = i;
			}

		//verifica se existe melhor caminho atraves do proximo node

		visitado[proximono] = 1; // atribui o proximo no visitado 1

		for (i = 0; i < tamanhografo; i++) {

			if (!visitado[i]) { // se o proximo no visitado for 0 não visitado
				if (distanciaminima + custo[proximono][i] < distancia[i]) { // se a soma do menor caminho mais o custo for menor que a distancia o valor atribuido ao no que voce quer visitar

					distancia[i] = distanciaminima + custo[proximono][i];
					pred[i] = proximono;
				}
			}

			cont++;

		}

		//imprimir	o caminho e a distancia de cada node
		for (i = 0; i < tamanhografo; i++) {
			if (i != nodeinicial) {
				printf("\nDistancia do no %d até %d custo: %d",nodeinicial+1 , i+1, distancia[i]);
				printf("\nCaminho = %d", i+1);

				j = i;

				do {
					j = pred[j];
					printf(" <- %d ", j+1);
				} while (j != nodeinicial);
			}
		}
	}
}