//
// Created by person on 14/09/16.
//

#ifndef TP1_LIVRO_H
#define TP1_LIVRO_H

#include <stdio.h>


/*
 * Prototipo: typedef struct livro
 *
 * Funcao: Strct para armazenar as informacoes de cada livro, tais como seu
 * titulo e sua displonibilidade na bilbioteca, em variaveis do tipo Livro_t.
 */

typedef struct livro{

    char titulo[51];
    char dispovivel;

} Livro_t;

/*
 * Prototipo: Livro_t** Aloca_vetor(size_t Num_livs);
 *
 * Funcao: Aloca espaço para o vetor de livros que sera usado para operacoes de leitura dos livros para a memoria
 * principal, escrita nos arquivos e comparacao entre os livros
 *
 * Entrada: Numero de livros a serem alocados na memoria principal
 *
 * Saida: Vetor do tipo Livro_t**.
 */

Livro_t** Aloca_vetor(int Num_livs);

/*
 * Prototipo: void Passa_valores_livro(Livro_t* livro, char* titulo, char disponivel);
 *
 * Funcao: Passa os valores lidos dos arquivos na memoria secundaria para as variaveis
 * do tipo Livro_t, tais como o titulo do livro e sua disponibilidade na biblioteca.
 *
 * Entrada: livro que receberá os valores, titulo a ser passado, valor de disponibilidade
 * a ser passado.
 *
 * Saida: funcao void
 */

void Passa_valores_livro(Livro_t* livro, char* titulo, char disponivel);

/*
 * Prototipo: void Apaga_vet_livros(Livro_t** vetor_livros);
 *
 * Funcao: Libera espaco na memoria alocada para um vetor de livros
 *
 * Entrada: vetor a ser liberado.
 *
 * Saida: funcao void
 */

void Apaga_vet_livros(Livro_t** vetor_livros, int tam_memoria);

/*
* Prototipo: void Apaga_livro(Livro_t* liv);
*
* Funcao: libera espaço na memoria alocada para um unico livro.
*
* Entrada: livro a ser liberado
*
* Saida: funcao void
*/

void Apaga_livro(Livro_t* liv);

/*
* Prototipo: void Le_entrada(FILE* entrada);
*
* Funcao: le livros passados no stdin para uma variavel do tipo Livro_t
* auxiliar e entao escreve em um arquivo na memoria secundaria que sera usado
 * no metodo de ordenacao externa do programa
*
* Entrada: arquivo onde serao escritos os livros lidos do stdin
*
* Saida: funcao void
*/

void Le_entrada(FILE* entrada);

#endif //TP1_LIVRO_H
