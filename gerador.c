#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_ALFABETO 26
#define INICIO_ALFABETO 'a'
#define TAMANHO_LIVROS 8

int main(void){

	int n, m, e, l, k;
	int i, j;

	int randomChar;
	
	FILE *saida;
	saida = fopen("pesquisa", "w");

	printf("Digite os primeiros 5 inteiros(N, M, E, L e K)\n");
	scanf("%d %d %d %d %d", &n, &m, &e, &l, &k);
	fprintf(saida, "%d %d %d %d %d\n", n, m, e, l, k);
	
	//scanf("%d", &k);

	srand((unsigned)time(NULL));

	for(i = 0; i < n; i++){
		
		for(j = 0; j < TAMANHO_LIVROS; j++){

			randomChar += rand()%TAMANHO_ALFABETO + INICIO_ALFABETO;
			fprintf(saida, "%c", (char)randomChar);
			randomChar = 0;
		}

		fprintf(saida, " %d\n", rand()%2);
	}

	for(i = 0; i < k; i++){
		
		for(j = 0; j < TAMANHO_LIVROS; j++){

			randomChar += rand()%TAMANHO_ALFABETO + INICIO_ALFABETO;
			fprintf(saida, "%c", (char)randomChar);
			randomChar = 0;
		}

		fprintf(saida, "\n");
	}

	return 0;
}
