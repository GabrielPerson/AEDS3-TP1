//
// Created by person on 15/09/16.
//

#ifndef TP1_ARQUIVO_H
#define TP1_ARQUIVO_H

#include "livro.h"
#include <stdio.h>

/*
 * Prototipo: void Escreve_arquivo(Livro_t* liv, FILE* arq);
 *
 * Funcao: Escreve o titulo e a disponbilidade de um livro em um arquivo. Usada para escrita em arquivos
 * onde seja possivel a leitura de seu conteudo.
 *
 * Entrada: Livro a ser escrito. Livro onde sera escrito os dados.
 *
 * Saida: funcao void
 */

void Escreve_arquivo(Livro_t* liv, FILE* arq);

/*
 * Prototipo: void Le_arquivo(Livro_t* livro, FILE* arq);
 *
 * Funcao: Le dados de um livro de um determinado arquivo. Usada em arquivos onde pode-se ler seu conteudo.
 *
 * Entrada: livro que recebera os dados lidos do arquivo. Arquivo que contem os dados do livro
 *
 * Saida: funcao void
 */

void Le_arquivo(Livro_t* livro, FILE* arq);

/*
 * Prototipo: size_t Cria_arquivos_temporarios(FILE* entrada, size_t Max_memoria);
 *
 * Funcao: Funcao que, dado um arquivo contendo livros nao ordenados, separa esse arquivo em outros arquivos
 * ordenados do tamanho da memoria principal.
 *
 * Entrada: arquivo que sera dividido. tamanho maximo da memoria(e dos arquivos menores)
 *
 * Saida: retorna o numero de arquivos criados.
 */

int Cria_arquivos_temporarios(FILE* entrada, int Max_memoria);

/*
 * Prototipo: void Salva_arquivo(char* nome_arq, Livro_t** vet_livros, int cont);
 *
 * Funcao: funcao que imprime livros de um vetor de livros em um arquivo binario atraves da funcao "fwrite"
 *
 * Entrada: nome do arquivo que sera aberto. vetor de livros. tamanho do numero de livros que serao escritos
 *
 * Saida: funcao void
 */

void Salva_arquivo(char* nome_arq, Livro_t** vet_livros, int cont);

#endif //TP1_ARQUIVO_H
