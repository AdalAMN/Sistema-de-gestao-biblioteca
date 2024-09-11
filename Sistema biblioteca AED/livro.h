#ifndef LIVRO_H
#define LIVRO_H

typedef struct {
    char titulo[100];
    char autor[100];
    char ISBN[20];
    int ano_publicacao;
    int disponivel;
} Livro;

Livro* adicionar_livro(Livro* livros, int* total_livros);
void listar_livros(Livro* livros, int total_livros);

#endif
