//
// Created by person on 15/09/16.
//

#include "arquivo.h"
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"

void Escreve_arquivo(Livro_t* livro,  FILE* arq){

    size_t i = 0;
    size_t tam_string = 0;

    tam_string = strlen(livro->titulo);

    for(i = 0 ; i < tam_string; i++)
        fprintf(arq, "%c", livro->titulo[i]);

    fprintf(arq," ");

    fprintf(arq, "%c", livro->dispovivel);
    fprintf(arq,"\n");

}

void Le_arquivo(Livro_t* livro,FILE* arq){

    char *titulo_aux, disp;

    titulo_aux = (char*) calloc(50, sizeof(char));

    fscanf(arq,"%s %c",titulo_aux, &disp);
    fscanf(arq,"\n");

    Passa_valores_livro(livro, titulo_aux, disp);

    free(titulo_aux);
}

int Cria_arquivos_temporarios(FILE* entrada, int Max_memoria){


    char nome_arq_temp[15];
    int cont = 0;
    int j = 0;
    Livro_t** vetor_livros = Aloca_vetor(Max_memoria);
    while(!feof(entrada)){
        fread(vetor_livros[cont], sizeof(*vetor_livros[cont]),1,entrada);
        cont++;
        if(cont == Max_memoria){
            sprintf(nome_arq_temp, "temp0%d", j);
            Ordena_livros(vetor_livros, Max_memoria);
            Salva_arquivo(nome_arq_temp, vetor_livros, cont);
            cont = 0;
            j++;
            Apaga_vet_livros(vetor_livros, Max_memoria);
            vetor_livros = Aloca_vetor(Max_memoria);
        }
    }
    if(cont > 0 && vetor_livros[0]->titulo[0] != '\0'){
        sprintf(nome_arq_temp, "temp0%d",j);
        Ordena_livros(vetor_livros, Max_memoria);
        Salva_arquivo(nome_arq_temp, vetor_livros, cont);
        j++;
    }
    Apaga_vet_livros(vetor_livros, Max_memoria);
    return j;
}

void Salva_arquivo(char* nome_arq, Livro_t** vet_livros, int cont){

    int i = 0;
    FILE* arq = fopen(nome_arq,"wb");
    for(i = 0;i < cont;i++)
        fwrite(vet_livros[i], sizeof(*vet_livros[i]),1,arq);

    fclose(arq);
}

