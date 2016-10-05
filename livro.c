//
// Created by person on 14/09/16.
//

#include "livro.h"
#include <stdlib.h>
#include <string.h>

Livro_t** Aloca_vetor(int Max_memoria){

    int i;
    Livro_t** vetor;

    vetor = (Livro_t**) calloc(Max_memoria, sizeof(Livro_t*));
    for(i = 0; i < Max_memoria; i++) {
        vetor[i] = (Livro_t*) calloc(1, sizeof(Livro_t));
    }

    return vetor;
}

void Apaga_vet_livros(Livro_t** vetor_livros, int tam_memoria){

    int i;

    for(i = 0; i < tam_memoria; i++) {
        Apaga_livro(vetor_livros[i]);
        vetor_livros[i] = NULL;
    }

    free(vetor_livros);
}

void Apaga_livro(Livro_t* liv){

    free(liv);

    liv = NULL;
}

void Passa_valores_livro(Livro_t* liv, char* titulo, char disponivel){

    size_t i = 0;
    size_t tam_titulo = 0;

    tam_titulo = strlen(titulo);

    for(i =0; i < tam_titulo; i++)
        liv->titulo[i] = titulo[i];

    liv->dispovivel = disponivel;

}

void Le_entrada(FILE* entrada){

    char titulo_aux[51], disponivel_aux;
    Livro_t* livro_aux;

    scanf("%s %c\n", titulo_aux, &disponivel_aux);
    livro_aux = (Livro_t*)calloc(1, sizeof(Livro_t));
    Passa_valores_livro(livro_aux,titulo_aux,disponivel_aux);
    fwrite(livro_aux, sizeof(*livro_aux),1,entrada);
    Apaga_livro(livro_aux);

}