//
// Created by person on 30/09/16.
//

#include "busca.h"
#include <string.h>

void Busca(int Num_consultas, int Num_estantes){

    int i = 0;
    char titulo_aux[51];
    FILE* indice;

    for(i = 0; i < Num_consultas;i++){
        indice = fopen("indice","rb");
        if(i != Num_consultas-1)
            scanf("%s\n", titulo_aux);
        else
            scanf("%s",titulo_aux);
        Busca_indice(titulo_aux,indice, Num_estantes);
        fclose(indice);
    }
}

void Cria_estantes(FILE* arq_ord, int Num_estantes, int Max_livro_estante){

    int i = 0, j = 0;

    FILE* index;
    FILE* estante;
    index = fopen("indice","wb");
    char arq_estante[15];
    Livro_t* livro_aux;
    int flag_livro2 = 0;

    for(i = 0; i < Num_estantes;i++){
        sprintf(arq_estante,"estante%d",i);
        estante = fopen(arq_estante,"wb");
        j = 0;
        if(feof(arq_ord))
            fprintf(index,"#\n");
        while(j < Max_livro_estante && !feof(arq_ord)){
            livro_aux = (Livro_t*) calloc(1, sizeof(Livro_t));
            Le_arquivo(livro_aux,arq_ord);
            if(j == 0)
                Escreve_indice(index,livro_aux,flag_livro2);
            else if(j == Max_livro_estante-1 || feof(arq_ord)){
                flag_livro2 = 1;
                Escreve_indice(index,livro_aux, flag_livro2);
                flag_livro2 = 0;
            }
            fwrite(livro_aux, sizeof(*livro_aux),1,estante);
            Apaga_livro(livro_aux);
            j++;
        }
        fclose(estante);
    }
    fclose(index);
}

void Escreve_indice(FILE* arq_indice, Livro_t* livro_aux, int flag_livro2) {

    size_t i = 0;

    size_t tam_livro = strlen(livro_aux->titulo);

    for (i = 0; i < tam_livro; i++)
        fprintf(arq_indice, "%c", livro_aux->titulo[i]);
    if (flag_livro2 == 0)
        fprintf(arq_indice, " ");
    else
        fprintf(arq_indice, "\n");

}

void Busca_indice(char* livro, FILE* arquivo, int Num_estantes){

    int cont1 = 0, cont2 = 0;
    char livro_arq[51], estante[11];
    int comp = 0;
    int seek = 0;
    FILE* arq_estante;

    while(!feof(arquivo)) {
        fscanf(arquivo, "%s", livro_arq);
        comp = strcmp(livro, livro_arq);
        if (cont2 == Num_estantes || livro_arq[0] == '#'){
            printf("livro nao encontrado\n");
            return;
        }
        else{
            if(cont1 == 0){
                if(comp < 0){
                    printf("livro nao encontrado\n");
                    return;
                }
                else{
                    cont1++;
                    seek += (strlen(livro_arq)* sizeof(char)+1);
                    fseek(arquivo,seek,SEEK_SET);
                }
            }
            else if(cont1 > 0) {
                if (comp <= 0) {
                    sprintf(estante, "estante%d", cont2);
                    arq_estante = fopen(estante, "rb");
                    if (arq_estante == NULL) {
                        printf("livro nao encontrado\n");
                        return;
                    }
                    else
                        Busca_estantes(livro,arq_estante,cont2);
                    fclose(arq_estante);
                    return;
                } else if (comp > 0) {
                    cont1 = 0;
                    cont2++;
                    seek += (strlen(livro_arq) * sizeof(char) + 1);
                    fseek(arquivo, seek, SEEK_SET);
                }
            }
        }
    }
}

void Busca_estantes(char* livro, FILE* estante, int Num_estante){

    size_t i = 0;
    int comp = 0;
    Livro_t* livro_estante;


    while(!feof(estante)){

       livro_estante = (Livro_t*)calloc(1, sizeof(Livro_t));
       fread(livro_estante, sizeof(*livro_estante),1,estante);
       comp = strcmp(livro,livro_estante->titulo);

        if(comp < 0) {
            printf("livro nao encontrado\n");
            Apaga_livro(livro_estante);
            return;
        }
        else if(comp == 0) {
            if (livro_estante->dispovivel == '1') {
                printf("disponivel na posicao %ld na estante %d\n", i, Num_estante);
                Apaga_livro(livro_estante);
                return;
            }
            else {
                printf("emprestado\n");
                Apaga_livro(livro_estante);
                return;
            }
        }
        else if(comp > 0) {
            i++;
            fseek(estante, i * sizeof(*livro_estante), SEEK_SET);
        }
        Apaga_livro(livro_estante);
    }
}
