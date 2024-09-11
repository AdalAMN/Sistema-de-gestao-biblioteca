#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"

// Função para realocar a memória ao adicionar um livro
Livro* realocar_livros(Livro* livros, int total_livros) {
    livros = realloc(livros, (total_livros + 1) * sizeof(Livro));
    if (livros == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    return livros;
}
