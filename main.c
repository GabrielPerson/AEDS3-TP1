//
// Created by person on 13/09/16.
//

#include <stdio.h>
#include "ordenacao.h"
#include "busca.h"

int main(){

    int Num_livros = 0, Max_memoria = 0, Num_estantes = 0;
    int Max_livro_estante = 0, Num_consultas = 0;
    int i = 0;
    int Num_arquivos_temporarios = 0;

    scanf("%d %d %d %d %d", &Num_livros ,&Max_memoria ,&Num_estantes ,&Max_livro_estante ,&Num_consultas);

    FILE* arq_entrada = fopen("entrada", "wb");
    FILE* arq_ordenado;

    if(arq_entrada == NULL) printf("*****ERRO NA LEITURA DO ARQUIVO*****");

    for(i = 0; i < Num_livros; i++)
        Le_entrada(arq_entrada);

    fclose(arq_entrada);


    arq_entrada = fopen("entrada", "rb");

    Num_arquivos_temporarios = Cria_arquivos_temporarios(arq_entrada, Max_memoria);

    fclose(arq_entrada);

    remove("entrada");

    Merge_sort(Num_arquivos_temporarios);

    arq_ordenado = fopen("livros_ordenados","rb");

    Cria_estantes(arq_ordenado,Num_estantes,Max_livro_estante);

    fclose(arq_ordenado);

    Busca(Num_consultas, Num_estantes);

    return 0;
}