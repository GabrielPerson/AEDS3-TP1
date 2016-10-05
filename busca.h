//
// Created by person on 30/09/16.
//

#ifndef TP1_BUSCA_H
#define TP1_BUSCA_H

#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include "arquivo.h"
#include "ordenacao.h"

/*
 * Prototipo: void Busca(size_t Num_consultas, size_t Num_estantes);
 *
 * Funcao: Inicia o processo de busca dos livros recebidos na stdin, abrindo o indice,
 * lendo os livros e realizando a busca no indice.
 *
 * Entrada: Numero de consultas a serem realizadas no indice e nas estantes,
 * numero de estantes a serem pesquisadas.
 *
 * Saida: função void
 */

void Busca(int Num_consultas, int Num_estantes);

/*
 * Prototipo: void Cria_estantes(FILE* arq_ord, size_t Num_estantes, size_t Max_livro_estante);
 *
 * Funcao: recebe o arquivo com os livros ordenados e os passa para as estantes
 * e para o indice.
 *
 * Entrada: Arvquivo ordenado, numero de estantes a serem criados, maximo de livros
 * a serem adicionados em cada estantes.
 *
 * Saida: função void
 */

void Cria_estantes(FILE* arq_ord, int Num_estantes, int Max_livro_estante);

/*
 * Prototipo: void Escreve_indice(FILE* arq_indice, FILE* arq_ord, Livro_t* livro_aux, int livro2);
 *
 * Funcao: escreve o livro recebido no arquivo indice
 *
 * Entrada: livro a ser escrito, arquivo indice, flag que define se é o primeiro ou
 * ultimo livro de cada arquivo do indice
 *
 * Saida: função void
 */

void Escreve_indice(FILE* arq_indice, Livro_t* livro_aux, int livro2);

/*
 * Prototipo: void Busca_indice(char* livro, FILE* arquivo, size_t Num_estantes);
 *
 * Funcao: Realiza a busca do livro no indice, através da função strcmp.
 * Caso o livro a ser pesquisado seje "maior" do que o primeiro livro do indice,
 * compara-se com o segundo. Caso seje "menor" pesquisa-se na estante e caso seje
 * "maior" compara-se com os proximos livros do indice.
 *
 * Entrada: titulo do livro a ser pesquisado, arquivo indice, numero de estantes a ser
 * pesquisado.
 *
 * Saida: função void
 */

void Busca_indice(char* livro, FILE* arquivo, int Num_estantes);

/*
 * Prototipo: void Busca_estantes(char* livro, FILE* estante, size_t Num_estante);
 *
 * Funcao: Realiza busca sequencial na estante, usando a função strcmp para comparar
 * o livro a ser pesquisado e cada livro da estante. Caso seje "menor", o livro não se
 * encontra na estante. Caso seje "maior", compara-se com o proximo livro. E caso seje
 * "igual" verifica-se se o livro encontra-se disponivel ou emprestado.
 *
 * Entrada: livro a ser pesquisado, arquivo da estante onde sera realizada a pesquisa,
 * numero da estante onde sera feita a pesquisa.
 *
 * Saida: função void
 */

void Busca_estantes(char* livro, FILE* estante, int Num_estante);

#endif //TP1_BUSCA_H
