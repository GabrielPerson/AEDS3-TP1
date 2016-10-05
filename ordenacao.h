//
// Created by person on 19/09/16.
//

#ifndef TP1_ORDENACAO_H
#define TP1_ORDENACAO_H
#include "livro.h"
#include "arquivo.h"

/*
 * Prototipo: void Ordena_livros(Livro_t** vetor_livros, size_t Max_memoria);
 *
 * Funcao: Ordena um vetor de livros que serão inseridos nos arquivos temporarios usados no processo de merge sort
 * externo através do algoritmo bubble sort, comparando os titulos entre os livros
 *
 * Entrada: vetor de livros a ser ordenado. Tamanho maximo da memoria
 *
 * Saida: funcao void
 */

void Ordena_livros(Livro_t** vetor_livros, int Max_memoria);

/*
 * Prototipo: void Merge_sort(size_t num_arqs);
 *
 * Funcao: Aplica o algoritmo de merge sort externo nos arquivos temporarios criados. Utiliza uma funcao auxiliar
 * para realizar a comparacao entre o livros dos arquivos.
 * A cada iteração o numero de arquivos é dividido por 2, ate que restem somente 2 arquivos para serem fundidos,
 * e assim, cria-se o arquivo de saida com o nome "livros_ordenados".
 *
 * Entrada: Numero de arquivos temporarios criados a partir da divisao do arquivo com todos os livros não ordenados.
 *
 * Saida: funcao void.
 */

void Merge_sort(int num_arqs);

/*
 * Prototipo: void Escreve_menor(FILE* temp_entrada1,FILE* temp_entrada2, FILE* temp_saida,Livro_t** buf_livros, int flag_ordenado);
 *
 * Funcao: Realiza a comparacao entre
 * livros de dois arquivos de cada vez. Quando se acha o menor livro na comparacao, escreve o mesmo em outro arquivo
 * temporario e le-se o proximo livro do mesmo arquivo de origem.
 *
 * Entrada:
 *
 * Saida:
 */

void Escreve_menor(FILE* temp_entrada1,FILE* temp_entrada2, FILE* temp_saida,Livro_t** buf_livros, int flag_ordenado);

//void Seek_and_read(Livro_t* livro, FILE* entrada, int seek);

#endif //TP1_ORDENACAO_H
