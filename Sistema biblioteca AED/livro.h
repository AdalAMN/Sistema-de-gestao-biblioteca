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
void buscar_por_titulo(Livro* livros, int total_livros, const char* titulo);
void buscar_por_autor(Livro* livros, int total_livros, const char* autor);
void buscar_por_ISBN(Livro* livros, int total_livros, const char* ISBN);
void emprestar_livro(Livro* livros, int total_livros, const char* titulo);
void devolver_livro(Livro* livros, int total_livros, const char* titulo);

#endif