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

void buscar_por_titulo(Livro* livros, int total_livros, const char* titulo) {
    for (int i = 0; i < total_livros; i++) {
        if (strcmp(livros[i].titulo, titulo) == 0) {
            printf("Livro encontrado:\n");
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("ISBN: %s\n", livros[i].ISBN);
            printf("Ano de Publicacao: %d\n", livros[i].ano_publicacao);
            printf("Disponivel: %s\n", livros[i].disponivel ? "Sim" : "Nao");
            return;
        }
    }
    printf("Livro nao encontrado.\n");
}

//função para buscar livro pelo autor
void buscar_por_autor(Livro* livros, int total_livros, const char* autor) {
    for (int i = 0; i < total_livros; i++) {
        if (strcmp(livros[i].autor, autor) == 0) {
            printf("Livro(s) encontrado(s)!\n");
            listar_livros(&livros[i], 1);
        }
    }
}

// Função para buscar livro pelo ISBN
void buscar_por_ISBN(Livro* livros, int total_livros, const char* ISBN) {
    for (int i = 0; i < total_livros; i++) {
        if (strcmp(livros[i].ISBN, ISBN) == 0) {
            printf("Livro encontrado!\n");
            listar_livros(&livros[i], 1);
            return;
        }
    }
    printf("Livro nao encontrado!\n");
}

// Função para emprestar um livro
void emprestar_livro(Livro* livros, int total_livros, const char* titulo) {
    for (int i = 0; i < total_livros; i++) {
        if (strcmp(livros[i].titulo, titulo) == 0) {
            if (livros[i].disponivel) {
                livros[i].disponivel = 0;
                printf("Livro emprestado com sucesso!\n");
            } else {
                printf("O livro ja esta emprestado!\n");
            }
            return;
        }
    }
    printf("Livro nao encontrado!\n");
}

// Função para devolver um livro
void devolver_livro(Livro* livros, int total_livros, const char* titulo) {
    for (int i = 0; i < total_livros; i++) {
        if (strcmp(livros[i].titulo, titulo) == 0) {
            if (!livros[i].disponivel) {
                livros[i].disponivel = 1;
                printf("Livro devolvido com sucesso!\n");
            } else {
                printf("O livro ja esta disponivel!\n");
            }
            return;
        }
    }
    printf("Livro nao encontrado!\n");
}