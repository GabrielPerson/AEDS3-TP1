//
// Created by person on 19/09/16.
//

#include "ordenacao.h"
#include <stdlib.h>
#include <string.h>


void Ordena_livros(Livro_t** vetor, int Max_memoria){

    int i = 0,j = 0;
    int k = 0;
    int comp = 0;
    char aux_disp;

    for(i = Max_memoria-1; i >= 1; i--){
        for(j = 0; j < i; j++){
            comp = strcmp(vetor[j]->titulo,vetor[j+1]->titulo);
            if(comp > 0 && vetor[j+1]->titulo[0] != '\0') {
                char* aux = (char*)calloc(51, sizeof(char));
                for (k = 0; k< 51; k++){
                    aux[k] = vetor[j]->titulo[k];
                    aux_disp = vetor[j]->dispovivel;
                    vetor[j]->titulo[k] = vetor[j + 1]->titulo[k];
                    vetor[j]->dispovivel = vetor[j + 1]->dispovivel;
                    vetor[j + 1]->titulo[k] = aux[k];
                    vetor[j + 1]->dispovivel = aux_disp;
                }
                free(aux);
            }
        }
    }
}

void Merge_sort(int num_arqs){

    int i = 0, j = 0, x = 0;
    int Num_merges = 0;
    Livro_t** buffer_livros;
    int arq_sobra = 0;
    int sobra_j = 0, sobra_k = 0;
    int flag_ordenado = 0;

    char arq_entrada1[15];
    char arq_entrada2[15];
    char arq_saida[18];
    FILE *temp_saida;
    FILE *temp_entrada1;
    FILE *temp_entrada2;

    while(num_arqs != 1){
        buffer_livros = Aloca_vetor(2);
        Num_merges = num_arqs/2;
        i = 0;
        j = 0;
        if(num_arqs%2 != 0 && arq_sobra != 1) {
            arq_sobra = 1;
            sobra_k = x;
            sobra_j = num_arqs-1;
        }else if(arq_sobra != 1)
            arq_sobra = 0;
        while(i < Num_merges) {
            sprintf(arq_entrada1,"temp%d%d",x,j);

            if(num_arqs == 2){
                if(arq_sobra == 1)
                    sprintf(arq_entrada2,"temp%d%d",sobra_k,sobra_j);

                else
                    sprintf(arq_entrada2,"temp%d%d",x,j+1);

                sprintf(arq_saida,"livros_ordenados");
                flag_ordenado = 1;
            }
            else {
                if(arq_sobra == 1 && j == num_arqs-2) {
                    sprintf(arq_entrada2, "temp%d%d", sobra_k, sobra_j);
                    arq_sobra = 0;
                }
                else
                    sprintf(arq_entrada2,"temp%d%d",x,j+1);

                sprintf(arq_saida, "temp%d%d", x + 1, i);
            }
            temp_entrada1 = fopen(arq_entrada1,"rb");
            temp_entrada2 = fopen(arq_entrada2,"rb");
            temp_saida = fopen(arq_saida, "wb");
            Escreve_menor(temp_entrada1, temp_entrada2 ,temp_saida, buffer_livros, flag_ordenado);
            i++;
            j+=2;
            fclose(temp_entrada1);
            temp_entrada1 = NULL;
            fclose(temp_entrada2);
            temp_entrada2 = NULL;
            fclose(temp_saida);
            temp_saida = NULL;
        }
        x++;
        Apaga_vet_livros(buffer_livros, 2);
        if(num_arqs%2 != 0)
            num_arqs++;
        num_arqs/=2;
    }

    system("rm -f temp*");

}

void Escreve_menor(FILE* temp_entrada1 ,FILE* temp_entrada2, FILE* temp_saida, Livro_t** buf_livros, int flag_ordenado) {

    int comp = 0;
    int seek1 = 1, seek2 = 1;

    if(temp_entrada1 != NULL)
        fread(buf_livros[0], sizeof(*buf_livros[0]),1,temp_entrada1);
    if(temp_entrada2 != NULL)
        fread(buf_livros[1], sizeof(*buf_livros[1]),1,temp_entrada2);

   while(buf_livros[0]->titulo[0] != '\0' || buf_livros[1]->titulo[0] != '\0') {

        comp = strcmp(buf_livros[0]->titulo, buf_livros[1]->titulo);

        if(buf_livros[0]->titulo[0] != '\0' && buf_livros[1]->titulo[0] != '\0'){
            if(comp < 0){
                if(flag_ordenado == 0)
                    fwrite(buf_livros[0], sizeof(*buf_livros[0]),1,temp_saida);
                else
                    Escreve_arquivo(buf_livros[0], temp_saida);
                //Seek_and_read(buf_livros[0],temp_entrada1,seek1);
                Apaga_livro(buf_livros[0]);
                buf_livros[0] = (Livro_t *) calloc(1, sizeof(Livro_t));
                fseek(temp_entrada1, seek1*sizeof(*buf_livros[0]), SEEK_SET);
                fread(buf_livros[0], sizeof(*buf_livros[0]),1,temp_entrada1);
                seek1++;
            }
            else if(comp > 0){
                if(flag_ordenado == 0)
                    fwrite(buf_livros[1], sizeof(*buf_livros[1]),1,temp_saida);
                else
                    Escreve_arquivo(buf_livros[1], temp_saida);
                //Seek_and_read(buf_livros[1],temp_entrada2,seek2);
                Apaga_livro(buf_livros[1]);
                buf_livros[1] = (Livro_t *) calloc(1, sizeof(Livro_t));
                fseek(temp_entrada2, seek2* sizeof(*buf_livros[1]), SEEK_SET);
                fread(buf_livros[1], sizeof(*buf_livros[1]),1,temp_entrada2);
                seek2++;
            }
        }
       else if(buf_livros[1]->titulo[0] == '\0'){
            if(flag_ordenado == 0)
                fwrite(buf_livros[0], sizeof(*buf_livros[0]),1,temp_saida);
            else
                Escreve_arquivo(buf_livros[0], temp_saida);
            //Seek_and_read(buf_livros[0],temp_entrada1,seek1);
            Apaga_livro(buf_livros[0]);
            buf_livros[0] = (Livro_t *) calloc(1, sizeof(Livro_t));
            fseek(temp_entrada1, seek1* sizeof(*buf_livros[0]), SEEK_SET);
            fread(buf_livros[0], sizeof(*buf_livros[0]),1,temp_entrada1);
            seek1++;
        }
       else if(buf_livros[0]->titulo[0] == '\0'){
            if(flag_ordenado == 0)
                fwrite(buf_livros[1], sizeof(*buf_livros[1]),1,temp_saida);
            else
                Escreve_arquivo(buf_livros[1], temp_saida);
            //Seek_and_read(buf_livros[1],temp_entrada2,seek2);
            Apaga_livro(buf_livros[1]);
            buf_livros[1] = (Livro_t *) calloc(1, sizeof(Livro_t));
            fseek(temp_entrada2, seek2* sizeof(*buf_livros[1]), SEEK_SET);
            fread(buf_livros[1], sizeof(*buf_livros[1]),1,temp_entrada2);
            seek2++;
        }
    }

}

/*EU QUERIA MODULARIZAR A FUNCAO DE CIMA. EU JURO. MAS A "SEEK_AND_READ" NAO
 * TAVA FUNCIONANDO. EU JURO
*/
 /*
void Seek_and_read(Livro_t* livro, FILE* entrada, int seek){

    //Apaga_livro(livro);
    //livro = NULL;
    livro = (Livro_t*)calloc(1, sizeof(Livro_t));
    fseek(entrada,seek * sizeof(*livro),SEEK_SET);
    fread(livro, sizeof(*livro),1,entrada);

}*/
