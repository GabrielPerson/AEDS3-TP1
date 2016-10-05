#Comandos para uso do makefile:
#<make> -> compilação do codigo
#<make valgrind> -> depurar e executar o codigo usando o valgrind passando os valores de entrada por input
#<make test> -> executar o codigo passando as entradas
#<make time> -> executa o codigo passando as entradas e retornando tambem o tempo de execução.
#<make clean> -> remove os arquivos .o, executavel, as estantes, o arquivo ordenado e o indice.

CC = gcc

CFLAGS = -O0 -Wall -Wextra -Werror -std=c99 -pedantic

OBJ = main.o livro.o arquivo.o ordenacao.o busca.o

DEPS = trie.h dicionario.h

VFLAGS = --leak-check=full --leak-resolution=high --show-reachable=yes --track-origins=yes

EXEC = ./exe 

all: exe

exe: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o exe estante* livros_ordenados indice

valgrind:
	valgrind $(VFLAGS) $(EXEC) < input

test:
	$(EXEC) < input

time:
	time $(EXEC) < input
