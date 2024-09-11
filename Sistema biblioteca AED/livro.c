#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"
#include "estrutura.h"

// Função para adicionar um livro à coleção
Livro* adicionar_livro(Livro* livros, int* total_livros) {
    livros = realocar_livros(livros, *total_livros);

    printf("Digite o titulo do livro: ");
    getchar(); // Limpar buffer
    fgets(livros[*total_livros].titulo, 100, stdin);
    strtok(livros[*total_livros].titulo, "\n"); // Remover nova linha

    printf("Digite o autor do livro: ");
    fgets(livros[*total_livros].autor, 100, stdin);
    strtok(livros[*total_livros].autor, "\n");

    printf("Digite o ISBN do livro: ");
    fgets(livros[*total_livros].ISBN, 20, stdin);
    strtok(livros[*total_livros].ISBN, "\n");

    printf("Digite o ano de publicacao: ");
    scanf("%d", &livros[*total_livros].ano_publicacao);

    livros[*total_livros].disponivel = 1; // Inicialmente disponível
    (*total_livros)++;

    printf("Livro adicionado com sucesso!\n");
    return livros;
}

// Função para listar todos os livros
void listar_livros(Livro* livros, int total_livros) {
    for (int i = 0; i < total_livros; i++) {
        printf("Titulo: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("ISBN: %s\n", livros[i].ISBN);
        printf("Ano de publicacao: %d\n", livros[i].ano_publicacao);
        printf("Disponibilidade: %s\n", livros[i].disponivel ? "Disponivel" : "Emprestado");
        printf("------------------------------------\n");
    }
}
